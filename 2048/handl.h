#ifndef HANDL_H
#define HANDL_H

bool checkZero(int boardGame[][4]);  // kiem tra ton tại vi tri o trong
void creCheck(int boardGame[][4], int boardCheck[][4]);      // gan gia tri co mang kiem tra
bool checkMove(int boardGame[][4], int boardCheck[][4]);   // kiem tra co sư dich chuyen sau khi dieu khien hay khong
bool check_End_Game(int boardGame[][4]); // kiem tra ket thuc tro choi

#endif // HANDL_H
