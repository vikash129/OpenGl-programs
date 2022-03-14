#include <iostream>
#include "../../OpenGl.hpp"

using namespace std;

Shape shape;
Event event;
#define show(x,y) cout <<x <<"  " <<y<<endl<<endl

// food class
class Food
{
public:
    int w, h,gap;
    int food[2] ;
    void drawFood();
    void RandomFood();
};

// food function
void Food ::drawFood()
{
    glColor3f(1, 1, 0);
    shape.circle(12, food[0], food[1]);
};

void Food ::RandomFood()
{
    //num = min + rand() % max -> [min,max]
    food[0] =gap +  rand() % 380;
    food[1] =gap +  rand() % 480; 
};