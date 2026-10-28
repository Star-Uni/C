#include <stdio.h>

//Exercise description

/*Write a program that inputs three different integers from the keyboard,
then prints the sum, the average, the product, the smallest and the largest of these numbers. 
Use only the single-selection form of the if statement. 
The screen dialogue should appear as follows:

Enter three different integers: 13 27 14
Sum is 54
Average is 18
Product is 4914
Smallest is 13
Largest is 27
*/

int main(void){

    int i1, i2, i3;
    
    printf("Enter three different integers: ");
    scanf("%d%d%d", &i1, &i2, &i3);
    
    printf("Sum is %d\n", i1+i2+i3);

    printf("Average is %d\n", (i1+i2+i3)/3);

    printf("Product is %d\n", i1*i2*i3);

    if(i1 < i2){

        if(i1 < i3){

            printf("Smallest is %d\n", i1);

            if(i2 > i3){

                printf("Largest is %d\n", i2);
            }

            if(i2 < i3){

                printf("Largest is %d\n", i3);
            }
        }
    }

    if(i2 < i1){

        if(i2 < i3){

            printf("Smallest is %d\n", i2);

            if(i1 > i3){

                printf("Largest is %d\n", i1);
            }

            if(i1 < i3){

                printf("Largest is %d\n", i3);
            }
        }
    }

    if(i3 < i1){

        if(i3 < i2){

            printf("Smallest is %d\n", i3);

            if(i1 > i2){

                printf("Largest is %d\n", i1);
            }

            if(i1 < i2){

                printf("Largest is %d\n", i2);
            }
        }
    }

    return 0;
}