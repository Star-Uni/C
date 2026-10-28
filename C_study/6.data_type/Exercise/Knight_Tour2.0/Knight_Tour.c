#include <stdio.h>


int Move_Hor(int x);
int Move_Ver(int x);
void Update_Acc(int current_hor, int current_ver, int accessibility[][8]);
void Print_Table(int table[][8]);
int Decide_Move(int current_hor, int current_ver, int table[][8], int accessibility[][8]);
int Decide_Tied_Move(int current_hor, int current_ver, int table[][8], int accessibility[][8], int tied_move[], int tie);

int main(){

    int table[8][8] = {0};
    int accessibility[8][8] = 
    {{2,3,4,4,4,4,3,2},
    {3,4,6,6,6,6,4,3},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {3,4,6,6,6,6,4,3},
    {2,3,4,4,4,4,3,2}};

    int current_hor, current_ver;
    current_ver = 4;
    current_hor = 5;

    table[current_ver][current_hor] = 1;

    for(int step = 2;step <= 64;++step){

        int move = Decide_Move(current_hor, current_ver, table, accessibility);

        if(move == -1){
            
            printf("Fail, Only %d steps are made", step-1);
            break;
        }

        Update_Acc(current_hor, current_ver, accessibility);

        current_ver += Move_Ver(move);
        current_hor += Move_Hor(move);

        table[current_ver][current_hor] = step;

        Print_Table(table);
        puts("");
    }

    return 0;
}


int Move_Hor(int x){

    int hor[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    return hor[x];
}

int Move_Ver(int x){

    int ver[] = {1, 2, 2, 1, -1, -2, -2, -1};

    return ver[x];
}

void Update_Acc(int current_hor, int current_ver, int accessibility[][8]){

    for(int i = 0; i<8 ;++i){

        if(current_ver+Move_Ver(i) >= 0 && current_ver+Move_Ver(i) <= 7 && current_hor+Move_Hor(i) <= 7 && current_hor+Move_Hor(i) >= 0){
        
            accessibility[current_ver+Move_Ver(i)][current_hor+Move_Hor(i)] -= 1;
        }
    }
}

void Print_Table(int table[][8]){

    printf("   %-3d%-3d%-3d%-3d%-3d%-3d%-3d%-3d\n",0,1,2,3,4,5,6,7);

    for(size_t i = 0;i < 8;++i){

        printf("%-3d",i);

        for(size_t j = 0;j < 8;++j){

            printf("%-3d",table[i][j]);
        }

        puts("");
    }
}

int Decide_Move(int current_hor, int current_ver, int table[][8], int accessibility[][8]){

    int move = -1;
    int curr_acc = 8;
    int tied_move[8];
    int tie = 0;

    for(int i = 0;i < 8;++i){

        if((current_ver+Move_Ver(i) >= 0 && current_ver+Move_Ver(i) <= 7 && current_hor+Move_Hor(i) <= 7 && current_hor+Move_Hor(i) >= 0) && table[current_ver+Move_Ver(i)][current_hor+Move_Hor(i)] == 0){
            
            if(curr_acc > accessibility[current_ver+Move_Ver(i)][current_hor+Move_Hor(i)]){

                curr_acc = accessibility[current_ver+Move_Ver(i)][current_hor+Move_Hor(i)];
                move = i;
            }
        }
    }

    for(int i = 0;i < 8;++i){

        if((current_ver+Move_Ver(i) >= 0 && current_ver+Move_Ver(i) <= 7 && current_hor+Move_Hor(i) <= 7 && current_hor+Move_Hor(i) >= 0) && table[current_ver+Move_Ver(i)][current_hor+Move_Hor(i)] == 0){
                
            if(curr_acc == accessibility[current_ver+Move_Ver(i)][current_hor+Move_Hor(i)]){

                tied_move[tie++] = i;
            }
        }
    }

    if(tie > 1){

        return Decide_Tied_Move(current_hor, current_ver, table, accessibility, tied_move, tie);
    }

    return move;
}

int Decide_Tied_Move(int current_hor, int current_ver, int table[][8], int accessibility[][8], int tied_move[], int tie){

    int lowest_acc = 8;
    int best_move = -1;

    for(int i = 0;i < tie;++i){

        int fore_hor = current_hor + Move_Hor(tied_move[i]);
        int fore_ver = current_ver + Move_Ver(tied_move[i]);
        int fore_table[8][8];

        for(size_t i = 0;i < 8;++i){

            for(size_t j = 0;j < 8;++j){

                fore_table[i][j] = table[i][j];
            }
        }

        fore_table[fore_ver][fore_hor] = -1;

        int fore_move = Decide_Move(fore_hor, fore_ver, fore_table, accessibility);

        int fore_acc = accessibility[fore_ver+Move_Ver(fore_move)][fore_hor+Move_Hor(fore_move)];
        
        if(lowest_acc > fore_acc){

            lowest_acc = fore_acc;
            best_move = tied_move[i];
        }
    }

    return best_move;
}
