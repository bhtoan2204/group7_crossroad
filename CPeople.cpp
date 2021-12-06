#include "CPEOPLE.h"

CPEOPLE::CPEOPLE() :x(1), y(1), state(true) {}
int CPEOPLE::getX() { return x; }
int CPEOPLE::getY() { return y; }
void CPEOPLE::setX(int x) { this->x = x; }
void CPEOPLE::setY(int y) { this->y = y; }
void CPEOPLE::setState(bool isDead) { state = isDead; }

bool CPEOPLE::checkValidPos(int x, int y) {
	if (x < 0) return false;
	if (x > MAX_X)return false;
	if (y < 0) return false;
	if (y > MAX_Y) return false;
}
void CPEOPLE::drawPeople() {
	for (int i = 0; i < MAX_People_X; i++) {
		for (int j = 0; j < MAX_People_Y; j++) {
			////BattleField[mX + i][mY + j - 1] = BattleField[mX + i][mY + j - 2];
			BattleField[x + i][y + j - 1] = People[i][j];
		}
	}
}
void CPEOPLE::Up() {
	if (checkValidPos(x - step, y)) {
		x -= step;
		drawPeople();
		for (int i = 0; i < MAX_People_X; i++) {
			for (int j = 0; j < MAX_People_Y; j++) {
				BattleField[x + i + step][y + j - 1] = ' ';
			}
		}
	}
}

void CPEOPLE::Down() {
	if (checkValidPos(x + step, y)) {
		y += step;
		drawPeople();
		for (int i = 0; i < MAX_People_X; i++) {
			for (int j = 0; j < MAX_People_Y; j++) {
				BattleField[x + i - step][y + j - 1] = ' ';
			}
		}
	}
}

void CPEOPLE::Right() {
	if (checkValidPos(x, y + 1)) {
		++y;
		drawPeople();
		for (int i = 0; i < MAX_People_X; i++) {
			BattleField[x + i][y - 2] = ' ';
		}
	}
}
void CPEOPLE::Left() {
	if (checkValidPos(x, y - 1)) {
		--y;
		drawPeople();
		for (int i = 0; i < MAX_People_X; i++) {
			BattleField[x + i][y + 2] = ' ';
		}
	}
}

//bool CPEOPLE::isImpactAnimal(vector<CANIMAL*>& cAni)
//{
//	for (CANIMAL* ca : cAni) {
//		if ((x == ca->getX()) && (y >= (ca->getY() - 1) && y <= (ca->getY() + 8)))
//			return true;
//	}
//	return false;
//}
//
//bool CPEOPLE::isImpactVehicle(vector<CVEHICLE*>& cVehi)
//{
//	for (CVEHICLE* cv : cVehi) {
//		if ((x == cv->getX()) && (y >= (cv->getY() - 1) && y <= (cv->getY() + 8)))
//			return true;
//	}
//	return false;
//}

bool CPEOPLE::isFinish() { return (x == 1) ? true : false; }
bool CPEOPLE::isDead() { return !state; }