#include <stdio.h>
#include <string.h>

int memory[100] = {0};

int memory_id = 1;

int alloc(int byte, int size);
int erase(int byte, int id);
void defragment(int byte);

int main(){

    int operation_num, memory_byte;

    scanf(" %d %d", &operation_num, &memory_byte);

    int output_list[operation_num];

    int output_num = 0;

    for(int i = 0; i < operation_num; ++i){

        char operation[11];
        int num;

        scanf(" %s %d", operation, &num);

        if(!strcmp(operation, "alloc")){

            output_list[output_num++] = alloc(memory_byte, num);
        }
        else if(!strcmp(operation, "erase")){

            output_list[output_num++] = erase(memory_byte, num);
        }
        else{

            defragment(memory_byte);
        }
    }

    for(int i = 0; i < output_num; ++i){

        switch (output_list[i]){

            case -2:{
                
                break;
            }
            case -1:{
                
                puts("ILLEGAL_ERASE_ARGUMENT");

                break;
            }
            case 0:{
                
                puts("NULL");
                break;
            }
            default:

                printf("%d", output_list[i]);
                puts("");

                break;
            }
    }
    return 0;
}

int alloc(int byte, int size){

    for(int i = 0, current = 0, current_pos = 0; i < byte; i++){

        if(!memory[i]){

            current++;
        }
        else{

            current = 0;
            current_pos = i+1;
        }

        if(current == size){

            for(int j = current_pos; j < current_pos + size; ++j){

                memory[j] = memory_id;
            }

            return memory_id++;
        }
    }

    return 0;
}

int erase(int byte, int id){

    int pos = 0;

    for(; pos < byte && memory[pos] != id; pos++);

    if(pos == byte || id < 1){

        return -1;
    }

    for(; memory[pos] == id; ++pos){

        memory[pos] = 0;
    }

    return -2;
}


void defragment(int byte){

    int findnextmemory(int byte, int *start);

    for(int i = 0, pos_0 = 0; i < byte; ++i){

        if(!memory[i]){

            int start = i+1;
            int end;

            if(end = findnextmemory(byte, &start)){

                int len = end - start + 1;

                memmove(&memory[i], &memory[start], (len) * sizeof (int));

                pos_0 = i;

                for(i += len; memory[pos_0] == memory[i] || memory[i] == 0; ++i){

                    memory[i] = 0;
                }

                pos_0 += len;
                i = pos_0;
            }
            else{

                return;
            }
        }
    }

    return;
}

int findnextmemory(int byte, int *start){

    for(; *start < byte; ++(*start)){

        if(memory[*start]){

            int end = *start+1;

            for(; end < byte && memory[end] == memory[*start]; ++end);

            return --end;
        }
    }

    return 0;
}