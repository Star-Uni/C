#include <stdio.h>
#include <stdlib.h>

int *kayak_cap_ptr, *catamaran_cap_ptr;

int cataraman_index_cmp(const void *a, const void *b);
int kayak_index_cmp(const void *a, const void *b);
int asc_cmp(const void *a, const void *b);

int decide(int kayak_cap1, int kayak_cap2, int catamaran_cap);
void Sort(int a[], int a_index[], int size);
void append_catamaran(int *max_cap, int *catamaran_num, int catamaran_cap[], int catamaran_cap_num[], int catamaran_cap_index[], int vehicles[], int *v_num);
void append_kayak(int *max_cap, int *kayak_num, int kayak_cap[], int kayak_cap_num[], int kayak_cap_index[], int vehicles[], int *v_num, int *v);

int main(){

    int volume, n;

    scanf(" %d %d", &n, &volume);
    
    int kayak_cap[n], catamaran_cap[n];
    int kayak_cap_num[n], catamaran_cap_num[n];
    int kayak_cap_index[n], catamaran_cap_index[n];
    int kayak_num = 0, catamaran_num = 0;

    kayak_cap_ptr = kayak_cap;
    catamaran_cap_ptr = catamaran_cap;

    int max_cap = 0;
    int vehicles[n];

    for(int i = 1; kayak_num + catamaran_num < n; ++i){

        getchar();

        if(getchar() == '1'){

            scanf(" %d", &kayak_cap[kayak_num]);
            kayak_cap_index[kayak_num] = kayak_num;
            kayak_cap_num[kayak_num++] = i;
        }
        else{

            scanf(" %d", &catamaran_cap[catamaran_num]);
            catamaran_cap_index[catamaran_num] = catamaran_num;
            catamaran_cap_num[catamaran_num++] = i;
        }
    }

    
    qsort(catamaran_cap_index, catamaran_num, sizeof (int), cataraman_index_cmp);
    qsort(kayak_cap_index, kayak_num, sizeof (int), kayak_index_cmp);
    qsort(catamaran_cap, catamaran_num, sizeof (int), asc_cmp);
    qsort(kayak_cap, kayak_num, sizeof (int), asc_cmp);

    int vehicle_num = 0;

    for(; volume - kayak_num > 1 && volume > 1 && catamaran_num > 0;){

        append_catamaran(&max_cap, &catamaran_num, catamaran_cap, catamaran_cap_num, catamaran_cap_index, vehicles, &vehicle_num);

        volume -= 2;
    }

    if(volume % 2 == 1 && kayak_num > 0){

        max_cap += kayak_cap[--kayak_num];
        vehicles[vehicle_num++] = kayak_cap_num[kayak_cap_index[kayak_num]];

        volume--;
    }

    for(; volume > 0;){

        if(!kayak_num && !catamaran_num){

            break;
        }
        else if (!kayak_num){

            if(volume >= 2){

                append_catamaran(&max_cap, &catamaran_num, catamaran_cap, catamaran_cap_num, catamaran_cap_index, vehicles, &vehicle_num);

                volume -= 2;
            }
            else{

                break;
            }
        }
        else if (!catamaran_num){

            append_kayak(&max_cap, &kayak_num, kayak_cap, kayak_cap_num, kayak_cap_index, vehicles, &vehicle_num, &volume);
        }
        else if(volume >= 2){

            if(decide(kayak_cap[kayak_num-1], (kayak_num <= 1)? 0: kayak_cap[kayak_num-2], catamaran_cap[catamaran_num-1])){

                append_kayak(&max_cap, &kayak_num, kayak_cap, kayak_cap_num, kayak_cap_index, vehicles, &vehicle_num, &volume);
            }
            else{

                append_catamaran(&max_cap, &catamaran_num, catamaran_cap, catamaran_cap_num, catamaran_cap_index, vehicles, &vehicle_num);

                volume -= 2;
            }

        }
        else{

            max_cap += kayak_cap[--kayak_num];
            vehicles[vehicle_num++] = kayak_cap_num[kayak_cap_index[kayak_num]];

            volume--;
        }


    }

    printf("%d\n", max_cap);

    for(int i = 0; i < vehicle_num; ++i){

        printf("%d ", vehicles[i]);
    }
    return 0;
}

int decide(int kayak_cap1, int kayak_cap2, int catamaran_cap){

    if(!kayak_cap2){

        if(kayak_cap1 > catamaran_cap){

            return 1;
        }
        else{

            return 0;
        }
    }
    else if(kayak_cap1 + kayak_cap2 > catamaran_cap){

        return 1;
    }
    else{

        return 0;
    }
}

void append_catamaran(int *max_cap, int *catamaran_num, int catamaran_cap[], int catamaran_cap_num[], int catamaran_cap_index[], int vehicles[], int *v_num){

    *max_cap += catamaran_cap[--(*catamaran_num)];
    vehicles[(*v_num)++] = catamaran_cap_num[catamaran_cap_index[*catamaran_num]];
}

void append_kayak(int *max_cap, int *kayak_num, int kayak_cap[], int kayak_cap_num[], int kayak_cap_index[], int vehicles[], int *v_num, int *v){

    if(*kayak_num > 1 && *v > 1){

        *max_cap += kayak_cap[--(*kayak_num)] + kayak_cap[*kayak_num-1];
        vehicles[(*v_num)++] = kayak_cap_num[kayak_cap_index[*kayak_num]];
        vehicles[(*v_num)++] = kayak_cap_num[kayak_cap_index[--(*kayak_num)]];

        *v -= 2;
    }
    else{

        *max_cap += kayak_cap[--(*kayak_num)];
        vehicles[(*v_num)++] = kayak_cap_num[kayak_cap_index[*kayak_num]];

        *v -= 1;
    }
}

int cataraman_index_cmp(const void *a, const void *b){

    int a_index = *(int*)a;
    int b_index = *(int*)b;
    
    return catamaran_cap_ptr[a_index] - catamaran_cap_ptr[b_index];
}

int kayak_index_cmp(const void *a, const void *b){

    int a_index = *(int*)a;
    int b_index = *(int*)b;
    
    return kayak_cap_ptr[a_index] - kayak_cap_ptr[b_index];
}

int asc_cmp(const void *a, const void *b){

    return *(int*)a - *(int*)b;
}