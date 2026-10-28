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

#include <stdio.h>

int main(void) {
    //
    // Keep reading scores (integers from 0 to 100) until -1 is entered.
    // Then print the minimum score, the maximum score, and the number of
    // scores that are strictly greater than the average.
    // If the first input is -1, print "No scores entered." instead.
    //
    // You may assume that at most 100 scores will be entered.

    // TODO: Complete the program. Feel free to modify the provided code.
    int scores[100]; // At most 100 valid scores will be provided.
    int num_scores = 0; // Tracking the number of scores input by the user
    int gotEnd = 0; // Indicator used to decide if we can end the loop
    int current_input = 0; // Track the current input from the user.

    while(gotEnd == 0){
        scanf("%d", &current_input);
        
        if(current_input == -1){

            break;
        }
        else{

            scores[num_scores++] = current_input;
        }
    }

    if(!num_scores){

        printf("No scores entered.");

        return 0;
    }
    
    int max = 0, min = 100, sum = 0;

    for(int i = 0; i < num_scores; ++i){

        if(scores[i] > max){

            max = scores[i];
        }

        if(scores[i] < min){

            min = scores[i];
        }

        sum += scores[i];
    }

    int num = 0; 
    double aver = sum / (double)num_scores;
    for(int i = 0; i < num_scores; ++i){
        if(scores[i] > aver){

            num++;
        }
    }

    printf("Min = %d\nMax = %d\nAbove average = %d", min, max, num);


    return 0;
}
