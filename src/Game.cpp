#include "Game.h"

Game::Game()
{

    level = Easy ;
    speed = Fast ;
    winner = false ;

    score = 0 ;
    game_over = false ;
}

void Game::bindMap(Map *m)
{
    my_map = m ;
    my_map->generate();
}

void Game::bindSnake(Snake *s)
{
    snake = s ;
    Part_Of_Snake_Body valid_head = my_map->generateSnakeCreateLocation();
    snake->create(valid_head);
}
void Game::updateSnakeLocation()
{

    int current_x_of_snake_head = snake->getHead().x ;
    int current_y_of_snake_head = snake->getHead().y ;
    char direction_of_head = snake->getHead().direction ;

    int current_x_of_snake_tail = snake->getTail().x ;
    int current_y_of_snake_tail = snake->getTail().y ;
    bool new_food = false;
    if (direction_of_head == 'u')
    {
        // UP
        // Check For Collision
        if (my_map->getMap()[current_y_of_snake_head - 1][current_x_of_snake_head] == my_map->getWall() ||
                my_map->getMap()[current_y_of_snake_head - 1][current_x_of_snake_head] == snake->getSymbol())
        {
            game_over = true;
            winner = false;
            return;
        }
        // Check For New Food
        if (my_map->getMap()[current_y_of_snake_head - 1][current_x_of_snake_head] == my_map->getFood())
        {
            // Check For Win !
            if (snake->getSize() == my_map->countOfEmptySpace())
            {
                winner = true ;
                score++;
                game_over = true ;
                return ;
            }
            snake->eatFood();
            score++;
            new_food = true;
        }
        snake->updateHead(snake->getHead().x,snake->getHead().y-1);
    }
    else if (direction_of_head == 'd')
    {
        // DOWN
        // Check For Collision
        if (my_map->getMap()[current_y_of_snake_head + 1][current_x_of_snake_head] == my_map->getWall() ||
                my_map->getMap()[current_y_of_snake_head + 1][current_x_of_snake_head] == snake->getSymbol())
        {
            game_over = true;
            winner = false;
            return;
        }
        // Check For New Food
        if (my_map->getMap()[current_y_of_snake_head + 1][current_x_of_snake_head] == my_map->getFood())
        {
            // Check For Win !
            if (snake->getSize() == my_map->countOfEmptySpace())
            {
                winner = true ;
                score++;
                game_over = true ;
                return ;
            }
            snake->eatFood();
            score++;
            new_food = true;
        }
        snake->updateHead(snake->getHead().x,snake->getHead().y+1);
    }
    else if (direction_of_head == 'r')
    {
        // RIGHT
        // Check For Collision
        if (my_map->getMap()[current_y_of_snake_head][current_x_of_snake_head+1] == my_map->getWall() ||
                my_map->getMap()[current_y_of_snake_head][current_x_of_snake_head+1] == snake->getSymbol())
        {
            game_over = true;
            winner = false;
            return;
        }
        // Check For New Food
        if (my_map->getMap()[current_y_of_snake_head][current_x_of_snake_head+1] == my_map->getFood())
        {
            // Check For Win !
            if (snake->getSize() == my_map->countOfEmptySpace())
            {
                winner = true ;
                score++;
                game_over = true ;
                return ;
            }
            snake->eatFood();
            score++;
            new_food = true;
        }
        snake->updateHead(snake->getHead().x +1,snake->getHead().y);
    }
    else
    {
        // LEFT
        // Check For Collision
        if (my_map->getMap()[current_y_of_snake_head][current_x_of_snake_head - 1] == my_map->getWall() ||
                my_map->getMap()[current_y_of_snake_head][current_x_of_snake_head - 1] == snake->getSymbol())
        {
            game_over = true;
            winner = false;
            return;
        }
        // Check For New Food
        if (my_map->getMap()[current_y_of_snake_head][current_x_of_snake_head - 1] == my_map->getFood())
        {
            // Check For Win !
            if (snake->getSize() == my_map->countOfEmptySpace())
            {
                winner = true ;
                score++;
                game_over = true ;
                return ;
            }
            snake->eatFood();
            score++;
            new_food = true;
        }

        snake->updateHead(snake->getHead().x - 1,snake->getHead().y);
    }

    snake->update(current_x_of_snake_head,current_y_of_snake_head);
    // Update Map
    my_map->update(snake,new_food,current_x_of_snake_tail,current_y_of_snake_tail);


}
void Game::getNewDirection()
{
    system("stty -echo");
    system("stty cbreak");
    char new_direction;
    while (!game_over)
    {
        new_direction = getchar();
        if (new_direction == '8' && snake->getHead().direction != 'd')
        {
            snake->setDirection('u');
        }
        else if (new_direction == '2' && snake->getHead().direction != 'u')
        {
            snake->setDirection('d');
        }
        else if (new_direction == '6' && snake->getHead().direction != 'l')
        {
            snake->setDirection('r');
        }
        else if (new_direction == '4' && snake->getHead().direction != 'r')
        {
            snake->setDirection('l');
        }
        usleep(speed);
    }
    system("stty echo");
    system("stty -cbreak");

}


void Game::start()
{
    my_map->print(score);
    while (!game_over)
    {
        updateSnakeLocation();
        clearScreen();
        my_map->print(score);
        usleep(speed);
    }
    std::cout<<"Game Over \nPlease Press Any Key ..."<<std::endl;

}
void Game::clearScreen()
{
    system("clear");
}

int Game::getScore()
{
    return score ;
}

LEVEL Game::getLevel()
{
    return level ;
}

void Game::setLevel(LEVEL new_level)
{
    level = new_level ;
}

SPEED Game::getSpeed()
{
    return speed ;
}

void Game::setSpeed(SPEED new_speed)
{
    speed = new_speed ;
}
bool Game::is_over()
{
    return game_over ;
}

bool Game::is_winner()
{
    return winner ;
}

void Game::resetState()
{
    game_over = false ;
    winner = false ;
    score = 0;
}

Game::~Game()
{

    delete snake;
}
