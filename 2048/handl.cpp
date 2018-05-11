#include <fstream>

using namespace std;

bool checkZero(int boardGame[][4])  // kiem tra ton tại vi tri o trong
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
void creCheck(int boardGame[][4], int boardCheck[][4])      // gan gia tri co mang kiem tra
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			boardCheck[i][j] = boardGame[i][j];
		}
	}
}
bool checkMove(int boardGame[][4], int boardCheck[][4])   // kiem tra co sư dich chuyen sau khi dieu khien hay khong
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (boardCheck[i][j] != boardGame[i][j]) return true;
		}
	}
	return false;
}
bool check_End_Game(int boardGame[][4]) // kiem tra ket thuc tro choi
{
    if (checkZero(boardGame) == true)
        return false;
	else if (checkZero(boardGame) == false)
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
