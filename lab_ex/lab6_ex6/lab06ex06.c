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
 * Date         : 15/10/2026
 */

// Please write down the formula for T_i on paper before
// you start writing the program


#include <stdio.h>

int main(void){

    double pi = 3;

    int n;

    printf("n? ");
    scanf(" %d", &n);

    printf("%.6lf\n", pi);

    for(int i = 1; i < n; ++i){

        pi += (i%2 == 0)?-4.0/((i*2)*(1+i*2)*(2+i*2)):4.0/((i*2)*(1+i*2)*(2+i*2));

        if(i == 1 || i == n-1 || i == n-2){

            printf("%.6lf\n", pi);
        } 
        else if(i == n-3){
            
            printf("...\n");
        }
    }

    return 0;
}