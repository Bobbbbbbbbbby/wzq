#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>


#define SIZE 15
#define Width 15
#define Height 15

void Player1Draw(int board[][Height],int new[]);
void Player2Draw(int board[][Height],int new[]);
int Check(int board[][Height]);

void displayBoard(void);
void recordtoDisplayArray(void);

wchar_t aInitDisplayBoardArray[SIZE][SIZE + 1]
        = {
                L"┌┬┬┬┬┬┬┬┬┬┬┬┬┬┐",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"├┼┼┼┼┼┼┼┼┼┼┼┼┼┤",
                L"└┴┴┴┴┴┴┴┴┴┴┴┴┴┘"
        };

int board[Width][Height];
int new[2];

wchar_t aDisplayBoardArray[SIZE][SIZE + 1];
wchar_t play1Pic = L'●';
wchar_t play1CurrentPic = L'♥';
wchar_t play2Pic = L'○';
wchar_t play2CurrentPic = L'♡';

int main()
{
    setbuf(stdout, 0);
    setlocale(LC_ALL, "C.UTF-8");
    int result = 0;
    for (;;)
    {
        for (int i = 0; i < Width; i++)
        {
            for (int j = 0; j < Height; j++)
                board[i][j] = 0;
        }
        wprintf(L"Do you want to defeat my AI?\nEnter y to go to the PVE, n to go to the PVP\n");
        char choice;
        scanf("%c",&choice);
        if(choice=='n')
        {
            for (;;)
            {
                Player1Draw(board, new);
                result = Check(board);
                recordtoDisplayArray();
                displayBoard();
                if (result != 0)
                    break;
                Player2Draw(board, new);
                result = Check(board);
                recordtoDisplayArray();
                displayBoard();
                if (result != 0)
                    break;
                displayBoard();
            }
        }
        else
            break;
        if (result == 1)
            wprintf(L"Congratulations player 1, you win!\n");
        else if (result == 2)
            wprintf(L"Congratulations player 2, you win!\n");
        wprintf(L"Enter r to restart, enter other characters to quit:");
        char input;
        scanf("%c", &input);
        scanf("%c", &input);
        if (input == 'r')
            continue;
        else
        {
            wprintf(L"\n!!Terminated!!");
            break;
        }
    }
}

void displayBoard(void)
{
    setlocale(LC_ALL, "C.UTF-8");
    int i;
    //第一步：清屏
    system("clear");
    //第二步：将aDisplayBoardArray输出到屏幕上
    for (i = 0; i < SIZE; i++)
        wprintf(L"%3d %S\n", SIZE - i, aDisplayBoardArray[i]);
    //第三步：输出最下面一行字母
    printf(" ");
    printf(" ");
    printf(" ");
    printf(" ");
    printf(" ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%c", 'A' + i);
        printf(" ");
    }
    printf("\n");
}

void recordtoDisplayArray(void)
{
    //第一步：将aInitDisplayBoardArray中记录的空棋盘，复制到aDisplayBoardArray中
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE + 1; j++)
        {
            aDisplayBoardArray[i][j] = aInitDisplayBoardArray[i][j];
        }
    }
    //第二步：扫描aRecordBoard，当遇到非0的元素，将●或者◎复制到aDisplayBoardArray的相应位置上
    //注意：aDisplayBoardArray所记录的字符是中文字符，每个字符占2个字节。●和◎也是中文字符，每个也占2个字节。
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 1 && i == new[0] && j == new[1])
            {
                aDisplayBoardArray[i][j] = play1CurrentPic;
            } else if (board[i][j] == 1)
            {
                aDisplayBoardArray[i][j] = play1Pic;
            }
            if (board[i][j] == 2 && i == new[0] && j == new[1])
            {
                aDisplayBoardArray[i][j] = play2CurrentPic;
            } else if (board[i][j] == 2)
            {
                aDisplayBoardArray[i][j] = play2Pic;
            }
        }
    }
}
