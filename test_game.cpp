#include<iostream>
#include <cstdio>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
int black=0,blue=9,chartreuse=10,aqua=11,red=12,magenta=13,yellow=14,white=15;
int score;
int boardGame[4][4]={0};
int boardCheck[4][4];
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void clrScr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void show_Game()
{
    TextColor(red);
    gotoXY(5,4);
    cout<<"How to play:";
    gotoXY(5,6);
    cout<<"Press 'A' to turn left";
    gotoXY(5,8);
    cout<<"Press 'D' to turn right";
    gotoXY(5,10);
    cout<<"Press 'W' to go up";
    gotoXY(5,12);
    cout<<"Press 'S' to go down";
    gotoXY(5,14);
    cout<<"Press 'R' to restart";
    TextColor(14);
    for(int line=0;line<=16;line++)
        for(int column=0;column<=32;column++)
        {
            if(line==0&&column==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(201);
            }
            else if(line==16&&column==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(200);
            }
            else if(line==0&&column==32)
            {
                gotoXY(column+40,line+3);
                cout<<char(187);

            }
            else if(line==16&&column==32)
            {
                gotoXY(column+40,line+3);
                cout<<char(188);
            }
            else if(line%4==0&&column==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(199);
            }
            else if(line%4==0&&column==32)
            {
                gotoXY(column+40,line+3);
                cout<<char(182);
            }
            else if(line==0&&column%8==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(209);
            }
            else if(line==16&&column%8==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(207);
            }
            else if(line%4==0&&column%8==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(197);
            }
            else if(line==0||line==16)
            {
                gotoXY(column+40,line+3);
                cout<<char(205);
            }
            else if(line%4==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(196);
            }
            else if(column==0||column==32)
            {
                gotoXY(column+40,line+3);
                cout<<char(186);
            }
            else if(column%8==0)
            {
                gotoXY(column+40,line+3);
                cout<<char(179);
            }
        }
    TextColor(red);
    gotoXY(80,4);
    cout<<"Your score  :";
    gotoXY(80,6);
    cout<<"Best score  :";
}
bool checkZero()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (boardGame[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}
void creCheck()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			boardCheck[i][j] = boardGame[i][j];
		}
	}
}

bool checkMove()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (boardCheck[i][j] != boardGame[i][j]) return true;
		}
	}
	return false;
}

bool check_End_Game()
{
    if (checkZero() == true)
        return false;
	else if (checkZero() == false)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (boardGame[i][j] == boardGame[i][j + 1])
					return false;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (boardGame[i][j] == boardGame[i + 1][j])
					return false;
			}
		}
	}
	return true;
}
void add_Num()
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
void setColor(int value)
{
	switch (value) {
	    case 0:     TextColor(black);       break;
        case 2:		TextColor(white);       break;
        case 4:		TextColor(yellow);      break;
        case 8:		TextColor(magenta);     break;
        case 16:	TextColor(red);         break;
        case 32:	TextColor(aqua);        break;
        case 64:	TextColor(chartreuse);  break;
        case 128:	TextColor(blue);        break;
        case 256:	TextColor(8);          break;
        case 512:	TextColor(7);          break;
        case 1024:  TextColor(6);          break;
        case 2048:  TextColor(5);          break;
        case 4096:  TextColor(4);          break;
        case 8192:  TextColor(3);          break;
        case 16384: TextColor(2);          break;
	}
}
void refill_Matrix()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            gotoXY(41+i*8,5+j*4);
            TextColor(0);
            cout<<"       ";
        }
    for(int line = 0; line < 4 ; line++ )
        for(int column = 0; column < 4;column++ )
        {
                if(boardGame[line][column]<100)
                {
                    gotoXY(44+column*8,5+line*4);
                    setColor(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<10000)
                {
                    gotoXY(43+column*8,5+line*4);
                    setColor(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<1000000)
                {
                    gotoXY(42+column*8,5+line*4);
                    setColor(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<100000000)
                {
                    gotoXY(41+column*8,5+line*4);
                    setColor(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<10000000000)
                {
                    gotoXY(40+column*8,5+line*4);
                    setColor(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
        }
}
void write_bestScore(int score)
{
	fstream fileScore;
	fileScore.open("score.txt", ios::out);
	fileScore << score;
	fileScore.close();
}
int get_bestScore()
{
	int score;
	fstream fileScore;
	fileScore.open("score.txt", ios::in);
	fileScore >> score;
	fileScore.close();
	return score;
}
void refill_Score()
{
    gotoXY(93,4);
    TextColor(0);
    cout<<"          ";
    gotoXY(93,4);
    TextColor(red);
    cout<<score;
    if (score > get_bestScore())
    {
		write_bestScore(score);
	}
    gotoXY(93,6);
    TextColor(red);
    cout<<get_bestScore();
}
void start_Game()
{
    for(int i=0;i<2;i++)
        add_Num();
    refill_Matrix();
    refill_Score();
    show_Game();
}
void turnleft()
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
void turnright()
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
void turnup()
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
void turndown()
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
void end_Game()
{
    gotoXY(80,22);
    TextColor(14);
    cout<<"Over!";
}
void get_Key()
{
    char c=_getch();
    if(c=='a'||c=='A'||c==75)
        turnleft();
    else if(c=='d'||c=='D'||c==77)
        turnright();
    else if(c=='w'||c=='W'||c==72)
        turnup();
    else if(c=='s'||c=='S'||c==80)
        turndown();
    else if(c=='r'||c=='R')
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                boardGame[i][j]=0;
            }
        start_Game();
        creCheck();
    }
    else
        get_Key();
}
int main()
{
    start_Game();
    while(check_End_Game() == false)
    {
        creCheck();
        get_Key();
        if( checkMove() == true)
            add_Num();
        refill_Matrix();
        refill_Score();
    }
    end_Game();
}
