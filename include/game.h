#ifndef _GAME_H_
#define _GAME_H_

#include <model.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _LEFT 260
#define _RIGHT 261
#define _UP 259
#define _DOWN 258

void move_snake(Snake *snake);

void eat_food(FOOD *food, Snake *snake);

int snake_die(Snake *snake);

void init_snake(int _row, int _col);

void create_food(Snake *snake);

int load();

Snake *get_snake();

FOOD *get_food();

void key_down(Snake *snake);

void set_key(int k);

int get_key();

#endif