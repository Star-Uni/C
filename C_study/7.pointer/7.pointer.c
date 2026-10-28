#include <stdio.h>

void Modify_Value(int * const ptr);
void Modify_Address_In_Function(const int *ptr1, const int * const ptr2);
void Print(const int * const ptr);
void Modify_Address(int * *const ptr1, const int * const ptr2);
void Reverse_str_array(char * *ptr, int size);

int main(void){

    /* pointer in a data type which storing address, in hexadecimal form
    the conversion specifer for it is %p, output like 0000114514abcdef
    for defining a pointer:*/

    int a;
    int *ptr_a = &a;

    /* & is an unary operator to get the variable's address
    While, * is another unary operator to get the value stored in the address
    * and & are complementary, *(&ptr_a) returns ptr_a itself, *(&a) also returns itself*/

    printf("%p\n", ptr_a);
    printf("%p\n", &a);
    printf("%p\n\n", &*ptr_a);

    // they output the same address (varies every execution)

    /* Generally, there are four types of pointer with different levels of privilege:
    
    int *ptr_a: the address that pointer points to can be modified, so can the value
    const int *ptr_a: the address that pointer points to can be modified, but the value can't
    int * const ptr_a: the address that pointer points to can't be modified, but the value can
    const int * const ptr_a: the address that pointer points to can't be modified, nor can the value*/

    // By wisely using pointer and the const qualifier, we can pass parameters by reference or value whatever we want


    // int * const ptr_a: variable pass-by-reference, modification of value in whole program

    int value1 = 1;

    printf("Value before enter the function: %d\n", value1);

    Modify_Value(&value1);

    printf("Value after exit the function: %d\n\n", value1);

    // const int *ptr_a: pointer pass-by-value, modification of address in function body

    int value2 = 100;
    int *value1_ptr = &value1;

    printf("Address the pointer points to before enter the function: %p\n", value1_ptr);
    printf("Value the pointer points to before enter the function: %d\n", *value1_ptr);

    Modify_Address_In_Function(value1_ptr, &value2);

    printf("Address the pointer points to after exit the function: %p\n", value1_ptr);
    printf("Value the pointer points to after exit the function: %d\n\n", *value1_ptr);
    
    // const int * const ptr_a: pass-by-value only, no modification

    Print(&value1);

    // To modify the address a pointer points to in whole program:
    
    int value3 = 1000;
    int *value2_ptr = &value2;

    printf("Address the pointer points to before enter the function: %p\n", value2_ptr);
    printf("Value the pointer points to before enter the function: %d\n", *value2_ptr);

    Modify_Address(&value2_ptr, &value3);

    printf("Address the pointer points to after exit the function: %p\n", value2_ptr);
    printf("Value the pointer points to after exit the function: %d\n\n", *value2_ptr);

    /* By using above means, there is a high flexibility to decide 
    whether pass-by-reference or pass-by-value parameters should be used
    Sometimes, modifying address is also useful
    For example, an array of pointers pointing the first characters of strings:*/

    char *strings[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven"};

    /* Array name and function name are actually the address of its first element/the starting address of the code
    To remind, array name and function name are like * const, their address can't be modify directly*/

    void(*Reverse_str_array_ptr)(char **, int) = Reverse_str_array;

    /*using pointer to call a function is often used when some functions require other function,
    like qsort, requires a function to give the sorting rule*/

    (*Reverse_str_array_ptr)(strings,sizeof (strings)/ sizeof (strings[0]));
    
    // sizeof is an unary opertor return sizes of the operand
    // In the function, the addresses pointers point to are modified(swapped), to reverse the array of strings

    for(int i = 0;i<7;++i){

        printf("strings[%d] = %s\n", i, *(strings+i));

        /* ptr + (int)n not means the hexadecimal number of address + n, 
        but the hexadecimal number of address + sizeof(*ptr)*n
        The incrementation follows the same rule like above
        pointer's arithmetric operation always returns integer,
        like (ptr + 1) - (ptr + 3) return 2, not the real difference of the two hexadecimal numbers*/
    }

    return 0;
}

void Modify_Value(int * const ptr){

    *ptr = 10;
    printf("Value before exit the function: %d\n", *ptr);
}

void Modify_Address_In_Function(const int *ptr1, const int * const ptr2){

    ptr1 = ptr2;
    printf("Address the pointer points to before exit the function: %p\n", ptr1);
    printf("Value the pointer points to before exit the function: %d\n", *ptr1);
}

void Print(const int * const ptr){

    printf("Value: %d\nAddress: %p\n\n",*ptr,ptr);
}

void Modify_Address(int * *const ptr1, const int * const ptr2){

    *ptr1 = ptr2;
    printf("Address the pointer points to before exit the function: %p\n", *ptr1);
    printf("Value the pointer points to before exit the function: %d\n", **ptr1);
}

void Reverse_str_array(char * *ptr, int size){
    
    for(int i = 1;i <= size/2;++i){

        char *tmp = *ptr;
        *ptr = *(ptr+size-(2*i-1));
        ptr+=size-(2*i-1);
        *ptr = tmp;
        ptr-=size-(2*i-1);
        ++ptr;
    }
}