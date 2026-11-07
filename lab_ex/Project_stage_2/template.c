/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : <your name>
 * Student ID    : <your student ID>
 * Class/Section : <your class/section>
 * Date          : <date>
 */


// [DO NOT MODIFY]
// DO NOT ADD new header files

#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 40
#define INITIAL_RANGE 1

// In Part 2, BOMB_FUSE must be changed.
#define BOMB_FUSE 4

/* Square states specified in the project document. */
#define CORRIDOR 7
#define WALL 9
#define BRICK_EMPTY 8
#define BRICK_BOOST 6
#define BOOST 5
#define PLAYER 1
#define PLAYER_ON_BOMB 3
#define BOMB 2
#define EXPLODE 4
#define EXPLODE_BOOST -1
// END OF [DO NOT MODIFY]

/* Indexes in the state[] array specified in the project document. */
#define STATE_FIELDS 15     // no. of fields
#define PLAYER_ROW 0		// player location
#define PLAYER_COL 1		// player location
#define PLAYER_ALIVE 2 		// player status (for game end checks)
#define EXPLOSION_RANGE 3 	// current bomb explosion range
#define BOMB_ACTIVE 4 		// current bomb state
#define BOMB_ROW 5			// current bomb row index
#define BOMB_COL 6			// current bomb column index
#define BOMB_TIMER 7		// current bomb timer value
#define ACTION_COUNT 8		// number of user valid actions (WASD + PB)
#define MOVE_COUNT 9		// number of user valid movement (WASD)
#define BOMB_COUNT 10		// total bombs dropped
#define BRICKS_REMAINS 11	// game statistics
#define BRICKS_DESTROYED 12	// game statistics
#define BOOSTS_DROPPED 13	// game statistics
#define BOOSTS_COLLECTED 14	// game statistics

// The GAME STATUS constants
#define GAME_RUNNING 0
#define GAME_WON 1
#define GAME_LOST 2

// [DO NOT MODIFY] 
void initialise(int board[][MAX_COLS], int size[], int state[]);
void displayBoard(int board[][MAX_COLS], int size[], int state[]);
void displayLegend(int state[]);
int movePlayer(int board[][MAX_COLS], int size[], int state[], int rowChange, int colChange);
int dropBomb(int board[][MAX_COLS], int state[]);
void advanceTime(int board[][MAX_COLS], int size[], int state[]);
void explodeBomb(int board[][MAX_COLS], int size[], int state[]);
void endGameMessage(int state[], int win); // e.g., win can take GAME_WON or GAME_LOST or otherwise
// END OF [DO NOT MODIFY]

/* Define your helper functions prototype below. You can implement it somewhere else in this file.*/



/* DO NOT DECLARE EXTRA GLOBAL VARIABLES */

int main(void) {
    // Suggested starter variables
    int board[MAX_ROWS][MAX_COLS];
    int size[2];
    int state[STATE_FIELDS];
    
    int game_quit = 0;

    // Initialize the game board
    initialise(board, size, state);

    // Pseudocode
    /* While the game is still running
            Display Board, Legend, and ask for input 
            Read the user input and process it
            Check End Game condition
        
       Display Board and Legend
       Display End Game Message and Statistics
    */

    for(;!game_quit;){

        displayBoard(board, size, state);
        displayLegend(state);

        char input;
        int length = 1;
        scanf(" %c%*[^\n]%n", &input, &length);

        if(length != 1){

            puts("Invaild Input");
            continue;
        }

        switch(input){
            case 'W':
            case 'w':{
                    
                movePlayer(board, size, state, -1, 0)?advanceTime(board, size, state):puts("Error: a wall, soft brick, or bomb blocks the movement.");
                break;
            }
            case 'A':
            case 'a':{
                    
                movePlayer(board, size, state, 0, -1)?advanceTime(board, size, state):puts("Error: a wall, soft brick, or bomb blocks the movement.");
                break;
            }
            case 'S':
            case 's':{
                    
                movePlayer(board, size, state, 1, 0)?advanceTime(board, size, state):puts("Error: a wall, soft brick, or bomb blocks the movement.");
                break;
            }
            case 'D':
            case 'd':{
                    
                movePlayer(board, size, state, 0, 1)?advanceTime(board, size, state):puts("Error: a wall, soft brick, or bomb blocks the movement.");
                break;
            }
            case 'B':
            case 'b':{
                    
                dropBomb(board, state)?advanceTime(board, size, state):puts("Error: an unexploded bomb already exists.");
                break;
            }
            case 'P':
            case 'p':{

                state[ACTION_COUNT]++;
                advanceTime(board, size, state);
                break;
            }
            case 'Q':
            case 'q':{
            
                game_quit = 1;
                puts("Game saved in save.txt.");
                
                displayBoard(board, size, state);
                displayLegend(state);
                endGameMessage(state, 0);

                FILE *file_ptr;
                file_ptr = fopen("save.txt", "w");

                for(int i = 0; i < STATE_FIELDS; ++i){

                    fprintf(file_ptr ,"%d ", state[i]);
                }

                fprintf(file_ptr ,"\n%d %d\n", size[0], size[1]);

                for(int i = 0; i < size[0]; ++i){

                    for(int j = 0; j < size[1]; ++j){

                        fprintf(file_ptr ,"%d ", board[i][j]);
                    }

                    fprintf(file_ptr, "\n");
                }

                fclose(file_ptr);

                break;
            }
            default:{
            
                puts("Error: enter W, A, S, D, B, P, or Q.");
                break;
            }
        }
        
        if(!state[PLAYER_ALIVE]){

            displayBoard(board, size, state);
            displayLegend(state);
            endGameMessage(state, GAME_LOST);

            break;
        }
        else if(!state[BRICKS_REMAINS]){

            displayBoard(board, size, state);
            displayLegend(state);
            endGameMessage(state, GAME_WON);

            break;
        }

    }

    return 0;
}

