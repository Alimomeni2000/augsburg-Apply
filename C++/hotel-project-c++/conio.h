//
// Created by Hassan on 11/26/2019.
//
#include <termios.h>
#include <stdio.h>

void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch(void);
char getche(void);
