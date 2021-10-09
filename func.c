//
// Created by Bobby on 2021/10/9.
//
#include <stdio.h>
void Player1Draw(int board[][19])
{
    printf("Player one Draw:");
    int x,y;
    scanf("%d %d",x,y);
    for(;;)
    {
        if (board[x][y]!=2)
        {
            board[x][y]=1;
            return;
        }
        else if(!((x>=0&&x<=19)&&(y>=0&&y<=19)))
        {
            printf("Bad input, try again\n");
            scanf("%d %d",x,y);
        }
    }
}
void Player2Draw(int board[][19])
{
    printf("Player two Draw:");
    int x,y;
    scanf("%d %d",x,y);
    for(;;)
    {
        if(board[x][y]!=1)
        {
            board[x][y] = 2;
            return;
        }
        else if(!((x>=0&&x<=19)&&(y>=0&&y<=19)))
        {
            printf("Bad input, try again\n");
            scanf("%d %d",x,y);
        }
    }
}

