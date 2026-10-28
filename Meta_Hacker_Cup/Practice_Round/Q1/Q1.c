#include <stdio.h>
#include <limits.h>

typedef struct{

    const int temp;
    const int target;
}Dish;

void warm_up_dish(Dish cases[], int size);
int *find_max_ptr(Dish cases[]);

int main(){

    int n;

    scanf(" %d", &n);

    for(int i = 0; i < n; ++i){

        int dish_num;

        scanf(" %d", &dish_num);

        Dish cases[dish_num];

        for(int j = 0; j < dish_num; ++j){

            scanf(" %d", &cases[j].temp);
        }

        for(int j = 0; j < dish_num; ++j){

            scanf(" %d", &cases[j].target);
        }

        int *max_ptr = find_max_ptr(cases);

        

    }
    
}

int *find_max_ptr(Dish cases[]){

    int max = -1;
    int *max_ptr;

    for(int i = 0; cases[i].temp != 0; ++i){

        (max < cases[i].temp)?max_ptr = &(cases[i].temp):NULL;
        (max < cases[i].temp)?max = cases[i].temp:1;
    }

    return max_ptr;
}

void warm_up_dish(Dish cases[], int size){

    for(int i = 0; i < size; ++i){
        
    }
}