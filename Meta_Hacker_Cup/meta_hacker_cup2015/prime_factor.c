#include <stdio.h>
#include <math.h>

int prime_natural_id[2000000] = {0};

int main(){

    int lower_range, upper_range, target, num = 0;
    
    scanf(" %d %d %d", &lower_range, &upper_range, &target);

    int range = upper_range - lower_range + 1;



    for(int i = 2; i < upper_range; ++i){

        if(!prime_natural_id[i-1]){

            for(int j = i; j <= upper_range; j += i){
                
                if(prime_natural_id[j-1] == -1){

                    continue;
                }
                else if(prime_natural_id[j-1] < target-1){

                    prime_natural_id[j-1] += 1;
                }
                else if(prime_natural_id[j-1] == target-1){

                    num++;
                    prime_natural_id[j-1] += 1;
                }
                else{

                    num--;
                    prime_natural_id[j-1] = -1;
                }
            }
        }
    }

    printf("%d", num);

    return 0;
}