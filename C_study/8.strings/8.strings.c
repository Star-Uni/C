#include <stdio.h>
#include <ctype.h>// library handling characters
#include <string.h>// library handling strings
#include <stdlib.h>

void printsize(char * s1, char s2[]);
int iswhich(char s[], int (*type)(int));

int main(){

    // Strings are actaully a character array, so, string names are also addresses of their first characters

    char s[6+1] = "123456";// = {'1','2','3','4','5','6','\0'} where '\0' is a escape sequence, the terminating null character, ASCII 0 
    // always retains one unit size for '\0', 6 for content, 1 for termination
    
    char *s_ptr1 = s;

    printf("Size of s: %d\n", sizeof s);// Output: 7 (size of the string "123456\0")
    printf("Size of s_ptr1(char *s_ptr1 = s): %d\n", sizeof s_ptr1);// Output: 8 (size of a pointer)
    printf("Size of *s_ptr1: %d\n", sizeof *s_ptr1);// Output: 1 (size of the character '0')

    printsize(s,s);// Output: 8 8

    // When called by function, its size will only be 8 (size of a pointer)

    char *s1[100];
    char *s2[] = {"aaa", "bbb"};

    // this kind of char array is read-only, s1's element are all NULL(null pointer)
    // Currently, just use char s1[100][100]; to define a string array

    // ctype.h
    // ctype standing for character type, providing functions handling characters

    int (*istype_func[])(int)= {
    isblank, // check if is a blank character that separates words in a line of text(' ', '\t')
    isdigit, // check if is number
    isalpha, // check if is letter
    isalnum, // check if is number or letter
    isxdigit,// check if is 16-based number
    islower, // check if is lowercase letter
    isupper, // check if is uppercase letter
    isspace, // check if is ' '
    iscntrl, // check if is control character (escape sequence other than '\\', '\'', '\"', '\?')
    isprint, // check if is printing character (a character that’s visible on the screen, not include control characters)
    ispunct, // check if is printing character other than letters, digits, space ('$', '%', '#' etc.)
    isgraph};// check if is printing character other than ' '

    printf("Is \"123abcD\" alphabet or number?: %d\n", iswhich("123abcD", istype_func[3]));// Output 1
    printf("Is \"AB1234\" hexadecimal?: %d\n", iswhich("AB1234", istype_func[4]));// Output 1
    printf("Is \"hello world\" lowercase?: %d\n", iswhich("hello world", istype_func[6]));// Output 0
    printf("Is \"AbCd\" uppercase?: %d\n", iswhich("AbCd", istype_func[5]));// Output 0
    printf("Is \"\\t\\n\\r\" control character?: %d\n", iswhich("\t\n\r", istype_func[8]));// Output 1
    printf("Is \"\\\\\\\"a1B\" printing character?: %d\n", iswhich("\\\"a1B", istype_func[9]));// Output 1

    // there are also input and output function for characters

    printf("Input a character: ");
    int n = getchar();// return the input character
    printf("'s integer value is: %d\n", putchar(n));// return n's integer value and output n
    
    //  stdlib.h
    //  also providing functions converts strings to numerical data type
    /*
      1.unsigned long strtoul(const char *s, char **ptr, int base), stand for string to unsigned long:
        convert the leading letters into unsigned long and return (0 for no convertable), ptr points to the remaining string
        base determine the which base number will be read, 16 for hex etc. 0 for all dec, oct, hex with appropriate heading like 0x

      2.long strtoul(const char *s, char **ptr, int base), stand for string to long:
        convert the leading letters into long and return (0 for no convertable), ptr points to the remaining string
        base determine the which base number will be read, 16 for hex etc. 0 for all dec, oct, hex with appropriate heading like 0x

      3.double strtod(const char *s, char **ptr), stand for string to double
        convert the leading letters into double and return (0 for no convertable), ptr points to the remaining string
    */

    char lf_s[] = "8964.114514cnmsbhzq123",
         ul_s1[] = "123AB456hello", 
         ul_s2[] = "0xABCDEFGhhh", 
         ul_s3[] = "012378hhh", 
         l_s[] = "-114514.1ab";
    char *lf_s_ptr = lf_s, *ul_s1_ptr = ul_s1, *ul_s2_ptr = ul_s2, *ul_s3_ptr = ul_s3, *l_s_ptr = l_s;

    double lf; lf = strtod(lf_s, &lf_s_ptr);
    unsigned long ul1; ul1 = strtoul(ul_s1, &ul_s1_ptr, 16);// stand for string to unsigned long
    unsigned long ul2; ul2 = strtoul(ul_s2, &ul_s2_ptr, 0);
    unsigned long ul3; ul3 = strtoul(ul_s3, &ul_s3_ptr, 0);
    long l; l = strtol(l_s, &l_s_ptr, 0);// stand for string to long

    printf("%s becomes %f, ptr points to %s\n", lf_s, lf, lf_s_ptr);
    // Output 8964.114514cnmsbhzq123 becomes 8964.114514, ptr points to cnmsbhzq123
    printf("%s becomes %#lx (%lu), ptr points to %s\n", ul_s1, ul1, ul1, ul_s1_ptr);
    // Output 123AB456hello becomes 0x123ab456 (305837142), ptr points to hello
    printf("%s becomes %#lx (%lu), ptr points to %s\n", ul_s2, ul2, ul2, ul_s2_ptr);
    // Output 0xABCDEFGhhh becomes 0xabcdef (11259375), ptr points to Ghhh
    printf("%s becomes %#lo (%lu), ptr points to %s\n", ul_s3, ul3, ul3, ul_s3_ptr);
    // Output 012378hhh becomes 01237 (671), ptr points to 8hhh
    printf("%s becomes %ld, ptr points to %s\n", l_s, l, l_s_ptr);
    // Output -114514.1ab becomes -114514, ptr points to .1ab

    char *l_s_ptr2 = l_s_ptr;
    l = strtol(l_s_ptr, &l_s_ptr2, 0);
    
    printf("The second time, %s becomes %ld, ptr points to %s\n", l_s_ptr, l, l_s_ptr2);
    // Output The second time, .1ab becomes 0, ptr points to .1ab
    

    // string.h
    // providing functions handling strings
    /*
      1.char *strcpy(char *s1, const char *s2), stand for string copy:
        copy the latter strings to the former, return the former

      2.char *strncpy(char *s1, const char *s2, size_t n), stand for string copy:
        copy the first n characters of the latter to the former, return the former

      3.char *strcat(char *s1, const char *s2), stand for string concatenate
        append the latter strings to the former (overwrite starting from the first '\0' with the latter), return the former
      
      4.char *strncat(char *s1, const char *s2, size_t n), stand for string concatenate
        append the first n characters of the latter strings to the former, return the former  

      5.int strcmp(const char *s1, const char *s2), stand for string compare
        compare two strings, return the -/0/+ (former </==/> latter), base on the characters' ASCII value
    
      6.int strncmp(const char *s1, const char *s2, size_t n), stand for string compare
        compare the first n characters of two strings, return the -/0/+  
    */

    char s3[20] = "007estimation";
    //  s3 = {'0', '0', '7', 'e', 's', 't', 'i', 'm', 'a', 't', 'i', 'o', 'n', '\0', '\0'...}

    printf("%s\n", strcpy(s3, "007cal"));// Output 007cal
    //  s3 = {'0', '0', '7', 'c', 'a', 'l', '\0', 'm', 'a', 't', 'i', 'o', 'n', '\0', '\0'...}
    
    printf("%s\n", s3+7);// Output mation
    //  s3+7 = {'m', 'a', 't', 'i', 'o', 'n', '\0', '\0'...}

    printf("%s\n", strncpy(s3, "114calculation", 3));// Output 114cal
    //  s3 = {'1', '1', '4', 'c', 'a', 'l', '\0', 'm', 'a', 't', 'i', 'o', 'n', '\0', '\0'...}
    


    char s4[20] = "Hello";
    //  s4 = {'H', 'e', 'l', 'l', 'o', '\0', '\0'...}

    printf("%s\n", strcat(s4, " World"));// Output Hello World
    //  s4 = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0', '\0'...}

    s4[5] = '\0';
    //  s4 = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0', '\0'...}

    printf("%s\n", strncat(s4, "114514", 3));// Output Hello114
    //  s4 = {'H', 'e', 'l', 'l', 'o', '1', '1', '4', '\0', 'l', 'd' '\0', '\0'...}

    printf("%s\n", s4+9);// Output ld

    printf("strcmp(\"Hello\", \"Hellos\") = %d\n", strcmp("Hello", "Hellos"));// Output -1
    //  In this case, "Hello" are equal, '\0' (0) < 's' (115)

    printf("strcmp(\"Hello\", \"Hellos\") = %d\n", strncmp("Hello", "Hellos", 5));// Output 0
    //  In this case, "Hello" are equal (first 5 letters)

    printf("strcmp(\"sixseven\", \"Sixseven\") = %d\n", strcmp("sixseven", "Sixseven"));// Output -1
    //  In this case, 's' (115) > 'S' (83)

    /*
      7.char *strchr(const char s, int c), stand for string character:
        find the first occurrence of the character in the string and return the pointer points to the character, NULL for not found

      8.char *strrchr(const char s, int c), stand for string reverse character:
        find the last occurrence of the character in the string and return the pointer points to the character, NULL for not found

      9.size_t strcspn(const char *s, const char *reject_set), stand for string complement span
        find and return the length that how many leading characters not consist of characters in another string
        P.S. string complement span -> span the string for characters belong to the complement of the reject set
      
     10.size_t strspn(const char *s, const char *accept_set), stand for string span
        find and return the length that how many leading characters only consist of characters in another string
        P.S. string span -> but span the string for characters belong to the accept set


     11.char *strpbrk(const char *s, const char *c_array), stand for string pointer break
        find the first occurrence of any character in the another string in the string and return the pointer points to the character
    
     12.char *strstr(const char *s1, const char *s2), stand for string in string
        find the first occurrence of another string in the string and return the pointer points to the former, NULL for not found
    */

    char s5[] = "Hello-world 007,est-mation";

    char *s5_ptr;
    s5_ptr =  strchr(s5, 'o');

    printf("first occurrence of '%c' in \"%s\" is the s5[%d] the remaining part: %s\n", 'o', s5, s5_ptr-s5, s5_ptr);
    //  Output: first occurrence of 'o' in "Hello-world 007-est-mation" is the s5[4] the remaining part: o-world 007-est-mation
    
    s5_ptr =  strrchr(s5, 'o');

    printf("last occurrence of '%c' in \"%s\" is the s5[%d], the remaining part: %s\n", 'o', s5, s5_ptr-s5, s5_ptr);
    //  Output: last occurrence of 'o' in "Hello-world 007-est-mation" is the s5[24], the remaining part: on

    int s5_len;

    s5_len =  strcspn(s5, "farm-war");

    printf("first %d letters of \"%s\" not consists of \"%s\", the remaining part: %s\n", s5_len, s5, "farm-war", s5+s5_len);
    //  Output: first 5 letters of "Hello-world 007-est-mation" not consists of "farm-war", the remaining part: -world 007-est-mation

    s5_len =  strspn(s5, "Hello-west");

    printf("first %d letters of \"%s\" only consists of \"%s\", the remaining part: %s\n", s5_len, s5, "Hello-west", s5+s5_len);
    //  Output: first 8 letters of "Hello-world 007-est-mation" only consists of "Hello-west", the remaining part: rld 007-est-mation

    s5_ptr =  strpbrk(s5, "sit");

    printf("fisrt occurrence of any one in \"%s\" in \"%s\" is the s5[%d], the remaining part: %s\n", "sit", s5, s5_ptr-s5, s5_ptr);
    //  Output: fisrt occurrence of any one in "sit" in "Hello-world 007-est-mation" is the s5[17], the remaining part: st-mation

    s5_ptr =  strstr(s5, "007");

    printf("fisrt occurrence of \"%s\" in \"%s\" is thes5[%d], the remaining part: %s\n", "007", s5, s5_ptr-s5, s5_ptr);
    //  Output: fisrt occurrence of "007" in "Hello-world 007-est-mation" is thes5[12], the remaining part: 007-est-mation

    /*
     13.int strlen(const char *s), stand for string length
        return the length of the string (not size)

     14.char *strtok(char *s, const char *delimiter), stand for string tokenization
        break a string into a series of tokens, which are seperated by delimiters ("-", ",-:;" or other set of characters)
        It requires the address of the strings at the first time, but needn't but a NULL the rest times
        Work as skipping all leading delimiter, find the end of the token and replace the terminating delimiter with '\0'
        Then, return pointer to the start of the token
    */
    
    printf("\"%s\"'s length: %d\n", s5, strlen(s5));// Output 26

    printf("\"%s\" is going to be tokenized into: ", s5);

    char *s5_tok = strtok(s5, "-,");
    printf("\"%s\"", s5_tok);

    for(s5_tok = strtok(NULL, "-,");s5_tok != NULL;s5_tok = strtok(NULL, "-,")){

        printf(", \"%s\"", s5_tok);
    }

    puts("");
    // Output "Hello-world 007-est-mation" is going to be tokenized into: "Hello", "world 007", "est", "mation"

    printf("%s\n", s5);// Output Hello
    // s5 = {'H','e','l','l','o','\0','w','o','r','l','d',' ','0','0','7','\0','e','s','t','\0','m','a','t','i','o','n'}

    /*
        P.S. n is the byte to be processed: size * sizeof(data type) 

     15.void *memchr(const void *s, int c, size_t n), stand for memory character:
        find the first occurrence of the character in the memory block and return the pointer points to the character, NULL for not found

     16.int memcmp(const void *s1, const void *s2, size_t n), stand for memory compare
        compare two memory block, return the -/0/+ (former </==/> latter), base on the bytes' value
      
     17.void *memcpy(void *s1, const void *s2, size_t n), stand for memory copy
        copy the latter memory block to the former, return the former
        undefined behaviour when there is mutual overlapping (also happens in strcpy)

     18.void *memmove(void *s1, const void *s2, size_t n), stand for memory move
        copy the latter memory block to the former, return the former
        but no undefined behaviour when there is mutual overlapping

     19.void *memset(void *s, int c, size_t n), stand for memory set
        set all the bytes of the memory block to the character's value, return the itself

        Different from strcpy, strcmp, strchr, these function work for the memory instead of strings,
        so other data type can also call them (void * does not limit the pointer type)
        for example, for copy a size 4 int array to another, n should be 4 * sizeof (int)
        
        but it has to be careful and wise enough when using mem functions for data type other than string
        For example, accordind to two's complement representation, -1 is 11111111 (up to -256), 1 is 00000001 (up to 255)
        when using memcmp to compare signed int, wrong result will be given if one is +ve, one is -ve
    */

    int a1[] = {1,2,3,4};
    int a2[] = {4,3,2,1};

    printf("memcmp(a1, a2, sizeof(a1)*sizeof(a1[0])): %d\n", memcmp(a1, a2, sizeof(a1)));// Output -1
    //  In this case, 1 < 4, thus return -1

    memcpy(a1, a2, sizeof(a1));
    //  a1 = {4,3,2,1}

    printf("memcmp(a1, a2, sizeof(a1)*sizeof(a1[0])): %d\n", memcmp(a1, a2, sizeof(a1)));// Output 0
    //  In this case, all elements are the same, thus return 0

    char s6[] = "Hello hello";

    printf("s6 becomes \"%s\"\n", memset(s6, '0', 5));// Output "00000 hello"


    return 0;
}

void printsize(char * s1, char s2[]){

    printf("Size of s in pass-by-reference function(char * s): %d\n", sizeof s1);
    printf("Size of s in pass-by-reference function(char s2[]): %d\n", sizeof s2);
}

int iswhich(char s[], int (*type)(int)){

    for(int i = 0; s[i] != '\0'; ++i){

        if(!(*type)(s[i])){

            return 0;
        }
    }

    return 1;
}