#pragma once

enum direction
{
	NORTH = 0, EAST, SOUTH, WEST
};

struct Point 
{
	int x, y;
	Point(int x, int y):x(x), y(y) {}
	Point() = default;
};

struct TilePos
{
	unsigned x, y;
	TilePos(unsigned x, unsigned y): x(x), y(y) {}
	TilePos() = default;
};

struct GUI_event
{
	enum {TIMER, KEYPRESS, KEYCHAR, KEYRELEASE, EXIT} type;
	unsigned long long value;
};