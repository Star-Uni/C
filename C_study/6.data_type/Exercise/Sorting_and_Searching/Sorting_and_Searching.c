#include <stdio.h>
#include <stdlib.h>

void Bubble_Sort(int a[], int index);
void Selection_Sort(int a[], int index);
void Insertion_Sort(int a[], int index);
int Binary_Search(int target, int a[], int index);


int random_number(int start, int end);
void print_array(char array_name[], int a[], int size);
char *print_element(char array_name[], int index);

int main(void){

    srand(100);

    int array1[10],array2[10],array3[10];

    for(size_t i = 0;i < 10;++i){

        array1[i] = random_number(1,100);
        array2[i] = random_number(1,100);
        array3[i] = random_number(1,100);
    }

    puts("array1 before bubble sorting:");
    print_array("array1", array1, 10);

    Bubble_Sort(array1, 10);

    puts("array1 after bubble sorting:");
    print_array("array1", array1, 10);


    puts("array2 before selection sorting:");
    print_array("array2", array2, 10);

    Selection_Sort(array2, 10);

    puts("array2 after selection sorting:");
    print_array("array2", array2, 10);


    puts("array3 before insertion sorting:");
    print_array("array3", array3, 10);

    Insertion_Sort(array3, 10);

    puts("array3 after insertion sorting:");
    print_array("array3", array3, 10);

    
    int one_to_thousand[1000];
    
    for(int i = 1;i <= 1000;++i){

        one_to_thousand[i-1] = i;
    }

    int array[100];

    for(size_t i = 0;i < 100;++i){

        int temp = random_number(i+1,1000);

        array[i] = one_to_thousand[temp];

        one_to_thousand[temp] = -1;
        Selection_Sort(one_to_thousand,1000);
    }

    Selection_Sort(array, 100);

    int correct_index = random_number(0,99);
    printf("Correct index is %d\n", correct_index);

    printf("Index returned by function is %d\n", Binary_Search(array[correct_index],array,100));
    

}

void Bubble_Sort(int a[], int index){

    int temp;

    for(size_t i = index;i > 0;--i){

        for(size_t j = 1;j < i;++j){

            if(a[j] < a[j-1]){

                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}

void Selection_Sort(int a[], int index){

    int temp, min, min_index;

    for(size_t i = 0;i<index-1;++i){

        min = a[i];
        min_index = -1;

        for(size_t j = i+1;j<index;++j){

            if(a[j] < min){ 

                min = a[j];
                min_index = j;
            }
        }

        if(min_index == -1){

            continue;
        }
        else{

            temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

void Insertion_Sort(int a[], int index){

    int temp;

    for(size_t i = 1;i<index;++i){

        for(size_t j = 0;j<i;++j){

            if(a[i] < a[j]){ 

                temp = a[i];

                for(size_t x = i;x > j;--x){

                    a[x] = a[x-1];
                }

                a[j] = temp;
                break;
            }
        }
    }
}

int random_number(int start, int end){

    return rand()%(end-start)+start;
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

    printf("%-12s", array_name);

    for(size_t i = 0;i < size;++i){

        printf("%-12s", print_element(array_name, i));
    } 

    puts("");
    printf("%-12s", "Elements");

    for(size_t i = 0;i < size;++i){

        printf("%-12d", a[i]);
    } 

    puts("\n");
}

int Binary_Search(int target, int a[], int index){

    int count = 0;
    int left = 0;
    int right = index - 1;
    int mid = (left + right) / 2;

    while(left <= right){

        count += 1;

        if(a[mid] > target){

            right = mid - 1;
            mid = (left + right) / 2;
        }
        else if(a[mid] < target){

            left = mid + 1;
            mid = (left + right) / 2;
        }
        else{

            printf("Find after %d execution\n", count);
            return mid;
        }
    }

    puts("Not Found");
    return -1;
}