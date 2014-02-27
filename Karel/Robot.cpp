#include <iostream>
#include "Robot.h"

Robot::Robot()
{
	loc_x = 0;
	loc_y = 0;
	beepers = 0;
	direction = 1;
}

Robot::~Robot(){}

Robot::Robot(int x, int y, int b, int h)
{
	loc_x = x;
	loc_y = y;
	beepers = b;
	direction = h;
}

int Robot::getLoc_x()
{
	return loc_x;
}

int Robot::getLoc_y()
{
	return loc_y;
}

int Robot::getBeepers()
{
	return beepers;
}

int Robot::getDirection()
{
	return direction;
}

void Robot::move_up()
{
	loc_y = loc_y--;
}
void Robot::move_down()
{
	loc_y = loc_y++;
}
void Robot::move_left()
{
	loc_x = loc_x--;
}
void Robot::move_right()
{
	loc_x = loc_x++;
}