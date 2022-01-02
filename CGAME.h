#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <mmsystem.h>
#include <vector>
#include <string>
#include <fstream>

#define MAX_X 25
#define MAX_Y 81

#include "CPEOPLE.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CDINOSAUR.h"
#include "CBIRD.h"
#include "CConsole.h"

using namespace std;

extern int xCur;
extern int xNoti;
extern int yNoti;
extern int level;
extern int time_truck;
extern int time_car;
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

class CGAME
{
	private:
		CTRUCK* axt;
		CCAR* axh;
		CDINOSAUR* akl;
		CBIRD* ac;
		CPEOPLE cn;
	public:
		CGAME();
		~CGAME();

		void drawMenu();
		//void drawNoti(int x); //1: Save, 2:Load, 3:Continue, 4:Win, 5:Lose
		void drawGame();
		void drawExplosion();
		void drawLight();

		CPEOPLE& getPEOPLE();
		vector<CANIMAL*>& getANIMAL();
		vector<CVEHICLE*>& getVEHICLE(int x = 0); //0: Car & Truck, 1: Car, 2: Truck

		void loadAssets();
		void initGame();
		void startGame();
		void exitGame(thread& t);
		void pauseGame(thread& t);
		void resumeGame();
		void saveGame(string fName);
		bool loadGame(string fName);
		void notiGame();
		void notiSpecificGame(int x);
		void removeNoti();
		void updatePosPeople(char c);
		void updatePosVehicle();
		void updatePosAnimal();
		void updateLight(vector<CVEHICLE*>& CV);
		void SoundEffect();
};

