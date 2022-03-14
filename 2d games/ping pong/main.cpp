#include "Game.hpp"

#define FrameRate 1000 / 30

int w = 700, h = 500, gap = 100;

Game game(w, h, gap);

void keyboardEvent(unsigned char key, int x, int y) { game.keyBoardKeys(key); };
void keyboardUPEvent(unsigned char, int x, int y) { game.keyBoardUPKeys(); };

void SpecialKeyEvent(int key, int x, int y) { game.specialKeys(key); };
void SpecialKeyUPEvent(int, int, int y) { game.specialUPKey(); };

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
  glutKeyboardUpFunc(keyboardUPEvent);

  glutSpecialFunc(SpecialKeyEvent);
  glutSpecialUpFunc(SpecialKeyUPEvent);

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

  game.drawBoard();
  game.showScore();

  game.drawBall();

  game.drawPaddle(left_paddle.x , left_paddle.y);
  game.drawPaddle(right_paddle.x , right_paddle.y);

  game.checkBoundary();
 
  if (!game.pause && !game.gameOver)
  {
    game.movePlayer();
    game.moveBall();
    game.checkPoint();
  }

  glutSwapBuffers();
  glFlush();
}
