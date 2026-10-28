#include <stdio.h>
#include <math.h>

int main(){

    int n,m,a;

    scanf("%d %d %d", &n, &m, &a);

    printf("%.0f", ceil((double) n/a)*ceil((double) m/a));

    return 0;
}