#include "Map.h"

void Map::initialize()
{
    map = new char*[y_length];
    for(int i=0; i<y_length; i++)
    {
        map[i] = new char[x_length];
    }
}


void Map::print(int current_score)
{
    std::cout<<"start printing\n";
    for(int y=0; y<y_length; y++)
    {
        for (int x = 0; x<x_length; x++)
        {

            std::cout<<map[y][x];
        }
        std::cout<<std::endl;

    }
    std::cout<<"Score : "<<current_score<<std::endl;
}

void Map::newFood()
{
    int x = 0 ;
    int y = 0 ;
    do
    {
        srand(time(0));
        y = rand() % (y_length - 2) + 1;
        srand(time(0));
        x = rand() % (x_length - 2) + 1;

    }
    while (map[y][x] != empty_space);
    map[y][x] = food;
}
char Map::getEmptySpace()
{
    return empty_space ;
}

char Map::getFood()
{
    return food ;
}
char Map::getWall()
{
    return wall ;
}
char** Map::getMap()
{
    return map;
}
void  Map::update(Snake *snake,bool new_food,int x, int y )
{
    for (int i = 0; i < snake->getSize(); i++)
    {
        map[snake->getBody()[i].y][snake->getBody()[i].x] = snake->getSymbol();
    }
    map[y][x] = empty_space ;
    if (new_food)
    {
        newFood();
    }
}
Part_Of_Snake_Body Map::generateSnakeCreateLocation()
{
    int x = 0 ;
    int y = 0 ;
    char direction = 'n';
    do
    {
        srand(time(0));
        y = rand() % (y_length - 2) + 1;
        srand(time(0));
        x = rand() % (x_length - 2) + 1;

    }
    while (map[y][x] != empty_space);
    do
    {
        int int_direction ;
        srand(time(0));
        int_direction = rand() % 4 + 1;
        switch(int_direction)
        {
        case 1 :
        {
            // Down
            if (map[y-1][x] == empty_space)
            {
                direction = 'd' ;
            }
            else
            {
                direction = 'n' ;
            }
            break ;
        }
        case 2 :
        {
            // Left
            if (map[y][x-1] == empty_space)
            {
                direction = 'l' ;
            }
            else
            {
                direction = 'n' ;
            }
            break ;
        }
        case 3 :
        {
            // Right
            if (map[y][x+1] == empty_space)
            {
                direction = 'r' ;
            }
            else
            {
                direction = 'n' ;
            }
            break ;
        }
        case 4 :
        {
            if (map[y+1][x] == empty_space)
            {
                direction = 'u' ;
            }
            else
            {
                direction = 'n' ;
            }
            break ;
        }
        default :
        {

        }
        }
    }
    while(direction == 'n');

    Part_Of_Snake_Body head{x,y,direction};
    return head ;

}

int Map::countOfEmptySpace()
{
    int e_s = 0 ;
    for (int y = 0 ; y < y_length ; y++)
    {
        for (int x=0 ; x<x_length ; x++)
        {
            if (map[y][x] == empty_space)
            {
                e_s ++ ;
            }
        }
    }
    // return 2*x_length + 2*(y_length-2)-1 ;
    return e_s ;
}
