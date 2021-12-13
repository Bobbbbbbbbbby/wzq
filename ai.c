//
// Created by Bobby on 2021/12/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define Zero 0
#define Ninety 90
#define Down 135
#define Up 45
//Down用来表示135度，因为从左向右看是向下的，45度同理
#define SIZE 15
#define Width 15
#define Height 15

struct place{
    int x;
    int y;
};

//规定，开始的棋子总是左上角；
struct SingleCoin{
    int color;
    struct place Coin;
};
//规定，用Live i来表示气的位置，如果出现都是负值，那么是死的。
struct DoubleCoin{
    int color;
    int direction;
    struct place StartCoin;
    struct place EndCoin;
    struct place Live1;
    struct place Live2;
};

struct TripleCoin{
    int color;
    int direction;
    struct place StartCoin;
    struct place EndCoin;
    struct place Live1;
    struct place Live2;
};

struct QuaCoin{
    int color;
    int direction;
    struct place StartCoin;
    struct place EndCoin;
    struct place Live1;
    struct place Live2;
};

int Vertical(int board[][Height],int x,int y);
int Horizontal(int board[][Height],int x,int y);
int An45(int board[][Height],int x,int y);
int An135(int board[][Height],int x,int y);

void AIDrawBlack(int board[][Height],int new[])
{

}

void AIDrawWhite(int board[][Height],int new[])
{
    struct SingleCoin
    for(int x;x<Width;x++)
    {
        for(int y;y<Height;y++)
        {
            int verticalNum= Vertical(board,x,y);
            int horizontalNum=Vertical(board,x,y);
            int an45Num= An45(board,x,y);
            int an135Num= An135(board,x,y);
            if(verticalNum==4||horizontalNum==4||an45Num==4||an135Num==4)
            {

            }
        }
    }
}
//扫描棋盘确定所有的单点和连线的情况