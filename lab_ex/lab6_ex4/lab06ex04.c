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
#include <limits.h>

int main(void) {

    double a, b, max = INT_MIN;
    int x_Low, x_Up ,count = 0, max_id;

    printf("Input parameters of f(x) a,b: ");
    scanf(" %lf %lf", &a, &b);

    printf("Input range of x: ");
    scanf(" %d %d", &x_Low, &x_Up);

    for(int i = x_Low; i <= x_Up; ++i){

        double v = a*i*i*i + b;

        (max < v)?(max_id = i):(1);
        (max < v)?(max = v):(1);
        (v > 0)?(count++):(1);
    }

    printf("Positive value count: %d\n", count);
    printf("Maximum value: f(%d) = %.2f\n", max_id, max);

    return 0;
}
