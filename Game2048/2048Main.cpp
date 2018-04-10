#include "2048Funcition.cpp"
int main()
{
    introduction();
    Startgame();
    do{
        checklose=0;
        getkey();
        checkmatrix();
    }
    while(check==0||checkmatrix()==1);
    endgame();
}
