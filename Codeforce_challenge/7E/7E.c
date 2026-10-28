#include <stdio.h>
#include <string.h>

char macro_name[100][101], macro_expression[100][101];


int main(){

    int n;

    scanf(" %d", &n);

    for(int i = 0; i < n; i++){

        scanf(" #define %s %s", macro_name+i, macro_expression+i);
    }

    char init_expression[10000];

    scanf(" %s", &n);

    char replaced_expression[10000];
    strcpy(replaced_expression, init_expression);

    replace(replaced_expression, n, 0);

    char bracketed_expression[10000];
    strcpy(replaced_expression, init_expression);

    replace(replaced_expression, n, 1);

}


void replace(char expression[], int n, int mode){

    for(int i = 0; i < n; ++i){

        int idx = strstr(expression, macro_name[i]);

        if(mode){

            int s[105];
            sprintf(s, "( %s )", macro_expression[i]);

            strcpy(expression+idx, s);
        }
        else{

            strcpy(expression+idx, macro_expression[i]);
        }
    }    

    return;
}