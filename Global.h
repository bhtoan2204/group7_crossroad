#pragma once
#include "CGAME.h"

#define MAX_X 19
#define MAX_Y 71
#define MAX_T_X 2
#define MAX_T_Y 8
#define MAX_C_X 2
#define MAX_C_Y 8
#define MAX_D_X 2
#define MAX_D_Y 8
#define MAX_B_X 2
#define MAX_B_Y 8
#define MAX_P_X 2
#define MAX_P_Y 3
#define MAX_LEVEL 4

extern CGAME cg;
extern bool IS_RUNNING;
extern int xNoti;
extern int yNoti;
extern int level;
extern int time_truck;
extern int time_car;
extern char MOVING;
extern char Title[5][77];
extern char Menu[3][24];
extern char prevBattleField[MAX_X][MAX_Y], BattleField[MAX_X][MAX_Y];
extern char InfoTable[10][19];
extern char NotiTable[3][24];
extern char Truck[MAX_T_X][MAX_T_Y];
extern char Car[MAX_C_X][MAX_C_Y];
extern char Dino[MAX_D_X][MAX_D_Y];
extern char Bird[MAX_B_X][MAX_B_Y];
extern char People[MAX_P_X][MAX_P_Y];
extern char Explosion[3][3];
extern vector<CANIMAL*> cAni;
extern vector<CVEHICLE*> cVehi;
extern string filename;