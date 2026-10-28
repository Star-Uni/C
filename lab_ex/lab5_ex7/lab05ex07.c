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
 * Date         : 8/10/2026
 */

/* include header file */
#include <stdio.h>
#include <string.h>

int main(void) {
	// 1. User input
	char phone[20];
	printf("Input phone number: ");
	scanf("%s", phone);

	// 2. Phone number validation
	// TO BE COMPLETED
	// ...
  // HINT:
  // What is the range of valid numbers? Think about it carefully. 
	if(!(phone[0] <=  '9' && phone[0] >= '2') || strlen(phone) != 8){
		printf("Invalid phone number");
		return 0;
	}
	else{

		int d = 0;
		for(int i = '0'; i <= '9'; ++i){

			if(strchr(phone, i) != NULL){

				d += 1;
			}
		}

		printf("There are %d unique digit(s).", d);

		return 0;
	}
	
}
