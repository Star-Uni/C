#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int intpow(int x, int y);
long combination(int n, int r);
char *dectobi(int n);

int main(){

    int n = 1000;

    //scanf("%d", &n);

    char matrix[n][n];
    int best_route = 0;



    /*for(int i = 0;i < n;++i){

        for(int j = 0; j < n; ++j){

            scanf(" %d", matrix[i][j]);
        }
    }*/
    
    char routes[combination(2*n-2, n-1)][2*n-1];

    for(int i = 0, k = 0;i < intpow(2,2*n-2);++i){

        char route[2*n-1];
        strncpy(route, dectobi(i), 2*n-2);
        route[2*n-2] = '\0';

        int D_num = 0, R_num = 0;
        
        for(int j = 0;j < 2*n-2;++j){

            (route[j] == 'R')?(R_num += 1):(D_num += 1);
        }

        (R_num == D_num)?strncpy(routes[k++], route, 2*n-1):NULL;
    }
    
    for(long i = 0;i < combination(2*n-2, n-1);printf("%s\n", routes[i]),++i);

    return 0;
}

long factorial(int x){

    return (x == 0)?(1):(x * factorial(x - 1));
}

long combination(int n, int r){

    return factorial(n)/(factorial(n-r)*factorial(r));
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

char *dectobi(int n){

    static char binary[33];
    for(int i = 0; i < 32; binary[i] = 'R', ++i);
    char *binary_ptr = binary;
    int a = n;

    while(a > 0){

        *(binary_ptr++) = ((a%2 == 0)?'R':'D');
        a /= 2;
    }

    /*int len = strlen(binary);

    for(int i = 0; i < len / 2; ++i){

        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }

    //printf("%s",binary);*/
    return binary;
}