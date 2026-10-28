#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

int checkrepeat(char names[][33], int name_frequency[], char name[], int name_idx);

int main(){

    int n;

    scanf(" %d", &n);

    char name[n][33];
    
    int name_frequency[MAX_SIZE] = {0};

    for(int i = 0, j = 0; i < n; ++i){

        scanf(" %s", name+i);
    }

    for(int i = 0, j = 0; i < n; ++i){
        
        int repeat = 0;

        if(repeat = checkrepeat(name, name_frequency, name[i], i)){

            printf("%s%d\n", name[i], repeat);
        }
        else{

            puts("OK");
        }
    }

    return 0;
}

int checkrepeat(char names[][33], int name_frequency[], char name[], int name_idx){

    for(int i = name_idx-1; i >= 0; --i){

        if(!strcmp(names[i], name)){

            name_frequency[name_idx] += 1 + name_frequency[i];

            return name_frequency[name_idx];
        }
    }

    return 0;
}