#include <iostream>
#include "../../OpenGl.hpp"

Shape shape;
Event event;

using namespace std;

class Board
{
public:
    int w, h  ;
    char pos[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    void initGame(char &, int &, char &, int &);
    void setBoard(int i, int j, char turn) { pos[i][j] = turn; };
    int checkPos(int i, int j, char turn);
    int checkWin(char turn);
    void drawLines(int, int);
    void drawX(int, int);
    void drawO(int, int);
};

void Board ::initGame(char &turn, int &count, char &win, int &gameOver)
{
    gameOver = 0;
    turn = 'X';
    count = 0;
    win = false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pos[i][j] = ' ';
        };
    };
};

int Board ::checkPos(int x, int y, char turn)
{
    int i, j;
    if ((x > 0 && y > 100) && (x < w && y < h))
    {
        i = (y - 100) / 200;
        j = x / 200;

        if (pos[i][j] == ' ')
        {
            setBoard(i, j, turn);
            return 1;
        }
        else
        {
            event.drawText("invalid move!! position box already filled" , w / 4 - 10, 55 );
            return 0;
        }
    }
    else
    {
       event.drawText("Out of the Box" , w / 4 - 10, 55 );
        return 0;
    }
}



int Board ::checkWin(char turn)
{

    if (pos[0][0] == turn && pos[0][1] == turn && pos[0][2] == turn)      return 1;

     else if   (pos[1][0] == turn && pos[1][1] == turn && pos[1][2] == turn)   return 2;
      else if    (pos[2][0] == turn && pos[2][1] == turn && pos[2][2] == turn) return 3;
    
      else if    (pos[0][0] == turn && pos[1][0] == turn && pos[2][0] == turn)  return 4;
       else if   (pos[0][1] == turn && pos[1][1] == turn && pos[2][1] == turn)  return 5;
       else if   (pos[0][2] == turn && pos[1][2] == turn && pos[2][2] == turn) return 6;

       else if    (pos[0][0] == pos[1][1] && pos[1][1] == turn && pos[2][2] == pos[0][0])  return 7;
       else if   (pos[0][2] == turn && pos[1][1] == turn && pos[2][0] == turn) return 8;
    
    return 0;
};

// graphs
void Board ::drawLines(int a, int gap)
{
    glColor3f(1, 0, 0);
    glLineWidth(5);
    // gap=0;
    // horizontal lines
    shape.line(0, gap + a / 3, a, gap + a / 3);     // upper
    shape.line(0, gap + a / 1.5, a, gap + a / 1.5); // lower

    // vertical lines lines
    shape.line(a / 3, gap, a / 3, gap + a);
    shape.line(a / 1.5, gap, a / 1.5, gap + a);
}

int s_h = 30 ;
void Board ::drawX(int x, int y)
{
    glColor3f(1, 1, 0);

    shape.line( x+s_h , y+s_h , x-s_h,y-s_h );
    shape.line( x-s_h , y+s_h , x+s_h,y-s_h );
};
void Board ::drawO(int x, int y)
{
    glColor3f(0, 1, 1);
    shape.circle(s_h , x,y);
};

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h); // GLint x, GLint y, GLsizei width, GLsizei height

    glOrtho(0, w, h, 0, 0, 1); // for 2d

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
};
