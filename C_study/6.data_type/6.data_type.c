#include <stdio.h>

void print_array(char array_name[], int a[], int size);
char *print_element(char array_name[], int index);
void test_array(char array_name[], int a[], int size);
void test_element(char array_name[], int element, int index);
void print_2D_array(char array_name[], int a[][3], int column, int row);

int main(void){

    /* In c, there are primitive data types and non-primitive data types (or called derived data type)
    primitive data types includes int, char, double
    non-primitive data types are more complex datatypes based on primitive data types
    like: array, structure*/

    // arrays can be defined and initialized through various ways

    int a1[5];//defined, but not yet initialized

    print_array("a1", a1, 5);
    /* when elements are not initialized, they contain garbage values
    garbage values are meaningless and seem to be random like -1919, 114514*/

    for(size_t i = 0;i < 5;i++){

        // using for loop to initialize element is one way
        a1[i] = i;
    }

    print_array("a1", a1, 5);

    // also, elements can be initialized when the array is defined

    int a2[5] = {1,2,3,4,5};
    int a3[] = {1,2,3};
    int a4[5] = {1};
    int a5[5] = {1,2,3,4,5,6};

    print_array("a2", a2, 5);// elements: 1, 2, 3, 4, 5
    print_array("a3", a3, 3);// elements: 1, 2, 3
    print_array("a4", a4, 5);// elements: 1, 0, 0, 0, 0
    print_array("a5", a5, sizeof a5 / 4);// elements: 1, 2, 3, 4, 5

    /*a5[5] = 6;
    printf("%d", a5[5]);

    print_array(a5, sizeof a5 / 4);*/

    /* a5[5] = 6; as this case, it will not be ignored, 
    printf("%d", a5[5]) still output 6
    However, the size of a5 is still 20 bytes,
    it is still an undefined behavior, it is written into an out-of-bounds address,
    outcome can be fatal or seem no problem, depends on compiler

    In this cases
    6 is wrongly stored in a address after 4 bytes(data size of int) of address of a5[4]
    It can be successfully output, as a5[5] still refers the address after 4 bytes of address of a5[4]*/

    /*By above shown, we get:
    
    When initializing elements when definition:

    1. array size can be omitted from a definition with an initializer list,
       the number of elements in the array will be the number of elements in the initializer list

    2. there can be fewer initializers than elements in the array, 
       the remaining elements are initialized to zero

    3. there can be more initializers than elements in the array, 
       the excessive elements are ignored, will not be stored in wrong address
       
    P.S. The size of arrays can also be variable, 
         this type of arrays call VLAs (Variable-Length Arrays)
    */

    // In fact, the array’s name evaluates to the address of the array’s first element.

    printf("%p %p %p\n\n", a1, &a1[0], &a1);// %p is conversion specifier for printing addresses
    // all output: the address of a1[0]

    /* Therefore, when an array passes to a function,
    it actually passes the address of the array’s first element
    The function can thus modify array elements 
    
    Meanwhile, when an array element passes to a function,
    it actually passes the value of the element
    The function can not modify the array element 
    
    By short, entire arrays are passed by reference, individual array elements are passed by value
    The former can be modified in the function body and the latter cannot
    
    Some test below*/

    int test[] = {1,2,3,4,5};

    // test array passed to function
    
    printf("%s when before enter the test function\n", "test[]");
    print_array("test", test, 5);// output: 1, 2, 3, 4, 5

    test_array("test", test, 5);// output: enter: 1, 2, 3, 4, 5; exit: 6, 7, 8, 9, 10

    printf("%s when just exit the test function\n", "test[]");
    print_array("test", test, 5);// output: 6, 7, 8, 9, 10

    // test element passed to functinon

    printf("%s[%d] when before enter the test function\n", "test", 2);
    printf("%s[%d] = %d\n", "test", 2, test[2]);// output: 3

    test_element("test", test[2], 2);// output: enter: 3; exit: 8 

    printf("%s[%d] when just exit the test function\n", "test", 2);
    printf("%s[%d] = %d\n", "test", 2, test[2]);// output: 3

    /* When solving more complicated problems, Multidimensional arrays are often used
    There are also multiple ways to initialize a multidimensional array
    A common case is table, which includes columns and rows, a 2D-array can perfectly mimic it*/

    int table1[][3] = {{1,2,3}, {2,3,4}};
    int table2[2][3] = {1,2,3,4,5};
    int table3[2][3];

    for(size_t i = 0;i < 2;++i){// Still, using for loop to initialize elements

        for(size_t j = 0;j < 3;++j){

            table3[i][j] = i+j+1;
        }
    }

    print_2D_array("table1", table1, 2, 3);
    /* result: 1 2 3
               2 3 4*/

    print_2D_array("table2", table2, 2, 3);
    /* result: 1 2 3
               4 5 0*/

    print_2D_array("table3", table3, 2, 3);
    /* result: 1 2 3
               2 3 4*/

    /*By above shown, we get:
    
    When initializing Multidimensional arrays when definition:

    1. only the index in the first bracket can be omitted from a definition with an initializer list,
       the subsequent indices cannot be left empty as the compiler uses them 
       to determine the locations in memory of elements in multidimensional arrays
       As an example, compiler don't know how many elements in a row so a table cannot be constructed well

       P.S. When defining a function's parameter, a 2D array parameter also has to follow this principle:
            only the index in the first bracket can be omitted

    2. there can be fewer initializers than elements in the array, 
       the remaining elements are initialized to zero, just like 1D array
       
    3. if initializers are not given row by row, 
       it continues assigning values to the next row when the current one is full
    */
    
    return 0;

}

char *print_element(char array_name[], int index){

    static char element[50];
    int i = 0;

    while(array_name[i] != '\0'){
        element[i++] = array_name[i];
    }

    element[i] = '[';
    element[++i] = '0'+index;
    element[++i] = ']';

    return element;
    
}

void print_array(char array_name[], int a[], int size){

    printf("%-16s", array_name);

    for(size_t i = 0;i < size;++i){

        printf("%-16s", print_element(array_name, i));
    } 

    puts("");
    printf("%-16s", "Elements");

    for(size_t i = 0;i < size;++i){

        printf("%-16d", a[i]);
    } 

    puts("\n");
}

void test_array(char array_name[], int a[], int size){

    printf("%s[] when just enter the test function\n", array_name);
    print_array(array_name, a, size);

    for(size_t i = 0; i < size; ++i){

        a[i] += 5; 
    }

    printf("%s[] before exit the test function\n", array_name);
    print_array(array_name, a, size);
}

void test_element(char array_name[], int element, int index){

    printf("%s[%d] when just enter the test function\n", array_name, index);
    printf("%s[%d] = %d\n", array_name, index, element);

    element += 5;

    puts("");

    printf("%s[%d] when just exit the test function\n", array_name, index);
    printf("%s[%d] = %d\n", array_name, index, element);
}

void print_2D_array(char array_name[], int a[][3], int row, int column){

    printf("%s:\n", array_name);

    printf("%-12sColumn%-6dColumn%-6dColumn%-6d\n", "Row\\Column", 0, 1, 2);
    
    for(size_t i = 0;i < row;++i){
        
        printf("Row%-9d", i);

        for(size_t j = 0;j < column;++j){

            printf("%-12d", a[i][j]);
        }

        puts("");
    }
}