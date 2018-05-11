#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "handl.h"
#include "display.h"
#include "console.h"
using namespace std;

void add_Num(int boardGame[][4])      // ham khoi tao so ngau nhien
{
    srand(time(NULL));
    int potx,poty,ramdom;
    do
    {
        potx=rand()%4;
        poty=rand()%4;
    }
    while(boardGame[potx][poty]!=0);
    ramdom=rand()%100;
    if (ramdom<80)
        boardGame[potx][poty]=2;
    else
        boardGame[potx][poty]=4;
}
void turnup(int boardGame[][4], int &score)  //di chuyen cac o len tren
{
    int test=0;
    for(int q=0;q<3;q++)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<4;j++)
                if(boardGame[i][j]==0&&boardGame[i+1][j]!=0)
                {
                    test++;
                    boardGame[i][j]=boardGame[i+1][j];
                    boardGame[i+1][j]=0;
                }
    }
    for(int w=0;w<3;w++)
        for(int e=0;e<4;e++)
            if(boardGame[w][e]==boardGame[w+1][e]&&boardGame[w][e]!=0)
            {
                test++;
                boardGame[w][e]=boardGame[w][e]+boardGame[w+1][e];
                boardGame[w+1][e]=0;
                score=score+boardGame[w][e];
            }
    for(int r=0;r<3;r++)
        for(int t=0;t<4;t++)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r+1][t];
            boardGame[r+1][t]=0;
        }
}
void turnright(int boardGame[][4], int &score)  //di chuyen cac o ve ben phai
{
    for(int q=0;q<3;q++)
    {
        for(int i=0;i<4;i++)
            for(int j=3;j>0;j--)
                if(boardGame[i][j]==0&&boardGame[i][j-1]!=0)
                {
                    boardGame[i][j]=boardGame[i][j-1];
                    boardGame[i][j-1]=0;
                }
    }
    for(int w=0;w<4;w++)
        for(int e=3;e>0;e--)
            if(boardGame[w][e]==boardGame[w][e-1]&&boardGame[w][e]!=0)
            {
                boardGame[w][e]=boardGame[w][e]+boardGame[w][e-1];
                boardGame[w][e-1]=0;
                score=score+boardGame[w][e];
            }
    for(int r=0;r<4;r++)
        for(int t=3;t>0;t--)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r][t-1];
            boardGame[r][t-1]=0;
        }
}
void turnleft(int boardGame[][4], int &score)   // di chuyen cac o ve ben trai
{
    for(int q=0;q<3;q++)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<3;j++)
                if(boardGame[i][j]==0&&boardGame[i][j+1]!=0)
                {
                    boardGame[i][j]=boardGame[i][j+1];
                    boardGame[i][j+1]=0;
                }
    }
    for(int w=0;w<4;w++)
        for(int e=0;e<3;e++)
            if(boardGame[w][e]==boardGame[w][e+1]&&boardGame[w][e]!=0)
            {
                boardGame[w][e]=boardGame[w][e]+boardGame[w][e+1];
                boardGame[w][e+1]=0;
                score=score+boardGame[w][e];
            }
    for(int r=0;r<4;r++)
        for(int t=0;t<3;t++)
        if(boardGame[r][t]==0&&boardGame[r][t+1]!=0)
        {
            boardGame[r][t]=boardGame[r][t+1];
            boardGame[r][t+1]=0;
        }
}
void turndown(int boardGame[][4], int &score)   //di chuyen cac o xuong duoi
{
    for(int q=0;q<3;q++)
    {
        for(int i=3;i>0;i--)
            for(int j=0;j<4;j++)
                if(boardGame[i][j]==0&&boardGame[i-1][j]!=0)
                {
                    boardGame[i][j]=boardGame[i-1][j];
                    boardGame[i-1][j]=0;
                }
    }
    for(int w=3;w>0;w--)
        for(int e=0;e<4;e++)
            if(boardGame[w][e]==boardGame[w-1][e]&&boardGame[w][e]!=0)
            {
                boardGame[w][e]=boardGame[w][e]+boardGame[w-1][e];
                boardGame[w-1][e]=0;
                score=score+boardGame[w][e];
            }
    for(int r=3;r>0;r--)
        for(int t=0;t<4;t++)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r-1][t];
            boardGame[r-1][t]=0;
        }
}
void start_Game(int boardGame[][4], int &score)     // bat dau tro choi
{
    score=0;
    for(int i=0;i<2;i++)
        add_Num(boardGame);
    refill_Matrix(boardGame);
    refill_Score(score);
    show_Game();
}
void end_Game()   // ket thuc tro choi
{
    gotoXY(80,22);
    textColor(14);
    cout<<"Over!";
}
void get_Key(int boardGame[][4], int boardCheck[][4], int &score)  // dieu khien tro choi
{
    char c=_getch();
    if(c=='a'||c=='A'||c==75)
        turnleft(boardGame, score);
    else if(c=='d'||c=='D'||c==77)
        turnright(boardGame, score);
    else if(c=='w'||c=='W'||c==72)
        turnup(boardGame, score);
    else if(c=='s'||c=='S'||c==80)
        turndown(boardGame, score);
    else if(c=='r'||c=='R')
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                boardGame[i][j]=0;
            }
        start_Game(boardGame, score);
        creCheck(boardGame, boardCheck);
    }
    else if(c=='e'||c=='E')
    {
        end_Game();
        exit(0);
    }
    else
        get_Key(boardGame, boardCheck, score);
}
