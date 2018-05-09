#include <cstring>
#include <cstdlib>
#include "Minesweeper.h"
#include "Record.h"
#include "IO.h"
#include "myTime.h"
using namespace std;

Minesweeper::Minesweeper(){
	GetRange();
	if(Finished) return;
	SetTable();
	Start();
	PrintMap();
}

void Minesweeper::GetRange(){
	if(io.END){Finished=true; return;}
	rec.Set=true;
	SetRange(io.Height,io.Width,io.Bombs);
	if(io.Range==4) rec.Set=false;
}

void Minesweeper::SetRange(int y,int x, int b){
	Height=y; Width=x; Bombs=b; Win=false; Finished=false;
}

void Minesweeper::SetTable(){
	memset(Appear,false,sizeof(Appear));
	memset(Table,0,sizeof(Table));
	memset(isFlag,false,sizeof(isFlag));
	int n=Height*Width;
	Rest=n;
	srand(time(NULL));
	for(int i=0; i<Bombs; i++){
		int tmp=rand()%n;
		int Y=tmp/Width, X=tmp%Width;
		if(Table[Y][X]==-1) i--;
		else Table[Y][X]=-1;
	}
	for(int i=0; i<Height; i++)
		for(int j=0; j<Width; j++)
			if(Table[i][j]==-1){
				if(Check(i-1,j) && Table[i-1][j]!=-1) Table[i-1][j]++;
				if(Check(i+1,j) && Table[i+1][j]!=-1) Table[i+1][j]++;
				if(Check(i,j-1) && Table[i][j-1]!=-1) Table[i][j-1]++;
				if(Check(i,j+1) && Table[i][j+1]!=-1) Table[i][j+1]++;
				if(Check(i-1,j-1) && Table[i-1][j-1]!=-1) Table[i-1][j-1]++;
				if(Check(i-1,j+1) && Table[i-1][j+1]!=-1) Table[i-1][j+1]++;
				if(Check(i+1,j-1) && Table[i+1][j-1]!=-1) Table[i+1][j-1]++;
			    if(Check(i+1,j+1) && Table[i+1][j+1]!=-1) Table[i+1][j+1]++;
			}
}

bool Minesweeper::Check(int y,int x){
	if(y<0 || x<0 || y>=Height || x>=Width) return false;
	return true;
}

void Minesweeper::Start(){
	io.GameInit();
	start=false;
	int y,x,ch;
	Flag=0;
	if(rec.Set){ rec.Read(Bombs); rec.Print();}
	while(!Finished){
		if(start && !Finished) mytime.ShowTime();
		int Stat=io.Move();
		if(Stat==-1){ //press r or R
			GetRange();
			if(Finished) return;
			SetTable();
			Start();
			return;
		}
		if(Stat==1){ //press enter
			while(!start && Table[io.y-io.starty][io.x-io.startx]==-1)
				SetTable();
			if(!start){start=true; Finished=false; mytime.TimeStart();}
			Show(io.y-io.starty, io.x-io.startx);
		}
		else if(Stat==2){ //press f or F
			int Y=io.y-io.starty, X=io.x-io.startx;
			if(start && !Finished && !Appear[Y][X]){ 
				if(isFlag[Y][X]){
					isFlag[Y][X]=false;
					Flag=io.PutFlag(Y,X,Flag,1);
				}
				else{
					isFlag[Y][X]=true;
					Flag=io.PutFlag(Y,X,Flag,0);
				}
			}
		}
		if(Rest<=Bombs){ Win=true; End();}
	}
}

void Minesweeper::Show(int y, int x){
	if(!Appear[y][x] && !isFlag[y][x]) Appear[y][x]=true;
	else return;
	if(Table[y][x]==-1){
		Appear[y][x]=true;
		Finished=true;
		End();
	}
	else if(Table[y][x]==0) ShowSide(y,x);
	else io.Display(y+1,x+1,Table[y][x],2);
	Rest--;
}

