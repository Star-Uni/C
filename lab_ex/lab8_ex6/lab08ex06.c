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
#include <stdlib.h>

/*
 * Parameter: number, a decimal integer from 2 to 255.
 * Task: print its binary digits without leading zeros, spaces or a newline.
 * Return: the number of 1 in its binary representation.
 */
int decimalToBinary(int d, int *count) {
	
  char s[20], *ptr_1, *ptr_2;

  for(ptr_1 = ptr_2 = s;d > 0;ptr_1++, d /= 2){

    *ptr_1 = ((d%2)?'1':'0');
    *count += ((*ptr_1 == '1')?1:0);
  }

  for(ptr_1--;ptr_1 - ptr_2 > 0;ptr_1--, ptr_2++){

    *ptr_1 ^= *ptr_2;
    *ptr_2 ^= *ptr_1;
    *ptr_1 ^= *ptr_2;
  }

  return (int) strtol(s, NULL, 0);

}

int main(void) {
  /* Complete the main program. */

  int a,b;

  scanf(" %d %d", &a, &b);

  for(int i = b; i >= a; --i){

    int count = 0;

    printf("%d %d ", i, decimalToBinary(i, &count));
    
    printf((count%2)?"\n":"evil number\n");
  }
  return 0;
}
