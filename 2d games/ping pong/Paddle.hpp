#include "Ball.hpp"

#define EXIT 27
#define SPACE 32

class Paddle
{
public:
    int l = 200, b = 40;
    int w, h, gap;
    int speed = 40;

    int x ;
    int  y = 0  ;
    int  y_dir = 0   ;
    int  score = 0;
    bool winner = false;

    void movePlayer();
    void drawPaddle(int, int);
    void initPaddle();

    // for player 1
    void specialKeys(int key);
    void specialUPKey();

    // for player 2
    void keyBoardUPKeys();
};

Paddle left_paddle;
Paddle right_paddle;

void Paddle ::initPaddle()
{
    left_paddle.winner = right_paddle.winner = false;
    left_paddle.score = right_paddle.score = 0;
    left_paddle.y = right_paddle.y = 0;
};

void Paddle ::drawPaddle(int x, int y)
{
    glColor3f(0.88, 0.5, 0.2);
    shape.polygon(x + b / 2, y + l / 2, x - b / 2, y + l / 2, x - b / 2, y - (l / 2), x + b / 2, y - (l / 2));

    glColor3f(0, 0, 0);
    shape.polygon(x + b / 2, y + l / 2, x - b / 2, y + l / 2, x - b / 2, y - (l / 2), x + b / 2, y - (l / 2), GL_LINE_LOOP);
}

void Paddle ::movePlayer()
{
    // if (left_paddle.y + left_paddle.y_dir < h - gap && left_paddle.y + left_paddle.y_dir > -h + gap)
    // {
    //     left_paddle.y += left_paddle.y_dir;
    // }
    if (ball.y+ball.radius < h - gap && ball.y-ball.radius > -h + gap)
    {
                left_paddle.y = ball.y ;
    }

    if (right_paddle.y + right_paddle.y_dir < h - gap && right_paddle.y + right_paddle.y_dir > -h + gap)
    {
        right_paddle.y += right_paddle.y_dir;
    }
}
// right player
void Paddle ::specialUPKey()
{
    right_paddle.y_dir = 0;
}
void Paddle ::specialKeys(int key)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        right_paddle.y_dir = speed;
        break;

    case GLUT_KEY_DOWN:
        right_paddle.y_dir = -speed;
        break;
    };
}

void Paddle ::keyBoardUPKeys()
{
    left_paddle.y_dir = 0;
}
