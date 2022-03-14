#include <iostream>
#include <GL/glut.h>
#include <string.h>
using namespace std;


class Event 
{
public:
    void drawText(string text, float x, float y);

};

void Event ::drawText(string text, float x, float y)
{
    int len   = text.length();

    glRasterPos2f(x, y);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    };
};









