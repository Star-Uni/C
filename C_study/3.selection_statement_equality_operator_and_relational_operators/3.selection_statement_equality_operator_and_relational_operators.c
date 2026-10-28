#include <stdio.h>

int main(void){

    int x,y,z;
    x = z = 1;
    /*the assignment z = 1 also has its value, which is 1, the right-hand side value
    Therefore x = z = 1 is feasible as (z = 1) = 1*/
    y = 2;

    //a single-selection statement
    if(x == z){//equality operator: == & !=
        puts("x = z");
    }

    if(x != y){
        puts("x not = y");
    }

    if(x <= y){//relational operator: < & > & <= & >=
        puts("x <= y");
    }

    if(y > z){
        puts("y > z");
    }
    /*to be cautionary, if statement x == z is mistyped as x = z, puts("x = z") will always be executed
    It is because (x = z) is an assignment with value, unless z = 0, it will always be true
    Thus, It is important to distinguish between == and =, as no syntax error but logical error will occur*/

    int var1, var2;
    var1 = 100;
    var2 = 99;
    
    //a double-selection statement
    if(var1 > var2 && var1 > 0){// && and || means AND and OR respectively, they are logical operator
        puts("var1 is a non-zero integer greater than var2");
    }
    else{
        puts("var1 is not greater than var2, or var1 is a negetive integer");
    }

    //another double-selection statement
    puts(var1 > var2 && var1 > 0?"var1 is a non-zero integer greater than var2":"var1 is not greater than var2, or var1 is a negetive integer");
    //?: is a conditional operator, as well as the only tertary operator which takes three operants
    var1 > var2 && var1 > 0?puts("var1 is a non-zero integer greater than var2"):puts("var1 is not greater than var2, or var1 is a negetive integer");
    //it is as same as the upper statement

    enum Day {Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun} day;
    /*enum is a data type, helping the program more readable
    It is a set of integers represented by identifiers
    The default vaule of the first identifier is 0, and incremented by 1 as it comes to the next
    It also can be assigned explicitly, like Mon = 10, Tue = 100,
    and the rest will be automatically incremented by 1 starting from 101*/
    
    int temp;

    printf("Today is the ?th day in a week:");
    scanf("%d", &temp);

    day = (enum Day) temp;

    //a multi-selection statement by matching the value
    switch(day){
        case Mon:{
            printf("It is Monday");
            break;//end the matching, else it will keep continuously check other statements
        }
        case Tue:{
            printf("It is Tuesday");
            break;
        }
        case Wed:{
            printf("It is Wednesday");
            break;
        }
        case Thu:{
            printf("It is Thursday");
            break;
        }
        case Fri:{
            printf("It is Friday");
            break;
        }
        case Sat:{
            printf("It is Saturday");
            break;
        }
        case Sun:{
            printf("It is Sunday");
            break;
        }
        default:{//all other input 
            printf("Invaild Input");
        }
    }

    //another more common multi-selection statement
    int mark = 78;

    if(mark >= 90){
        printf("Your Grade: Excellent\n");
    }
    else if(mark >= 75){
        printf("Your Grade: Good\n");
    }
    else if(mark >= 60){
        printf("Your Grade: Pass\n");
    }
    else{
        printf("Your Grade: Failed\n");
    }
    /*it it actual several nested selection statements, but ignoring the identation
    identation is optional, but recommonded to use in most cases to improve readability*/

    //with identation
    if(mark >= 90){

        printf("Your Grade: Excellent\n");
    }

    else{

        if(mark >= 75){

        printf("Your Grade: Good\n");
        }

        else{

            if(mark >= 60){

                printf("Your Grade: Pass\n");
            }

            else{

                printf("Your Grade: Failed\n");
            }
        }
    }
    return 0;
}