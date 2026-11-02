#include <stdio.h>
#include <windows.h>

#define COMMAND 2

int memory[100] = {0};
int accumulator, instructionCounter, instructionRegister, operationCode, operand;

void load(int a);
int execute();
void dump();

int main(){

    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
        "*** Welcome to Simpletron! ***",
        "*** Please enter your program one instruction ***",
        "*** (or data word) at a time. I will type the ***",
        "*** location number and a question mark (?). ***",
        "*** You then type the word for that location. ***",
        "*** Type the sentinel -99999 to stop entering ***",
        "*** your program. ***");

    char *command[][100] = {
        {
            "+1009",
            "+1010",
            "+2009",
            "+3010",
            "+2111",
            "+1111",
            "+4300",
            "-99999",
        },
        {
            "+1014",
            "+2014",
            "+4207",
            "+4107",
            "+3015",
            "+2115",
            "+4000",
            "+1115",
            "+4300",
            "-99999"
        },
        {
            "+1020",
            "+1021",
            "+1022",
            // init
            "+1023",
            "+2023",
            "+3024",
            "+2124",
            // input and plus
            "+2021",
            "+3122",
            "+2121",
            // increment --
            "+4212",
            "+4003",
            // == 0
            "+2024",
            "+3220",
            "+2124",
            // divide
            "+1124",
            // output
            "+4300",
            "-99999"
        }
    };

    printf("00 ? ");
    sscanf(*(command[COMMAND]), " %d", memory);
    Sleep(100);
    printf("%+05d\n", *memory);
    

    for(int i = 1; memory[i-1] != -99999; i++){
        
        printf("%02d ? ", i);
        sscanf(*((command[COMMAND])+i), " %d", memory+i);
        Sleep(10);
        printf("%+05d\n", *(memory+i));
    }

    load(0);

    printf("%s\n%s\n",  "*** Program loading completed ***", "*** Program execution begins ***");

    for(;execute();) load(++instructionCounter);

    return 0;

}

void dump(){

    printf("REGISTERS: \n%-25s%+05d\n%-25s%5.2d\n%-25s%+05d\n%-25s%5.2d\n%-25s%5.2d\n",
    "accumulator", accumulator,
    "instructionCounter", instructionCounter,
    "instructionRegister", instructionRegister,
    "operationCode", operationCode,
    "operand", operand);

    puts("\nMEMORY:");

    for(int i = 0; i < 10; i++) printf("\t%d", i);
    puts("");

    for(int i = 0; i < 10; i++){

        printf("%2d\t", i*10);

        for(int j = 0; j < 10; j++) printf("%+05d\t", memory[i*10+j]);

        puts("");
    }

}

int execute(){

    switch (operationCode){

        case 10:{

            printf("? ");
            scanf(" %d", memory + operand);
            break;
        }
        case 11:{

            printf("> %d\n", memory[operand]);
            break;
        }
        case 20:{

            accumulator = memory[operand];
            break;
        }
        case 21:{

            memory[operand] = accumulator;
            break;
        }
        case 30:{

            accumulator += memory[operand];
            break;
        }
        case 31:{

            accumulator -= memory[operand];
            break;
        }
        case 32:{

            accumulator /= memory[operand];
            break;
        }
        case 33:{

            accumulator *= memory[operand];
            break;
        }
        case 40:{

            instructionCounter = operand - 1;
            break;
        }
        case 41:{

            if(accumulator < 0) instructionCounter = operand - 1;
            break;
        }
        case 42:{

            if(!accumulator) instructionCounter = operand - 1;
            break;
        }
        case 43:{

            puts("*** Simpletron execution terminated ***");
            dump();
            return 0;
        }
        default:{
        
            break;
        }
    }

    return 1;
}

void load(int a){

    instructionCounter = a;
    instructionRegister = memory[instructionCounter];
    operationCode = instructionRegister / 100;
    operand = instructionRegister % 100;

    return;
}