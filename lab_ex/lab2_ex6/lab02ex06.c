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
 * Date         : 17/9/2026
 */

#include <stdio.h>

int main(void) {
	
    int adults, children;
    double cost, tip;

    printf("Input number of adults: ");
    scanf(" %d", &adults);

    printf("Input number of children: ");
    scanf(" %d", &children);

    printf("Input cost of meal: ");
    scanf(" %lf", &cost);

    printf("Input tips: ");
    scanf(" %lf", &tip);

    printf("Each adult pays: %.2f\n", (cost + tip)/(adults + children*0.5));
    printf("Each child pays: %.2f\n", (cost + tip)/(adults + children*0.5)*0.5);


}