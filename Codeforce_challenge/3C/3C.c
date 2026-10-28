#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int win(const char board[][4], const char x);

int main(){

    char board[3][4];

    int count_x = 0, count_o = 0;
    
    for(int i = 0; i < 3; ++i){

        scanf("%3s", board[i]);
    }

    for(int i = 0; i < 3; ++i){

        for(int j = 0; j < 3; ++j){
            
            (board[i][j] == 'X')?(count_x += 1):((board[i][j] == '0')?(count_o += 1):(1));
        }
    }

    if(count_x > count_o+1 || count_o > count_x || win(board, 'X') && win(board, '0')){

        printf("illegal");
    }
    else if(win(board, 'X')){
        
        printf((count_x > count_o)?"the first player won":"illegal");
    }
    else if(win(board, '0')){

        printf((count_x == count_o)?"the second player won":"illegal");
    }
    else if(count_x + count_o == 9){

        printf("draw");
    }
    else if(count_x > count_o){

        printf("second");
    }
    else{

        printf("first");
    }

    return 0;
}

int win(const char board[][4], const char x){

    char x_row[4] = {x,x,x};

    for(int i = 0; i < 3; ++i){

        if(!strcmp(x_row, board[i])){

            return 1;
        }
    }

    for(int i = 0; i < 3; ++i){

        char ver[4] = "\0\0\0\0";

        for(int j = 0; j < 3; ++j){

            ver[j] = board[j][i];
        }

        if(!strcmp(x_row, ver)){

            return 1;
        }
    }

    if( board[0][0] == x && board[1][1] == x && board[2][2] == x ||
        board[2][0] == x && board[1][1] == x && board[0][2] == x){

        return 1;
    }

    return 0;
}
