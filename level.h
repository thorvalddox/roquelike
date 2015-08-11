#include <cstdint>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <ostream>
#include <time.h>


using std::vector;
using std::set;
using std::shuffle;
using std::ostream;

typedef uint8_t byte;

class Level
{
public:
    Level(int bricks,int bricksize);
    void generate();
    byte getpos(int x,int y) const;
    void setpos(byte value, int x,int y);
    bool gethidden(int x, int y) const;
    void sethidden(bool value,int x, int y);
private:
    const int brick;
    const int bricksize;
    const int size;
    vector<byte> data;
};

class Maze
{
public:
    Maze(int size);
    void print(ostream *);


private:
    vector<int> contiles();
    void generate();
    int nextto(int next,int dir);

    const int size;
    vector<vector<bool>> connections;
    vector<bool> connectedto;
    vector<int> border;
};
