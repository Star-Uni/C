#include <stdio.h>
#include <string.h>
#include <math.h>

int max(int a[], int n);

int main(){

    int n;

    scanf("%d", &n);

    char name[n][33];
    int score[n];

    char player[n][33];
    int player_score[n];

    for(int i = 0;i < n;++i){

        scanf(" %s %d", name[i], &score[i]);
    }

    strcpy(player[0], name[0]);
    player_score[0] = score[0];

    int player_num = 1;

    for(int i = 1; i < n; ++i){

        int flag = 1;
        for(int j = 0; j < (sizeof player / sizeof player[0]);j++){

            if(!strcmp(name[i],player[j])){

                player_score[j] += score[i];
                flag = 0;
                break;
            }
        }

        if(flag){

            strcpy(player[player_num], name[i]);
            player_score[player_num++] = score[i];
        }
    }
    
    int max_score = max(player_score, player_num);
    char winner[n][33];
    int winner_num = 0;

    for(int i = 0; i < player_num;++i){

        (player_score[i] == max_score)?(strcpy(winner[winner_num++], player[i])):(NULL);
    }

    int winner_score[winner_num];

    for(int i = 0; i < winner_num;++i){

        winner_score[i] = 0;
    }

    for(int i = 0; i < n; ++i){

        int flag = 0;

        for(int j = 0; j < winner_num;j++){

            if(!strcmp(name[i],winner[j])){

                winner_score[j] += score[i];

                if(winner_score[j] >= max_score){

                    printf("%s", winner[j]);
                    flag = 1;
                }

                break;
            }
        }

        if(flag){

            break;
        }
    }

    return 0;
}

int max(int a[], int n){

    int max = 0;

    for(int i = 0; i < n;++i){

        (a[i] > max)?max = a[i]:1;
    }

    return max;
}