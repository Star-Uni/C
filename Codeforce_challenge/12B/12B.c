#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void *a, const void *b);

int main(){

    char ques[11], ans[11];

    scanf("%s %s",ques, ans);

    qsort(ques, strlen(ques), sizeof ques[0], compar);

    char *least_ptr;

    for(char i = '1'; i <= '9';++i){

        if((least_ptr = strchr(ques, i)) != NULL){

            *least_ptr = '0';
            ques[0] = i;
            break;
        }

    }

    printf((!strcmp(ques,ans))?"OK":"WRONG_ANSWER");
    
    return 0;
}

int compar(const void *a, const void *b){

    return *(char *)a - *(char *)b;
}