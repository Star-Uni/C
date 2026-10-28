#include <stdio.h>
#include <stdlib.h>

/*
In this problem, you’ll recreate one of the truly great moments in history, 
namely the classic race of the tortoise and the hare.
You’ll use random number generation to develop a simulation of this memorable event.

Our contenders begin the race at “square 1” of 70 squares. 
Each square represents a possible position along the race course. 
The finish line is at square 70. 

The course weaves its way up the side of a slippery mountain,
so occasionally the contenders lose ground.
There’s a clock that ticks once per second. 
With each tick of the clock, your program should adjust the position of the animals according to the rules

Tortoise    Fast plod           Slip                Slow plod
            50%                 20%                 30%
            3 squares forward   6 squares backward  1 square forward

Hare        Sleep               Big hop             Big slip                Small hop           Small slip
            20%                 20%                 10%                     30%                 20%
            No move at all      9 squares forward   12 squares backward     1 square forward    2 squares backward

Begin the race by printing
BANG !!!!!
AND THEY'RE OFF !!!!!

Then, for each tick of the clock (i.e., each iteration of a loop), print a 70-position line showing the
letter T in the position of the tortoise and the letter H in the position of the hare. Occasionally, the
contenders will land on the same square. In this case, the tortoise bites the hare and your program
should print OUCH!!! beginning at that position. All print positions other than the T, the H, or the
OUCH!!! (in case of a tie) should be blank.

After each line is printed, test whether either animal has reached or passed square 70. If so,
then print the winner and terminate the simulation. If the tortoise wins, print TORTOISE WINS!!!
YAY!!! If the hare wins, print Hare wins. Yuch. If both animals win on the same tick of the clock,
you may want to favor the turtle (the “underdog”), or you may want to print It's a tie. If neither
animal wins, perform the loop again to simulate the next tick of the clock. When you’re ready to
run your program, assemble a group of fans to watch the race. You’ll be amazed at how involved
your audience gets!
*/

#define SQUARE_NUM 70 // better divisible by 10

void Display_Squares(char square[]);
void Move(char square[],char contender, int *position, int (*event)());
int T_event();
int H_event();

int main(void){
    
    int t_pos, h_pos;
    t_pos = h_pos = 0;

    srand(4);// 1: t_win   2: tie   4:h_win
    
    char squares[SQUARE_NUM] = {'.'};

    for(int i = 0;i < SQUARE_NUM;++i){

        squares[i] = '.';
    }

    Display_Squares(squares);

    while(t_pos < 70 && h_pos < 70){

        Move(squares,'T', &t_pos, &T_event);
        Move(squares,'H', &h_pos, &H_event);

        Display_Squares(squares);
    }
    
    puts(t_pos==h_pos?"It's a tie":(t_pos>=h_pos?"TORTOISE WINS!!! YAY!!!":"Hare wins. Yuch."));

    return 0;
}

void Display_Squares(char square[]){

    for(int i = 0;i < (SQUARE_NUM+1)/10;++i){

        for(int j = 1;j<=12;(i == 0)?printf("* "):(i%2 == 1)?((j == 11)?printf("v "):printf("* ")):((j == 2)?printf("v "):printf("* ")),++j);

        puts("");

        printf("* ");

        for(int j = 0;j < 10;printf("%-2c", square[10*i+j]),++j);

        printf("* ");

        puts("");
    }

    for(int j = 1;j<=12;++j,printf("* "));

    puts("\n");
}

void Move(char square[],char contender, int *position, int (*event)()){

    square[*position] = (square[*position] == '2')?((contender == 'H')?'T':'H'):'.';

    *position += (*event)();
    *position = *position > 70?70:(*position < 0?0:*position);

    square[*position] = (square[*position] != '.')?'2':contender;
}

int T_event(){

    int x = rand()%10+1;

    if(x > 5){

        return 3;
    }
    else if(x > 3){

        return -6;
    }
    else{

        return 1;
    }
}

int H_event(){

    int x = rand()%10+1;

    if(x > 8){

        return 0;
    }
    else if(x > 6){

        return 9;
    }
    else if(x > 5){

        return -12;
    }
    else if(x > 2){

        return 1;
    }
    else{

        return -2;
    }
}