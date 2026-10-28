#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int checktype(char *s, int *row, int *RXCY_col);
void exchange(char *s, int row, char *col);

int main(){

    int n;
    scanf("%d", &n);

    char a[n][100];
    for(size_t i = 0; i < n; scanf(" %s", a[i]),++i);

    for(size_t i = 0; i < n; ++i){

        int row, RXCY_col;

        if(checktype(a[i], &row, &RXCY_col)){

            // RXCY-type
            char s[10];
            sprintf(s,"%d",RXCY_col);

            exchange(a[i], row, s);

            printf("%s\n", a[i]);

        }
        else{

            exchange(a[i], row, a[i]);

            printf("%s\n", a[i]);
            // CR-type
        }
    }

    return 0;
}

void reverse(char * const s, const char * init_s, const int len){

    if(!len){

        return;
    }

    reverse(s + 1, init_s, len - 1);
    *s = init_s[len - 1];
}

int intpow(int x, int y){

    int n = x;

    if(y == 0){
    
        return 1;
    }

    for(int i = 1; i < y;++i){
        
        n *= x;
    }

    return n;
}

void exchange(char *s, int row, char *col){

    if(isdigit(*col)){ // RXCY to CR

        // simulating 26 base, A = 0, B = 1
        // column has no 0 value, thus the value -1 

        char CR_col[10] = {0};
        int RXCY_col = strtol(col, NULL, 10);

        int col_num = 0;
        
        for(int i = RXCY_col;i;++col_num){

            i = (i-1)/26;
        }

        CR_col[col_num] = '\0';

        for(int i = col_num-1;i >= 0;--i){

            RXCY_col -= 1;

            CR_col[i] = 'A' + RXCY_col % 26;

            RXCY_col /= 26;
        }

        sprintf(s, "%s%d", CR_col, row);
    }
    else{

        int RXCY_col = 0;

        for(int i = 0, j = strlen(col) - 1;*(col + i) != '\0';++i, --j){

            RXCY_col += (*(col + i) - 'A' + 1) * intpow(26, j);
        }
        sprintf(s, "R%dC%d", row, RXCY_col);
    }
    
}


int checktype(char *s, int *row, int *RXCY_col){

    for(size_t i = 0; s[i] != '\0';++i){

        if(isdigit(s[i])){

            for(size_t j = i; s[j] != '\0';++j){

                if(isupper(s[j])){

                    for(; s[j] != '\0';++j){

                        if(isdigit(s[j])){

                            *row = strtol(s+i, NULL, 10);
                            *RXCY_col = strtol(s+j, NULL, 10);

                            return 1;// RXCY-type
                        }
                    }
                }
            }

            *row = strtol(s+i, NULL, 10);
            s[i] = '\0';

            return 0;// CR-type
        }
    }
}