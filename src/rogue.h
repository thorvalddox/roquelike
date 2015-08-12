#pragma once

#define TILE_SIZE 16

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

struct Rectangle
{
	int x, y;
	int w, h;
	Rectangle (int x, int y, int w, int h): x(x), y(y), w(w), h(h) {}
	Rectangle() = default;
};

struct GUI_event
{
	enum {TIMER, KEYPRESS, KEYCHAR, KEYRELEASE, EXIT} type;
	unsigned long long value;
};
