#pragma once;
using namespace std;

class Robot
{
private:
	int loc_x, loc_y;
	int beepers;
	int direction;

public:
	Robot(int loc_x, int loc_y, int beepers, int direction);
	Robot();
	~Robot();

	int getLoc_x();
	int getLoc_y();
	int getBeepers();
	int getDirection();

	void move_forward();
	void move_back();

	void turn_right();
	void turn_left();

	void move_left();
	void move_right();
	void turn();
};