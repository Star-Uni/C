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

#include <stdio.h>

int main(void) {
  
  double mgpa,gpa;

  printf("Major GPA: ");
  scanf(" %lf", &mgpa);

  printf("Overall GPA: ");
  scanf(" %lf", &gpa);

  printf((mgpa > 4 || gpa > 4 || mgpa < 0 || gpa < 0)?"Invalid GPA":((mgpa >= 3.5 && gpa >= 3.3)?"First Class Honours":((mgpa >= 3.1 && gpa >= 2.8)?"Second Class Honours Upper Division":(mgpa >= 2.5 && gpa >= 2)?"Second Class Honours Lower Division":((mgpa >= 1.5 && gpa >= 1.5)?"Third Class Honours":"Pass"))));

  return 0;
}