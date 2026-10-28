#include <stdio.h>
#include <string.h>

// Sometimes, primitive data types can't fulfil our needs

/*
To store a date, using only primitive data types, we may declare 3 variable:
int y, m, d for year, month, day respectively
Or just use a string s[11] to store "yyyy-mm-dd"
But it can be extremely simple by constructing a struct, one of the two devired date type:
*/

struct Date{// Date is the structure tag, struct Date is the type

    struct{

        unsigned short y;
        unsigned short m : 4;
        unsigned short d : 5;
        // for unsigned type in structure, their bit field can be restricted
        /*
        sizeof (unsigned short) = 2 (i.e. 16 bits)
        y: 16 bits (a regular member) -> up to 2^16-1
        m: 4 bits -> up to 2^4-1 (i.e. 15)
        d: 5 bits -> up to 2^5-1 (i.e. 31)
        Total useful bits: 25 bits
        Its main use is to match the pattern for hardwares, protocols etc. 
        */
       
        // unnamed bit field like unisgned x : n occupy next n bits memory with emptiness

        unsigned short : 0;
        /* 
        but for 0, it works as a \t skips remaining bits
        memory block for unsigned short can be like: 
        | yyyy yyyy yyyy yyyy | mmmm dddd d000 0000 | ...following variables or
        | yyyy yyyy yyyy yyyy | dddd dmmm m000 0000 | 0000 0000 0000 0000 or
        | yyyy yyyy yyyy yyyy | mmmm 0000 0000 0000 | dddd d000 0000 0000 | ...following variables 
        etc. depends on various factors

        so the next variable starts at a new memory block of unsigned short
        It is useful for some scenarioes in hardwares etc.
        */
    };
    // nested structure is allowed, but as same as not nested

    unsigned short date[3];
    enum month{JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;
    /*
    enum is not a derived data type, but belongs to enumerated data type
    It provide alias of int value, unless explicit assignment, it increments by 1 (first element is 0 by default)
    */

    struct Date *p;
    // declare a pointer to structure itself is allowed, but declare a variable with type of the structure itself is not allowed
    // Like linked-list has to declare a pointer to the linked-list type 

} date_chongyang, holidays[10];// One way to declare some variables with type Date

// another derived data type is union
/*
Different from a structure, members of a union can't coexist
The size of a union will be the size of the member that has the largest size
It helps save memory
*/
union type{

