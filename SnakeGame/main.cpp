#include <bits/stdc++.h>
#include <conio.h>
#include<windows.h>
using namespace std;

bool GameOver;
const int width = 25;
const int height = 20;

int x, y, fx, fy, score;
int tailX[1001], tailY[1001];
int n;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;



int Setup()
{
    GameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fx= rand() % width;
    fy = rand() % height;
    score = 0;
}

void Map()
{

    system("cls");
    int i, j;

    for( i = 0; i< width+2; i++)
        cout<<"#";
    cout<<endl;

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(j == 0)
                cout << "#";

            if( i == y && j ==x)
                cout<<"O";
            else if( i ==fy && j== fx)
                cout<<"F";
            else
            {
                bool print = false;
                for (int k = 0; k< n; k ++)
                {

                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }

                }
                 if (!print)
                        cout<<" ";

            }


            if(j == width-1)
                cout<<"#";
        }

        cout<<endl;
    }
    for( i = 0; i< width+2; i++)
        cout<<"#";
    cout<< endl;

    cout<<"SCORE " << score<< endl;
    cout<<"Press x to kill the game"<<endl;

}
void Input()
{
    if (kbhit())
    {
        switch(getch())
        {
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 'w':
            dir = UP;
            break;

        case 's':
            dir = DOWN;
            break;

        case 'x':
            GameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for( int i = 1; i < n; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }


    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    if ( x > width || x < 0 || y > height || y < 0)
        GameOver = true;

    for(int i = 0 ; i< n; i++)
        if(tailX[i] == x && tailY[i] == y)
        GameOver = true;

    if ( x == fx && y == fy)
    {
        score = score + 10;
        fx= rand() % width;
        fy = rand() % height;
        n++;
    }
}



int main()
{

    Setup();
    while(!GameOver)
    {
        Map();
        Input();
        Logic();
        Sleep(25);


    }


    return 0;
}
