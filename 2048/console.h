#ifndef CONSOLE_H
#define CONSOLE_H

#define  black 0
#define navy 1
#define green 2
#define teal 3
#define maron 4
#define mediumorchid 5
#define olive 6
#define lightgray 7
#define dimgray 8
#define blue 9
#define chartreuse 10
#define aqua 11
#define red 12
#define magenta 13
#define yellow 14
#define white 15

void gotoXY(int column, int line);
void textColor(int color);
void clrScr();

#endif // CONSOLE_H
