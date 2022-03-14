#include "base.hpp"

void display();
void reshape();

Base car;

int main(int argc, char **argv)
{
    car.w = 600;
    car.h = 500;

    init(argc, argv);

    glutDisplayFunc(display);
    car.reshape();

    glClearColor(0, 0, 0, 1);
    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // glColor3f(0, 0, 1);
    // shape.point(20, 0, 0);

    car.show();

    glFlush();
}
