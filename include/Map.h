#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Snake.h"

class Map
{
protected:
    int x_length ;
    int y_length ;
    char wall ;
    char food ;
    char empty_space ;
    char **map ;

public:

    void newFood();
    void print(int);
    void initialize();
    char getWall();
    char getEmptySpace();
    char getFood();
    char** getMap();
    void update(Snake*,bool,int,int);
    // نقطه اولیه برای ایحاد مار را مشخص می کند
    Part_Of_Snake_Body generateSnakeCreateLocation();
    virtual void generate() = 0 ;
    int countOfEmptySpace() ;


private:

};

#endif // MAP_H
