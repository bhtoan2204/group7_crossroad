#pragma once
#ifndef CConsole_h
#define CConsole_h

#include<iostream>
#include<Windows.h> // thu vien do hoa
#include<conio.h> // thu vien nay chac de lay ki tu tu ban phiem
#include<time.h> // thu vien thoi gian chay
using namespace std;

#define Color_Black			0
#define Color_DarkBlue		1
#define Color_DarkGreen		2
#define Color_DarkCyan		3
#define Color_DarkRed		4
#define Color_DarkPink		5
#define Color_DarkYellow	6
#define Color_DarkWhite		7
#define Color_Grey			8
#define Color_Blue			9
#define Color_Green			10
#define Color_Cyan			11
#define Color_Red			12
#define Color_Pink			13
#define Color_Yellow		14
#define Color_White			15

#define default_ColorCode		7

#define key_Enter		13
#define Ctrl_V			22

#define key_Backspace	8
#define key_DownArrow	80
#define key_UpArrow		72
#define key_LeftArrow	75
#define key_RightArrow	77

#define key_NONE	-1

#define getSizeHelper  1000 // lay khung man hinh
#define rightShift 20 // 

/*man hinh tui se cho la 1200 900  rong va dai*/

class CConsole
{
private:
	int _width;
	int _height;

	void reSizeConsole(int width, int height);
	void getSize(int& width, int& height);
	//string getClipboard();
	//void printString(string, int, int, int, size_t, size_t);

public:
	CConsole(int width, int height);
	~CConsole();



	int width();
	int height();

	int inputKey(); // tra ve nut minh bam
	void clrscr(); // ham xoa man hinh ha

	// screen: goto (x,y)
	void GotoXY(int x, int y);
	//screen: get X
	int currentCursorX();
	// screen: get Y
	int currentCursorY();

	void TextColor(int color);
	// ham nay set cai backgound voi color
	void SetBackGroundTextColor(int backgound_color, int text_color);
	// screen:
	void fixConsoleWindow(); //  co dinh man hinh
	// ham nay de an hien con tro 1: de bat 0: de tat
	void ShowCur(bool CursorVisibility);
	// ham nay de vo hieu hoa boi den
	void DisableSelection();

	//string textEdit(int row, int begin, int end);
};
#endif // !CConsole_h




