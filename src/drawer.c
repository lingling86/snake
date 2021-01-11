#include <drawer.h>
#include <wchar.h>

int monitor;
int r, c;

void draw(Snake *snake, FOOD *food)
{
	printw("score: %d",snake->count);
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
}

void draw_(Snake *snake, FOOD *food)
{
	move(1,0);
	printw("opposite score: %d",snake->count);
	// draw food
	attron(A_REVERSE);
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

	// draw snake
	for (int i = 0; i < snake->len; i++)
	{
		move(snake->x[i], snake->y[i]);
		printw("  ");
	}
	attroff(A_REVERSE);
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

void debug_(Snake *snake, FOOD *food)
{
	// clear();
	move(3, 0);
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

void game_over(int _row, int _col, Snake *snake)
{
	r = _row;
	c = _col;
	clear();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	move(r / 2 - 2, c / 2 - 4);
	attron(COLOR_PAIR(1));
	printw("game over");
	move(r / 2 - 1, c / 2);
	printw("%d", snake->count);
	attroff(COLOR_PAIR(1));
	refresh();
}

void init_draw(int flag, int _row, int _col)
{
	move(_row / 2 - 2, _col / 2 - 2);
	printw("SNAKE");
	switch (flag)
	{
	case 0:
		attron(A_REVERSE);
		move(_row / 2 - 1, _col / 2 - 2);
		printw("normal mode");
		attroff(A_REVERSE);
		move(_row / 2, _col / 2 - 2);
		printw("online mode");
		break;
	case 1:
		move(_row / 2 - 1, _col / 2 - 2);
		printw("normal mode");
		attron(A_REVERSE);
		move(_row / 2, _col / 2 - 2);
		printw("online mode");
		attroff(A_REVERSE);
		break;
	}
	refresh();
}