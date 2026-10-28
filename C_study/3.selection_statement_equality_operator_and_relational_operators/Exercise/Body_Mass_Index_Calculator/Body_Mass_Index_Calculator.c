#include <stdio.h>

//Exercise description

/*Create a BMI calculator application that reads the user’s weight in pounds and height in inches
(or, if you prefer, the user’s weight in kilograms and height in meters),
then calculates and displays the user’s body mass index.
Also, the application should display the following information
from the Department of Health and Human Services/National Institutes of Health so the user can evaluate his/her BMI:

BMI VALUES
Underweight: less than 18.5
Normal: between 18.5 and 24.9
Overweight: between 25 and 29.9
Obese: 30 or greater
*/

int main(void){

    puts("BMI VALUES");
    puts("Underweight: less than 18.5");
    puts("Normal: between 18.5 and 24.9");
    puts("Overweight: between 25 and 29.9");
    puts("Obese: 30 or greater");

    double w,h,bmi;

    printf("Your Weight (in kg): ");
    scanf("%lf", &w);

    printf("Your Height (in m): ");
    scanf("%lf", &h);

    bmi = w/h/h;

    printf("Your BMI is %.1f\n", bmi);

    if(bmi >= 30){

        puts("You are obese!");
        return 0;
    }
    
    if(bmi >= 25){
        
        puts("You are overweight");
        return 0;
    }

    if(bmi >= 18.5){
        
        puts("You are normal");
        return 0;
    }

    puts("You are underweight");
    return 0;
}