#include "CConsole.h"

void CConsole::getSize(int& width, int& height)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

}

CConsole::CConsole(int width, int height)
{
	/**/
	reSizeConsole(width, height);
	int row = 0;
	int col = 0;
	getSize(col, row);
	this->_width = col;
	this->_height = row;
}

void CConsole::reSizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

CConsole::~CConsole(){}

//// ham nay de nhap chu tu ban phim neu su dung ctrl v 
//string CConsole::getClipboardText() {
//	string text;
//
//	if (OpenClipboard(NULL))
//	{
//		HANDLE clip;
//		clip = GetClipboardData(CF_TEXT);
//		// lock and copy
//		text = (LPSTR)GlobalLock(clip);
//		// unlock 
//		GlobalUnlock(clip);
//		CloseClipboard();
//	}
//
//	return text;
//}

// // ham nay de ghi chu len man hinh
//void ConsoleHandle::printString(string s, int row, int begin, int end, size_t cursorPos, size_t cursorPosConsole) {
//	hideCursor();
//	--end;
//	size_t len;
//
//	gotoXY(begin, row);
//	for (len = begin; len <= end; ++len)
//		cout << " ";
//
//	gotoXY(begin, row);
//	len = s.length();
//	if (len <= end - begin + 1)
//		cout << s;
//	else {
//		for (size_t i = cursorPos - (cursorPosConsole - begin); i <= cursorPos - cursorPosConsole + end; ++i)
//			cout << s[i];
//	}
//	showCursor();
//}
//// ham nay chac de to mau chu
//void goLeft(size_t& cursor1, size_t& cursor2, int begin) {
//	--cursor1;
//	if (cursor1 < cursor2 - begin)
//		--cursor2;
//}
//
//void goRight(size_t& cursor1, size_t& cursor2, int end, string s, int step) {
//	cursor1 += step;
//	cursor2 += step;
//	if (cursor2 > end)
//		cursor2 = end - (s.length() - cursor1);
//}
//
//string CConsole::textEdit(int row, int begin, int end) {
//	showCursor();
//	gotoXY(begin, row);
//	string res;
//	size_t cursorPos = 0, cursorPosConsole = begin;
//	char c;
//	do {
//		c = _getch();
//		if (c == Ctrl_V) {
//			string paste = getClipboardText();
//			res.insert(cursorPos, paste);
//			goRight(cursorPos, cursorPosConsole, end, res, paste.length());
//		}
//		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ':' || c == '/' || c == '.' || c == ' ') {
//			res.insert(cursorPos, 1, c);
//			goRight(cursorPos, cursorPosConsole, end, res, 1);
//		}
//		else if (c == key_Backspace) {
//			if (cursorPos > 0) {
//				res.erase(cursorPos - 1, 1);
//				goLeft(cursorPos, cursorPosConsole, begin);
//			}
//		}
//		else if (c == -32) {
//			switch (_getch()) {
//			case key_RightArrow:
//				if (cursorPos < res.length()) {
//					goRight(cursorPos, cursorPosConsole, end, res, 1);
//				}
//				break;
//			case key_LeftArrow:
//				if (cursorPos > 0) {
//					goLeft(cursorPos, cursorPosConsole, begin);
//				}
//			}
//		}
//
//		printString(res, row, begin, end, cursorPos, cursorPosConsole);
//		gotoXY(cursorPosConsole, row);
//	} while (c != key_Enter);
//
//	hideCursor();
//	return res;
//}
// lay chieu rong cua man hinh == collums

int CConsole::width()
{
	return this->_width;
}

// lay chieu dai cua man hinh == rows
int CConsole::height()
{
	return this->_height;
}

// ham di chuyen den toa do 
void CConsole::GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ham cho bt toa do x cua con tro man hinh
int CConsole::currentCursorX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

// ham cho bt toa do y cua con tro man hinh
int CConsole::currentCursorY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

// ham co dinh man hinh
void CConsole::fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
}

// ham to mau chu
void CConsole::TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ham nay set cai backgound voi color
void CConsole::SetBackGroundTextColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

// ham nay de an hien con tro 1: de bat 0: de tat
void CConsole::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 1;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

// ham nay de vo hieu hoa boi den
void CConsole::DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

// ham nay de xoa man hinh
void CConsole::clrscr()
{
	// phien ban mot
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);

	///*phien ban 2*/
	//CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	//HANDLE	hConsoleOut;
	//COORD	Home = { 0,0 };
	//DWORD	dummy;

	//hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	//FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	//csbiInfo.dwCursorPosition.X = 0;
	//csbiInfo.dwCursorPosition.Y = 0;
	//SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

// ham nay de nhan biet nut tren ban phim
int CConsole::inputKey()
{
	//if (_kbhit())
	//{
	//	int key = _getch();

	//	if (key == 224)	// special key
	//	{
	//		key = _getch();
	//		return key + 1000;
	//	}

	//	return key;
	//}
	//else
	//{
	//	return key_none;
	//}

	//return key_none;
	return -1;
}
