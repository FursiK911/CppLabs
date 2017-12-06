#pragma once
class Direction :
{
private:
	char* direction;
public:
	Direction();
	~Direction();
	char* getDirection();
	void setDirection(char* dir);
};

