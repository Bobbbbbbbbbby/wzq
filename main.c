#include <stdio.h>

#define Width 19
#define Height 19

extern void Player1Draw(int board[][19]);

extern void Player2Draw(int board[][19]);

extern int Check(int board[][19]);

int main() {
    setbuf(stdout, 0);
    int board[Width][Height];

    int result = 0;
    for (;;) {
        for (int i = 0; i < Width; i++)
        {
            for (int j = 0; j < Height; j++)
                board[i][j] = 0;
        }
        for (;;) {
            Player1Draw(board);
            result = Check(board);
            if (result != 0)
                break;
            Player2Draw(board);
            result = Check(board);
            if (result != 0)
                break;
        }
        if (result == 1)
            printf("Congratulations player 1, you win!\n");
        else if (result == 2)
            printf("Congratulations player 2, you win!\n");
        printf("Enter r to restart, enter other characters to quit:");
        char input;
        scanf("%c", &input);
        scanf("%c", &input);
        if (input == 'r')
            continue;
        else {
            printf("\n!!Terminated!!");
            break;
        }
    }
}