#include <stdio.h>

//Exercise description

/*Write a program that prints a table of all the Roman-numeral equivalents 
of the decimal numbers in the range 1 to 100.
*/

int f(int x);

int main(void){

    printf("Number\t\tRoman\n");
    for(int i = 1;i <= 399;++i){

        printf("%d\t\t", i);
        f(i);
        printf("\n");
    }

    return 0;
}

int f(int x){

    if(x <= 5-2){

        for(int i = x;i >= 1;i--){
            printf("I");
        }

        return 0;

    }
    else if(x <= 10-2){

        x -= 5;

        if(x < 0){
            f(-x);
        }

        printf("V");
        f(x);

        return 0;
    }
    else if(x < 40){

        x -= 10;

        if(x < 0){
            f(-x);
        }

        printf("X");

        while(x > 0){

            if (x >= 10){
                printf("X");
                x -= 10;
            }
            else{

                f(x);
                return 0;
            }
        }
    }
    else if(x < 90){

        x -= 50;

        if(x < 0){

            printf("X");
        }
        
        printf("L");

        if(x < 0){

            f(10+x);
        }

        f(x);
        return 0;
    }
    else if(x < 400){

        x -= 100;

        if(x < 0){

            printf("X");
        }
        
        printf("C");

        if(x < 0){

            f(10+x);
        }

        f(x);
        return 0;
    }

    return 0;

}