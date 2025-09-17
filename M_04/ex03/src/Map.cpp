#include "Map.hpp"

Map::Map()
    : _world("default world")
{
    int count = 1;
    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            _grid[y][x] = NULL;

            if (count <= MATERIAS)
            {
                if (y == HEIGHT / 2 || x == WIDTH / 2)
                {
                    if (count % 2 == 0)
                        _grid[y][x] = new Ice();
                    else
                        _grid[y][x] = new Cure();
                    count++;
                }
            }
            x++;
        }
        y++;
    }
}

Map::Map(const std::string& worldValue)
    : _world(worldValue)
{
    int count = 1;
    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            _grid[y][x] = NULL;

            if (count <= MATERIAS)
            {
                if (y == HEIGHT / 2 || x == WIDTH / 2)
                {
                    if (count % 2 == 0)
                        _grid[y][x] = new Ice();
                    else
                        _grid[y][x] = new Cure();
                    count++;
                }
            }
            x++;
        }
        y++;
    }
}

Map::Map(const Map& object)
    : _world(object._world)
{
    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            if (object._grid[y][x])
                _grid[y][x] = object._grid[y][x]->clone();
            else
                _grid[y][x] = NULL;
            x++;
        }
        y++;
    }
}

Map& Map::operator=(const Map& object)
{
    if (this != &object)
    {
        _world = object._world;
        int y = 0;
        while (y < HEIGHT)
        {
            int x = 0;
            while (x < WIDTH)
            {
                if (_grid[y][x])
                    delete (_grid[y][x]);
                if (object._grid[y][x])
                    _grid[y][x] = object._grid[y][x]->clone();
                else
                    _grid[y][x] = NULL;
                x++;
            }
            y++;
        }
    }
    return (*this);
}

Map::~Map()
{
    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            if (_grid[y][x])
                delete (_grid[y][x]);
            x++;
        }
        y++;
    }
}

const std::string& Map::getWorld(void) const
{
    return (_world);
}

AMateria*   Map::getMateria(int x, int y) const
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        return _grid[y][x];
    return NULL;
}

void Map::setWorld(const std::string& worldValue)
{
    _world = worldValue;
}

void    Map::setMateria(AMateria* materiaValue, int x, int y)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        _grid[y][x] = materiaValue;
}

void Map::showMap(Character* players[], int playersSize, Character* enemies[], int enemiesSize)
{
    /*std::cout
        << "Width: "
        << WIDTH
        << "\nHeight: "
        << HEIGHT
        << "\nWorld: "
        << _world
        << "\n"
        << std::endl;*/

    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            bool printed = false;

            int i = 0;
            while (i < playersSize)
            {
                const int* pos = players[i]->getPosition();
                if (players[i]
                    && pos[0] >= 0 && pos[0] < WIDTH
                    && pos[1] >= 0 && pos[1] < HEIGHT
                    && pos[0] == x && pos[1] == y)
                {
                    std::cout << players[i]->getName();
                    printed = true;
                    break;
                }
                i++;
            }

            int j = 0;
            while (!printed && j < enemiesSize)
            {
                const int* pos = enemies[j]->getPosition();
                if (enemies[j]
                    && pos[0] >= 0 && pos[0] < WIDTH
                    && pos[1] >= 0 && pos[1] < HEIGHT
                    && pos[0] == x && pos[1] == y)
                {
                    std::cout << enemies[j]->getName();
                    printed = true;
                    break;
                }
                j++;
            }

            if (!printed)
            {
                if (_grid[y][x])
                    std::cout << _grid[y][x]->getType();
                else
                    std::cout << "🍀";
            }

            x++;
        }
        std::cout << "\n";
        y++;
    }
    std::cout << std::endl;
}
