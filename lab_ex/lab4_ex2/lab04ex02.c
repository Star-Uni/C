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
    int prizeLookup[] =
      { 1,0,0,2,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,1,0,1,
        // lookup table to be completed
      };
      
    int num;

    printf("Draw no.? ");
    scanf("%d", &num);

    if (prizeLookup[num-1] == 2) {
      
        printf("You won a top prize!");
      }
    else if(prizeLookup[num-1]){

      printf("You won a consolation prize!");
    }
    else{

      printf("No prize :(");
    }

  return 0;
}