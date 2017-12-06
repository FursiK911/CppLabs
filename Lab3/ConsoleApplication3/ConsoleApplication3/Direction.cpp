#include "Direction.h"



Direction::Direction()
{
}


Direction::~Direction()
{
}

char * Direction::getDirection()
{
	return direction;
}

void Direction::setDirection(char* dir)
{
	direction = dir;
}
