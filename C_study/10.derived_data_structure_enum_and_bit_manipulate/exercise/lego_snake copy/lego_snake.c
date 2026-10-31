#include <stdio.h>

int w,b,n;

long long layers[20][19][19];

void increment(int x, int y, int layer);

void init_layer(int layer);

void print_layer(int layer);

int main(){

    scanf(" %d %d %d", &n, &w, &b);

    for(int k = 0; k < n;++k){

        init_layer(k);

        for(int i = 0; i < b-1;++i){

            if(!k){ 
            
                layers[k][b/2 - 1][w/2 - 1] = 1;
                break;
            }

            for(int j = 0; j < w-1;++j){

                increment(i, j, k);
            }
        }

        //print_layer(layers, k);
    }


    long long count = 0;
    for(int i = 0; i < b-1;++i){

        for(int j = 0; j < w-1;++j){

            count += layers[n-1][i][j] ;
        }
    }

    printf("%lld", count);
    
    return 0;
}

void increment(int x, int y, int layer){

    for(int i = x-1; i <= x+1; ++i){

        for(int j = y-1; j <= y+1; ++j){

            if(i >= 0 && j >= 0 && i < b-1 && j < w-1){

                layers[layer][i][j] += layers[layer-1][x][y];
            }
        }
    }

    return;
}

void init_layer(int layer){

    for(int i = 0; i < b-1;++i){

        for(int j = 0; j < w-1;++j){

            layers[layer][i][j] = 0;
        }
    }

    return;
}

void print_layer(int layer){ // only for small sample debugging, just ignore 

    for(int i = 0; i < b-1;++i){

        for(int j = 0; j < w-1;++j){

            printf("%4lld", layers[layer][i][j]);
        }
        puts("\n");
    }

    puts("");

    return;
}