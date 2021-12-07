#pragma once
#include"CConsole.h"
#include"Point.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
#ifndef Map_h
#define Map_h
#include"CConsole.h"
#include"Point.h"
#include"CVEHICLE.h"
#include"CCar.h"
#include"CTruck.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
void drawCrossRoad(int x, int y, CConsole* handle);
void drawWarrior(int x, int y, int color, CConsole* handle);
void eraseDraw(int x, int y, int height, int width, CConsole* handle);
void drawShape(char** frame, int height, int width, int x, int y, CConsole* handle);
void drawProgressBar(int xC, int yC, CConsole* handle);
void drawTitle(int x, int y, CConsole* handle);
void drawSupperCar(int x, int y, CConsole* handle);
string* drawLose();
string* drawSkull();
string* drawWin();
string* drawEndGame();
string* drawGuidelines();

#endif // !Map_h


