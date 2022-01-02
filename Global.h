#pragma once
#include "CGAME.h"

#define MAX_X 25
#define MAX_Y 81
#define MAX_T_X 3
#define MAX_T_Y 8
#define MAX_C_X 3
#define MAX_C_Y 8
#define MAX_D_X 3
#define MAX_D_Y 8
#define MAX_B_X 3
#define MAX_B_Y 13
#define MAX_P_X 3
#define MAX_P_Y 4
#define MAX_LEVEL 4

extern CGAME cg;
extern int xCur;
extern bool IS_RUNNING;
extern int xNoti;
extern int yNoti;
extern int level;
extern int time_truck;
extern int time_car;
extern char MOVING;
extern char Title[16][83];
extern char Menu[3][24];
extern char prevBattleField[MAX_X][MAX_Y], BattleField[MAX_X][MAX_Y];
extern char InfoTable[13][58];
extern char NotiTable[3][24];
extern char Truck[MAX_T_X][MAX_T_Y];
extern char Car[MAX_C_X][MAX_C_Y];
extern char Dino[MAX_D_X][MAX_D_Y];
extern char Bird[MAX_B_X][MAX_B_Y];
extern char People[MAX_P_X][MAX_P_Y];
extern char Explosion[3][5];
extern vector<CANIMAL*> cAni;
extern vector<CVEHICLE*> cVehi;
extern string filename;