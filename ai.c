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

struct place
{
    int x;
    int y;
};

//规定，Live1总是左边；
struct SingleCoin
{
    int color;
    struct place Coin;
    struct place Live1;
    struct place Live2;
    struct place Live3;
    struct place Live4;
};
//规定，用Live i来表示气的位置，如果出现都是负值，那么是死的。
struct DoubleCoin
{
    int color;
    int direction;
    struct place Live1;
    struct place Live2;
};

struct TripleCoin
{
    int color;
    int direction;
    struct place Live1;
    struct place Live2;
};

struct QuaCoin
{
    int color;
    int direction;
    struct place Live1;
    struct place Live2;
};

int Vertical(int board[][Height], int x, int y);

int Horizontal(int board[][Height], int x, int y);

int An45(int board[][Height], int x, int y);

int An135(int board[][Height], int x, int y);

void AIDrawBlack(int board[][Height], int new[])
{

}

void AIDrawWhite(int board[][Height], int new[])
{
    struct SingleCoin setOfBlackSingle[100];
    int blackSingleCoinCounter = 0;
    struct DoubleCoin setOfBlackDouble[100];
    int blackDoubleCoinCounter = 0;
    struct TripleCoin setOfBlackTriple[100];
    int blackTripleCoinCounter = 0;
    struct QuaCoin setOfBlackQua[100];
    int blackQuaCoinCounter = 0;
    struct SingleCoin setOfWhiteSingle[100];
    int whiteSingleCoinCounter = 0;
    struct DoubleCoin setOfWhiteDouble[100];
    int whiteDoubleCoinCounter = 0;
    struct TripleCoin setOfWhiteTriple[100];
    int whiteTripleCoinCounter = 0;
    struct QuaCoin setOfWhiteQua[100];
    int whiteQuaCoinCounter = 0;
    for (int x; x < Width; x++)
    {
        for (int y; y < Height; y++)
        {
            if (board[x][y] == 1)
            {
                int verticalNum = Vertical(board, x, y);
                int horizontalNum = Horizontal(board, x, y);
                int an45Num = An45(board, x, y);
                int an135Num = An135(board, x, y);
                if (verticalNum == 4 || horizontalNum == 4 || an45Num == 4 || an135Num == 4)
                {
                    struct QuaCoin temp[4];
                    //0号元素储存垂直，1号元素储存水平，2号元素储存斜向上，3号元素储存斜向下，color=-1代表不是4
                    if (verticalNum == 4)
                    {
                        temp[0].color = board[x][y];
                        temp[0].direction = Zero;

                        int i = 1;
                        while (y + i < Height && board[x][y + i] == board[x][y])
                            i++;
                        if (y + i < Height && board[x][y + i] == 0)
                        {
                            temp[0].Live1.x = x;
                            temp[0].Live1.y = y + i;
                        } else//死棋
                        {
                            temp[0].Live1.x = -1;
                            temp[0].Live1.y = -1;
                        }
                        int j = 1;
                        while (y - j > 0 && board[x][y - j] == board[x][y])
                            j++;
                        if (y - j > 0 && board[x][y - j] == 0)
                        {
                            temp[0].Live2.x = x;
                            temp[0].Live2.y = y - j;
                        } else//死棋
                        {
                            temp[0].Live2.x = -1;
                            temp[0].Live2.y = -1;
                        }
                    } else
                    {
                        temp[0].color = -1;
                    }

                    if (horizontalNum == 4)
                    {
                        temp[1].color = board[x][y];
                        temp[1].direction = Ninety;

                        int i = 1;
                        while (x + i < Width && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && board[x + i][y] == 0)
                        {
                            temp[1].Live2.x = x + i;
                            temp[1].Live2.y = y;
                        } else//死棋
                        {
                            temp[1].Live2.x = -1;
                            temp[1].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && board[x - j][y] == 0)
                        {
                            temp[1].Live1.x = x - j;
                            temp[1].Live1.y = y;
                        } else//死棋
                        {
                            temp[1].Live1.x = -1;
                            temp[1].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an45Num == 4)
                    {
                        temp[2].color = board[x][y];
                        temp[2].direction = Up;

                        int i = 1;
                        while (x + i < Width && y + i < Height && board[x + i][y + i] == board[x][y])
                            i++;
                        if (x + i < Width && y + i < Height && board[x + i][y + i] == 0)
                        {
                            temp[2].Live2.x = x + i;
                            temp[2].Live2.y = y + i;
                        } else//死棋
                        {
                            temp[2].Live2.x = -1;
                            temp[2].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y - j > 0 && board[x - j][y - j] == board[x][y])
                            j++;
                        if (x - j > 0 && y - j > 0 && board[x - j][y - j] == 0)
                        {
                            temp[2].Live1.x = x - j;
                            temp[2].Live1.y = y - j;
                        } else//死棋
                        {
                            temp[2].Live1.x = -1;
                            temp[2].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an135Num == 4)
                    {
                        temp[3].color = board[x][y];
                        temp[3].direction = Down;

                        int i = 1;
                        while (x + i < Width && y - i > 0 && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && y - i > 0 && board[x + i][y] == 0)
                        {
                            temp[3].Live2.x = x + i;
                            temp[3].Live2.y = y - i;
                        } else//死棋
                        {
                            temp[3].Live2.x = -1;
                            temp[3].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y + j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && y + j > 0 && board[x - j][y] == 0)
                        {
                            temp[3].Live1.x = x - j;
                            temp[3].Live1.y = y;
                        } else//死棋
                        {
                            temp[3].Live1.x = -1;
                            temp[3].Live1.y = -1;
                        }
                    } else
                    {
                        temp[3].color = -1;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int isTheSame = 0;
                        for (int i = 0; i < blackQuaCoinCounter; i++)
                        {
                            if (temp[j].color == setOfBlackQua[i].color &&
                                temp[j].direction == setOfBlackQua[i].direction &&
                                temp[j].Live1.x == setOfBlackQua[i].Live1.x &&
                                temp[j].Live2.x == setOfBlackQua[i].Live2.x &&
                                temp[j].Live2.y == setOfBlackQua[i].Live2.y &&
                                temp[j].Live1.y == setOfBlackQua[i].Live1.y)
                                isTheSame = 1;
                        }
                        if (isTheSame == 0)
                        {
                            setOfBlackQua[blackQuaCoinCounter] = temp[j];
                            blackQuaCoinCounter++;
                        }
                    }

                } else if (verticalNum == 3 || horizontalNum == 3 || an45Num == 3 || an135Num == 3)
                {
                    struct TripleCoin temp[4];
                    //0号元素储存垂直，1号元素储存水平，2号元素储存斜向上，3号元素储存斜向下，color=-1代表不是4
                    if (verticalNum == 3)
                    {
                        temp[0].color = board[x][y];
                        temp[0].direction = Zero;

                        int i = 1;
                        while (y + i < Height && board[x][y + i] == board[x][y])
                            i++;
                        if (y + i < Height && board[x][y + i] == 0)
                        {
                            temp[0].Live1.x = x;
                            temp[0].Live1.y = y + i;
                        } else//死棋
                        {
                            temp[0].Live1.x = -1;
                            temp[0].Live1.y = -1;
                        }
                        int j = 1;
                        while (y - j > 0 && board[x][y - j] == board[x][y])
                            j++;
                        if (y - j > 0 && board[x][y - j] == 0)
                        {
                            temp[0].Live2.x = x;
                            temp[0].Live2.y = y - j;
                        } else//死棋
                        {
                            temp[0].Live2.x = -1;
                            temp[0].Live2.y = -1;
                        }
                    } else
                    {
                        temp[0].color = -1;
                    }

                    if (horizontalNum == 3)
                    {
                        temp[1].color = board[x][y];
                        temp[1].direction = Ninety;

                        int i = 1;
                        while (x + i < Width && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && board[x + i][y] == 0)
                        {
                            temp[1].Live2.x = x + i;
                            temp[1].Live2.y = y;
                        } else//死棋
                        {
                            temp[1].Live2.x = -1;
                            temp[1].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && board[x - j][y] == 0)
                        {
                            temp[1].Live1.x = x - j;
                            temp[1].Live1.y = y;
                        } else//死棋
                        {
                            temp[1].Live1.x = -1;
                            temp[1].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an45Num == 3)
                    {
                        temp[2].color = board[x][y];
                        temp[2].direction = Up;

                        int i = 1;
                        while (x + i < Width && y + i < Height && board[x + i][y + i] == board[x][y])
                            i++;
                        if (x + i < Width && y + i < Height && board[x + i][y + i] == 0)
                        {
                            temp[2].Live2.x = x + i;
                            temp[2].Live2.y = y + i;
                        } else//死棋
                        {
                            temp[2].Live2.x = -1;
                            temp[2].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y - j > 0 && board[x - j][y - j] == board[x][y])
                            j++;
                        if (x - j > 0 && y - j > 0 && board[x - j][y - j] == 0)
                        {
                            temp[2].Live1.x = x - j;
                            temp[2].Live1.y = y - j;
                        } else//死棋
                        {
                            temp[2].Live1.x = -1;
                            temp[2].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an135Num == 3)
                    {
                        temp[3].color = board[x][y];
                        temp[3].direction = Down;

                        int i = 1;
                        while (x + i < Width && y - i > 0 && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && y - i > 0 && board[x + i][y] == 0)
                        {
                            temp[3].Live2.x = x + i;
                            temp[3].Live2.y = y - i;
                        } else//死棋
                        {
                            temp[3].Live2.x = -1;
                            temp[3].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y + j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && y + j > 0 && board[x - j][y] == 0)
                        {
                            temp[3].Live1.x = x - j;
                            temp[3].Live1.y = y;
                        } else//死棋
                        {
                            temp[3].Live1.x = -1;
                            temp[3].Live1.y = -1;
                        }
                    } else
                    {
                        temp[3].color = -1;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int isTheSame = 0;
                        for (int i = 0; i < blackTripleCoinCounter; i++)
                        {
                            if (temp[j].color == setOfBlackTriple[i].color &&
                                temp[j].direction == setOfBlackTriple[i].direction &&
                                temp[j].Live1.x == setOfBlackTriple[i].Live1.x &&
                                temp[j].Live2.x == setOfBlackTriple[i].Live2.x &&
                                temp[j].Live2.y == setOfBlackTriple[i].Live2.y &&
                                temp[j].Live1.y == setOfBlackTriple[i].Live1.y)
                                isTheSame = 1;
                        }
                        if (isTheSame == 0)
                        {
                            setOfBlackTriple[blackTripleCoinCounter] = temp[j];
                            blackTripleCoinCounter++;
                        }
                    }

                } else if (verticalNum == 2 || horizontalNum == 2 || an45Num == 2 || an135Num == 2)
                {
                    struct DoubleCoin temp[4];
                    //0号元素储存垂直，1号元素储存水平，2号元素储存斜向上，3号元素储存斜向下，color=-1代表不是4
                    if (verticalNum == 2)
                    {
                        temp[0].color = board[x][y];
                        temp[0].direction = Zero;

                        int i = 1;
                        while (y + i < Height && board[x][y + i] == board[x][y])
                            i++;
                        if (y + i < Height && board[x][y + i] == 0)
                        {
                            temp[0].Live1.x = x;
                            temp[0].Live1.y = y + i;
                        } else//死棋
                        {
                            temp[0].Live1.x = -1;
                            temp[0].Live1.y = -1;
                        }
                        int j = 1;
                        while (y - j > 0 && board[x][y - j] == board[x][y])
                            j++;
                        if (y - j > 0 && board[x][y - j] == 0)
                        {
                            temp[0].Live2.x = x;
                            temp[0].Live2.y = y - j;
                        } else//死棋
                        {
                            temp[0].Live2.x = -1;
                            temp[0].Live2.y = -1;
                        }
                    } else
                    {
                        temp[0].color = -1;
                    }

                    if (horizontalNum == 2)
                    {
                        temp[1].color = board[x][y];
                        temp[1].direction = Ninety;

                        int i = 1;
                        while (x + i < Width && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && board[x + i][y] == 0)
                        {
                            temp[1].Live2.x = x + i;
                            temp[1].Live2.y = y;
                        } else//死棋
                        {
                            temp[1].Live2.x = -1;
                            temp[1].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && board[x - j][y] == 0)
                        {
                            temp[1].Live1.x = x - j;
                            temp[1].Live1.y = y;
                        } else//死棋
                        {
                            temp[1].Live1.x = -1;
                            temp[1].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an45Num == 2)
                    {
                        temp[2].color = board[x][y];
                        temp[2].direction = Up;

                        int i = 1;
                        while (x + i < Width && y + i < Height && board[x + i][y + i] == board[x][y])
                            i++;
                        if (x + i < Width && y + i < Height && board[x + i][y + i] == 0)
                        {
                            temp[2].Live2.x = x + i;
                            temp[2].Live2.y = y + i;
                        } else//死棋
                        {
                            temp[2].Live2.x = -1;
                            temp[2].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y - j > 0 && board[x - j][y - j] == board[x][y])
                            j++;
                        if (x - j > 0 && y - j > 0 && board[x - j][y - j] == 0)
                        {
                            temp[2].Live1.x = x - j;
                            temp[2].Live1.y = y - j;
                        } else//死棋
                        {
                            temp[2].Live1.x = -1;
                            temp[2].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an135Num == 2)
                    {
                        temp[3].color = board[x][y];
                        temp[3].direction = Down;

                        int i = 1;
                        while (x + i < Width && y - i > 0 && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && y - i > 0 && board[x + i][y] == 0)
                        {
                            temp[3].Live2.x = x + i;
                            temp[3].Live2.y = y - i;
                        } else//死棋
                        {
                            temp[3].Live2.x = -1;
                            temp[3].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y + j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && y + j > 0 && board[x - j][y] == 0)
                        {
                            temp[3].Live1.x = x - j;
                            temp[3].Live1.y = y;
                        } else//死棋
                        {
                            temp[3].Live1.x = -1;
                            temp[3].Live1.y = -1;
                        }
                    } else
                    {
                        temp[3].color = -1;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int isTheSame = 0;
                        for (int i = 0; i < blackDoubleCoinCounter; i++)
                        {
                            if (temp[j].color == setOfBlackDouble[i].color &&
                                temp[j].direction == setOfBlackDouble[i].direction &&
                                temp[j].Live1.x == setOfBlackDouble[i].Live1.x &&
                                temp[j].Live2.x == setOfBlackDouble[i].Live2.x &&
                                temp[j].Live2.y == setOfBlackDouble[i].Live2.y &&
                                temp[j].Live1.y == setOfBlackDouble[i].Live1.y)
                                isTheSame = 1;
                        }
                        if (isTheSame == 0)
                        {
                            setOfBlackDouble[blackDoubleCoinCounter] = temp[j];
                            blackDoubleCoinCounter++;
                        }
                    }

                } else if (verticalNum == 1 && horizontalNum == 1 && an45Num == 1 && an135Num == 1)
                {

                    if(x>0&&board[x-1][y]==0)
                    {
                        setOfBlackSingle[blackSingleCoinCounter].Live1.x=x-1;
                        setOfBlackSingle[blackSingleCoinCounter].Live2.y=y;
                    }
                    else if(x>0&&board[x-1][y
                    ]==0)
                    {
                        setOfBlackSingle[blackSingleCoinCounter].Live1.x=x-1;
                        setOfBlackSingle[blackSingleCoinCounter].Live2.y=y;
                    }
                    blackSingleCoinCounter++;
                }
            } else if (board[x][y] == 2)
            {
                int verticalNum = Vertical(board, x, y);
                int horizontalNum = Horizontal(board, x, y);
                int an45Num = An45(board, x, y);
                int an135Num = An135(board, x, y);
                if (verticalNum == 4 || horizontalNum == 4 || an45Num == 4 || an135Num == 4)
                {
                    struct QuaCoin temp[4];
                    //0号元素储存垂直，1号元素储存水平，2号元素储存斜向上，3号元素储存斜向下，color=-1代表不是4
                    if (verticalNum == 4)
                    {
                        temp[0].color = board[x][y];
                        temp[0].direction = Zero;

                        int i = 1;
                        while (y + i < Height && board[x][y + i] == board[x][y])
                            i++;
                        if (y + i < Height && board[x][y + i] == 0)
                        {
                            temp[0].Live1.x = x;
                            temp[0].Live1.y = y + i;
                        } else//死棋
                        {
                            temp[0].Live1.x = -1;
                            temp[0].Live1.y = -1;
                        }
                        int j = 1;
                        while (y - j > 0 && board[x][y - j] == board[x][y])
                            j++;
                        if (y - j > 0 && board[x][y - j] == 0)
                        {
                            temp[0].Live2.x = x;
                            temp[0].Live2.y = y - j;
                        } else//死棋
                        {
                            temp[0].Live2.x = -1;
                            temp[0].Live2.y = -1;
                        }
                    } else
                    {
                        temp[0].color = -1;
                    }

                    if (horizontalNum == 4)
                    {
                        temp[1].color = board[x][y];
                        temp[1].direction = Ninety;

                        int i = 1;
                        while (x + i < Width && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && board[x + i][y] == 0)
                        {
                            temp[1].Live2.x = x + i;
                            temp[1].Live2.y = y;
                        } else//死棋
                        {
                            temp[1].Live2.x = -1;
                            temp[1].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && board[x - j][y] == 0)
                        {
                            temp[1].Live1.x = x - j;
                            temp[1].Live1.y = y;
                        } else//死棋
                        {
                            temp[1].Live1.x = -1;
                            temp[1].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an45Num == 4)
                    {
                        temp[2].color = board[x][y];
                        temp[2].direction = Up;

                        int i = 1;
                        while (x + i < Width && y + i < Height && board[x + i][y + i] == board[x][y])
                            i++;
                        if (x + i < Width && y + i < Height && board[x + i][y + i] == 0)
                        {
                            temp[2].Live2.x = x + i;
                            temp[2].Live2.y = y + i;
                        } else//死棋
                        {
                            temp[2].Live2.x = -1;
                            temp[2].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y - j > 0 && board[x - j][y - j] == board[x][y])
                            j++;
                        if (x - j > 0 && y - j > 0 && board[x - j][y - j] == 0)
                        {
                            temp[2].Live1.x = x - j;
                            temp[2].Live1.y = y - j;
                        } else//死棋
                        {
                            temp[2].Live1.x = -1;
                            temp[2].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an135Num == 4)
                    {
                        temp[3].color = board[x][y];
                        temp[3].direction = Down;

                        int i = 1;
                        while (x + i < Width && y - i > 0 && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && y - i > 0 && board[x + i][y] == 0)
                        {
                            temp[3].Live2.x = x + i;
                            temp[3].Live2.y = y - i;
                        } else//死棋
                        {
                            temp[3].Live2.x = -1;
                            temp[3].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y + j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && y + j > 0 && board[x - j][y] == 0)
                        {
                            temp[3].Live1.x = x - j;
                            temp[3].Live1.y = y;
                        } else//死棋
                        {
                            temp[3].Live1.x = -1;
                            temp[3].Live1.y = -1;
                        }
                    } else
                    {
                        temp[3].color = -1;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int isTheSame = 0;
                        for (int i = 0; i < whiteQuaCoinCounter; i++)
                        {
                            if (temp[j].color == setOfWhiteQua[i].color && temp[j].direction == setOfWhiteQua[i].direction &&
                                temp[j].Live1.x == setOfWhiteQua[i].Live1.x && temp[j].Live2.x == setOfWhiteQua[i].Live2.x &&
                                temp[j].Live2.y == setOfWhiteQua[i].Live2.y && temp[j].Live1.y == setOfWhiteQua[i].Live1.y)
                                isTheSame = 1;
                        }
                        if (isTheSame == 0)
                        {
                            setOfWhiteQua[whiteQuaCoinCounter] = temp[j];
                            whiteQuaCoinCounter++;
                        }
                    }

                }
                else if (verticalNum == 3 || horizontalNum == 3 || an45Num == 3 || an135Num == 3)
                {
                    struct TripleCoin temp[4];
                    //0号元素储存垂直，1号元素储存水平，2号元素储存斜向上，3号元素储存斜向下，color=-1代表不是4
                    if (verticalNum == 3)
                    {
                        temp[0].color = board[x][y];
                        temp[0].direction = Zero;

                        int i = 1;
                        while (y + i < Height && board[x][y + i] == board[x][y])
                            i++;
                        if (y + i < Height && board[x][y + i] == 0)
                        {
                            temp[0].Live1.x = x;
                            temp[0].Live1.y = y + i;
                        } else//死棋
                        {
                            temp[0].Live1.x = -1;
                            temp[0].Live1.y = -1;
                        }
                        int j = 1;
                        while (y - j > 0 && board[x][y - j] == board[x][y])
                            j++;
                        if (y - j > 0 && board[x][y - j] == 0)
                        {
                            temp[0].Live2.x = x;
                            temp[0].Live2.y = y - j;
                        } else//死棋
                        {
                            temp[0].Live2.x = -1;
                            temp[0].Live2.y = -1;
                        }
                    } else
                    {
                        temp[0].color = -1;
                    }

                    if (horizontalNum == 3)
                    {
                        temp[1].color = board[x][y];
                        temp[1].direction = Ninety;

                        int i = 1;
                        while (x + i < Width && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && board[x + i][y] == 0)
                        {
                            temp[1].Live2.x = x + i;
                            temp[1].Live2.y = y;
                        } else//死棋
                        {
                            temp[1].Live2.x = -1;
                            temp[1].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && board[x - j][y] == 0)
                        {
                            temp[1].Live1.x = x - j;
                            temp[1].Live1.y = y;
                        } else//死棋
                        {
                            temp[1].Live1.x = -1;
                            temp[1].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an45Num == 3)
                    {
                        temp[2].color = board[x][y];
                        temp[2].direction = Up;

                        int i = 1;
                        while (x + i < Width && y + i < Height && board[x + i][y + i] == board[x][y])
                            i++;
                        if (x + i < Width && y + i < Height && board[x + i][y + i] == 0)
                        {
                            temp[2].Live2.x = x + i;
                            temp[2].Live2.y = y + i;
                        } else//死棋
                        {
                            temp[2].Live2.x = -1;
                            temp[2].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y - j > 0 && board[x - j][y - j] == board[x][y])
                            j++;
                        if (x - j > 0 && y - j > 0 && board[x - j][y - j] == 0)
                        {
                            temp[2].Live1.x = x - j;
                            temp[2].Live1.y = y - j;
                        } else//死棋
                        {
                            temp[2].Live1.x = -1;
                            temp[2].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an135Num == 3)
                    {
                        temp[3].color = board[x][y];
                        temp[3].direction = Down;

                        int i = 1;
                        while (x + i < Width && y - i > 0 && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && y - i > 0 && board[x + i][y] == 0)
                        {
                            temp[3].Live2.x = x + i;
                            temp[3].Live2.y = y - i;
                        } else//死棋
                        {
                            temp[3].Live2.x = -1;
                            temp[3].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y + j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && y + j > 0 && board[x - j][y] == 0)
                        {
                            temp[3].Live1.x = x - j;
                            temp[3].Live1.y = y;
                        } else//死棋
                        {
                            temp[3].Live1.x = -1;
                            temp[3].Live1.y = -1;
                        }
                    } else
                    {
                        temp[3].color = -1;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int isTheSame = 0;
                        for (int i = 0; i < whiteTripleCoinCounter; i++)
                        {
                            if (temp[j].color == setOfWhiteTriple[i].color &&
                                temp[j].direction == setOfWhiteTriple[i].direction &&
                                temp[j].Live1.x == setOfWhiteTriple[i].Live1.x &&
                                temp[j].Live2.x == setOfWhiteTriple[i].Live2.x &&
                                temp[j].Live2.y == setOfWhiteTriple[i].Live2.y && temp[j].Live1.y == setOfWhiteTriple[i].Live1.y)
                                isTheSame = 1;
                        }
                        if (isTheSame == 0)
                        {
                            setOfWhiteTriple[whiteTripleCoinCounter] = temp[j];
                            whiteTripleCoinCounter++;
                        }
                    }

                } else if (verticalNum == 2 || horizontalNum == 2 || an45Num == 2 || an135Num == 2)
                {
                    struct DoubleCoin temp[4];
                    //0号元素储存垂直，1号元素储存水平，2号元素储存斜向上，3号元素储存斜向下，color=-1代表不是4
                    if (verticalNum == 2)
                    {
                        temp[0].color = board[x][y];
                        temp[0].direction = Zero;

                        int i = 1;
                        while (y + i < Height && board[x][y + i] == board[x][y])
                            i++;
                        if (y + i < Height && board[x][y + i] == 0)
                        {
                            temp[0].Live1.x = x;
                            temp[0].Live1.y = y + i;
                        } else//死棋
                        {
                            temp[0].Live1.x = -1;
                            temp[0].Live1.y = -1;
                        }
                        int j = 1;
                        while (y - j > 0 && board[x][y - j] == board[x][y])
                            j++;
                        if (y - j > 0 && board[x][y - j] == 0)
                        {
                            temp[0].Live2.x = x;
                            temp[0].Live2.y = y - j;
                        } else//死棋
                        {
                            temp[0].Live2.x = -1;
                            temp[0].Live2.y = -1;
                        }
                    } else
                    {
                        temp[0].color = -1;
                    }

                    if (horizontalNum == 2)
                    {
                        temp[1].color = board[x][y];
                        temp[1].direction = Ninety;

                        int i = 1;
                        while (x + i < Width && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && board[x + i][y] == 0)
                        {
                            temp[1].Live2.x = x + i;
                            temp[1].Live2.y = y;
                        } else//死棋
                        {
                            temp[1].Live2.x = -1;
                            temp[1].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && board[x - j][y] == 0)
                        {
                            temp[1].Live1.x = x - j;
                            temp[1].Live1.y = y;
                        } else//死棋
                        {
                            temp[1].Live1.x = -1;
                            temp[1].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an45Num == 2)
                    {
                        temp[2].color = board[x][y];
                        temp[2].direction = Up;

                        int i = 1;
                        while (x + i < Width && y + i < Height && board[x + i][y + i] == board[x][y])
                            i++;
                        if (x + i < Width && y + i < Height && board[x + i][y + i] == 0)
                        {
                            temp[2].Live2.x = x + i;
                            temp[2].Live2.y = y + i;
                        } else//死棋
                        {
                            temp[2].Live2.x = -1;
                            temp[2].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y - j > 0 && board[x - j][y - j] == board[x][y])
                            j++;
                        if (x - j > 0 && y - j > 0 && board[x - j][y - j] == 0)
                        {
                            temp[2].Live1.x = x - j;
                            temp[2].Live1.y = y - j;
                        } else//死棋
                        {
                            temp[2].Live1.x = -1;
                            temp[2].Live1.y = -1;
                        }
                    } else
                    {
                        temp[1].color = -1;
                    }

                    if (an135Num == 2)
                    {
                        temp[3].color = board[x][y];
                        temp[3].direction = Down;

                        int i = 1;
                        while (x + i < Width && y - i > 0 && board[x + i][y] == board[x][y])
                            i++;
                        if (x + i < Width && y - i > 0 && board[x + i][y] == 0)
                        {
                            temp[3].Live2.x = x + i;
                            temp[3].Live2.y = y - i;
                        } else//死棋
                        {
                            temp[3].Live2.x = -1;
                            temp[3].Live2.y = -1;
                        }
                        int j = 1;
                        while (x - j > 0 && y + j > 0 && board[x - j][y] == board[x][y])
                            j++;
                        if (x - j > 0 && y + j > 0 && board[x - j][y] == 0)
                        {
                            temp[3].Live1.x = x - j;
                            temp[3].Live1.y = y;
                        } else//死棋
                        {
                            temp[3].Live1.x = -1;
                            temp[3].Live1.y = -1;
                        }
                    } else
                    {
                        temp[3].color = -1;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int isTheSame = 0;
                        for (int i = 0; i < whiteDoubleCoinCounter; i++)
                        {
                            if (temp[j].color == setOfWhiteDouble[i].color &&
                                temp[j].direction == setOfWhiteDouble[i].direction &&
                                temp[j].Live1.x == setOfWhiteDouble[i].Live1.x &&
                                temp[j].Live2.x == setOfWhiteDouble[i].Live2.x &&
                                temp[j].Live2.y == setOfWhiteDouble[i].Live2.y && temp[j].Live1.y == setOfWhiteDouble[i].Live1.y)
                                isTheSame = 1;
                        }
                        if (isTheSame == 0)
                        {
                            setOfWhiteDouble[whiteDoubleCoinCounter] = temp[j];
                            whiteQuaCoinCounter++;
                        }
                    }

                } else if (verticalNum == 1 && horizontalNum == 1 && an45Num == 1 && an135Num == 1)
                {

                }
            }
        }
    }
}
//扫描棋盘确定所有的单点和连线的情况