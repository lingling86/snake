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
	unsigned short x;
	unsigned short y;
	unsigned short prop;
} FOOD;

typedef struct
{
	unsigned short x[200];
	unsigned short y[200];
	unsigned short count;
	unsigned short speed;
	unsigned short len;
} Snake;

typedef struct
{	
	Snake snake;
	FOOD food;
} mutl;

#endif