void initialise(int board[][MAX_COLS], int size[], int state[]) {
    // The hardcoded game board
    FILE *file_ptr;
    int save = 0;

    if((file_ptr = fopen("save.txt", "r")) == NULL){

        file_ptr = fopen("board.txt", "r");
    }
    else{

        for(;1;){
            
            printf("A save.txt exists. Reload? [Y/N]: ");

            char temp;
            int length = 1;
            scanf(" %c%*[^\n]%n", &temp, &length);

            if(length != 1){

                puts("Invaild Input");
            }
            else if(temp == 'n' || temp == 'N'){

                file_ptr = fopen("board.txt", "r");
                break;
            }
            else if(temp == 'y' || temp == 'Y'){

                for(int i = 0; i < STATE_FIELDS; ++i){

                    fscanf(file_ptr, " %d", state+i);
                }

                save = 1;

                break;
            }
            else{
                
                puts("Invaild Input");
            }
        }
    }
    
    int row;
    int col;

    fscanf(file_ptr, " %d %d", &row, &col);

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){

            fscanf(file_ptr, " %d", board[i]+j);

            board[i][j] == EXPLODE?(board[i][j] = CORRIDOR):1;
            board[i][j] == EXPLODE_BOOST?(board[i][j] = BOOST):1;
        }
    }

    size[0] = row, size[1] = col;

    fclose(file_ptr);

    // Initialize the game board, size, and state
    if(!save){

        state[PLAYER_ALIVE] = 1;
        state[EXPLOSION_RANGE] = INITIAL_RANGE;
        state[BOMB_ACTIVE] = 0;
        state[ACTION_COUNT] = 0;
        state[MOVE_COUNT] = 0;
        state[BOMB_COUNT] = 0;
        state[BRICKS_DESTROYED] = 0;
        state[BRICKS_REMAINS] = 0;
        state[BOOSTS_DROPPED] = 0;
        state[BOOSTS_COLLECTED] = 0;

        
        for(int i = 0; i < row; ++i){

            for(int j = 0; j < col; ++j){

                switch (board[i][j]){

                    case PLAYER:{
                        
                        state[PLAYER_ROW] = i, state[PLAYER_COL] = j;
                        break;
                    }
                    case BRICK_EMPTY:
                    case BRICK_BOOST:{
                        
                        state[BRICKS_REMAINS]++;
                        break;
                    }
                    default:{

                        break;
                    }
                }
            }
        }
    }
    return;
}

void displayBoard(int board[][MAX_COLS], int size[], int state[]){

    char *CELLS[9] = {"@@", "BB", "@B", "##", "EX", "()", "  ", "()", "[]"};

    for(int i = 0; i < size[0]; i++){

        for(int j = 0; j < size[1]; j++){

            if(board[i][j] == EXPLODE_BOOST){

                printf("%s", CELLS[EXPLODE-1]);
                continue;
            }

            printf("%s", CELLS[board[i][j]-1]);
        }

        puts("");
    }

    printf("Actions=%d Moves=%d Bombs=%d Range=%d Soft bricks=%d\n", 
    state[ACTION_COUNT], state[MOVE_COUNT], state[BOMB_COUNT], state[EXPLOSION_RANGE], state[BRICKS_REMAINS]);
    
    printf("Destroyed=%d Boosts dropped=%d Boosts collected=%d\n", 
    state[BRICKS_DESTROYED], state[BOOSTS_DROPPED], state[BOOSTS_COLLECTED]);

    if(state[BOMB_ACTIVE]){

        printf("Bomb 1: timer=%d at (%d,%d)\n", 
        state[BOMB_TIMER], state[BOMB_COL], state[BOMB_ROW]);
    }

    return;
}

void displayLegend(int state[]) {

    puts("Legend: [] wall, () soft brick, @@ player, @B player on bomb, BB bomb, EX boost, ## explosion");
    
    printf("Command [W/A/S/D = move, B = bomb, P = pause, Q = quit]: ");

    return;
}



