#include <iostream>
using namespace std;

#include "../../OpenGl.hpp"

Shape shape;

class Base{
public:
int w,h;
void show();
void reshape();
};

void Base :: show(){
    glColor3f(1,0,0);
    
    shape.polygon(150 ,160  ,200,200 , 400,200 ,450,160);
        glColor3f(0,1,0);

    shape.polygon(100 ,160   ,   100,100   ,       450,100 ,    450,160);
        glColor3f(1,1,1);

    shape.circle(50,200,100);
    shape.circle(50,450,100);
};

void Base :: reshape(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0,0,w,h);
   gluOrtho2D(0,w,0,h);


     glMatrixMode(GL_MODELVIEW);
}
