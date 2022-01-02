#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <thread>

#include "Global.h"
#include "CConsole.h"

using namespace std;

void SoundBG()
{
	PlaySound(TEXT("_Sound\\ES_Riding_On.wav"), NULL, SND_ASYNC);
}

void SoundThread()
{
	while (IS_RUNNING) {
		cg.SoundEffect();
		Sleep(80);
	}
	if (cg.getPEOPLE().isFinish())
		PlaySound(TEXT("_Sound\\Finish.wav"), NULL, SND_ASYNC);
	else if(cg.getPEOPLE().isDead())
		PlaySound(TEXT("_Sound\\Lose.wav"), NULL, SND_ASYNC);
}

void TrafficThread()
{
	while (IS_RUNNING) {
		Sleep(1);
		time_car+=5;
		if (time_car == 1000) {
			cg.updateLight(cg.getVEHICLE(1));
			time_car = 0;
		}
		time_truck+=10;
		if (time_truck == 650) {
			cg.updateLight(cg.getVEHICLE(2));
			time_truck = 0;
		}
	}
}

void SubThread()
{
	thread t2(SoundThread);
	thread t3(TrafficThread);
	cg.removeNoti();
	bool flag_delay = true;
	while (IS_RUNNING)
	{
		if (!cg.getPEOPLE().isDead()) {
			cg.updatePosPeople(MOVING);
		}

		MOVING = ' ';
		cg.drawLight();
		cg.updatePosVehicle();

		if (flag_delay) {
			flag_delay = false;
			cg.updatePosAnimal();
		}
		else flag_delay = true;

		cg.getPEOPLE().drawPeople();

		cg.drawGame();
		GotoXY(0, 24);
		ShowCur(false);

		if (cg.getPEOPLE().isImpactAnimal(cg.getANIMAL()) || cg.getPEOPLE().isImpactVehicle(cg.getVEHICLE())) {
			cg.drawExplosion();
			cg.getPEOPLE().setState(false);
			IS_RUNNING = false;
			MOVING = ' ';
			cg.notiGame();
			Sleep(2000);
			cg.notiSpecificGame(3);
		}


		if (cg.getPEOPLE().isFinish()) {
			cg.getPEOPLE().setState(false);
			IS_RUNNING = false;
			MOVING = ' ';
			cg.notiGame();
			t2.join();
			t3.join();
			Sleep(2000);
			if (level < MAX_LEVEL) level++;
			cg.initGame();
			cg.startGame();
			t2 = thread{ SoundThread };
			t3 = thread{ TrafficThread };
		}
		Sleep(80);
	}
	cg.exitGame(t2);
	cg.exitGame(t3);
}

int main() {
	int temp;
	ShowCur(false);
	reSizeConsole(900, 420);
	FixConsoleWindow();
	cg.loadAssets();

	xCur = 20;
	xNoti = 46;
	yNoti = 19;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	//Menu
	thread t(SoundBG);
	while (1) {
		cg.drawMenu();
		temp = toupper(_getch());
		if (temp == '1' || temp == '\r') {
			system("cls");
			reSizeConsole(1150, 500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cg.initGame();
			cg.startGame();
			break;
		}
		else if (temp == '2') {
			MOVING = 'T';
			cg.notiGame();
			break;
		}
		else if (temp == 27) {
			t.detach();
			return 0;
		}
	}
	t.detach();
	PlaySound(NULL, NULL, SND_ASYNC);

	xCur = 24;
	xNoti = 116;
	yNoti = 13;

	//Game
	
	thread t1;
	t1 = thread{ SubThread };
	while (1) {
		temp = toupper(_getch());
		if (!cg.getPEOPLE().isDead())
		{
			if (temp == 27) {
				cg.exitGame(t1);
				return 0;
			}
			else if (temp == 'P' || temp == 'L' || temp == 'T') {
				MOVING = temp;
				cg.pauseGame(t1);
				if (temp != 'T') {
					while (1) {
						int ex_temp = toupper(_getch());
						if (ex_temp == 'Y') {
							cg.resumeGame();
							t1 = thread{ SubThread };
							break;
						}
						else if (ex_temp == 'N') {
							IS_RUNNING = false;
							return 0;
						}
					}
				}
				else {
					IS_RUNNING = true;
					t1 = thread{ SubThread };
				}
			}
			else{
				if (!IS_RUNNING) {
					IS_RUNNING = true;
					cg.exitGame(t1);
					t1 = thread{ SubThread };
				}
				MOVING = temp;
			}
		}
		else {
			if (temp == 'Y') {
				cg.exitGame(t1);
				cg.initGame();
				cg.startGame();
				t1 = thread{ SubThread };
			}
			else if(temp=='N'){
				cg.exitGame(t1);
				return 0;
			}
		}
	}
}