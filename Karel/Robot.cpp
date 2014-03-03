#include <iostream>
#include "Robot.h"

Robot::Robot()
{
	loc_x = 0;
	loc_y = 0;
	beepers = 0;
	direction = 1;  // NORTH = 1, 
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

void Robot::move_forward()
{
		switch(direction)
		{
		case 0:
			//if(loc_y > 0)
			loc_y--;
			break;
		case 1:
			loc_x++;
			break;
		case 2:
			loc_y++;
			break;
		case 3:
			loc_x--;
			break;
		}
}
void Robot::move_back()
{
	int temp = getDirection();
	turn();
	turn();
	move_forward();
	direction = temp;
}

void Robot::turn_right()
{
	turn();
}
void Robot::turn_left()
{
	turn();
	turn();
	turn();
}


void Robot::move_left()
{
	loc_x--;
}
void Robot::move_right()
{
	loc_x++;
}

void Robot::turn()
{
	if(direction == 3)
		direction = 0;
	else
		direction++;

}

