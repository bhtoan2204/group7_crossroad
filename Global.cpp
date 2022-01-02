#include "Global.h"

CGAME cg;
int xCur;
bool IS_RUNNING = true;
int xNoti;
int yNoti;
int level;
int time_truck;
int time_car;
char MOVING = ' ';
char Title[16][83];
char Menu[3][24];
char prevBattleField[MAX_X][MAX_Y], BattleField[MAX_X][MAX_Y];
char InfoTable[13][58];
char NotiTable[3][24];
char Truck[MAX_T_X][MAX_T_Y];
char Car[MAX_C_X][MAX_C_Y];
char Dino[MAX_D_X][MAX_D_Y];
char Bird[MAX_B_X][MAX_B_Y];
char People[MAX_P_X][MAX_P_Y];
char Explosion[3][5];
vector<CANIMAL*> cAni;
vector<CVEHICLE*> cVehi;
string filename;