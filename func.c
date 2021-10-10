//
// Created by Bobby on 2021/10/9.
//
#include <stdio.h>
int Vertical(int board[][19],int x,int y);
int Horizontal(int board[][19],int x,int y);
int An45(int board[][19],int x,int y);
int An135(int board[][19],int x,int y);


void Player1Draw(int board[][19])
{
    printf("Player one Draw:");
    int x,y;
    scanf("%d %d",&x,&y);
    for(;;)
    {
        if(!((x>=0&&x<=19)&&(y>=0&&y<=19)))
        {
            printf("Bad input, try again\n");
            scanf("%d %d",&x,&y);
        }
        if (board[x][y]!=0)
        {
            printf("Bad input, try again\n");
            scanf("%d %d",&x,&y);
        }
        else
        {
            board[x][y]=1;
            return;
        }

    }
}//Let player 1 put a coin
void Player2Draw(int board[][19])
{

    printf("Player two Draw:");
    int x,y;
    scanf("%d %d",&x,&y);
    for(;;)
    {
        if(!((x>=0&&x<=19)&&(y>=0&&y<=19)))
        {
            printf("Bad input, try again\n");
            scanf("%d %d",&x,&y);
        }
        if (board[x][y]!=0)
        {
            printf("Bad input, try again\n");
            scanf("%d %d",&x,&y);
        }
        else
        {
            board[x][y]=2;
            return;
        }
    }
}//Let player 2 put a coin


int Vertical(int board[][19],int x,int y)
{
    int color=board[x][y];
    int number=1;
    for(int xChange=x-1;board[xChange][y]==color&&xChange>=0;xChange-=1)
        number+=1;
    for(int xChange=x+1;board[xChange][y]==color&&xChange<=18;xChange+=1)
        number+=1;
    return number;
}//Check how many coins of the same color in the same volume
int Horizontal(int board[][19],int x,int y)
{
    int color=board[x][y];
    int number=1;
    for(int yChange=y-1;yChange>=0&&board[x][yChange]==color;yChange--)
        number+=1;
    for(int yChange=y+1;yChange<=18&&board[x][yChange]==color;yChange++)
        number+=1;
    return number;
}//Check how many coins of the same color in the same line
int An45(int board[][19],int x,int y)
{
    int color=board[x][y];
    int number=1;
    for(int i=1;(x-i)>=0&&(y-i)>=0&&board[x-i][y-i]==color;i++)
        number+=1;
    for(int i=1;(x-i)<=18&&(y-i)<=18&&board[x+i][y+i]==color;i++)
        number+=1;
    return number;
}//Check how many coins of the same color in the angle 45 degrees
int An135(int board[][19],int x,int y)
{
    int color=board[x][y];
    int number=1;
    for(int i=1;(x-i)>=0&&(y+i)<=18&&board[x-i][y+i]==color;i++)
        number+=1;
    for(int i=1;(x+i)<=18&&(y-i)>=0&&board[x+1][y-1]==color;i++)
        number+=1;
    return number;
}//Check how many coins of the same color int the angle of 135 degrees


int Check(int board[][19])
{
    for(int x=0;x<19;x++)
    {
        for(int y=0;y<19;y++)
        {
            if(board[x][y]==0)
                continue;
            else if(board[x][y]==1)
            {
                int vertical= Vertical(board,x,y);
                int horizontal= Horizontal(board,x,y);
                int an45= An45(board,x,y);
                int an135= An135(board,x,y);
                if(vertical>=5||horizontal>=5||an45>=5||an135>=5)
                    return 1;
                else
                    continue;
            }
            else if(board[x][y]==2)
            {
                int vertical= Vertical(board,x,y);
                int horizontal= Horizontal(board,x,y);
                int an45= An45(board,x,y);
                int an135= An135(board,x,y);
                if(vertical>=5||horizontal>=5||an45>=5||an135>=5)
                    return 2;
                else
                    continue;
            }
        }
    }
    return 0;
}

