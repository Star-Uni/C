/* C standard library stores a number of prepackaged functions
there are some of them*/
#include <stdio.h>//input&output
#include <math.h>//math calculation
#include <stdlib.h>//several functions, including random number generation
#include <time.h>//time and date

//Besides standard library functions, there can be programmer-defined functions

unsigned int random_number(unsigned int width, unsigned int least);
unsigned int fibonacci(unsigned int x);

int main(void){

    /* rand() function generates an integer between 0 and RAND_MAX
    it generates pseudo-random number, depends on the seed
    srand() is used to set the seed*/

    srand(time(NULL));
    /*time(NULL) is the number of seconds that have passed since January 1, 1970
    it varies every seconds, so it can be used as the seed to generate random number*/

    int rand_num = rand();
    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("random_number generated = %d\n", rand_num);

    //to generate a random number with a range, see the statement in the function
    printf("Random number with range 1 to 68 %u\n", random_number(67,1)); 

    /*math function library has various useful functions for calculation
    includes trigo, log, exp etc.*/
    printf("3^(2.5) = %lf\n", pow(3,2.5));
    printf("square root of 3 = %lf\n", sqrt(3));
    printf("cube root of 3 = %lf\n", cbrt(3));
    printf("e^3 = %lf\n", exp(3));
    printf("ln3 = %lf\n", log(3));
    printf("log3 = %lf\n", log10(3));
    printf("sin(3 rad) = %lf\n", sin(3));
    printf("cos(3 rad) = %lf\n", cos(3));
    printf("tan(3 rad) = %lf\n", tan(3));

    //it also helps some decimal calculation, and rounding
    printf("remindar of 11.4514 / 1.919 = %lf\n", fmod(11.4514,1.919));
    printf("absolute value of -11.4514= %lf\n", fabs(-11.4514));
    printf("round up 11.4514 corr. to integer= %lf\n", ceil(11.4514));
    printf("round down 11.4514 corr. to integer= %lf\n", floor(11.4514));

    //function calls itself called recursive function, like the function below
    printf("You want the ?th item in Fabonacci sequence: ");

    unsigned int temp;
    scanf("%u", &temp);

    printf("It is %u", fibonacci(temp)) ;
}

unsigned int random_number(unsigned int width, unsigned int least){// width and least are both parameters of the function, which are automatic

    return rand() % width + least;
}

unsigned int fibonacci(unsigned int x){

    if(x == 1 || x == 2){
        return 1;
    }
    return fibonacci(x - 1) + fibonacci(x - 2);//it calls itself

    /*when functions are called, there is a function call stack storing the calls
    stack is a LIFO data structure
    when a function calls another function, an entry called stack frame is pushed onto the stack
    stack frame contains parameters and the return address
    Once the last called function returns the value, it is popped from the stack,
    Sometimes, a recursive function causes billions of stack frames in the stack,
    Then, a stack overflow occurs, which is a fatal error*/
}

