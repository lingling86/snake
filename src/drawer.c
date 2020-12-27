#include <drawer.h>
#include <wchar.h>

int monitor;

void draw(Snake *snake, FOOD *food)
{
	clear();

	// draw food
	move(food->x, food->y);
	switch (food->prop)
	{
	case DEFAULT:
		addwstr(L"\U0001F34F");
		break;
	case SPEED:
		addwstr(L"\U0001F34E");
		break;
	}

	attron(A_REVERSE);
	// draw snake
	for (int i = 0; i < snake->len; i++)
	{
		move(snake->x[i], snake->y[i]);
		printw("  ");
	}
	attroff(A_REVERSE);

	
	refresh();
}

void debug_draw(Snake *snake, FOOD *food)
{
	clear();
	move(0, 0);
	printw("LINES = %d, COLS = %d, monitor = %d\n", LINES, COLS, monitor);
	// for (int i = 0; i < snake->len; i++)
	printw("x = %d, y = %d\n", snake->x[0], snake->y[0]);
	printw("FOOD x = %d, y = %d\n", food->x, food->y);
	refresh();
}

void debug(int n)
{
	monitor = n;
}

void game_over(Snake *snake)
{
	// TODO: draw a game over window
}