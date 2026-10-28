#include <stdio.h>
#include <math.h>

int triangleornot(int s[]);

int main(){

    int stick[4];
    int seg_flag = 0;

    scanf(" %d %d %d %d", stick, stick+1, stick+2, stick+3);

    for(int i = 0; i < 4; ++i){

        int used_stick[3] = {-1};

        for(int j = 0, k = 0; j < 4; ++j){

            (i == j)?:(used_stick[k++] = stick[j]);
        }

        switch (triangleornot(used_stick)){
            case 2:{
                
                printf("TRIANGLE");

                return 0;

                break;
            }
            case 1:{
                
                seg_flag = 1;

                break;
            }
            case 0:{
        
                break;
            }
            default:

                break;
            }

        
    }

    if(seg_flag){

        printf("SEGMENT");
    }
    else{

        printf("IMPOSSIBLE");
    }

    return 0;
}

int triangleornot(int s[]){

    if( s[0] + s[1] > s[2] && 
        s[0] + s[2] > s[1] && 
        s[1] + s[2] > s[0]){

        return 2;
    }
    else if(s[0] + s[1] >= s[2] && 
            s[0] + s[2] >= s[1] && 
            s[1] + s[2] >= s[0]){

        return 1;
    }
    else{

        return 0;
    }
}