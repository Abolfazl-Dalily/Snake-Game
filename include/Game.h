#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Snake.h"
#include "EasyMap.h"
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
enum LEVEL {Easy, Medium, Hard } ;
enum SPEED {Slow=300000, Fast=250000, VeryFast=200000 } ;

class Game
{
private:
    LEVEL level ;
    SPEED speed ;
    int score ;
    Map *my_map ;
    Snake *snake;
    bool winner ;
    bool game_over ;


public:
    Game();

    void start();
    void updateSnakeLocation();
    void bindMap(Map*);
    void bindSnake(Snake*);
    void getNewDirection();
    void clearScreen();
    int getScore();

    LEVEL getLevel();
    void setLevel(LEVEL);

    SPEED getSpeed();
    void setSpeed(SPEED);
    bool is_over();
    bool is_winner();
    void resetState();

    ~Game();

protected:


};

#endif // GAME_H
