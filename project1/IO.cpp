#include <iostream>
#include <cstring>
#include <ncurses.h>
#include "IO.h"
using namespace std;

IO::IO(){
	AskRange();
}

void IO::AskRange(){
	initscr();
	clear();
	printw("\n");
	printw("\tSelect the range:\n");
	printw("\t (Press Q to leave.)\n\n");
	printw("\t\t1. 9*9 with 10 bombs\n");
	printw("\t\t2. 16*16 with 40 bombs\n");
	printw("\t\t3. 16*30 with 99 bombs\n");
	printw("\t\t4. defined by yourself!!\n\n");
	move(1,28);
	cbreak();
	char Ans=getch();
	END=false;
	while( (Ans<'1' || Ans>'4') && !(Ans=='q' || Ans=='Q') ){
		mvaddstr(1,25," ");
		mvaddstr(1,35,"Wrong Input!!");
		move(1,28);
		Ans=getch();
	}
	if(Ans=='Q' || Ans=='q'){END=true; endwin(); return;}
	Range=Ans-'0';
	if(Range==1){Width=Height=9; Bombs=10;}
	else if(Range==2){Width=Height=16; Bombs=40;}
	else if(Range==3){Height=16; Width=30; Bombs=99;}
	else if(Range==4){
		move(9,0);
		printw("\t (Enter 0 to return.)\n\n");
		printw("\tHeight (max 20):  ");
		scanw("%d",&Height);
		if(Height==0){AskRange(); return;}
		while(Height>20 || Height<2){ 
			mvaddstr(11,25,"             ");
			mvaddstr(11,30,"Wrong Input!!"); 
			move(11,25); 
			scanw("%d",&Height);
		}
		mvaddstr(11,30,"                ");
		move(12,0);
		printw("\tWidth (max 30):  ");
		scanw("%d",&Width);
		if(Width==0){AskRange(); return;}
		while(Width>30 || Width<2){
			mvaddstr(12,25,"             ");
			mvaddstr(12,30,"Wrong Input!!");
			move(12,25); 
			scanw("%d",&Width);
		}
		mvaddstr(12,30,"                ");
		move(13,0);
		printw("\tAmount of bombs (max %3d):  ",Width*Height/2);
		scanw("%d",&Bombs);
		if(Bombs==0){AskRange(); return;}
		while(Bombs>Width*Height/2 || Bombs<1){ 
			mvaddstr(13,36,"             ");
			mvaddstr(13,41,"Wrong Input!!"); 
			move(13,36); 
			scanw("%d",&Bombs);
		}
	}
	endwin();
}

void IO::SetColor(){
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_WHITE);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_BLACK,COLOR_GREEN);
	init_pair(5,COLOR_RED,COLOR_GREEN); //bombs
	init_pair(6,COLOR_CYAN,COLOR_BLUE); //flag color
}

void IO::GameInit(){
	initscr();
	clear();
	SetColor();  refresh();
	startx=COLS/2-20-Width/2; starty=LINES/2-Height/2;
	x=startx; y=starty;
	cbreak(); noecho(); keypad(stdscr,TRUE); refresh();
	SetLeft(Height+2,Width+2,starty-1,startx-1);
	SetRight();
}

void IO::SetLeft(int h,int w,int sy,int sx){
	Left=newwin(h,w,sy,sx);
	wattron(Left,COLOR_PAIR(1));
	box(Left,0,0);
	wrefresh(Left);
	wattroff(Left,COLOR_PAIR(1));
}

void IO::SetRight(){
	Right=newwin(7,30,LINES/2-4,COLS-40);
	wprintw(Right,"Time: %3d  seconds\n",0);
	wprintw(Right,"Bombs left: %2d\n",Bombs);
	wprintw(Right,"Flags used:  0\n\n");
	wprintw(Right,"Press 'ENTER' to open\n");
	wprintw(Right,"Press 'f' to put flags\n");
	wprintw(Right,"Press 'r' to return");
	wrefresh(Right);
}

int IO::Move(){
	wrefresh(Left);
	move(y,x);
	int ch;
	ch=getch();
	switch(ch){
		case KEY_LEFT: --x; break;
		case KEY_RIGHT: ++x; break;
		case KEY_UP: --y; break;
		case KEY_DOWN: ++y; break;
		case 'r':
			AskRange();
			return -1;
		case 'f': case 'F':
			return 2;
		case KEY_ENTER: case '\n': case '\r': 
			return 1;
	}
	while(x<startx) x+=Width;
	while(x>=startx+Width) x-=Width;
	while(y<starty) y+=Height;
	while(y>=starty+Height) y-=Height;
	move(y,x);
	return 0;
}

int IO::PutFlag(int y,int x,int Flag,bool Put){
	if(Put){
		Flag--;
		mvwprintw(Left,y+1,x+1," "); wrefresh(Left);
	}
	else{
		Flag++;
		wattron(Left, COLOR_PAIR(6));
		mvwprintw(Left,y+1,x+1,"f"); wrefresh(Left);
		wattroff(Left, COLOR_PAIR(6));
	}
	mvwprintw(Right,1,0,"Bombs left: %2d\n",Bombs-Flag);
	mvwprintw(Right,2,0,"Flags used: %2d\n",Flag);
	wrefresh(Right);
	return Flag;
}

void IO::Display(int y,int x,char w,int color){
	wattron(Left,COLOR_PAIR(color));
	if(w>=0 && w<=9) w+='0';
	mvwprintw(Left,y,x,"%c",w); 
	wrefresh(Left);
	wattroff(Left,COLOR_PAIR(color));
}

void IO::Result(bool Win){
	attron(COLOR_PAIR(2));
	if(Win) mvprintw(2,40,"You Win"); 
	else mvprintw(2,40,"You Lose");
	attroff(COLOR_PAIR(2));
}

string IO::GetName(){
	attron(COLOR_PAIR(2));
	mvprintw(5,40,"HIGH SCORE!!");
	mvprintw(6,40,"Your Name (Max Length 10): ");
	attroff(COLOR_PAIR(2));
	echo();
	char name[30];
	getstr(name);
	while(strlen(name)>10){
		mvprintw(6,67,"                        ");
		mvprintw(7,67,"Too LONG!!");
		move(6,67);	
		getstr(name);
	}
	noecho();
	return name;
}

void IO::Finished(){
	attron(COLOR_PAIR(2));
	nodelay(stdscr,TRUE);
	mvprintw(4,40,"Press R to play again");
	mvprintw(5,40,"Press Q to end");
	refresh();
	int ch;
	do{
		ch=getch();
		if(ch=='r' || ch=='R'){
			nodelay(stdscr,FALSE);
			attroff(COLOR_PAIR(2));
			endwin();
			AskRange();
			return;
		}
	}while(ch!='Q' && ch!='q' && ch!='r' && ch!='R');
	attroff(COLOR_PAIR(2));
	delwin(Left); delwin(Right);
	endwin();	
	END=true;
}

