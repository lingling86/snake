#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <model.h>
#include <curses.h>

void draw(Snake *snake, FOOD *food);

void debug_draw(Snake *snake, FOOD *food);

void game_over(Snake *snake);

void debug(int n);

#endif