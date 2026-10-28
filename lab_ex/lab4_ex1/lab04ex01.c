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

/* include header file */
#include <stdio.h>
#include <ctype.h>

/* starting point of this C program */
int main(void) {

  char c = getchar();
  printf("You have entered '%c'.\n", c);

  if(isdigit(c)){
    
    printf("'%c' is a number.", c);
  }
  else if(islower(c)){
    
    printf("'%c' is a small letter.", c);
  }
  else if(isupper(c)){
    
    printf("'%c' is a capital letter.", c);
  }
  else{

    printf("'%c' is not an alphanumeric letter.", c);
  }

  return 0;
}