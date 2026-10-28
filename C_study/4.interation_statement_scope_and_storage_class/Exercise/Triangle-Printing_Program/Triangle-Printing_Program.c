#include <stdio.h>

//Exercise description

/*Write a program that prints the following patterns separately,
one below the other. Use for loops to generate the patterns.
All asterisks (*) should be printed by a single printf statement of the form printf("%s", "*");
(this causes the asterisks to print side by side)

(A)          (B)         (C)         (D)
*            **********  **********           *
**           *********    *********          **
***          ********      ********         ***
****         *******        *******        ****
*****        ******          ******       *****
******       *****            *****      ******
*******      ****              ****     *******
********     ***                ***    ********
*********    **                  **   *********
**********   *                    *  **********
*/

int main(){

    char x;

    printf("Which type of triangle (A/B/C/D): ");
    scanf("%c", &x);

    switch(x){

        case 'A':{

            for(int i = 1;i <= 10;++i){

                for(int j = 1;j <= i;++j){

                    printf("%s", "*");
                }
                printf("\n");
            }

            break;
        }

        case 'B':{

            for(int i = 10;i >= 1;--i){

                for(int j = 1;j <= i;++j){

                    printf("%s", "*");
                }
                printf("\n");
            }

            break;
        }

        case 'C':{

            for(int i = 10;i >= 1;--i){

                for(int j = 1;j <= 10-i;++j){

                    printf(" ");
                }

                for(int j = 1;j <= i;++j){

                    printf("%s", "*");
                }
                printf("\n");
            }

            break;
        }

        case 'D':{

            for(int i = 1;i <= 10;++i){

                for(int j = 1;j <= 10-i;++j){

                    printf(" ");
                }

                for(int j = 1;j <= i;++j){

                    printf("%s", "*");
                }
                printf("\n");
            }

            break;
        }
    }
    
    return 0;
}