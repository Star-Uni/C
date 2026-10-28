#include <stdio.h>
#include <stdlib.h>

typedef struct lady{
    
    int b;
    int i;
    int w;
    int s;
}Lady;

int compar(const void *a, const void *b);

int main(){

    int n, count = 0;

    scanf(" %d", &n);

    Lady ladies[n]; 

    for(int i = 0; i < n; ++i){

        scanf(" %d", &((ladies+i)->b));
        ladies[i].s = 0;
    }
    for(int i = 0; i < n; ++i){

        scanf(" %d", &((ladies+i)->i));
    }
    for(int i = 0; i < n; ++i){

        scanf(" %d", &((ladies+i)->w));
    }

    qsort(ladies, n, sizeof(Lady), compar);

    for(int i = 0; i < n; ++i){

        if(ladies[i].s){

            continue;
        }

        for(int j = i+1; j < n; ++j){

            if(ladies[j].s){

                continue;
            }

            if(ladies[i].b > ladies[j].b && ladies[i].i > ladies[j].i && ladies[i].w > ladies[j].w){

                ladies[j].s = 1;
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}

int compar(const void *a, const void *b){

    int b_diff = ((Lady *)b)->b - ((Lady *)a)->b;

    if(!b_diff){

        int i_diff = ((Lady *)b)->i - ((Lady *)a)->i;

        if(!i_diff){

            int w_diff = ((Lady *)b)->w - ((Lady *)a)->w;

            if(!w_diff){

                return 0;
            }
            else{

                return w_diff;
            }
        }
        else{

            return i_diff;
        }
    }

    return ((Lady *)b)->b - ((Lady *)a)->b;
}