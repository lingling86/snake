#include <game.h>

static int row, col;
static Snake snake;
static FOOD food;
static int _key;
static int flag = 0;

void set_key(int k)
{
    _key = k;
}

int get_key()
{
    return _key;
}

void move_snake(Snake *snake)
{
    for (int i = snake->len - 1; i > 0; i--)
    {
        snake->x[i] = snake->x[i - 1];
        snake->y[i] = snake->y[i - 1];
    }
    switch (_key)
    {
    case _LEFT:
        snake->y[0] -= 2;
        break;
    case _RIGHT:
        snake->y[0] += 2;
        break;
    case _DOWN:
        snake->x[0]++;
        break;
    case _UP:
        snake->x[0]--;
        break;
    }
}

void eat_food(FOOD *food, Snake *snake)
{
    if (food->x == snake->x[0] && food->y == snake->y[0])
    {
        switch (food->prop)
        {
        case DEFAULT:
            snake->len++;
            break;
        case SPEED:
            if (snake->speed >= 100)
                snake->speed *= 0.7;
            else
                snake->speed *= 0.9;
            break;
        }
        snake->count++;
        create_food(snake);
    }
}

int snake_die(Snake *snake)
{
    if (snake->x[0] == -1 || snake->x[0] == row || snake->y[0] == -2 || snake->y[0] == col)
    {
        return 0;
    }
    for (int i = 1; i < snake->len - 1; i++)
    {
        if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i])
        {
            return 0;
        }
    }
    return 1;
}

void init_snake(int _row, int _col)
{
    row = _row;
    col = _col;
    _key = 261;
    srand(time(0));
    snake.x[0] = row / 2;
    snake.y[0] = col / 2;
    snake.len = 3;
    snake.speed = 300;
    snake.count = 0;
    for (int i = 1; i < snake.len; i++)
    {
        snake.x[i] = snake.x[i - 1];
        snake.y[i] = snake.y[i - 1] - 2;
    }
}

void create_food(Snake *snake)
{
    int i;
    int a, b;
    while (1)
    {
        food.x = rand() % row;
        food.y = rand() % col;
        food.prop = rand() % PROP_NUM;
        if (food.y % 2 != 0)
            continue;
        for (i = 0; i < snake->len; i++)
        {
            if (food.x != snake->x[i] && food.y != snake->y[i])
                goto end;
        }
    }
end:;
}

Snake *get_snake()
{
    return &snake;
}

FOOD *get_food()
{
    return &food;
}

int load()
{
    // int ked;
    // while (1)
    // {
    //     ked = getch();
    //     if (ked == _UP)
    //     {
    //         flag--;
    //         if (flag < 0)
    //             flag = 0;
    //         return flag;
    //     }
    //     else if (ked == _DOWN)
    //     {
    //         flag++;
    //         if (flag >= 3)
    //             flag = 2;
    //         return flag;
    //     }
    //     else if (ked == '\n')
    //         break;
    // }
    // return flag++;
}