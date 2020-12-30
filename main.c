#include <drawer.h>
#include <internet.h>
#include <model.h>
#include <stdlib.h>
#include <game.h>
#include <windows.h>

WSADATA wsaData;
static DWORD last = 0;
static DWORD cur;

void key_down(Snake *snake);

int main()
{
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	int cmd = 0;
	scanf("%d", &cmd);

	initscr();
	raw();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	init_snake(LINES, COLS);
	create_food(get_snake());

	if (cmd == 1)
	{
		createroom();
	}
	else if (cmd == 2)
	{
		connectroom();
	}

	while (1)
	{
		key_down(get_snake());
		cur = GetTickCount();
		if (cur - last > get_snake()->speed)
		{
			last = cur;
			move_snake(get_snake());
			mutl tmp = get_player_info();
			clear();
			draw(get_snake(), get_food());
			draw(&tmp.snake, &tmp.food);
			refresh();
		}
		eat_food(get_food(), get_snake());
		con();
		if (!snake_die(get_snake()))
			break;
	}
	WSACleanup();
	game_over(LINES, COLS, get_snake());
	Sleep(5000);
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