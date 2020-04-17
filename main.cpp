#include <iostream>
#include "Map.h"
#include "EasyMap.h"
#include "Snake.h"
#include "Game.h"

using namespace std;

enum FLAG  {Continue=1,Quit=2};
FLAG decide();
void setting(Game*);
int main()
{

    cout << "---Ya Heidar---" << endl;
    cout << "-- WelCome To Snake Game ... " <<endl;
    Game *game = new Game();
    FLAG f = Continue ;
    while (f == Continue){
        cout << "1 : Start Game " << endl ;
        cout << "2 : Setting " << endl ;
        cout << "3 : Help ( Recommender for new gammer )" << endl ;
        cout << "4 : Quit"<<endl;
        cout << "Select A Option From Above : " ;

        int option{};
        cin>>option;
        switch(option)
        {
            case 1 :
            {
                // Start Game With Default Setting !
                EasyMap easy_map ;
                Snake snake ;
                game->resetState();
                game->bindMap(&easy_map);
                game->bindSnake(&snake);
                thread read_new_direction(&Game::getNewDirection,game);
                game->start();
                read_new_direction.join();

                if (game->is_over())
                {

                    system("clear");
                    if (game->is_winner())
                    {
                        cout << "Winn Message !"<<endl ;
                    }
                    else
                    {
                        cout << "Oops ! You are Lose ! " <<endl;
                        cout << "Your Score : "<<game->getScore()<<endl;
                    }
                }
                f = decide();
                break;

            }
            case 2 :
            {

                setting(game);
                break;
            }
            case 3 :
            {
                system("clear");
                cout << "      8\nUse 4   6 key to change snake direction.\n      2 ";
                f = decide();
                break;
            }
            case 4 :
            {
                f = Quit ;
            }
        }
        system("clear");
    }
    cout << "GodBye !"<<endl;


    /*

    */
    return 0;
}

FLAG decide()
{
    int int_f ;
    cout << "\n1 : Continue "<<endl;
    cout << "2 : Quit"<<endl;
    cout << "Select A Option From Above : ";
    cin>>int_f;
    return (FLAG)int_f;
}

void setting(Game *game)
{
    int op ;
    FLAG f = Continue ;
    while(f==Continue){
        system("clear");
        cout<<"1 : Change Difficulty "<<endl;
        cout<<"2 : Change Speed"<<endl;
        cout<<"3 : Back"<<endl;
        cout<<"Select A Option From Above : ";
        cin>>op;

        switch(op)
        {
            case 1 : {
                int int_level ;
                system("clear");
                cout << "1 : Easy"<<endl;
                cout << "2 : Medium"<<endl;
                cout << "3 : Hard"<<endl;
                cout << "Select A Option From Above";
                cin>>int_level;
                game->setLevel(Easy);
                system("clear");
                cout << "Successfully Changed Level";
                f = decide();
                break;
            }
            case 2 : {
                int int_speed ;
                system("clear");
                cout << "1 : VeryFast"<<endl;
                cout << "2 : Fast"<<endl;
                cout << "3 : Slow"<<endl;
                cout << "Select A Option From Above : ";
                cin>>int_speed;
                game->setSpeed((SPEED)(int_speed*100000));
                system("clear");
                cout << "Successfully Changed Speed";
                f = decide();
                break;
            }
            case 3 :
            {
                f = Quit ;
            }
        }
    }
}

