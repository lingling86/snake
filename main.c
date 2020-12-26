#include <drawer.h>
#include <model.h>
#include <game.h>
#include <windows.h>

void key_down(Snake *snake);

int main()
{
	initscr();
	raw();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	init_snake(LINES, COLS);
	create_food(get_snake());

	while (1)
	{

		key_down(get_snake());
		eat_food(get_food(), get_snake());
		move_snake(get_snake());
		draw(get_snake(), get_food());
		if (!snake_die(get_snake()))
			break;
		Sleep(get_snake()->speed);
	}
	game_over(get_snake());
	endwin();
	return 0;
}

void key_down(Snake *snake)
{
	int ke = getch();
	if (ke == ERR)
		return;
	if (get_key() == _LEFT && ke == _RIGHT)
	{
		set_key(_LEFT);
		return;
	}
	if (get_key() == _UP && ke == _DOWN)
	{

		set_key(_UP);
		return;
	}

	if (get_key() == _DOWN && ke == _UP)
	{
		set_key(_DOWN);
		return;
	}
	if (get_key() == _RIGHT && ke == _LEFT)
	{
		set_key(_RIGHT);
		return;
	}
	set_key(ke);
}