    int i;
    double f;
    char s[100]; 
    struct Date d;
    //In this union, s has largest size (100), size of tpye is thus 100

}n = {3.14};// it does not assign 3.14 to n.f, be assign (int)3.14 to n.i

void display_next_day(struct Date date);
void print_binary(short a);

int main(){

    // To initialize, there are several ways

    struct Date date_mid_autumn = {2026,9};// initialize while declare, 0/NULL for remaining
    date_chongyang.y = 2026, date_chongyang.m = 10, date_chongyang.d = 18;// initialize after declare

    // For struct, there are two operaters for access its member: 
    /*
    structure member operator .
    structure pointer operator (also called arrow operater) ->
    */

    printf("The Chong Yang Festival is: %04u-%02u-%02u\n", date_chongyang.y, date_chongyang.m, date_chongyang.d);// Output 2026-10-18
            // .member to call the corresponding member

    printf("The Mid-Autumn Festival is: %04u-%02u-%02u\n", 
            date_mid_autumn.y, date_mid_autumn.m, date_mid_autumn.d);// 2026-09-00

    struct Date birthday, *birthday_ptr = &birthday;

    printf("When is your birthday? "); 

    birthday.y = 2067, birthday.m = 6, birthday.d = 7;

    printf("Your birthday is: %04u-%02u-%02u\n", birthday_ptr->y, (*birthday_ptr).m, birthday.d);// Output 2067-06-07
    /*
    three means are equal: 
    birthday_ptr -> y accesses the member y through a the struct pointer (no intervening spaces between - and >)
    (*birthday_ptr).m to dereference the struct pointer then call the member m (precedence matters)
    birthday.d access teh member d directly
    */

    // when passing a struct to a function, it is pass-by-value, even if the member is array

    birthday.date[0] = 2077, birthday.date[1] = 12, birthday.date[2] = 31;
    display_next_day(birthday);// Output: 2078-01-01

    printf("Your birthday is: %04u-%02u-%02u\n", birthday.date[0], birthday.date[1], birthday.date[2]);// Output: 2077-12-31

    // To make the program more clear and easy-to-read, we often use typedef to give an alias to a existing type

    typedef int int_4_digit;
    // int_4_digit is an alias of int, sometimes it might be more clear of the motive

    typedef struct Date Date;
    // but most common use of typedef is to ignore the structure tag and give a better alias for it
    /*
    Most common way is:
    struct date{

        unsigned short y;
        unsigned short m;
        unsigned short d;
        unsigned short date[3];
    };typedef struct date Date;
    ...
    Date a_date = {...};
    */
   
    Date a_date = {1986,9,4,{1986,9,4},OCT};
    // same as struct Date a_date = {1986,9,4,{1986,9,4},OCT}, but more clear

    typedef union type Type;
    // typedef also gievs union an alias

    Type x;

    strcpy(x.s, "abc");
    printf("x = %s\n", x.s);
    //x: 0x61('a') 0x62('b') 0x63('c') 0x00('\0') 0x00 ...

    x.d.y = 25956;

    printf("x = %d\n", x.d.y);
    //x: 0x64 0x65(25956) 0x63 0x00 0x00 (sizeof (unsigned short) = 2, so the remaining byte doesn't matter)...

    printf("x = %s\n", x.s);
    //x: 0x64('d') 0x65('e') 0x63('c') 0x00('\0') 0x00 ...

    // To better utilize an union, it can be defined:

    struct type1{

        enum t{I,F,S,D} t;
        Type x;
    };

    typedef struct type1 Type1;

    // by adding a current type identifier, it prevents confusion of current type

    Type1 y;
    y.x.i = 10, y.t = I;

    switch (y.t){
        
        case I:{

            printf("%d\n", y.x.i);
            break;
        }
        case F:{

            printf("%lf\n", y.x.d);
            break;
        }
        case S:{

            printf("%s\n", y.x.s);
            break;
        }
        case D:{

            printf("%04u-%02u-%02u\n\n", y.x.d.y, y.x.d.m, y.x.d.d);
            break;
        }

    }
    
    // Bitwise operator 
    /*
    Computers represent all data internally as sequences of bits
    For example:
    (char) 'a': 0110 0001
    (unsigned short) 8964: 0010 0011 0000 0100

    To manipulate bits, there are several operator to compute, compare, assign values on bit basis:
    
    Comparing:
    & (bitwise AND): compare each bit, 1 for both 1, 0 for any zero
    | (bitwise inclusive OR): compare each bit, 1 for any 1, 0 for both 0
    ^ (bitwise exclusive OR): compare each bit, 1 for different, 0 for same

    Computing:
    << (left siwft): left shift n bits
    >> (right siwft): right shift n bits
    ~ (complement): set all 0 to 1, 1 to 0

    Assigning:
    &= |= ^= <<= >>=

    P.S. no ~=
    */

    unsigned short bit1 = 89, bit2 = 64;

    printf("bit1: ");
    print_binary(bit1);
    printf("bit2: ");
    print_binary(bit2);

    printf("bit1 & bit2: ");
    print_binary(bit1&bit2);

    printf("bit1 | bit2: ");
    print_binary(bit1|bit2);

    printf("bit1 ^ bit2: ");
    print_binary(bit1^bit2);
    /*
    There is an interesting characteristic for ^
    any variable x ^ x == 0;
    therefore, switch value of a and b can also be implemented by:
    a = a^b;

    b = b^a;
    i.e. b = original_b ^ original_a ^ original_b
    two same items are mutually cancelled, thus b = original_a

    a = b^a; 
    i.e. a = original_a ^ original_a ^ original_b
    two same items are mutually cancelled, thus a = original_b
    */

    printf("bit1 << 2: ");
    print_binary(bit1<<2);

    printf("bit1 << 10: ");
    print_binary(bit1<<10);

    printf("bit1 >> 4: ");
    print_binary(bit1>>4);

    printf("~bit1: ");
    print_binary(~bit1);

    // bitwise operations are useful in optimizing some common-sense algorithm
    /*
    For example:
    Common-sense to find perfect power of 2 is:
    */

    int count = 0;

    printf("perfect power of 2 (1-1024): ");

    for(int i = 1; i <= 1024; ++i){

        int j = i;

        for(;!(j%2);++count){

            j /= 2;
        }

        if(j == 1 && i != 1){

            printf("%d ", i);
        }
    }

    printf("\nexecute %d times\n", count);
    
    // but by observation, all perfect power of 2's binary form are like: 100000, 1000. Therefore:

    count = 0;

    printf("perfect power of 2 (1-1024): ");

    for(int i = 0; i < 10; ++i, ++count){

        printf("%d ", 2<<i);
    }

    printf("\nexecute %d times\n", count);

    return 0;
}

void display_next_day(struct Date date){

    int days_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    date.date[2] += 1;

    if(date.date[2] > days_of_month[date.date[1] - 1]){

        date.date[2] = 1;
        date.date[1]++;

        if(date.date[1] == 13){

            date.date[1] = 1;
            date.date[0]++;
        }
    }

    printf("Next day is: %04u-%02u-%02u\n", date.date[0], date.date[1], date.date[2]);

    return;
}

void print_binary(short a){

    char bits[17];
    
    for(int i = sizeof(a)*8-1; i >= 0; --i){

        bits[i] = '0'+ a%2;
        a/=2;   
    }

    printf("%.4s %.4s %.4s %.4s\n", bits, bits + 4, bits + 8, bits + 12);
    
    return;
}
