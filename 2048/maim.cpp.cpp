#include "console.h"
#include "control.h"
#include "display.h"
#include "handl.h"
#include "score.h"

int main()
{
    int score;
    int boardGame[4][4]={0};
    int boardCheck[4][4];
    start_Game(boardGame, score);
    while(check_End_Game(boardGame) == false)
    {
        creCheck(boardGame, boardCheck);
        get_Key(boardGame, boardCheck, score);
        if( checkMove(boardGame, boardCheck) == true)
            add_Num(boardGame);
        refill_Matrix(boardGame);
        refill_Score(score);
    }
    end_Game();
}
