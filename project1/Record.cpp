#include <iostream>
#include <cstring>
#include <ncurses.h>
#include "Record.h"
using namespace std;

void Record::Read(int Bombs){
	FILE *rec;
	if(Bombs==10) rec=fopen("Record1.txt","r");
	else if(Bombs==40) rec=fopen("Record2.txt","r");
	else if(Bombs==99) rec=fopen("Record3.txt","r");
	for(int i=0; i<5; i++)
		fscanf(rec,"%s %d",RecordName[i],&RecordSec[i]);
	fclose(rec);
}

void Record::Print(){
	rec_win=newwin(8,31,LINES/2+3,COLS-42);
	box(rec_win,0,0);
	mvwprintw(rec_win,1,1," Record:");
	mvwprintw(rec_win,2,1," 1. %10s : %3d seconds",RecordName[0],RecordSec[0]);	
	mvwprintw(rec_win,3,1," 2. %10s : %3d seconds",RecordName[1],RecordSec[1]);
	mvwprintw(rec_win,4,1," 3. %10s : %3d seconds",RecordName[2],RecordSec[2]);
	mvwprintw(rec_win,5,1," 4. %10s : %3d seconds",RecordName[3],RecordSec[3]);
	mvwprintw(rec_win,6,1," 5. %10s : %3d seconds",RecordName[4],RecordSec[4]);
	wrefresh(rec_win);
}

bool Record::HighScore(time_t t){
	if(t<RecordSec[4]) return true;
	return false;
}

void Record::Reset(int Time,string name, int Bombs){
	delwin(rec_win);
	for(int i=0; i<5; i++)
		if(Time<RecordSec[i]){
			for(int j=4; j>i; j--){
				RecordSec[j]=RecordSec[j-1]; 
				strcpy(RecordName[j],RecordName[j-1]);
			}
			RecordSec[i]=Time; 
			strcpy(RecordName[i],name.c_str());
			break;
		}
	Print();
	FILE *rec;
	if(Bombs==10) rec=fopen("Record1.txt","w");
	else if(Bombs==40) rec=fopen("Record2.txt","w");
	else if(Bombs==99) rec=fopen("Record3.txt","w");
	for(int i=0; i<5; i++)
		fprintf(rec, "%s %d\n",RecordName[i],RecordSec[i]);
	fclose(rec);
	delwin(rec_win);
	endwin();
}
