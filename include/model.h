#ifndef _MODEL_H_
#define _MODEL_H_

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

#endif