#include "level.h"
#include "iostream"

#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3

bool IsTrue (bool i)
{
    return (i);
}

int between(int min,int max)
{
    if (min == max)
    {
        return min;
    }
    if (min > max)
    {
        return(between(max,min));
    }
    return(min + (rand() % (max-min)));
}

Level::Level(int brick,int bricksize):
    brick(brick),
    bricksize(bricksize),
    size(brick*bricksize),
    data(bricksize*brick*bricksize*brick,2),
    maze(brick),
    signs({"\033[42m,\033[40m","\033[41m.\033[40m",
        "\033[47mX\033[40m","\033[46m~\033[40m"," ",
        "\033[43m;\033[40m","\033[46m;\033[40m"})

{
    create_rooms();
    create_corr_horiz();
    create_corr_vert();
}

Tile Level::getpos(int x, int y) const
{
    return (Tile)(this->data[x*size + y] & 0x7f);
}

bool Level::gethidden(int x, int y) const
{
    return !!(this->data[x*size + y] & 0x80);
}

void Level::setpos(Tile value, int x, int y)
{
    if ((x < size) & (y < size) & (x > 0) & (y > 0))
    {
        this->data[x*size + y] = (int)value | (this->data[x*size + y]  & 0x80);
    }
}


void Level::sethidden(bool value, int x, int y)
{
    this->data[x*size + y] = (value?0x80:0x0) | (this->data[x*size + y]  & 0x7f);

}

void Level::setarea(Tile value, int x1,int y1, int x2, int y2, bool no_overwrite)
{
    for (int x=std::min(x1,x2);x<std::max(x1,x2)+1;x++)
    {
        for (int y=std::min(y1,y2);y<std::max(y1,y2)+1;y++)
        {
            if (!no_overwrite || getpos(x,y) == Tile::WALL)
            {
                setpos(value,x,y);
            }
        }
    }
}

void Level::addroom(int brick_x, int brick_y)
{
    Room room;
    int xoffset = bricksize*brick_x;
    int yoffset = bricksize*brick_y;
    vector<bool> * conn_vector = &maze.connections[brick_x+brick_y*brick];
    int conn_count = std::count_if(conn_vector->begin(),conn_vector->end(),IsTrue);
    if (!!(rand()%3) && (conn_count > 1))
    { //crossroads
        room.left = between(2,bricksize-2) + xoffset;
        room.top = between(2,bricksize-2) + yoffset;
        room.right = room.left;
        room.bottom = room.top;
        room.filling_tile = Tile::GROUND_CORRIDOR;
    }
    else
    { //crossroads
        room.left = between(1,bricksize/2) + xoffset;
        room.top = between(1,bricksize/2) + yoffset;
        room.right = between(1+bricksize/2,bricksize-1) + xoffset;
        room.bottom = between(1+bricksize/2,bricksize-1) + yoffset;
    }
    room.top_corr_x = between(room.left,room.right);
    room.bottom_corr_x = between(room.left,room.right);
    room.left_corr_y = between(room.top,room.bottom);
    room.right_corr_y = between(room.top,room.bottom);

    room.connect_right = maze.connections[brick_x+brick_y*brick][RIGHT];
    room.connect_bottom = maze.connections[brick_x+brick_y*brick][DOWN];
    rooms.push_back(room);
}



void Level::create_rooms()
{
    for (int x=0;x<brick;x++)
    {
        for (int y=0;y<brick;y++)
        {
            addroom(x,y);
        }
    }
    for (Room r:rooms)
    {
        std::cout << "generating room\n";
        setarea(r.filling_tile,r.left,r.top,r.right,r.bottom);
        if (!(rand()% 5))
        {
            for (int x=r.left;x<r.right+1;x++)
            {
                for (int y=r.top;y<r.bottom;y++)
                {
                    if (!(rand()% 2))
                    {
                        setpos(Tile::ROUGH,x,y);
                    }
                }
            }
        }
    }
}

