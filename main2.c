#include <winsock2.h>

#define PROP_NUM 2

enum
{
	DEFAULT,
	SPEED
};

typedef struct
{
	int x;
	int y;
	int prop;
} FOOD;

typedef struct
{
	int x[200];
	int y[200];
	int count;
	int speed;
	int len;
} Snake;

typedef struct
{	
	Snake snake;
	FOOD food;
} mutl;

SOCKET s;
SOCKADDR_IN dest;
WSADATA wsaData;
mutl player_O;

void key_down(Snake *snake);

int main()
{
	WSAStartup(MAKEWOED(2, 2), &wsaData);
	s = socket(AF_INET, SOCK_DGRAM, 0);
	unsigned long Opt = 1;
	ioctlsocket(0, FIONBIO, &Opt);
	dest.sin_family = AF_INET;
	dest.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	dest.sin_port = htons(4100);
	int state = connect(s, (SOCKADDR *)&dest, sizeof(dest));
	player_O.snake.x[0] = 3;
	player_O.snake.x[1] = 2;
	player_O.snake.x[2] = 1;
	player_O.snake.y[0] = 6;
	player_O.snake.y[1] = 6;
	player_O.snake.y[2] = 6;
	char *q = (char *)&player_O;
	send(s, q, sizeof(player_O), 0);
	return 0;
}