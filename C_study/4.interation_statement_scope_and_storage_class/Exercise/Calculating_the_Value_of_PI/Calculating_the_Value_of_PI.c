#include <stdio.h>

//Exercise description

/*Calculate the value of π from the infinite series
Print a table that shows the value of π approximated by one term of this series, by two terms, by three terms, and so on.
How many terms of this series do you have to use before you first get 3.14? 3.141? 3.1415? 3.14159?
*/

int main(void){

    double pi = 4;

    printf("Term\t\tPI\n");
    printf("1\t\t%lf\n", pi);

    for(int i = 2; i <= 100000; ++i){

        if(i%2 == 0){

            pi -= 4.0/(i*2-1);
        }
        else{

            pi += 4.0/(i*2-1);
        }

        if(i%1000 == 0 || i%1000 == 1){
         
            printf("%d\t\t%lf\n", i, pi);
        }
    }

    return 0;
}