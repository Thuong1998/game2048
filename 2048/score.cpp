#include <fstream>

using namespace std;

int get_bestScore()  // lay gia tri diem cao
{
	int score;
	fstream fileScore;
	fileScore.open("score.txt", ios::in);
	fileScore >> score;
	fileScore.close();
	return score;
}
void write_bestScore(int score) // ghi diem cao vao file
{
	fstream fileScore;
	fileScore.open("score.txt", ios::out);
	fileScore << score;
	fileScore.close();
}
