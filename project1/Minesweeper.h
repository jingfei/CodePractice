#include <iostream>
#include <string>
#include "Record.h"
#include "IO.h"
#include "myTime.h"
using namespace std;

class Minesweeper{
	public:
		Minesweeper();
	private:
		Record rec;
		IO io;
		myTime mytime;
		int Table[50][50];
		bool Appear[50][50], isFlag[50][50], Highscore;
		int Width, Height, Bombs, Flag, Rest;
		bool Finished, Win, start;
		time_t Time;
		void GetRange();
		void SetTable();
		bool Check(int y,int x);
		void SetRange(int y,int x,int b);
		void Start();
		void Show(int y,int x);
		void ShowSide(int y,int x);
		void End();
		void PrintMap();
};

