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
 
#include <stdio.h>

void prime_factor(int a, int *prime_factor){

    int prime_natural_id[a]; for(int i = 0; i < a; ++i) prime_natural_id[i] = 0;
    
    int upper_range = a, num = 0;

    for(int i = 2; i <= upper_range; ++i){

        if(!prime_natural_id[i-1]){

            for(int j = i+i; j <= upper_range; j += i){
                
                if(prime_natural_id[j-1]){

                    continue;
                }
                else{

                    prime_natural_id[j-1]++;
                }
            }

            for(;!(a%i);a/=i){

                prime_factor[i-1]++;
            }
        }
    }

    return;
}

// This function returns the GCD of x and y
// You don't have to modify this function
int gcd(int x, int y) 
{
    // This function implements the Euclidean Algorithm for finding GCD
    // See: https://en.wikipedia.org/wiki/Euclidean_algorithm
    while (y != 0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

// Complete the implementation of this function so that it returns the 
// LCM of x and y
int lcm(int x, int y) 
{
// Write your code here

    int max = (x-y < 0)?y:x;

    int x_prime_factor[max]; for(int i = 0; i < max; ++i) x_prime_factor[i] = 0;
    prime_factor(x, x_prime_factor);
    
    int y_prime_factor[max]; for(int i = 0; i < max; ++i) y_prime_factor[i] = 0;
    prime_factor(y, y_prime_factor);

    int lcm = 1;
    for(int i = 1; i <= y || i <= x; i++){

        for(int j = 0; (j < x_prime_factor[i-1] || j < y_prime_factor[i-1]); ++j){

            lcm *= i;
        }
    }

    return lcm;
}

// Complete the implementation of the main function.
int main(void)
{
// Write your code here

    int num[4];

    scanf(" %d %d %d %d", num, num + 1, num + 2, num + 3);

    printf("GCD is %d\n", gcd(gcd(num[0], num[1]), gcd(num[2], num[3])));
    printf("LCM is %d\n", lcm(lcm(num[0], num[1]), lcm(num[2], num[3])));
  
    return 0;
}
