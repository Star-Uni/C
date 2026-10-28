#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int kayak_num = 0, catamaran_num = 0;
    
int kayak_cap[MAX_SIZE], catamaran_cap[MAX_SIZE];
int kayak_cap_num[MAX_SIZE], catamaran_cap_num[MAX_SIZE];
int kayak_cap_index[MAX_SIZE], catamaran_cap_index[MAX_SIZE];

int max_cap = 0;
int vehicles[MAX_SIZE];

int vehicle_num = 0;

int cataraman_index_cmp(const void *a, const void *b);
int kayak_index_cmp(const void *a, const void *b);
int asc_cmp(const void *a, const void *b);

int decide(int kayak_cap1, int kayak_cap2, int catamaran_cap1);
void Sort(int a[], int a_index[], int size);
void append_catamaran(int *v);
void append_kayak(int *v);

int main(){

    int volume, n;

    scanf(" %d %d", &n, &volume);

    for(int i = 1, temp; kayak_num + catamaran_num < n; ++i){

        scanf(" %d", &temp);

        if(temp == 1){

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

    for(; volume - kayak_num > 1 && volume > 1 && catamaran_num > 0;){

        append_catamaran(&volume);
    }

    if(volume % 2 == 1 && kayak_num > 0){

        max_cap += kayak_cap[kayak_cap_index[--kayak_num]];
        vehicles[vehicle_num++] = kayak_cap_num[kayak_cap_index[kayak_num]];

        volume--;
    }

    for(; volume > 0 && (kayak_num || catamaran_num);){

        if (!kayak_num && volume >= 2){

            append_catamaran(&volume);
        }
        else if (!catamaran_num){

            append_kayak(&volume);
        }
        else if(volume >= 2){

            if(decide(kayak_cap[kayak_cap_index[kayak_num-1]], (kayak_num <= 1)? 0: kayak_cap[kayak_cap_index[kayak_num-2]], catamaran_cap[catamaran_cap_index[catamaran_num-1]])){

                append_kayak(&volume);
            }
            else{

                append_catamaran(&volume);
            }

        }
        else if(kayak_num && volume == 1){

            append_kayak(&volume);
        }
        else{

            break;
        }


    }

    printf("%d\n", max_cap);

    for(int i = 0; i < vehicle_num; ++i){

        printf("%d ", vehicles[i]);
    }
    return 0;
}

int decide(int kayak_cap1, int kayak_cap2, int catamaran_cap1){

    if(!kayak_cap2){

        if(kayak_cap1 > catamaran_cap1){

            return 1;
        }
        else{

            return 0;
        }
    }
    else if(kayak_cap1 + kayak_cap2 > catamaran_cap1){

        return 1;
    }
    else{

        return 0;
    }
}

void append_catamaran(int *v){

    max_cap += catamaran_cap[catamaran_cap_index[--(catamaran_num)]];
    vehicles[(vehicle_num)++] = catamaran_cap_num[catamaran_cap_index[catamaran_num]];

    *v -= 2;
}

void append_kayak(int *v){

    if(kayak_num > 1 && *v > 1){

        max_cap += kayak_cap[kayak_cap_index[--(kayak_num)]] + kayak_cap[kayak_cap_index[kayak_num-1]];
        vehicles[(vehicle_num)++] = kayak_cap_num[kayak_cap_index[kayak_num]];
        vehicles[(vehicle_num)++] = kayak_cap_num[kayak_cap_index[--(kayak_num)]];

        *v -= 2;
    }
    else{

        max_cap += kayak_cap[kayak_cap_index[--(kayak_num)]];
        vehicles[(vehicle_num)++] = kayak_cap_num[kayak_cap_index[kayak_num]];

        *v -= 1;
    }
}

int cataraman_index_cmp(const void *a, const void *b){

    int a_index = *(int*)a;
    int b_index = *(int*)b;
    
    return catamaran_cap[a_index] - catamaran_cap[b_index];
}

int kayak_index_cmp(const void *a, const void *b){

    int a_index = *(int*)a;
    int b_index = *(int*)b;
    
    return kayak_cap[a_index] - kayak_cap[b_index];
}
