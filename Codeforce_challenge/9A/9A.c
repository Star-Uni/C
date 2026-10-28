#include <stdio.h>
#define max ((p1 > p2)?p1:p2)

int main(){

    int p1,p2;

    scanf(" %d %d", &p1, &p2);

    int p = max;

    switch(p){

        case 1:{

            puts("1/1");
            break;
        }
        case 2:{

            puts("5/6");
            break;
        }
        case 3:{

            puts("2/3");
            break;
        }
        case 4:{

            puts("1/2");
            break;
        }
        case 5:{

            puts("1/3");
            break;
        }
        case 6:{

            puts("1/6");
            break;
        }
        default:{

            break;
        }

    }
}