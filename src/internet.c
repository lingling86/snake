#include <internet.h>

SOCKET s;
SOCKADDR_IN recvAddr; // for server, it is the address which is binded to
SOCKADDR_IN sendAddr; // address to send and receive message
int sendSize = sizeof(sendAddr);

static mutl player;

void createroom()
{
    s = socket(AF_INET, SOCK_DGRAM, 0);
    unsigned long Opt = 1;
    ioctlsocket(s, FIONBIO, &Opt);
    recvAddr.sin_family = AF_INET;
    recvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    recvAddr.sin_port = htons(4100);
    int state = bind(s, (SOCKADDR *)&recvAddr, sizeof(recvAddr));
    int tmp = 0;
    while (1)
    {
        // establish the connection
        recvfrom(s, (char *)&tmp, sizeof(tmp), 0, (SOCKADDR *)&sendAddr, &sendSize);
        if (tmp == 1)
            break;
    }
    state = WSAGetLastError();
}

void connectroom()
{
    s = socket(AF_INET, SOCK_DGRAM, 0);
    unsigned long Opt = 1;
    ioctlsocket(s, FIONBIO, &Opt);
    sendAddr.sin_family = AF_INET;
    sendAddr.sin_addr.s_addr = inet_addr("192.168.43.4");
    sendAddr.sin_port = htons(4100);
    int tmp = 1;
    sendto(s, (char *)&tmp, sizeof(tmp), 0, (SOCKADDR *)&sendAddr, sendSize);
    int a = GetLastError();
}

void con()
{
    mutl p;
    p.snake = *get_snake();
    p.food = *get_food();
    sendto(s, (char *)&p, sizeof(p), 0, (SOCKADDR *)&sendAddr, sendSize);
    recvfrom(s, (char *)&player, 20000, 0, (SOCKADDR *)&sendAddr, &sendSize);
}

mutl get_player_info()
{
    return player;
}