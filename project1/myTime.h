#ifndef MYTIME_H
#define MYTIME_H
#include <iostream>
#include <ncurses.h>
using namespace std;

class myTime{
	public:
		myTime();
		~myTime();
		void ShowTime();
		int GetTime();
		void TimeStart();
	private:
		WINDOW *time_win;
		time_t TimeBeg;
		void SetTime();
};
#endif
