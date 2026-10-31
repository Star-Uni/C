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

int binaryToDecimal(int b) {
	
  int d = 0;

  for(int i = 0;b > 0;++i, b/=10){

    int temp = b%10;

    for(int j = 0;j < i;++j){

      temp *= 2;
    }

    d += temp;
  }

  return d;
}

int decimalToBinary(int d) {
	
  char s[20], *ptr_1, *ptr_2;

  for(ptr_1 = ptr_2 = s;d > 0;ptr_1++, d /= 2){

    *ptr_1 = ((d%2)?'1':'0');
  }

  for(ptr_1--;ptr_1 - ptr_2 > 0;ptr_1--, ptr_2++){

    *ptr_1 ^= *ptr_2;
    *ptr_2 ^= *ptr_1;
    *ptr_1 ^= *ptr_2;
  }

  return (int) strtol(s, NULL, 0);

}

int main(void) {
  int b1, b2, d1, d2, diff_b, diff_d;
  // Read b1 and b2 from user, and start calculation

  printf("b1 and b2? ");
  scanf(" %d %d", &b1, &b2);
  
  // Do NOT modify the following lines
  // NEVER EVER TOUCH THESE!
  d1 = binaryToDecimal(b1);
  d2 = binaryToDecimal(b2);
  printf("The numbers (in decimal) are %d and %d\n", d1, d2);
  diff_d = d1 - d2;
  diff_b = decimalToBinary(diff_d);
  printf("The difference is %d (decimal) or %d (binary)\n", diff_d, diff_b);
  return 0;
}