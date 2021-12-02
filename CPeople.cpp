#include "CPeople.h"

CPeople::CPeople() :x(1), y(1), state(true) {}
int CPeople::getX() { return x; }
int CPeople::getY() { return y; }
void CPeople::setX(int x) { this->x = x; }
void CPeople::setY(int y) { this->y = y; }
void CPeople::setState(bool isDead) { state = isDead; }

bool CPeople::checkValidPosition(int x, int y) {
	if (x < 0) return false;
	if (x > MAX_Width)return false;
	if (y < 0) return false;
	if (y > MAX_Height) return false;
}
void CPeople::drawPeople() {
	for (int i = 0; i < MAX_People_Width; i++) {
		for (int j = 0; j < MAX_People_Height; j++) {
			////BattleField[mX + i][mY + j - 1] = BattleField[mX + i][mY + j - 2];
			BattleField[x + i][y + j - 1] = People[i][j];
		}
	}
}
void CPeople::Up() {
	if (checkValidPosition(x - step + 1, y)) {
		x -= step;
		drawPeople();
		for (int i = 0; i < MAX_People_Width; i++) {
			for (int j = 0; j < MAX_People_Height; j++) {
				BattleField[x + i + step - 1][y + j - 1] = ' ';
			}
		}
	}
}
void CPeople::Right() {
	if (checkValidPosition(x, y + 1)) {
		++y;
		drawPeople();
		for (int i = 0; i < MAX_People_Width; i++) {
			BattleField[x + i][y - 2] = ' ';
		}
	}
}
void CPeople::Left() {
	if (checkValidPosition(x, y - 1)) {
		--y;
		drawPeople();
		for (int i = 0; i < MAX_People_Width; i++) {
			//BattleField[mX + i][mY + 2] = ' ';
		}
	}
}
void CPeople::Down() {
	if (checkValidPosition(x - step + 1, y)) {
		y += step;
		drawPeople();
		for (int i = 0; i < MAX_People_Width; i++) {
			for (int j = 0; j < MAX_People_Height; j++) {
				//BattleField[x + i - step - 1][y + j - 1] = ' ';
			}
		}
	}
}
//bool CPeople::isImpactAnimal(CANIMAL cAni[]) {
//
//	return false;
//}
//bool CPeople::isImpactVehicle(CVEHICLE CVehi[]) {
//
//	return false;
//}
bool CPeople::isFinish() { return (x == 1) ? true : false; }
bool CPeople::isDead() { return !state; }