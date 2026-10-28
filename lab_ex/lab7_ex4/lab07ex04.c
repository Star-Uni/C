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
 * Date         : 22/10/2026
 */

// your code here

#include <stdio.h>

int main(void) {
  
  int x;

  printf("Rows (2-20)? ");
  scanf(" %d", &x);

  for(int i = 0; i < 2; ++i){

    for(int j = 0 ; j < x; ++j){

      for(int k = 1; k <= 2*x-1; ++k){

        if(k >= x-j && k <= x+j){

          if(x%2 == 0){

            printf(((k+j)%2 == 0)?"*":"@");
          }
          else{

            printf(((k+j)%2 == 1)?"*":"@");
          }
        }
        else{

          printf(".");
        }
      }

      puts("");
    }
  }
  return 0;
}