#include "board.hpp"
#include <string.h>

void display();
void reshape(int, int);
void mouseEvent(int button, int state, int x, int y);
void keyboardEvent(unsigned char key, int x, int y);

int count = 0;
char winner ;
char turn = 'X';
int gap = 100;
int w = 600, h = 600 + gap;
int gameOver = 0 ;

Board board;


int main(int argc, char **argv)
{
  
board.h = h ;
board.w = w ;

  init(argc, argv, w, h, 650, 0, "TIC TAC TOE GAME");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouseEvent);
  glutKeyboardFunc(keyboardEvent);

  glClearColor(0, 0, 0, 1);
  glutMainLoop();

  return 0;
};

void draw_pos()
{
  int x, y;
  for (int i = 0; i < 3; i++){

    for (int j = 0; j < 3; j++){

      x = j * (w / 3) + (w / 6);
      y = gap + i * (w / 3) + (w / 6);

      if (board.pos[i][j] == 'X')
      {
        board.drawX(x, y);
      }
      else if (board.pos[i][j] == 'O')
      {
        board.drawO(x, y);
      }
    };
  };
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glColor3f(0, 1, 1);
  event.drawText("Welcome to OpenGl", w / 2 - 60,gap/4);
  event.drawText("TIC TAC TOE", w / 2 - 50, gap / 2);

  board.drawLines(w, gap);

  draw_pos();

  if (count == 9)
  {
    glColor3f(1, 1, 0);
    event.drawText("game is draw, press (y/n) to rematch or exit", w / 4 - 10, 70);
  }
  else if (winner)
  {
    glColor3f(0, 1, 0);
    event.drawText(strcat(&winner, " win the game.press (y/n) to continue or exit"), w / 4 - 10, 70);
  }
  glutSwapBuffers();
  glFlush();
};

void mouseEvent(int button, int state, int x, int y)
{
  // cout << GLUT_LEFT_BUTTON <<endl; //0
  // cout << GLUT_RIGHT_BUTTON <<endl; //2
  // cout << GLUT_DOWN <<endl; //0
  // cout << GLUT_UP <<endl<<endl;//1

  if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON  && !gameOver) {
  if (board.checkPos(x, y , turn) )
  {
    if (board.checkWin(turn))
    {
      winner = turn;
      gameOver = 1;
    }
    else
    {
      count++;
      turn = turn == 'X' ? 'O' : 'X';
    }
  }
  };
};

void keyboardEvent(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'y':
    if (gameOver)
    {
      board.initGame(turn, count, winner ,gameOver);
      display();
    }
    break;
  case 'n':
  case 27:
    exit(0);
    break;
  default:
    break;
  };
}