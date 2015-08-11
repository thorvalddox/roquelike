#include "level.h"

#define up 0
#define left 1
#define right 2
#define down 3

Level::Level(int brick,int bricksize):
    brick(brick),
    bricksize(bricksize),
    size(brick*bricksize),
    data(bricksize*brick,0)
{
    //
}

byte Level::getpos(int x, int y) const
{
    return (this->data[x*size + y] & 0x7f);
}

bool Level::gethidden(int x, int y) const
{
    return !!(this->data[x*size + y] & 0x80);
}

void Level::setpos(byte value, int x, int y)
{
    this->data[x*size + y] = value | (this->data[x*size + y]  & 0x80);
}


void Level::sethidden(bool value, int x, int y)
{
    this->data[x*size + y] = (value?0x80:0x0) | (this->data[x*size + y]  & 0x7f);
}



Maze::Maze(int size):
    size(size),
    connections(pow(size,2),{false,false,false,false}),
    connectedto(pow(size,2),0),
    border(4,0)
{
    srand(time(NULL));
    connectedto[rand() % (size*size)] = true;
    border[up] = -size;
    border[left] = -1;
    border[right] = 1;
    border[down] = size;

    generate();
}

int Maze::nextto(int next,int dir)
{
    int probnext = next+border[dir];
    if (probnext < 0 || probnext >= pow(size,2))
    {
        return -1;
    }
    if (probnext/size != next/size && probnext%size != next%size)
    {
        return -1;
    }
    return(probnext);
}

vector<int> Maze::contiles()
{
    vector<int> ret;
    for (int i=0;i<pow(size,2);i++)
    {
        if (connectedto[i])
        {
            for (int j =0;j<4;j++)
            {
                if (nextto(i,j) != -1 && !connectedto[nextto(i,j)])
                {
                    ret.push_back(nextto(i,j));
                }
            }
        }
    }
    return ret;
}

void Maze::generate()
{
    vector<int> dirvec = {up,left,right,down};
    for (int step=0;step < pow(size,2)-1;step++)
    {
        vector<int> newconvec = contiles();
        if (!newconvec.size())
        {
            break;
        }
        int newcon = newconvec[rand() % newconvec.size()];
        std::random_shuffle(dirvec.begin(),dirvec.end());
        for (int dir: dirvec)
        {
            int next = nextto(newcon,dir);
            if (next == -1)
            {
                continue;
            }
            if (connectedto[next])
            {
                connections[newcon][dir] = true;
                connections[next][3-dir] = true;
                connectedto[newcon] = true;
                break;
            }
        }
    }
}

void Maze::print(ostream*out)
{
    for (int y=0;y<size;y++)
    {
        for (int h=0;h<3;h++)
        {
            for (int x=0;x<size;x++)
            {
                switch (h)
                {
                    case 0: *out << " " << (connections[y*size+x][up]?"|":" ")
                            << " ";break;
                    case 1: *out << (connections[y*size+x][left]?"-":" ") << "+" <<
                                (connections[y*size+x][right]?"-":" ");break;
                    case 2: *out << " " << (connections[y*size+x][down]?"|":" ")
                            << " ";break;
                    default: *out << "???";break;
                }
            }
            *out << "\n";
        }
    }
}
