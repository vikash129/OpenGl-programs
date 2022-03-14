#include "Snake.hpp"
#include <fstream>

#define dimension 25

#define EXIT 27
#define SPACE 32

class Game : public Snake, public Food
{
public:
    int w, h, gap, score = 0, highscore = 0;
    bool gameOver = false, pause = true;

    Game(int w, int h, int gap);

    void initGame();
    void drawBoundary();
    void checkBoundary();
    void checkPoint();
    void init(int, char **);
    void showScore();
    void reshape();

    void keyBoardKeys(unsigned char key);
    void specialKeys(int key);
};

Game ::Game(int w, int h, int gap)
{
    ifstream file;
    string temp;

    file.open("highScore.txt");
    getline(file, temp);

    file.close();

    if (temp.size())
        highscore = stoi(temp);

    this->w = w;
    this->h = h;
    this->gap = gap;

    Food::w = w;
    Food::h = h;
    Food::gap = gap;

    RandomFood();
};
void Game ::showScore()
{
    glColor3f(0, 0, 1);
    event.drawText("SCORE : " + to_string(score), 10, 30);
    event.drawText("HIGH SCORE : " + to_string(highscore), w - 200, 30);
}

// game function
void Game::init(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(w, h);
    glutInitWindowPosition(700, 0);

    glutCreateWindow("C++ Snake Game");
};
void Game::reshape()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluOrtho2D(0, w, h, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game ::initGame()
{

    score = 0;
    gameOver = false;
    pause = true;
    x_dir = 0;
    y_dir = 0;
    RandomFood();

    snake.clear();
    int x = 200, y = 100;

    for (int i = 0; i < 4; i++)
    {
        snake.push_back(x);
        snake.push_back(y);
        x += 20;
    };
};

void Game ::checkBoundary()
{
    int x = snake.at(0);
    int y = snake.at(1);

    if (x < gap || y < gap || x > w - gap - 30 || y > h - gap - 30)
    {

        if (score > highscore)
        {
            highscore = score;

            cout << highscore << endl;

            ofstream hout;
            hout.open("highScore.txt");
            hout << highscore << endl;
            hout.close();
        }

        gameOver = true;
        glColor3f(1, 0, 0);

        event.drawText("!! GAME OVER !!", w / 2 - 50, h / 2 - 30);
        event.drawText("!! TOTAL SCORE : " + to_string(score) + " !!", w / 2 - 70, h / 2 );
    }
};

void Game ::checkPoint()
{
    int x = snake.at(0) - food[0];
    int y = snake.at(1) - food[1];

    // show("dist : "   , sqrt( pow( x ,2)  + pow( y , 2 ) ) );
    if (sqrt(pow(x, 2) + pow(y, 2)) < 18)
    {
        RandomFood();
        score++;
        updateLength();
    }
};

void Game ::drawBoundary()
{

    glColor3f(1, 0, 0);
    shape.polygon(0, 0, w, 0, w, h, 0, h);

    glColor3f(0, 1, 0);
    shape.polygon(gap, gap, w - gap, gap, w - gap, h - gap, gap, h - gap);

    glLineWidth(5);
    glColor3f(0, 0, 0);

    shape.line(gap, gap, w - gap, gap);
    shape.line(w - gap, gap, w - gap, h - gap);
    shape.line(w - gap, h - gap, gap, h - gap);
    shape.line(gap, gap, gap, h - gap);
}

void Game ::keyBoardKeys(unsigned char key)
{

    switch (key)
    {
    case EXIT:
        exit(0);
        break;

    case '0':
        if (gameOver)
        {
            glClearColor(0, 0, 0, 1);
            initGame();
        }
        break;

    case SPACE:

        pause = !pause;

        break;
    }
};

void Game ::specialKeys(int key)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        y_dir = -1;
        x_dir = 0;
        break;

    case GLUT_KEY_DOWN:
        y_dir = 1;
        x_dir = 0;
        break;

    case GLUT_KEY_LEFT:
        x_dir = -1;
        y_dir = 0;
        break;

    case GLUT_KEY_RIGHT:
        x_dir = 1;
        y_dir = 0;
        break;
    };
}