void Minesweeper::ShowSide(int y, int x){
	if(!Appear[y][x]){ Appear[y][x]=true; Rest--;}
	if(isFlag[y][x]){Appear[y][x]=false; Rest++;}
	else if(Table[y][x]) io.Display(y+1,x+1,Table[y][x],2);
	else io.Display(y+1,x+1,' ',2);
	if(Check(y+1,x) && !Appear[y+1][x]){
		if(Table[y+1][x]==0) ShowSide(y+1,x);
		else if(!isFlag[y+1][x]){
			Appear[y+1][x]=true; Rest--;
			io.Display(y+2,x+1,Table[y+1][x],2);
		}
	}
	if(Check(y-1,x) && !Appear[y-1][x]){
		if(Table[y-1][x]==0) ShowSide(y-1,x);
		else if(!isFlag[y-1][x]){
			Appear[y-1][x]=true; Rest--;
			io.Display(y,x+1,Table[y-1][x],2);
		}
	}
	if(Check(y,x+1) && !Appear[y][x+1]){
		if(Table[y][x+1]==0) ShowSide(y,x+1);
		else if(!isFlag[y][x+1]){
			Appear[y][x+1]=true; Rest--;
			io.Display(y+1,x+2,Table[y][x+1],2);
		}
	}
	if(Check(y,x-1) && !Appear[y][x-1]){
		if(Table[y][x-1]==0) ShowSide(y,x-1);
		else if(!isFlag[y][x-1]){
			Appear[y][x-1]=true; Rest--;
			io.Display(y+1,x,Table[y][x-1],2);
		}
	}
	if(Check(y+1,x+1) && !Appear[y+1][x+1]){
		if(Table[y+1][x+1]==0) ShowSide(y+1,x+1);
		else if(!isFlag[y+1][x+1]){
			Appear[y+1][x+1]=true; Rest--;
			io.Display(y+2,x+2,Table[y+1][x+1],2);
		}
	}
	if(Check(y-1,x-1) && !Appear[y-1][x-1]){
		if(Table[y-1][x-1]==0) ShowSide(y-1,x-1);
		else if(!isFlag[y-1][x-1]){
			Appear[y-1][x-1]=true; Rest--;
			io.Display(y,x,Table[y-1][x-1],2);
		}
	}
	if(Check(y+1,x-1) && !Appear[y+1][x-1]){
		if(Table[y+1][x-1]==0) ShowSide(y+1,x-1);
		else if(!isFlag[y+1][x-1]){
			Appear[y+1][x-1]=true; Rest--;
			io.Display(y+2,x,Table[y+1][x-1],2);
		}
	}
	if(Check(y-1,x+1) && !Appear[y-1][x+1]){
		if(Table[y-1][x+1]==0) ShowSide(y-1,x+1);
		else if(!isFlag[y-1][x+1]){
			Appear[y-1][x+1]=true; Rest--;
			io.Display(y,x+2,Table[y-1][x+1],2);
		}
	}
}

void Minesweeper::End(){
	if(Win)	Time=mytime.GetTime();
	io.Result(Win);
	Highscore=false;
	if(rec.Set && Win && rec.HighScore(Time)) Highscore=true;	
	for(int i=0; i<Height; i++)
		for(int j=0; j<Width; j++){
			if(Table[i][j]==-1 && !isFlag[i][j] && !Appear[i][j]) 
				io.Display(i+1,j+1,'*',4);
			else if(Table[i][j]==-1 && Appear[i][j])
				io.Display(i+1,j+1,'*',5);
			else if(Table[i][j]!=-1 && isFlag[i][j])
				io.Display(i+1,j+1,'f',3);
			else if(isFlag[i][j]) 
				io.Display(i+1,j+1,'f',4);
		}
	if(Highscore){
		string name;
		name=io.GetName();
		rec.Reset(Time,name,Bombs);
		Highscore=false;
	}
	Finished=true;
	io.Finished();
	if(!io.END){
		GetRange();
		if(Finished) return;
		SetTable();
		Start();
	}
}

void Minesweeper::PrintMap(){
	FILE *Mine;
	Mine=fopen("Mine.txt","w");
	for(int i=0; i<Height; i++){
		for(int j=0; j<Width; j++)
			Table[i][j]==-1?fprintf(Mine,"b"):fprintf(Mine,"%d",Table[i][j]);
		fprintf(Mine,"\n");
	}
	fclose(Mine);
}
