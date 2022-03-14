#include "Game.hpp"
#define FrameRate 1000 / 12

int w = 500, h = 600, gap = 50;
Game game(w, h, gap);

void keyboardEvent(unsigned char key, int x, int y);
void SpecialKeyEvent(int key, int x, int y);
void control();
void display();

void timer(int)
{

  glutPostRedisplay();
  glutTimerFunc(FrameRate, timer, 0);
};

int main(int argc, char **argv)
{
  game.init(argc, argv);

  game.reshape();

  glutKeyboardFunc(keyboardEvent);
  glutSpecialFunc(SpecialKeyEvent);

  glutDisplayFunc(display);
  glutTimerFunc(0, timer, 0);

  glClearColor(0, 0, 0, 1);
  glutMainLoop();

  return 0;
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  game.drawBoundary();
  game.drawFood();
  game.showScore();
  game.drawSnake();

  game.checkBoundary();
  
  if (!game.pause && !game.gameOver)
  {
    game.moveSnake();
  }

  game.checkPoint();

  glutSwapBuffers();
  glFlush();
}

void keyboardEvent(unsigned char key, int x, int y)
{
  game.keyBoardKeys(key);
}

void SpecialKeyEvent(int key, int x, int y)
{
  game.specialKeys(key);
}
