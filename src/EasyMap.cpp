#include "EasyMap.h"

EasyMap::EasyMap()
{
}
void EasyMap::generate()
{


    // Draw Empty Space
    for (int y = 0; y < y_length; y++)
    {
        for (int x = 0; x <x_length; x++)
        {
            map[y][x] = empty_space;
        }
    }
    // Drow Wall
    for (int x = 0; x < x_length; x++)
    {
        map[0][x] = wall;
        map[y_length - 1][x] = wall;
    }
    for (int y = 0; y < y_length; y++)
    {
        map[y][0] = wall;
        map[y][x_length - 1] = wall;
    }

    newFood();
}


EasyMap::~EasyMap()
{

}