void Level::corr_h(Room l, Room r, bool addcliff)
{
    int knick_x = between(l.right+2,r.left-1);
    setarea(Tile::GROUND_CORRIDOR,
        l.right+1,l.right_corr_y,knick_x,l.right_corr_y);
    setarea(Tile::GROUND_CORRIDOR,
        knick_x,l.right_corr_y,knick_x,r.left_corr_y);
    setarea(Tile::GROUND_CORRIDOR,
        r.left-1,r.left_corr_y,knick_x,r.left_corr_y);
    if (addcliff)
    {
        int cliff_y = between(l.right_corr_y,r.left_corr_y);
        setpos(Tile::CLIFF,knick_x,cliff_y);
    }
}

void Level::create_corr_horiz()
{
    for (unsigned int i= 0;i<rooms.size();i++)
    {
        Room r = rooms[i];
        std::cout << "generating corridor\n";
        int x = i/brick;
        if (x == brick-1)
        {
            continue;
        }
        Room nextroom = rooms[i+brick];
        if ((r.connect_right) | !(rand() % 6))
        {
            corr_h(r,nextroom);
        }
        else if (!(rand() % 5)) {
            setarea(Tile::WATER,
                r.right+1,r.right_corr_y,nextroom.left-1,nextroom.left_corr_y);
        }
        else if (!(rand() % 4)) {
            corr_h(r,nextroom,true);
        }

    }
}

void Level::corr_v(Room t, Room b, bool addcliff)
{
    int knick_y = between(t.bottom+2,b.top-1);
    setarea(Tile::GROUND_CORRIDOR,
        t.bottom_corr_x,t.bottom+1,t.bottom_corr_x,knick_y);
    setarea(Tile::GROUND_CORRIDOR,
        t.bottom_corr_x,knick_y,b.top_corr_x,knick_y);
    setarea(Tile::GROUND_CORRIDOR,
        b.top_corr_x,b.top-1,b.top_corr_x,knick_y);
}

void Level::create_corr_vert()
{
    for (unsigned int i= 0;i<rooms.size();i++)
    {
        Room r = rooms[i];
        std::cout << "generating corridor V\n";
        int y = i%brick;
        if (y == brick-1)
        {
            continue;
        }
        Room nextroom = rooms[i+1];
        if ((r.connect_bottom) | !(rand() % 6))
        {
            corr_v(r,nextroom);
        }
        else if (!(rand() % 5)) {
            setarea(Tile::WATER,
                r.bottom_corr_x,r.bottom+1,nextroom.top_corr_x,nextroom.top-1);
        }
        else if (!(rand() % 4)) {
            corr_v(r,nextroom,true);
        }
    }
}

void Level::print(ostream * out) const
{
    maze.print(out);
    *out << "\n";
    for (int i=0;i<size*size;i++)
    {
        if (!(i%size))
        {
            *out << ";\n";
        }
        *out << signs[(int)getpos(i%size,i/size)];
    }
}

Maze::Maze(int size):
    connections(pow(size,2),{false,false,false,false}),
    size(size),
    connectedto(pow(size,2),0),
    border(4,0)
{
    srand(time(NULL));
    connectedto[rand() % (size*size)] = true;
    border[UP] = -size;
    border[LEFT] = -1;
    border[RIGHT] = 1;
    border[DOWN] = size;

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
    vector<int> dirvec = {UP,LEFT,RIGHT,DOWN};
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

void Maze::print(ostream*out) const
{
    for (int y=0;y<size;y++)
    {
        for (int h=0;h<3;h++)
        {
            for (int x=0;x<size;x++)
            {
                switch (h)
                {
                    case 0: *out << " " << (connections[y*size+x][UP]?"|":" ")
                            << " ";break;
                    case 1: *out << (connections[y*size+x][LEFT]?"-":" ") << "+" <<
                                (connections[y*size+x][RIGHT]?"-":" ");break;
                    case 2: *out << " " << (connections[y*size+x][DOWN]?"|":" ")
                            << " ";break;
                    default: *out << "???";break;
                }
            }
            *out << "\n";
        }
    }
}
