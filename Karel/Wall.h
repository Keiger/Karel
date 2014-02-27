#pragma once;
using namespace std;

class Wall
{
private:
	int loc_x, loc_y;

public:
	Wall(int loc_x, int loc_y);
	Wall();
	~Wall();

	int getLoc_x();
	int getLoc_y();

};