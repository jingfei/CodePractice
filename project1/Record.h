#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <string>
#include <ncurses.h>
using namespace std;

class Record{
	public:
		bool Set;
		void Read(int Bombs);
		void Print();
		void Reset(int Time,string name,int Bombs);
		bool HighScore(time_t t);
	private:
		WINDOW *rec_win;
		int RecordSec[5];
		char RecordName[5][20];
};
#endif
