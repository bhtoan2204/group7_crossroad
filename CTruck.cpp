#include "CTruck.h"
void CTruck::createTruck(int type) // :v doc file co ki tu dac biet ko duoc nha 
{
	this->_truck = new char* [this->_height];
	for (int i = 0; i < 3; i++)
	{
		this->_truck[i] = new char[this->_width];
	}
	if (type == 1)
	{
		char car1[][8] = { {' ',' ',' ',' ',' ',' ',' ',' '},
						   {'[','_',']','_','|','\\','_',' '},
					       {'[','o','o','-','-','o','_','|'} };

		for (int i = 0; i < this->_height; i++)
		{
			for (int j = 0; j < this->_width; j++)
			{
				this->_truck[i][j] = car1[i][j];
			}
		}

	}
	else if (type == 2)
	{
		char car2[][8] = { {' ','_','_','_',' ',' ',' ',' '},
						   {'[','_','_','_',']','\\','_',' '},
						   {'=','0','0','-','-','0','_','|'}};

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->_truck[i][j] = car2[i][j];
			}
		}
	}


}

CTruck::CTruck(const Point& p, int _type, int _height, int _width) :CVEHICLE(p, _height, _width)
{
	this->_type = _type;
	createTruck(_type);
}

CTruck::CTruck(const CTruck& car) :CVEHICLE(car)
{
	this->_type = car._type;
	createTruck(this->_type);
}

CTruck& CTruck::operator=(const CTruck& car)
{
	if (this != &car)
	{
		CVEHICLE::operator=(car);
		this->_type = car._type;
		createTruck(this->_type);
	}
	return *this;
}

char** CTruck::shapeHevicle(/**/)
{
	return this->_truck;
}

//void CTruck::drawHevicle()
//{
//	//for (int i = 0; i < MAX_C_X; i++) {
//	//	for (int j = MAX_C_Y - 1; j >= 0; j--) {
//	//		//BattleField[x + i][y + j] = BattleField[x + i][y + j - 1];
//	//		BattleField[getX() + i][getY() + j] = Car[i][j];
//	//	}
//	//}
//
//	for (int i = 0; i < this->_height; i++)
//	{
//		for (int j = 0; j < this->_width; j++)
//		{
//			cout << this->_truck[i][j];
//		}
//		cout << endl;
//	}
//}

void CTruck::soundHorn()
{
	//PlaySound(TEXT("_Sound\\ES_Truck_Horn.wav"), NULL, SND_SYNC);
}

void CTruck::move()
{
	//	//for (int i = 0; i < MAX_C_X; i++) {
	//	for (int j = MAX_C_Y - 1; j >= 0; j--) {
	//		//BattleField[x + i][y + j] = BattleField[x + i][y + j - 1];
	//		BattleField[getX() + i][getY() + j] = Car[i][j];
	//	}
	//}
}

CTruck::~CTruck()
{
	for (int i = 0; i < this->_height; i++)
	{
		if (this->_truck[i] != nullptr)
		{
			delete[] this->_truck[i];
		}
	}

	delete[] this->_truck;
}