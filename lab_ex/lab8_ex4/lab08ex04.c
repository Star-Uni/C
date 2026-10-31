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
 * Date         : 29/10/2026
 */


// your code here

#include <stdio.h>

int main(){

    int n, k;

    scanf(" %d %d", &n, &k);

    int ints[n]; 

    for(int i = 0; i < n; ++i){

        scanf(" %d", ints +i);
    }

    for(int i = 0; i < n-k+1; ++i){

        int sum = 0;

        for(int j = 0; j < k; ++j){

            sum += ints[i + j];
        }

        printf("%.2f ", sum/(double)k);
    }


    return 0;
}