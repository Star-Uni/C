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
 * Date         : 24/9/2026
 */

/* include header file */
#include <stdio.h>

/* starting point of this C program */
int main(void)
{
  double a;

  scanf("%lf", &a);

  printf("Continuous Wind Speed of %.1f => Tropical Cyclone ", a);

  printf("Warning Signal No %d", (a >= 117.5)?10:((a >= 62.5)?8:((a >= 41.5)?3:1)));
  
  return 0;
}


