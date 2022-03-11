#pragma once

#define  ROW  5
#define   COL   5

#include <stdio.h>

void menu();
void game();
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL], int row, int col);
int JudgeWinning(char board[ROW][COL],int row,int col);