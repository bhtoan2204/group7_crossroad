#include "CGAME.h"

CGAME::CGAME()
{
	level = 1;
	axt = NULL;
	axh = NULL;
	akl = NULL;
	ac = NULL;
	/*int n = 4;
	axt = new CTRUCK[n];
	axh = new CCAR[n];
	n = 3;
	akl = new CDINOSAUR[n];
	ac = new CBIRD[n];*/
}

void CGAME::drawMenu()
{
	memset((char*)Title, 0, 16 * 83);
	memset((char*)Menu, 0, 3 * 24);

	//Load Title
	FILE* f = fopen("_Assets\\Title.txt", "r");
	for (int i = 0; i < 16; i++) {
		char s[84];
		fgets(s, 84, f);
		for (int j = 0; j < 83; j++) {
			Title[i][j] = s[j];
		}
	}
	fclose(f);

	//Load Menu
	f = fopen("_Assets\\Menu.txt", "r");
	for (int i = 0; i < 3; i++) {
		char s[25];
		fgets(s, 25, f);
		for (int j = 0; j < 24; j++) {
			Menu[i][j] = s[j];
		}
	}
	fclose(f);

	//Draw Title
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	for (int i = 0; i < 16; i++) {
		GotoXY(19, 2 + i);
		cout.write(&Title[i][0], 82);
	}

	//Draw Menu
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	for (int i = 0; i < 3; i++) {
		GotoXY(46, 19 + i);
		cout.write(&Menu[i][0], 23);
	}

	GotoXY(0, xCur);
}

