#include<iostream>
#include"console.h"
#include<Windows.h>
#include<conio.h>
using namespace std;
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
int main()
{
int i=3;
while(1){
	if(kbhit()){
		char key=getch();
		if(key=='a') i--;
		if(key=='d') i++;
		if(i==2) i=19;
		if(i==20) i=3;
		clrscr();
		gotoXY(i,20);
		cout<<"__________";
		Sleep(200);
	}


	}
	return 0;
}


