#include "GlEvents.hpp"
#include "GlShapes.hpp"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define UP_RIGHT 4
#define DOWN_RIGHT 5
#define DOWN_LEFT 6
#define UP_LEFT 7


class OpenGl : public Shape , public Event{};

// open gl function
void init(int argc, char **argv, int w = 500, int h=600 , float x = 700, float y = 0, const char *windowName = "openGl window" )
{

    glutInit(&argc, argv);

    glutInitWindowSize(w, h);
    glutInitWindowPosition(x, y);

    glutCreateWindow(windowName);
};
