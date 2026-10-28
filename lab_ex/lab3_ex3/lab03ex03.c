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

int main(void) {

  int n1,n2,n3;

  scanf(" %d %d %d", &n1, &n2, &n3);

  printf((n1 == n2 && n1 == n3)?"Triple":(n1+n2+n3 > 10)?"BIG":"SMALL");

  return 0;
}