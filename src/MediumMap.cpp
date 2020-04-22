#include "MediumMap.h"

MediumMap::MediumMap()
{
    x_length = 25 ;
    y_length = 15 ;
    wall = '#';
    empty_space = '*';
    food = '@' ;
    initialize();
}

void MediumMap::generate()
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
        map[y][5] = wall ;
        map[y][20] = wall ;
    }

    newFood();
}



MediumMap::~MediumMap()
{
    //dtor
}
