#include <windows.h>
#include <iostream>
#include "score.h"
#include "console.h"

using namespace std;

void show_Game()   // vẽ khung tro choi va huong dã tro choi
{
    textColor(red);
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
    gotoXY(5,16);
    cout<<"Press 'E' to end game";
    textColor(14);
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
    textColor(red);
    gotoXY(80,4);
    cout<<"Your score  :";
    gotoXY(80,6);
    cout<<"Best score  :";
}
void set_Color(int value)  //ham  cai dáº¡t mau cho tung gia trÃ­
{
	switch (value) {
	    case 0:     textColor(black);       	break;
        case 2:		textColor(white);       	break;
        case 4:		textColor(yellow);      	break;
        case 8:		textColor(magenta);     	break;
        case 16:	textColor(red);         	break;
        case 32:	textColor(aqua);        	break;
        case 64:	textColor(chartreuse);  	break;
        case 128:	textColor(blue);        	break;
        case 256:	textColor(dimgray);     	break;
        case 512:	textColor(olive);       	break;
        case 1024:  textColor(mediumorchid);    break;
        case 2048:  textColor(maron);          	break;
        case 4096:  textColor(teal);         	break;
        case 8192:  textColor(green);         	break;
        case 16384: textColor(navy);          	break;
	}
}
void refill_Matrix(int boardGame[][4])   // ham dien cac gia trá»‹ cua mang vao o
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            gotoXY(41+i*8,5+j*4);
            textColor(0);
            cout<<"       ";
        }
    for(int line = 0; line < 4 ; line++ )
        for(int column = 0; column < 4;column++ )
        {
                if(boardGame[line][column]<100)
                {
                    gotoXY(44+column*8,5+line*4);
                    set_Color(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<10000)
                {
                    gotoXY(43+column*8,5+line*4);
                    set_Color(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<1000000)
                {
                    gotoXY(42+column*8,5+line*4);
                    set_Color(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<100000000)
                {
                    gotoXY(41+column*8,5+line*4);
                    set_Color(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
                else if(boardGame[line][column]<10000000000)
                {
                    gotoXY(40+column*8,5+line*4);
                    set_Color(boardGame[line][column]);
                    cout<<boardGame[line][column];
                }
        }
}
void refill_Score(int &score)   // in ra diem cua tro chÆ¡i
{
    gotoXY(93,4);
    textColor(0);
    cout<<"          ";
    gotoXY(93,4);
    textColor(red);
    cout<<score;
    if (score > get_bestScore())
    {
		write_bestScore(score);
	}
    gotoXY(93,6);
    textColor(red);
    cout<<get_bestScore();
}