int movePlayer(int board[][MAX_COLS], int size[], int state[], int rowChange, int colChange) {
    // Process a "move" command from user.
    // return value indicates success or fail
    
    int *position = board[state[PLAYER_ROW]]+state[PLAYER_COL];
    int *destination = board[state[PLAYER_ROW]+rowChange]+state[PLAYER_COL]+colChange;
    
    if( *destination != WALL &&
        *destination != BRICK_EMPTY &&
        *destination != BRICK_BOOST &&
        *destination != BOMB){
    
        *position = (*position == PLAYER_ON_BOMB?BOMB:CORRIDOR);

        if(*destination == BOOST){

            state[BOOSTS_COLLECTED]++;
            state[EXPLOSION_RANGE]++;
        }

        *destination = PLAYER;
        state[PLAYER_ROW] += rowChange;
        state[PLAYER_COL] += colChange;
        
        state[MOVE_COUNT]++;
        state[ACTION_COUNT]++;
        
        return 1;
    }
    
    return 0;
}

int dropBomb(int board[][MAX_COLS], int state[]) {
    // Process a dropBomb command from user.
    // return value indicates success or fail
    
    if(!state[BOMB_ACTIVE]){

        board[state[PLAYER_ROW]][state[PLAYER_COL]] = PLAYER_ON_BOMB;
        
        state[BOMB_ACTIVE]++;
        state[BOMB_COUNT]++;
        state[BOMB_ROW] = state[PLAYER_ROW];
        state[BOMB_COL] = state[PLAYER_COL];
        state[BOMB_TIMER] = 4;
        state[ACTION_COUNT]++;
    }
}



void advanceTime(int board[][MAX_COLS], int size[], int state[]) {
    // Advance game time; explode bomb if needed

    static int update_explode = 0;

    if(update_explode){

        for(int i = 0; i < size[0]; i++){

            for(int j = 0; j < size[1]; j++){

                board[i][j] == EXPLODE? board[i][j] = CORRIDOR:1;
                board[i][j] == EXPLODE_BOOST? board[i][j] = BOOST:1;
            }
        }

        update_explode = 0;
    }

    if(state[BOMB_ACTIVE]){

        if(!(--state[BOMB_TIMER])){

            explodeBomb(board, size, state);
            update_explode = 1;
        }    
    }

    return;
}

void explodeBomb(int board[][MAX_COLS], int size[], int state[]) {
    // Explode the bomb; read the data from state[]/board[][]

    int direction[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    board[state[BOMB_ROW]][state[BOMB_COL]] = EXPLODE;

    for(int j = 0; j < 4; j++){

        for(int i = 1, blocked = 0; i <= state[EXPLOSION_RANGE] && !blocked; i++){

            int *explosion = board[state[BOMB_ROW]+(i*direction[j][0])]+state[BOMB_COL]+(i*direction[j][1]);

            switch (*explosion)
            {
                case WALL:{
                    
                    blocked = 1;
                    break;
                }
                case PLAYER:{
                    
                    *explosion = EXPLODE;
                    state[PLAYER_ALIVE] = 0;
                    break;
                }
                case BRICK_BOOST:{
                    
                    *explosion = EXPLODE_BOOST;
                    state[BOOSTS_DROPPED]++;
                    state[BRICKS_DESTROYED]++;
                    state[BRICKS_REMAINS]--;
                    break;
                }
                case BRICK_EMPTY:{
                    
                    *explosion = EXPLODE;
                    state[BRICKS_DESTROYED]++;
                    state[BRICKS_REMAINS]--;
                    break;
                }
                case CORRIDOR:{
                    
                    *explosion = EXPLODE;
                    break;
                }
                default:{

                    break;
                }
            }
        }
    }

    state[BOMB_ACTIVE] = 0;

    return;
}


void endGameMessage(int state[], int win) {
    // Display End Game Message and Statistics

    switch (win){
        case GAME_LOST:{
            
            puts("[GAME OVER]: the player was caught in an explosion");
            break;
        }
        case GAME_WON:{
            
            puts("[YOU WIN]: all soft bricks were destroyed.");
            break;
        }
        default:{
            
            puts("[GAME OVER]: the player quits.");
            break;
        }
    }

    puts("+-----------------------+-----+");
    
    char *stat_items[4] = {"Successful moves", "Bombs dropped ", "Soft bricks destroyed", "Soft bricks remaining"};

    int stat[4] = {state[MOVE_COUNT], state[BOMB_COUNT], state[BRICKS_DESTROYED], state[BRICKS_REMAINS]};

    for(int i = 0; i < 4; i++){

        if(i != 3 || stat[3]){

            printf("| %21s | %2d |",stat_items[i], stat[i]);
            puts("\n+-----------------------+-----+");
        }
    }

    return;
}
