#ifndef CONTROL_H
#define CONTROL_H

void add_Num(int boardGame[][4]);      // ham khoi tao so ngau nhien
void turnup(int boardGame[][4], int &score);  //di chuyen cac o len tren
void turnright(int boardGame[][4], int &score);  //di chuyen cac o ve ben phai
void turnleft(int boardGame[][4], int &score);   // di chuyen cac o ve ben tra
void turndown(int boardGame[][4], int &score);   //di chuyen cac o xuong duoi
void get_Key(int boardGame[][4], int boardCheck[][4], int &score);  // dieu khien tro choi
void start_Game(int boardGame[][4], int &score);     // bat dau tro choi
void end_Game();   // ket thuc tro choi

#endif // CONTROL_H
