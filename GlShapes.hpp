#include <iostream>
using namespace std;
#include <GL/glut.h>
#include <stdarg.h>
#include <math.h>


class Shape
{
public:
    void point(float x, float y , int size);
    void line(float x1, float y1, float x2, float y2);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    void quadrant(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    void polygon(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4 , int = GL_POLYGON);
    void circle(float r, float x, float y , int = GL_POLYGON);

    void quadrant_3d(float cube[6][4][3], float color[4][3]);
};

void Shape ::circle(float r, float x0, float y0 , int shape)
{
    float x, y, rad;

    glBegin(shape);
    for (float deg = 0; deg < 360; deg++)
    {
        rad = deg * (M_PI / 180); // converts degree into radian

        // cout << rad << endl;
        x = x0 + r * cos(rad);
        y = y0 + r * sin(rad);

        glVertex2f(x, y);
    };

    // glColor3f(0, 0, 1);
    // for (float rad = M_PI; rad < 2 * M_PI; rad += 0.01)
    // {
    //     glVertex2f(r * cos(rad), r * sin(rad));
    // };

    glEnd();
};

void Shape ::point(float x, float y,int size)
{
    glPointSize(size);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
};

void Shape ::line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();
};

void Shape ::triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
};


void Shape ::quadrant(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_QUADS);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);

    glEnd();
};


void Shape ::polygon(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4 , int shape)
{
    glBegin(shape);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);

    glEnd();
};

// 3d - cube
void Shape ::quadrant_3d(float cube[6][4][3], float color[6][3])
{
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++)
    {
        glColor3f(color[i][0], color[i][1], color[i][2]);

        glVertex3f(cube[i][0][0],cube[i][0][1], cube[i][0][2]); // p1
        glVertex3f(cube[i][1][0],cube[i][1][1], cube[i][1][2]); // p2
        glVertex3f(cube[i][2][0],cube[i][2][1], cube[i][2][2]); // p3
        glVertex3f(cube[i][3][0],cube[i][3][1], cube[i][3][2]); // p4
    };
    glEnd();
};
