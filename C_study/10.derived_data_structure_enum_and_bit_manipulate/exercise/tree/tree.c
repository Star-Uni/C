#include <stdio.h>

int m, n;

int count = 0; 

void init_effect_idx(char grids[][n+1], int effect_index[][n]);

void plant(char grids[][n+1], int effect_index[][n]);

int main()
{
    scanf(" %d %d",&m, &n);

    char grids[m][n+1];

    int effect_index[m][n];

    for (int i = 0; i < m; i++) {

        scanf("%s", &grids[i]); 
    }

    init_effect_idx(grids, effect_index);
    plant(grids, effect_index);

    printf("%d", count);
    
    return 0;
}

void plant(char grids[][n+1], int effect_index[][n]){

    void update(int effect_index[][n], int x, int y);

    int best = 10, best_x, best_y;

    for(int i = 0; i < m; ++i){

        for(int j = 0; j < n; ++j){

            if(effect_index[i][j] == -1){

                continue;
            }
            else{

                if(best > effect_index[i][j]){

                    best = effect_index[i][j];
                    best_x = i, best_y = j;
                }
            }
        }
    }

    if(best != 10){

        update(effect_index, best_x, best_y);

        count++;

        plant(grids, effect_index);
    }
    else{

        return;
    }

    return;
}

void init_effect_idx(char grids[][n+1], int effect_index[][n]){

    int check_3x3(char grids[][n+1], int x, int y);

    for(int i = 0; i < m; ++i){

        for(int j = 0; j < n; ++j){

            if(grids[i][j] == '#'){

                effect_index[i][j] = -1;
            }
            else{

                effect_index[i][j] =  check_3x3(grids, i, j);
            }
        }
    }

    return;
}

int check_3x3(char grids[][n+1], int x, int y){

    int count = 0;

    for(int i = x-1; i <= x+1; ++i){

        for(int j = y-1; j <= y+1; ++j){

            if(i >= 0 && j >= 0 && i < m && j < n && i != x && j != y){

                count += ((grids[i][j] == '.')?1:0);
            }
        }
    }

    return count;
}

void update(int effect_index[][n], int x, int y){

    void update_effect_idx(int effect_index[][n], int x, int y);

    effect_index[x][y] = -1;

    for(int i = x-1; i <= x+1; ++i){

        for(int j = y-1; j <= y+1; ++j){

            if(i >= 0 && j >= 0 && i < m && j < n && i != x && j != y){
                
                if(effect_index[i][j] != -1){

                    update_effect_idx(effect_index, i, j);
                    effect_index[i][j] = -1;
                }
            }
        }
    }

    return;
}

void update_effect_idx(int effect_index[][n], int x, int y){

    for(int i = x-1; i <= x+1; ++i){

        for(int j = y-1; j <= y+1; ++j){

            if(i >= 0 && j >= 0 && i < m && j < n && i != x && j != y){
                
                if(effect_index[i][j] != -1){

                    effect_index[i][j] -= 1;
                }
            }
        }
    }

    return;
}