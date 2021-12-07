#include "CDINOSAUR.h"

void CDINOSAUR::Move() {
	setY(getY() + 1);
	if (getY() != MAX_Y - MAX_D_Y -1) {
		for (int i = 0; i < MAX_D_X; i++) {
			for (int j = 0; j < MAX_D_Y; j++) {
				BattleField[i + getX()][j + getY()] = Dino[i][j];
			}
		}
		for (int i = 0; i < MAX_D_X; i++)
			BattleField[getX() + i][getY() -1] = ' ';
	}
	else {
		setY(1);
		for (int i = 0; i < MAX_D_X; i++) {
			for (int j = 0; j < MAX_D_Y; j++) {
				BattleField[i + getX()][j + getY()] = Dino[i][j];
			}
		}
		for (int i = 0; i < MAX_D_X; i++) {
			for (int j = 0; j < MAX_D_Y; j++) {
				BattleField[getX() + i][MAX_Y - MAX_D_Y - 2+j] = ' ';
			}
		}
	}
}

void CDINOSAUR::Tell() {
	PlaySound(TEXT("_Sound\\ES_Dinoaur_Snar.wav"), NULL, SND_SYNC);
}