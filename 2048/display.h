#ifndef DISPLAY_H
#define DISPLAY_H

void show_Game(); // vẽ khung tro choi va huong dã tro choi
void set_Color(int value);  //ham  cai dạt mau cho tung gia tr�
void refill_Matrix(int boardGame[][4]);   // ham dien cac gia trị cua mang vao o
void refill_Score(int &score);   // in ra diem cua tro chơi

#endif // DISPLAY_H
