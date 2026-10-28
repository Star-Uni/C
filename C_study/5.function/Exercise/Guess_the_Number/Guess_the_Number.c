#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Exercise description

/*Write a C program that plays the game of “guess the number” as follows:
Your program chooses the number to be guessed by selecting an integer at random in the range 1 to 1000.
The program then types:

I have a number between 1 and 1000.
Can you guess my number?
Please type your first guess.

The player then types a first guess. The program responds with one of the following:

1. Excellent! You guessed the number!
Would you like to play again (y or n)?
2. Too low. Try again.
3. Too high. Try again.

If the player’s guess is incorrect, your program should loop until the player finally gets the number right. 
Your program should keep telling the player Too high or Too low to help the player “zero in” on the correct answer.
*/

int random_number(int start, int end);

int main(void){

    srand(111);
    int target,guess;
    char cont;

    guess = -1;
    target = random_number(1,1000);
    cont = 'y';

    printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.");

    while(target != guess && cont == 'y'){

        scanf("%d", &guess);

        if(guess < target){

            printf("Too low. Try again.");
        }
        else if(guess > target){

            printf("Too high. Try again.");
        }
        else{

            printf("Excellent! You guessed the number!\nWould you like to play again (y or n)?");
            scanf(" %c", &cont);
            
            if(cont == 'y'){

                guess = -1;
                target = random_number(1,1000);

                printf("Can you guess my number?");
            }
        }
    }

}

int random_number(int start, int end){

    return rand()%(end-start)+start;
}