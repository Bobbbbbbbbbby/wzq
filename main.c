#include <stdio.h>
#define Width 20
#define Height 20
int main()
{
    int board[Width][Height];
    for(int i=0;i<Width;i++)
    {
        for(int j=0;j<Height;j++)
            board[i][j]=0;
    }
}