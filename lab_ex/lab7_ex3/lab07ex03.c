/**
 * ENGG1110 Problem Solving by Programming 
 *
 * I declare that the assignment here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   http://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name : Tsui Sing Yu
 * Student ID   : 1155287536
 * Class/Section: ENGG1110C
 * Date         : 22/10/2026
 */

// your code here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char x[20];

    printf("x? ");
    scanf("%s", &x);

    int x_int;
    sscanf(x,"%d",&x_int);

    if(!strcmp(x,"1")){

            printf("Happy Number! :)");
            return 0;
        }
    else if(!strcmp(x,"4")){

            printf("Unhappy Number! :(");
            return 0;
        }
        
    for(;1;printf(" ")){

        if(x_int == 1){

            printf("\nHappy Number! :)");
            break;
        }
        else if(x_int == 4){

            printf("\nUnhappy Number! :(");
            break;
        }
        else{

            x_int = 0;

            for(int i = 0;x[i] != '\0';++i){

                x_int += (x[i] - '0')*(x[i] - '0');
            }

            sprintf(x, "%d", x_int);

            printf("=> %d", x_int);
        }
    }
}