#include "../../OpenGl.hpp"
// #define _USE_MATH_DEFINES
#include <math.h>

Shape shape;
Event event;

float deg2rad(int deg)
{
    return deg * float(atan(1) * 4 / 180);
    // return deg * float(M_PI / 180);
};

class Ball
{
public:
    int w = 700, h = 500;
    int gap;

    int state = UP_RIGHT;
    int x = 0;
    int y = 0;
    int speed = 25;
    int theta = 30;
    float degree = theta;
    float angle = deg2rad(degree);

    const int radius = 30;

  int max_x_dist = w - gap - radius;
    int max_y_dist = h - gap - radius;

    void drawBall();
    void moveBall();
    void initBall();
};

Ball ball;

void Ball ::initBall()
{
    ball.state = UP_RIGHT;
    ball.x = ball.y = 0;
    ball.speed = 25;
    ball.theta = 30;
    ball.degree = theta;
    ball.angle = deg2rad(degree);
}

void Ball ::drawBall()
{

    glColor3f(1, 1, 0);
    shape.circle(ball.radius, ball.x, ball.y);

    glColor3f(0, 0, 0);
    glLineWidth(2);
    shape.circle(ball.radius, ball.x, ball.y, GL_LINE_LOOP);
}

void Ball ::moveBall()
{
    ball.angle = deg2rad(ball.degree);
    ball.x += cos(ball.angle) * ball.speed;
    ball.y += sin(ball.angle) * ball.speed;
}
