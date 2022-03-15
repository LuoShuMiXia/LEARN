#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define MINE 80

void menu();
void game();
void initboard(char mine[ROWS][COLS], int rows, int cols, char x);
void board(char show[ROWS][COLS], int row, int col);
void setMine(char mine[ROWS][COLS], int row, int col, int x);
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int numMine(char mine[ROWS][COLS],  int x, int y);
