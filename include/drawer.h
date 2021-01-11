#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <model.h>
#include <curses.h>

void draw(Snake *snake, FOOD *food);

void draw_(Snake *snake, FOOD *food);

void init_draw(int flag, int _row, int _col);

void debug_draw(Snake *snake, FOOD *food);

void game_over(int _row,int _col,Snake *snake);
void debug_(Snake *snake, FOOD *food);

void debug(int n);

#endif