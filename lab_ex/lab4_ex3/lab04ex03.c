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
 * Date         : 28/9/2026
 */

#include <stdio.h>

int main(void) {

    /* The Fibonacci lookup table: F[n] is the n-th Fibonacci number */
    // Do not change the array f, the lookup table for Fibonacci number
    int F[21] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
                 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};

    int n;

    printf("Enter an integer n: ");
    scanf(" %d", &n);

    if(n < 0 || n > 20){

        printf("Invalid input");
    }
    else if(n < 2){

        printf("F[%d] = %d", n, F[n]);
    }
    
    else{

        printf("F[%d] = F[%d] + F[%d] = %d", n, n-1, n-2, F[n]);
    }

    return 0;
}