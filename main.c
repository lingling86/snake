#include <drawer.h>
#include <internet.h>
#include <model.h>
#include <stdlib.h>
#include <game.h>
#include <windows.h>
#ifdef _WIN32
#define COLOR "color e1"
#elif _Linux_
#define COLOR "PS1='[\[\e[32;40m\]\u@\h \w \t]$ \[\e[0m\]'"
#endif

WSADATA wsaData;
static DWORD last = 0;
static DWORD cur;
mutl tmp;
int ll = 0;

void key_down(Snake *snake);

int main()
{
	WSAStartup(MAKEWORD(2, 2), &wsaData);//使用Winsock库函数之前,必须先调用函数WSAStartup,该函数负责初始化动态连接库Ws2_32.dll.
	system(COLOR);
	initscr();
	raw();//无回车下的直接传输键盘的输入
	nodelay(stdscr, TRUE);//让程序变为不阻塞的，getch在无输入的时候返回ERR，即-1.
	keypad(stdscr, TRUE);//可获得功能键
	// noecho();
	curs_set(0);//光标不可见

	while (1)
	{
		int hm = load();
		if (hm == 5)
			break;
		else
			ll = hm;
		init_draw(hm, LINES, COLS);
	}
	clear();
	if (ll == 0)
	{
		init_snake(LINES, COLS);
		// init_snake(120, 60);
		create_food(get_snake());

		while (1)
		{
			key_down(get_snake());
			cur = GetTickCount();
			if (cur - last > get_snake()->speed)
			{
				last = cur;
				move_snake(get_snake());
				clear();
				// debug_draw(get_snake(), get_food());
				// debug_draw(&tmp.snake, &tmp.food);
				draw(get_snake(), get_food());
				refresh();
			}
			eat_food(get_food(), get_snake());
			// init_draw(LINES, COLS);
			if (!snake_die(get_snake()))
				break;
		}
	}
	else
	{
		// tmp.snake.x[0]=30;
		// tmp.snake.y[0]=60;
		init_snake(LINES, COLS);
		// init_snake(120, 60);
		create_food(get_snake());
		int cmd = 0;
		printw("please enter the player number\n");
		scanw("%d", &cmd);
		if (cmd == 1)
		{
			createroom();
		}
		else if (cmd == 2)
		{
			char sl[20];
			printw("please enter the IP address of player 1\n");
			getstr(sl);
			connectroom(sl);
		}

		while (1)
		{
			key_down(get_snake());
			cur = GetTickCount();
			if (cur - last > get_snake()->speed)
			{
				last = cur;
				move_snake(get_snake());
				tmp = get_player_info();
				clear();
				// debug_draw(get_snake(), get_food());
				// debug_(&tmp.snake, &tmp.food);
				draw(get_snake(), get_food());
				draw_(&tmp.snake, &tmp.food);
				refresh();
			}
			eat_food(get_food(), get_snake());
			// init_draw(LINES, COLS);
			con();
			if (!snake_die(get_snake()))
				break;
			if (!snake_die(&tmp.snake))
				break;
		}
		WSACleanup();
	}
	game_over(LINES, COLS, get_snake());
	Sleep(3000);
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