#include <stdio.h>

int main(void){

    /* There are four storage class specifiers: auto, register, extern and static
    They determine a variable's storage duration and scope
    storage duration and scope are separate things
    the former decides the value's lifespan, the latter decides where the value can be referenced
    auto: local variables have automatic storage class by default,
          created when the program control enters the block they defined,
          destroyed when program control exits the block,
          only referenced in the block
    extern: global variables and function names have external storage class by default,
            static storage duration,
            retains the value throughout the program until the execution ends
            can be referenced in everywhere after declaration
    static: static storage duration,
            retains the value throughout the program until the execution ends
            static local variable only referenced in the block they defined
    register: too out-dated, skip
          

    */
    int counter, sentinel, x;//they are static storage duration by default
    counter = sentinel = x = 1;
    
    while(counter <= 5){// it is a counter-controlled iteration

        x *= 2;
        counter += 1;
    }
    // it runs with knowing how many times it has to run
    printf("2^5 = %d\n", x);

    while(sentinel >= 100){// it is sentinel-controlled iteration
        sentinel *= 2;
    }
    /* it runs without knowing how many times it has to run,
    but reaching some concrete condition */
    printf("the leastest 2^x = %d\n", sentinel);

    int y = 1;

    for (int i = 1; i <= 5; ++i){// it is also a counter-controlled iteration
        y *= 3;
    }
    /* it does exactly the same thing like the first iteration in this program
    but it is more simple, clear
    Meanwhile, i has an automatic storage duration by default*/
    printf("3^5 = %d\n", y);

    //Sometimes, the program needs a interation nested in another interation, like
    for (int i = 1; i <= 10; ++i){
       for (int j = 1; j <= 10; ++j){
            printf("%d\t",i*j);
       }
       printf("\n");
    }

}
