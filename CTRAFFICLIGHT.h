#pragma once
class CTRAFFICLIGHT {
private:
	bool light;
public:
	CTRAFFICLIGHT();
	~CTRAFFICLIGHT() = default;
	bool getLight();
	void turnLight();
};

