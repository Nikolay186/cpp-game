#include <BearLibTerminal.h>

class Field
{
    private:
        Field();

    public:
        static const int sizeX = 300;
        static const int sizeY = 250;
};

class Direction
{
    private:
        Direction();

    public:
        enum Directions
        {
            UP = 1,
            DOWN = 2,
            LEFT = 3,
            RIGHT = 4
        };
};

class Movement
{
    private:
        Movement();

    public:
        static int GetDirection()
        {
            switch (terminal_read())
            {
                case TK_W:
                    return Direction::UP;
                case TK_S:
                    return Direction::DOWN;
                case TK_A:
                    return Direction::LEFT;
                case TK_D:
                    return Direction::RIGHT;
                case TK_CLOSE:
                    terminal_close();
                    break;
                default:
                    return 0;
            }
        }
};

class Character
{
    public:
        const int startX = 50;
        const int startY = 20;
        const char model = '@';

        int currentX;
        int currentY;

        void Init()
        {
            currentX = startX;
            currentY = startY;
            terminal_put(startX, startY, model);
        }

        void Move()
        {
            switch (Movement::GetDirection())
            {
                case Direction::UP:
                {
                    if (currentY - 1 <= Field::sizeY)
                        currentY -= 1;
                    else
                        currentY = 0;
                    break;
                }

                case Direction::DOWN:
                {
                    if (currentY + 1 >= 0)
                        currentY += 1;
                    else
                        currentY = Field::sizeY;
                    break;
                }

                case Direction::LEFT:
                {
                    if (currentX - 1 >= 0)
                        currentX -= 1;
                    else
                        currentX = Field::sizeX;
                    break;
                }

                case Direction::RIGHT:
                {
                    if (currentX + 1 <= Field::sizeX)
                        currentX += 1;
                    else
                        currentX = 0;
                    break;
                }
            }
        }

        void Update()
        {
            Move();
            terminal_put(currentX, currentY, model);
            terminal_refresh();
        }
};

int main()
{
    terminal_open();
    terminal_refresh();
    Character player;

    player.Init();

    while (true)
    {
        terminal_clear();
        player.Update();

        if (terminal_has_input())
        {
            if (terminal_read() == TK_CLOSE)
                break;
        }
    }
    terminal_close();
}
