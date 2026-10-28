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



#include <stdio.h>
#include <math.h>

int prime_natural_id[10000] = {0};

int main(){

    int lower_range = 2, upper_range = 10000;

    for(int i = 2; i < upper_range; ++i){

        if(!prime_natural_id[i-1]){

            for(int j = i+i; j <= upper_range; j += i){
                
                if(prime_natural_id[j-1] == -1){

                    continue;
                }
                else if(prime_natural_id[j-1] < 1){

                    prime_natural_id[j-1] += 1;
                }
                else if(prime_natural_id[j-1] == 1){

                    prime_natural_id[j-1] = -1;
                }
            }
        }
    }

    int n;

    scanf(" %d", &n);
    printf((prime_natural_id[n-1] == 0)?"%d is a prime":"%d is a composite", n);

    return 0;
}