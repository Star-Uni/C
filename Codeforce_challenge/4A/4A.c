#include <stdio.h>

int main(){

    int w;

    scanf("%d", &w);

    for(int i = 2; i <= w / 2; ++i){

        if(!(i % 2) && !((w - i) % 2)){

            printf("YES");

            return 0;
        }
    }

    printf("NO");

    return 0;
}