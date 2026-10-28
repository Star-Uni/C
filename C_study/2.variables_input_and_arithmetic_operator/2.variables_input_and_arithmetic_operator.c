#include <stdio.h>

int main(void){
    int r;/*integer data type*/
    double a;/*decimal data type*/
    double PI = 3.14;/*block letter for constant*/

    printf("The radius of the circle:");
    scanf("%d",&r);/*input data, a destrutive process, & = address (&x = address of x)*/

    a = r*r*PI;/*arithmetic operation*/
    /*only + - / * % () in C
    when int / int, only quotient will be output*/

    printf("The area of the cirlce:%f",a);/*output data, a nondestrutive process*/
    /*for each data type, different format specifiers are used
    float:%f, %.2f when corr. to 2 d.p., %lf when double precision
    integer:%d
    char:%c
    string:%s
    Moreover, %10d means automaticlly fill spaces 
    until the digts of the value + spaces = 10 on the left side
    %-10d does the same thing on the right side*/
    return 0;
}