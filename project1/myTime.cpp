#include <iostream>
#include <ncurses.h>
#include "myTime.h"
using namespace std;

myTime::myTime(){
	SetTime();
}

myTime::~myTime(){
	delwin(time_win);
	endwin();
}

void myTime::SetTime(){
	time_win=newwin(1,30,LINES/2-4,COLS-40);
	wprintw(time_win,"Time: %3d\n",0);
}

int myTime::GetTime(){
	int TimeNow=time(NULL);
	return TimeNow-TimeBeg;
}

void myTime::TimeStart(){
	TimeBeg=time(NULL);
}

void myTime::ShowTime(){
	time_t TimeNow=time(NULL);
	mvwprintw(time_win,0,0,"Time: %3d  seconds\n",(int)TimeNow-TimeBeg);
	wrefresh(time_win);
}