void drawNoti(int x)
{
	string s;
	if (x == 5 || x == 4) {
		/*s = "|                     |";
		for (int i = 0; i < 23; i++) NotiTable[0][i] = s[i];
		if (x == 5) s = "|    *  You Lose  *   |";
		else s = "|    ~  You Won  ~    |";
		for (int i = 0; i < 23; i++) NotiTable[1][i] = s[i];
		for (int i = 0; i < 23; i++) NotiTable[2][i] = NotiTable[0][i];*/
		if (x == 4) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			GotoXY(25,9);
			cout.write(" __ __            _ _ _ _     ", 30);
			GotoXY(25, 10);
			cout.write("|  |  |___ _ _   | | | |_|___ ", 30);
			GotoXY(25, 11);
			cout.write("|_   _| . | | |  | | | | |   |", 30);
			GotoXY(25, 12);
			cout.write("  |_| |___|___|  |_____|_|_|_|", 30);
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			GotoXY(25, 9);
			cout.write(" __ __            _                ", 35);
			GotoXY(25, 10);
			cout.write("|  |  |___ _ _   | |   ___ ___ ___ ", 35);
			GotoXY(25, 11);
			cout.write("|_   _| . | | |  | |__| . |  _| ._|", 35);
			GotoXY(25, 12);
			cout.write("  |_| |___|___|  |____|___|_`_|___|", 35);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (x == 3) {
		s = "|      Continue?      |";
		for (int i = 0; i < 23; i++) NotiTable[0][i] = s[i];
		s = "|   Yes        No     |";
		for (int i = 0; i < 23; i++) NotiTable[1][i] = s[i];
		s = "|   [Y]        [N]    |";
		for (int i = 0; i < 23; i++) NotiTable[2][i] = s[i];
	}
	else {
		if (x == 2) s = "| Enter name to load: |";
		else s = "| Enter name to save: |";
		for (int i = 0; i < 23; i++) NotiTable[0][i] = s[i];
		s = "|>                    |";
		for (int i = 0; i < 23; i++) NotiTable[1][i] = s[i];
		s = "|                     |";
		for (int i = 0; i < 23; i++) NotiTable[2][i] = s[i];
	}
	GotoXY(xNoti, yNoti);
	for (int i = 0; i < 3; i++) {
		GotoXY(xNoti, yNoti + i);
		cout.write(&NotiTable[i][0], 23);
	}
	GotoXY(0, xCur);
}

void CGAME::drawGame()
{
	for (int i = 0; i < MAX_X; i++) {
		int runStart = -1;
		for (int j = 0; j < MAX_Y; j++) {
			if (BattleField[i][j] == prevBattleField[i][j]) {
				if (runStart != -1) {
					GotoXY(runStart, i);
					cout.write(&BattleField[i][runStart], j - runStart);
					runStart = -1;
				}
			}
			else if (runStart == -1) {
				runStart = j;
			}
		}
		if (runStart != -1) {
			GotoXY(runStart, i);
			cout.write(&BattleField[i][runStart], MAX_X - runStart);
		}
	}
	cout.flush();
	memcpy((char*)prevBattleField, (char*)BattleField, MAX_X * MAX_Y);
}

void CGAME::drawExplosion()
{
	int posX = cn.getX() + 1, posY = cn.getY() + 1;
	GotoXY(posY, posX);
	cout << Explosion[1][2];
	Sleep(100);

	GotoXY(posY, posX-1);
	cout << Explosion[0][2];
	GotoXY(posY, posX+1);
	cout << Explosion[2][2];
	GotoXY(posY-1, posX);
	cout << Explosion[1][1];
	GotoXY(posY+1, posX);
	cout << Explosion[1][3];
	Sleep(100);

	GotoXY(posY-1, posX-1);
	cout << Explosion[0][1];
	GotoXY(posY+1, posX-1);
	cout << Explosion[0][3];
	GotoXY(posY-1, posX+1);
	cout << Explosion[2][1];
	GotoXY(posY+1, posX+1);
	cout << Explosion[2][3];
	Sleep(100);

	GotoXY(posY - 2, posX - 1);
	cout << Explosion[0][0];
	GotoXY(posY + 2, posX - 1);
	cout << Explosion[0][4];
	GotoXY(posY - 2, posX);
	cout << Explosion[1][0];
	GotoXY(posY + 2, posX);
	cout << Explosion[1][4];
	GotoXY(posY - 2, posX + 1);
	cout << Explosion[2][0];
	GotoXY(posY + 2, posX + 1);
	cout << Explosion[2][4];
	Sleep(100);

	GotoXY(0, xCur);
}

void CGAME::drawLight()
{
	int color = 4;
	GotoXY(80, axt[0].getPosition().getX());
	if (axt[0].getTrafficLight()) {
		color = 2;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << char(254);

	color = 4;
	GotoXY(80, axh[0].getPosition().getX());
	if (axh[0].getTrafficLight()) {
		color = 2;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

CGAME::~CGAME()
{
	delete[]axt;
	delete[]axh;
	delete[]ac;
	delete[]akl;
}

CPEOPLE& CGAME::getPEOPLE()
{
	return cn;
}

vector<CANIMAL*>& CGAME::getANIMAL()
{
	cAni.clear();
	for (int i = 0; i < level; i++) {
		CANIMAL* ca;
		ca = &ac[i];
		cAni.push_back(ca);
	}
	for (int i = 0; i < level; i++) {
		CANIMAL* ca;
		ca = &akl[i];
		cAni.push_back(ca);
	}
	return cAni;
}

vector<CVEHICLE*>& CGAME::getVEHICLE(int x)
{
	cVehi.clear();
	if (x == 0 || x == 1) {
		for (int i = 0; i < level + 1; i++) {
			CVEHICLE* cv;
			cv = &axh[i];
			cVehi.push_back(cv);
		}
	}
	if (x == 0 || x == 2) {
		for (int i = 0; i < level + 1; i++) {
			CVEHICLE* cv;
			cv = &axt[i];
			cVehi.push_back(cv);
		}
	}
	return cVehi;
}

void CGAME::loadAssets()
{
	//Load Battle Field
	FILE* f = fopen("_Assets\\BattleField.txt", "r");
	memset((char*)prevBattleField, 0, MAX_X * MAX_Y);
	memset((char*)BattleField, ' ', MAX_X * MAX_Y);
	for (int i = 0; i < MAX_X; i++) {
		char s[MAX_Y];
		fgets(s, MAX_Y, f);
		for (int j = 0; j < MAX_Y; j++) {
			BattleField[i][j] = s[j];
		}
		fgets(s, MAX_Y, f);
	}
	fclose(f);

	//Load Info
	f = fopen("_Assets\\Info.txt", "r");
	memset((char*)InfoTable, 0, 13 * 58);
	for (int i = 0; i < 13; i++) {
		char s[60];
		fgets(s, 60, f);
		for (int j = 0; j < 58; j++) {
			InfoTable[i][j] = s[j];
		}
		//fgets(s, 16, f);
	}
	fclose(f);

	//Load Noti
	f = fopen("_Assets\\Noti.txt", "r");
	memset((char*)NotiTable, 0, 3 * 24);
	for (int i = 0; i < 3; i++) {
		char s[25];
		fgets(s, 25, f);
		for (int j = 0; j < 24; j++) {
			NotiTable[i][j] = s[j];
		}
		//fgets(s, 16, f);
	}
	fclose(f);

	//Load Explosion effect
	f = fopen("_Assets\\Explosion.txt", "r");
	memset((char*)Explosion, 0, 3 * 5);
	for (int i = 0; i < 3; i++) {
		char s[7];
		fgets(s, 7, f);
		for (int j = 0; j < 5; j++) {
			Explosion[i][j] = s[j];
		}
		//fgets(s, 16, f);
	}
	fclose(f);

	//Load Truck
	f = fopen("_Assets\\Truck.txt", "r");
	memset((char*)Truck, 0, MAX_T_X * MAX_T_Y);
	for (int i = 0; i < MAX_T_X; i++) {
		char s[MAX_T_Y + 1];
		fgets(s, MAX_T_Y + 1, f);
		for (int j = 0; j < MAX_T_Y; j++) {
			Truck[i][j] = s[j];
		}
		fgets(s, MAX_T_Y, f);
	}
	fclose(f);

	//Load Car
	f = fopen("_Assets\\Car.txt", "r");
	memset((char*)Car, 0, MAX_C_X * MAX_C_Y);
	for (int i = 0; i < MAX_C_X; i++) {
		char s[MAX_C_Y + 1];;
		fgets(s, MAX_C_Y + 1, f);
		for (int j = 0; j < MAX_C_Y; j++) {
			Car[i][j] = s[j];
		}
		fgets(s, MAX_C_Y, f);
	}
	fclose(f);

	//Load Dinosaur
	f = fopen("_Assets\\Dinosaur.txt", "r");
	memset((char*)Dino, 0, MAX_D_X * MAX_D_Y);
	for (int i = 0; i < MAX_D_X; i++) {
		char s[MAX_D_Y + 1];;
		fgets(s, MAX_D_Y + 1, f);
		for (int j = 0; j < MAX_D_Y; j++) {
			Dino[i][j] = s[j];
		}
		fgets(s, MAX_D_Y, f);
	}
	fclose(f);

	//Load Bird
	f = fopen("_Assets\\Bird.txt", "r");
	memset((char*)Bird, 0, MAX_B_X * MAX_B_Y);
	for (int i = 0; i < MAX_B_X; i++) {
		char s[MAX_B_Y + 1];
		fgets(s, MAX_B_Y + 1, f);
		for (int j = 0; j < MAX_B_Y; j++) {
			Bird[i][j] = s[j];
		}
		fgets(s, MAX_B_Y, f);
	}
	fclose(f);

	//Load People
	f = fopen("_Assets\\People.txt", "r");
	memset((char*)People, 0, MAX_P_X * MAX_P_Y);
	for (int i = 0; i < MAX_P_X; i++) {
		char s[MAX_P_Y + 1];
		fgets(s, MAX_P_Y + 1, f);
		for (int j = 0; j < MAX_P_Y; j++) {
			People[i][j] = s[j];
		}
		fgets(s, MAX_P_Y, f);
	}
	fclose(f);
}

void CGAME::initGame()
{
	IS_RUNNING = true;

	//Set people
	cn.setX(21);
	cn.setY(40);
	cn.setState(true);

	//Set traffic
	time_truck = 0;
	time_car = 0;

	//Set vehicle
	//int n = 4;
	delete[] axt;
	axt = new CTRUCK[level + 1];
	delete[] axh;
	axh = new CCAR[level + 1];
	for (int i = 0; i < level + 1; i++) {
		axt[i].setX(17);
		axt[i].setY(MAX_Y - MAX_T_Y - 2 - i * (MAX_T_Y + 5));
		axh[i].setX(9);
		axh[i].setY(1 + i * (MAX_C_Y + 5));
	}

	//Set animal
	//n = 3;
	delete[] ac;
	ac = new CBIRD[level];
	delete[] akl;
	akl = new CDINOSAUR[level];
	for (int i = 0; i < level; i++) {
		ac[i].setX(5);
		ac[i].setY(MAX_Y - MAX_B_Y - 2 - i * (MAX_B_Y + 5));
		akl[i].setX(13);
		akl[i].setY(1 + i * (MAX_D_Y + 5));
	}
}

void CGAME::startGame()
{
	//Load Battle Field
	FILE* f = fopen("_Assets\\BattleField.txt", "r");
	memset((char*)prevBattleField, 0, MAX_X * MAX_Y);
	memset((char*)BattleField, ' ', MAX_X * MAX_Y);
	for (int i = 0; i < MAX_X; i++) {
		char s[MAX_Y];
		fgets(s, MAX_Y, f);
		for (int j = 0; j < MAX_Y; j++) {
			BattleField[i][j] = s[j];
		}
		fgets(s, MAX_Y, f);
	}
	fclose(f);

	//Draw Truck
	for (int k = 0; k < level + 1; k++) {
		for (int i = 0; i < MAX_T_X; i++) {
			for (int j = 0; j < MAX_T_Y; j++) {
				BattleField[axt[k].getPosition().getX() + i][axt[k].getPosition().getY() + j] = Truck[i][j];
			}
		}
	}

	//Draw Car
	for (int k = 0; k < level + 1; k++) {
		for (int i = 0; i < MAX_C_X; i++) {
			for (int j = 0; j < MAX_C_Y; j++) {
				BattleField[axh[k].getPosition().getX() + i][axh[k].getPosition().getY() + j] = Car[i][j];
			}
		}
	}

	//Draw Dino
	for (int k = 0; k < level; k++) {
		for (int i = 0; i < MAX_D_X; i++) {
			for (int j = 0; j < MAX_D_Y; j++) {
				BattleField[akl[k].getX() + i][akl[k].getY() + j] = Dino[i][j];
			}
		}
	}

	//Draw Bird
	for (int k = 0; k < level; k++) {
		for (int i = 0; i < MAX_B_X; i++) {
			for (int j = 0; j < MAX_B_Y; j++) {
				BattleField[ac[k].getX() + i][ac[k].getY() + j] = Bird[i][j];
			}
		}
	}

	//Draw People
	for (int i = 0; i < MAX_P_X; i++) {
		for (int j = 0; j < MAX_P_Y; j++) {
			BattleField[cn.getX() + i][cn.getY() + j - 1] = People[i][j];
		}
	}

	//Draw Info
	InfoTable[1][31] = (char)(level + 48);
	for (int i = 0; i < 13; i++) {
		GotoXY(87, 3 + i);
		cout.write(&InfoTable[i][0], 58);
	}

	//Remove Noti
	removeNoti();
}

void CGAME::exitGame(thread& t)
{
	IS_RUNNING = false;
	t.join();
}

void CGAME::pauseGame(thread& t)
{
	IS_RUNNING = false;
	t.join();
	notiGame();
}

void CGAME::resumeGame()
{
	IS_RUNNING = true;
}

void CGAME::saveGame(string fName)
{
	if (fName == "") return;
	fName = "_FileSave\\" + fName;
	ofstream ofs;
	ofs.open(fName, ofstream::out | ofstream::trunc);
	ofs.close();

	char const *s = fName.c_str();
	FILE* f = fopen(s, "w");
	fprintf(f, "%d\n", level);
	fprintf(f, "%d\n", time_truck);
	fprintf(f, "%d\n", time_car);
	fprintf(f, "%d\n", getPEOPLE().getX());
	fprintf(f, "%d\n", getPEOPLE().getY());
	vector<CANIMAL*> cAni = getANIMAL();
	vector<CVEHICLE*> cVehi = getVEHICLE();
	for (CANIMAL* ca : cAni) {
		fprintf(f, "%d\n", ca->getX());
		fprintf(f, "%d\n", ca->getY());
	}
	for (CVEHICLE* cv : cVehi) {
		fprintf(f, "%d\n", cv->getPosition().getX());
		fprintf(f, "%d\n", cv->getPosition().getY());
		fprintf(f, "%d\n", cv->getTrafficLight());
	}
	fclose(f);
}

bool CGAME::loadGame(string fName)
{
	if (fName == "") {
		if (getPEOPLE().getX() == 0)
			fName = "DEFAULT";
		else return true;
	}
	fName = "_FileSave\\" + fName;
	char const* s = fName.c_str();
	FILE* f = fopen(s, "r");
	if (!f) return false;
	fscanf(f, "%d%d%d", &level, &time_truck, &time_car);
	int x, y, t;
	fscanf(f, "%d%d", &x, &y);
	getPEOPLE().setX(x);
	getPEOPLE().setY(y);

	delete[] ac;
	ac = new CBIRD[level];
	delete[] akl;
	akl = new CDINOSAUR[level];
	delete[] axt;
	axt = new CTRUCK[level + 1];
	delete[] axh;
	axh = new CCAR[level + 1];

	for (int i = 0; i < level; i++) {
		fscanf(f, "%d%d", &x, &y);
		ac[i].setX(x);
		ac[i].setY(y);
	}
	for (int i = 0; i < level; i++) {
		fscanf(f, "%d%d", &x, &y);
		akl[i].setX(x);
		akl[i].setY(y);
	}
	for (int i = 0; i < level + 1; i++) {
		fscanf(f, "%d%d%d", &x, &y, &t);
		axh[i].setX(x);
		axh[i].setY(y);
		if (axh[i].getTrafficLight() != t)
			axh[i].changeTrafficLight();
	}
	for (int i = 0; i < level + 1; i++) {
		fscanf(f, "%d%d%d", &x, &y, &t);
		axt[i].setX(x);
		axt[i].setY(y);
		if (axt[i].getTrafficLight() != t)
			axt[i].changeTrafficLight();
	}
	fclose(f);
	system("cls");
	reSizeConsole(1150, 500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	startGame();
	return true;
}

void CGAME::notiGame()
{
	if (getPEOPLE().isFinish()) {
		drawNoti(4);
	}
	else if (getPEOPLE().isDead()) {
		drawNoti(5);
	}
	if (MOVING == 27 || MOVING == 'P') {
		drawNoti(3);
	}
	else if (MOVING == 'L' || MOVING == 'T') {
		filename = "";
		int f = 0, temp, pointer = xNoti + 2;
		if (MOVING == 'L') f = 1;
		else f = 2;
		drawNoti(f);
		GotoXY(pointer, yNoti + 1);
		while (1) {
			temp = toupper(_getch());
			if (temp == '\r') {
				if (MOVING == 'L') {
					saveGame(filename);
					drawNoti(3);
					break;
				}
				else {
					if (loadGame(filename))
						break;
				}
			}
			if (temp == '\b' && pointer > xNoti + 2) {
				GotoXY(--pointer, yNoti + 1);
				cout.write(" ", 1);
				filename.erase(filename.end() - 1);
				GotoXY(pointer, yNoti + 1);
			}
			else if (temp != '\b' && temp != '\r' && temp != 27 && pointer < xNoti + 2 + 20) {
				GotoXY(pointer++, yNoti + 1);	
				printf("%c", temp);
				filename += temp;
			}
		}
	}
}

void CGAME::notiSpecificGame(int x)
{
	drawNoti(x);
}

void CGAME::removeNoti()
{
	string s;
	s = "                        ";
	for (int i = 0; i < 24; i++) NotiTable[0][i] = s[i];
	s = "                        ";
	for (int i = 0; i < 24; i++) NotiTable[1][i] = s[i];
	s = "                        ";
	for (int i = 0; i < 24; i++) NotiTable[2][i] = s[i];
	GotoXY(xNoti, yNoti);
	for (int i = 0; i < 3; i++) {
		GotoXY(xNoti, yNoti + i);
		cout.write(&NotiTable[i][0], 23);
	}
	GotoXY(0, xCur);
}

void CGAME::updatePosPeople(char c)
{
	if (c == 'W') cn.Up();
	else if (c == 'A') cn.Left();
	else if (c == 'D') cn.Right();
	else if (c == 'S') cn.Down();
}

void CGAME::updatePosVehicle()
{
	for (int i = 0; i < level + 1; i++) {
		if(axt[i].getTrafficLight())
			axt[i].move();
		if(axh[i].getTrafficLight())
			axh[i].move();
	}
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < level; i++) {
		akl[i].Move();
		ac[i].Move();
	}
}

void CGAME::updateLight(vector<CVEHICLE*>& CV)
{
	for (CVEHICLE* cv : CV) {
		cv->changeTrafficLight();
	}
}

void CGAME::SoundEffect()
{
	if (cn.getX() == 5) 
		ac[0].Tell();
	else if (cn.getX() == 9)
		axh[0].soundHorn();
	else if (cn.getX() == 13) 
		akl[0].Tell();
	else if (cn.getX() == 17)
		axt[0].soundHorn();
}