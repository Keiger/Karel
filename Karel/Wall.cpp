#include <iostream>
#include "Wall.h"

Wall::Wall()
{
	loc_x = 0;
	loc_y = 0;
}

Wall::~Wall(){}

Wall::Wall(int x, int y)
{
	loc_x = x;
	loc_y = y;
}

int Wall::getLoc_x()
{
	return loc_x;
}

int Wall::getLoc_y()
{
	return loc_y;
}