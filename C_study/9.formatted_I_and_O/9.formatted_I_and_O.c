#include <stdio.h>

int main(){

    // All input and output is performed with streams, which are sequences of bytes.
    /* 
    When input, bytes flow from device to main memory, reverse flow when output
    Normally, the standard I&O stream is connected to the keyboard and screen respectively
    (when using sscanf, sprintf, it is connected to the string)
    */

    /*
    printf, scanf stand for print, scan formatted
    the formatted string helps better I&O through conversion specification with a leading %
    In output, it controls the length, justification, precision, rounding...
    In input, it controls what data type to be read, how to be read
    */

    /*
    There are various types of conversion specifier for each data type,
    and several flag characters, length modifiers, field width and precision to design the output
    
    conversion specifier:
    %d for signed decimal integers (only for signed decimal integers when input)
    %i for signed decimal integers (for signed decimal, octual, hexadecimal integers when input)
    %o/O for signed octual integers
    %x/X for signed hexadecimal integers
    %u for unsigned decimal integers

    length modifiers for above: h for short, l for long, ll for long long

    %f/F for decimal
    %e/E for decimal in exponential form (lowercase e for %e, E for %E)
    %g/G for decimal in either %f or %e (lowercase e for %g, E for %G) based on the exponent E (f when -4 <= exponent E <= 6, else e by default, it can be modify through adding precision but only for the left-hand side)

    length modifiers for above: l for double, L for long double
    
    %c for character
    %s for string
    %p for an address (pointer)
    %% for displaying a percentage sign %
    */

    // to control justification, precision and output format
    /*
    flags:
    - for left justification
    + for always display +ve and -ve sign
    space for a leading space for positive value
    # for always a floating point of %f, leading 0 and 0x of %o and %x respectively (0X for %X) 
    0 for leading zeros
    */

    printf("%+9.4lf\n", (double)3.1415926);// Output: "  +3.1416"
    /*
    9 for right justify 9 units
    .4 for precision of 4 d.p.
    + for display +ve and -ve sign
    */

    printf("%09.4lf\n", (double)3.1415926);// Output: "0003.1416"
    // 0 for leading zeros

    printf("% -9.4lf\n", (double)3.1415926);// Output: " 3.1416  "
    /*
    -9 for left justify 9 units
    space for a leading space of +ve value
    */
   
    printf("%#.0lf\n", (double)3.1415926);// Output: "3."
    // # for display floating point . no matter what precision

    printf("%#.4X\n", (unsigned int) 100);// Output: "0X0064"
    /* 
    # for leading 0X for %X
    .4 for display at least 4 digits
    */

    /*
    In input, some conversion specifiers have different use than output, as well as some new specifiers

    %i for signed decimal, octual, hexadecimal integers with clear leading sign 0x (hexa) or 0 (oct)
    %[accept set] for a string only consists of the characters in the set 
    %[^reject set] for a string only consists of the characters not in the set 
    %n for number of characters already input at the position, this specifier read nothing but count
    %% foe skipping a %
    %* for skipping some data (%*d for skip integer, %*3s for skip 3 characters etc.)
    space for skipping all whitespace characters (space, newline, tab)
    any character for skipping that certain character
    */

    char *s1 = "1234    98765";
    int d1, n1, d2, n2;

    sscanf(s1, " %d%n %d %n", &d1, &n1, &d2, &n2);

    printf("d1: %d\nn1: %d\nd2: %d\nn2: %d\n", d1, n1, d2, n2);
    /* 
    Output:
    d1: 1234
    n1: 4
    d2: 98765
    n2: 13
    */

    char s2[5], s3[10];

    sscanf(s1, " %[123] %[^567]", s2, s3);

    printf("s2: %s\ns3: %s\n", s2, s3);
    /*
    Output:
    s2: 123
    s3: 4    98
    */

    char *s4 = "2026-10-11";

    sscanf(s4, " %d-%*d%*c%d", &d1, &d2);

    printf("d1: %d\nd2: %d\n", d1, d2);
    /*
    Output:
    d1: 2026
    d2: 11
    */
   
    return 0;
}