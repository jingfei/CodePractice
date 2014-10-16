#ifndef IO_H
#define IO_H
#include <iostream>
#include <ncurses.h>
using namespace std;

class IO{
	public:
		IO();
		int Range, Height, Width, Bombs;
		int y,x,startx,starty;
		bool END;
		void GameInit();
		int Move();
		int PutFlag(int y,int x,int Flag,bool Put);
		void Display(int y,int x,char w,int color);
		void Result(bool Win);
		string GetName();
		void Finished();
	private:	
		WINDOW *Right, *Left;
		void AskRange();
		void SetColor();
		void SetLeft(int h,int w,int sy,int sx);
		void SetRight();
};
#endif
