#include "CBIRD.h"


void CBIRD::Move() {
	setY(getY()-1);
	if (getY() != 0) {
		for (int i = 0; i < MAX_B_X; i++) {
			for (int j = 0; j < MAX_B_Y; j++) {
				BattleField[i + getX()][j + getY()] = Bird[i][j];
			}
		}
		for (int i = 0; i < MAX_B_X; i++)
			BattleField[getX() + i][getY() + MAX_B_Y] = ' ';
	}
	else {
		setY(MAX_Y - MAX_B_Y - 2);
		for (int i = 0; i < MAX_B_X; i++) {
			for (int j = 0; j < MAX_B_Y; j++) {
				BattleField[i + getX()][j + getY()] = Bird[i][j];
			}
		}
		for (int i = 0; i < MAX_B_X; i++) {
			for (int j = 0; j < MAX_B_Y; j++) {
				BattleField[getX() + i][j + 1] = ' ';
			}
		}
	}
}

void CBIRD::Tell() {
	PlaySound(TEXT("_Sound\\ES_Bird_Screech.wav"), NULL, SND_SYNC);
}