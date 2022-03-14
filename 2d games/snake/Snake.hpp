
#include <vector>
#include "Food.hpp"


class Snake
{
public:
    int x_dir = -1, y_dir = 0;

    vector<int> snake = { 200, 100, 220, 100 , 240, 100, 260, 100,}; // top-left corner

    int size = 20;

    void setSnake(int i, int j, char turn);
    void drawSnake();
    void moveSnake();
    void updateLength();
    int length;
    int x,y ;
};

// snake function
void Snake::drawSnake()
{

    length = snake.size();

    glColor3f(1, 0, 0);

    for (int i = 0; i < length - 1; i+=2)
    {        
        x = snake.at(i);
        y = snake.at(i + 1);
        shape.quadrant(x, y, x + size, y, x + size, y + size, x, y + size);

        glColor3f(0, 0, 1);
    }
};

void Snake ::moveSnake()
{
  length = snake.size();

    for (int i = length - 1; i > 1; i -= 2)
    {
        snake[i - 1] = snake[i - 3];
        snake[i] = snake[i - 2];
    }
    snake[0] += (x_dir * size);
    snake[1] += (y_dir * size);

}

void Snake ::updateLength()
{
    length = snake.size();

snake.push_back( snake.at( length-2  ) ); //for x
snake.push_back(snake.at( length-1  ) );  //for y
}
