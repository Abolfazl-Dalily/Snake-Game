#ifndef SNAKE_H
#define SNAKE_H
#include <vector>


struct Part_Of_Snake_Body
{
    int x, y ;
    char direction ;

};


class Snake
{
private:
    std::vector<Part_Of_Snake_Body> body ;
    char symbol ;

public:
    Snake();
    void create(Part_Of_Snake_Body);
    void eatFood();
    void setDirection(char);
    char getDirection();
    char getSymbol();
    int getSize();
    Part_Of_Snake_Body getHead();
    Part_Of_Snake_Body getTail();
    void update(int,int);
    void updateHead(int,int);
    std::vector<Part_Of_Snake_Body> getBody();

    ~Snake();


protected:


};

#endif // SNAKE_H
