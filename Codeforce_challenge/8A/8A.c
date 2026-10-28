#include <stdio.h>
#include <string.h>

char flags[100001];
char seq1[101];
char seq2[101];
int forward = 0, backward = 0;

void forward_check();
void backward_check();
void sreverse(char s[]);
void swap(char *c1, char *c2);

int main(){

    scanf("%s %s %s", flags, seq1, seq2);

    forward_check();
    backward_check();

    if(forward && backward){

        puts("both");
    }
    else if(forward){

        puts("forward");
    }
    else if(backward){

        puts("backward");
    }
    else{

        puts("fantasy");
    }
    return 0;
}

void forward_check(){

    char *seq1_ptr;
    seq1_ptr = strstr(flags, seq1);

    if(seq1_ptr == NULL){

        return;
    }
    else if(strstr(seq1_ptr+strlen(seq1), seq2) != NULL){

        forward = 1;
        return;
    }
}

void backward_check(){

    sreverse(seq1);
    sreverse(seq2);

    char *seq2_ptr;
    seq2_ptr = strstr(flags, seq2);

    if(seq2_ptr == NULL){

        return;
    }
    else if(strstr(seq2_ptr+strlen(seq2), seq1) != NULL){

        backward = 1;
        return;
    }
}

void sreverse(char s[]){

    int len = strlen(s);

    for(int i = 0; i < len/2; ++i){

        swap(s+i,s+len-i-1);
    }

    return;
}

void swap(char *c1, char *c2){

    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;

    return;
}
