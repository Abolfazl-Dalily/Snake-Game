#include "Snake.h"

Snake::Snake()
{
    symbol = '&' ;
}

void Snake::create(Part_Of_Snake_Body head)
{
    body.push_back(head);
}

void Snake::eatFood()
{
    int current_x_of_snake_tail = getTail().x ;
    int current_y_of_snake_tail = getTail().y ;
    char direction_of_tail_snake = getTail().direction ;

    switch (direction_of_tail_snake)
    {
    case 'u':
    {
        Part_Of_Snake_Body new_up_part{current_x_of_snake_tail, current_y_of_snake_tail + 1, direction_of_tail_snake};
        body.push_back(new_up_part);
    }
    break;
    case 'd':
    {
        Part_Of_Snake_Body new_down_part{current_x_of_snake_tail, current_y_of_snake_tail - 1, direction_of_tail_snake};
        body.push_back(new_down_part);
    }
    break;
    case 'r':
    {
        Part_Of_Snake_Body new_right_part{current_x_of_snake_tail + 1, current_y_of_snake_tail, direction_of_tail_snake};
        body.push_back(new_right_part);
    }
    break;
    case 'l':
    {
        Part_Of_Snake_Body new_left_part{current_x_of_snake_tail - 1, current_y_of_snake_tail, direction_of_tail_snake};
        body.push_back(new_left_part);
    }
    break;
    default:

        break;
    }
}

void Snake::setDirection(char new_dir)
{
    body[0].direction = new_dir ;
}

char Snake::getDirection()
{
    return body[0].direction ;
}
Part_Of_Snake_Body Snake::getTail()
{
    return body.back();
}
Part_Of_Snake_Body Snake::getHead()
{
    return body[0];
}

int Snake::getSize()
{
    return body.size();
}
char Snake::getSymbol()
{
    return symbol ;
}



void Snake::update(int new_x, int new_y)
{
    for (int i = getSize() - 1; i > 1; i--)
    {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;

    }
    body[1].x = new_x ;
    body[1].y = new_y ;

}
void Snake::updateHead(int new_x, int new_y)
{
    body[0].x = new_x ;
    body[0].y  = new_y ;
}

std::vector<Part_Of_Snake_Body> Snake::getBody()
{
    return body;
}
Snake::~Snake()
{
}
