#pragma once
#include <cstdint>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <ostream>
#include <time.h>
#include <string>


using std::vector;
using std::set;
using std::shuffle;
using std::ostream;

typedef uint8_t byte;

enum class Tile {GROUND_ROOM, GROUND_CORRIDOR,
     WALL, WATER, CLIFF, ROUGH, ICE, SPIKES};

int between(int min, int max);

class Maze
{
public:
    Maze(int size);
    void print(ostream *);

    vector<vector<bool>> connections;
private:
    vector<int> contiles();
    void generate();
    int nextto(int next,int dir);

    const int size;

    vector<bool> connectedto;
    vector<int> border;
};

struct Room
{
    int top = 0;
    int left = 0;
    int right = 0;
    int bottom = 0;
    int top_corr_x = 0;
    int left_corr_y = 0;
    int right_corr_y = 0;
    int bottom_corr_x = 0;
    bool connect_right = false;
    bool connect_bottom = false;
    Tile filling_tile = Tile::GROUND_ROOM;
};



class Level
{
public:
    Level(int bricks,int bricksize);
    void generate();
    Tile getpos(int x,int y) const;
    void setpos(Tile vaclue, int x,int y);
    void setarea(Tile value, int x1,int y1, int x2, int y2, bool no_overwrite=false);
    bool gethidden(int x, int y) const;
    void sethidden(bool value,int x, int y);
    void print(ostream*);

private:
    void addroom(int brick_x, int brick_y);
    void create_rooms();
    void create_corr_vert();
    void create_corr_horiz();

    void corr_h(Room l,Room r,bool addcliff=false);
    void corr_v(Room t,Room b,bool addcliff=false);

    const int brick;
    const int bricksize;
    const int size;
    vector<byte> data;
    vector<Room> rooms;
    Maze maze;
    vector<std::string> signs;
};
