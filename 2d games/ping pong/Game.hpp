// #include <fstream>
#include "Paddle.hpp"

class Game : public Paddle, public Ball
{
public:
    int w, h, gap;
    bool gameOver = false, pause = true;

    Game(int w, int h, int gap)
    {
        this->w = w;
        this->h = h;
        this->gap = gap;

        Paddle::w = Ball::w = w;
        Paddle::h = Ball::h = h;
        Paddle::gap = Ball::gap = gap;

        left_paddle.x = -w + 150;
        right_paddle.x = w - 150;
    };
    bool chance = RIGHT;
    void keyBoardKeys(unsigned char key);
    void initGame();
    void drawBoard();
    void checkBoundary();
    void checkPoint();
    void init(int, char **);
    void showScore();
    void reshape();
    void control();
};

void Game ::showScore()
{
    glColor3f(0, 1, 0);

    event.drawText("SCORE : " + to_string(left_paddle.score), -w + gap + 100, h - 50); // left paddle
    event.drawText("SCORE : " + to_string(right_paddle.score), w - gap - 200, h - 50); // right paddle

    // event.drawText("HIGH SCORE : " + to_string(highscore), w - 200, 30);
}

// game function
void Game::init(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(w, h);
    glutInitWindowPosition(500, 0);

    glutCreateWindow("C++ Ping Pong Game");
};
void Game::reshape()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w + gap, h + gap);
    gluOrtho2D(-w - gap, w + gap, -h - gap, h + gap);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game ::initGame()
{
    initPaddle();
    initBall();
    gameOver = false;
    pause = true;
    chance = RIGHT;
};

void Game ::checkBoundary()
{
    glColor3f(1, 1, 0);

    if (ball.x > max_x_dist - ball.radius) // right boundary
    {
        left_paddle.winner = gameOver = true;
        event.drawText("!! LEFT PLAYER WINS !!", -w / 2, -50);
    }
    else if (ball.x < (-max_x_dist + ball.radius)) // left boundary
    {
        right_paddle.winner = gameOver = true;
        event.drawText("!! RIGHT PLAYER WINS !!", -w / 2, -50);
    }

    if (gameOver)
    {
        // cout << max_x_dist  << endl ;
        glColor3f(1, 0, 0);
        event.drawText("!! GAME OVER !!", -w / 2 + 100, 30);
    }
};

void Game ::checkPoint()
{
    if (sqrt(pow(ball.x - right_paddle.x, 2) + pow(ball.y - right_paddle.y, 2)) < 100) // right paddle
    {
        if (chance == RIGHT)
        {
            ++right_paddle.score;
            ball.speed++;
            chance = LEFT;
            ball.theta+=5;
            // cout << "right paddle score " << right_paddle.score << endl;
            switch (ball.state)
            {
            case DOWN_RIGHT:
                ball.degree = 180 + ball.theta;
                ball.state = DOWN_LEFT;
                break;
            case UP_RIGHT:
                ball.degree = 180 - ball.theta;
                ball.state = UP_LEFT;
                break;
            }
        }
    }

    else if (sqrt(pow(ball.x - left_paddle.x, 2) + pow(ball.y - left_paddle.y, 2)) < 100) // left paddle
    {

        if (chance == LEFT)
        {
            ball.theta-=5;
            chance = RIGHT;
            ++left_paddle.score;

            ball.speed++;

            switch (ball.state)
            {
            case DOWN_LEFT:
                ball.degree = -ball.theta;
                ball.state = DOWN_RIGHT;
                break;
            case UP_LEFT:
                ball.degree = ball.theta;
                ball.state = UP_RIGHT;
                break;
            }
        }
    }
};

void Game ::drawBoard()
{

    glColor3f(1, 1, 0);
    shape.polygon(-w - gap, -h - gap, w + gap, -h - gap, w + gap, h + gap, -w - gap, h + gap);

    glColor3f(0, 0, 1);
    shape.polygon(-w, -h, w, -h, w, h, -w, h); // inner board

    glLineWidth(5);

    glColor3f(1, 1, 1);
    shape.line(0, h, 0, -h); // centre line

    // //boundaries line
    glColor3f(0, 0, 0);
    shape.polygon(-w - gap, -h - gap, w + gap, -h - gap, w + gap, h + gap, -w - gap, h + gap, GL_LINE_LOOP);
    shape.polygon(-w, -h, w, -h, w, h, -w, h, GL_LINE_LOOP);

    control();
}

//////////////
void Game ::control()
{
    if (ball.y > max_y_dist - ball.radius) // up
    {
        switch (ball.state)
        {
        case UP_LEFT:
            ball.degree = 180 + ball.theta;
            ball.state = DOWN_LEFT;
            break;
        case UP_RIGHT:
            ball.degree = -ball.theta;
            ball.state = DOWN_RIGHT;
            break;
        }
    }
    else if (ball.y < -max_y_dist + ball.radius) // down
    {
        switch (ball.state)
        {
        case DOWN_RIGHT:
            ball.degree = ball.theta;
            ball.state = UP_RIGHT;
            break;
        case DOWN_LEFT:
            ball.degree = 180 - ball.theta;
            ball.state = UP_LEFT;
            break;
        }
    }
}

// left player
void Game ::keyBoardKeys(unsigned char key)
{
    switch (key)
    {
    // case 'w':
    //     left_paddle.y_dir = Paddle::speed;
    //     break;

    // case 's':
    //     left_paddle.y_dir = -Paddle::speed;
    //     break;

    case 13: // enter key
        initGame();
        break;

    case 'n':
    case 27:
        exit(0);
        break;

    case ' ':
        pause = !pause;
        break;
    }
};