#include "HardMap.h"

HardMap::HardMap()
{
    x_length = 25 ;
    y_length = 15 ;
    wall = '#';
    empty_space = '*';
    food = '@' ;
    initialize();
}
void HardMap::generate()
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

    // Draw Internal Wall

    for (int y = 3 ; y < y_length - 3 ; y ++ )
    {
        map[y][4] = wall ;
        map[y][20] = wall ;
    }

    for (int x = 6 ; x < x_length - 6 ; x++ )
    {
        map[7][x] = wall ;
        map[8][x] = wall ;
    }

    newFood();
}

HardMap::~HardMap()
{
    //dtor
}
