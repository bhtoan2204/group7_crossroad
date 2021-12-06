#pragma once
class CTRAFFICLIGHT
{
	private:
		bool value;
	public:
		CTRAFFICLIGHT() :value(true) {}
		bool getLight();
		void turnLight();
};