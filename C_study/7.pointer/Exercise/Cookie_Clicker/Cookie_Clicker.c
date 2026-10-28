#include <stdio.h>
#include <float.h> 

#define INIT_COOKIE 0
#define INIT_COOKIE_RATE 2
#define INIT_FACTORY 0

int Cookie_test(const double cost, const double rate, const double goal, double * const crate, int * const fnum, double * const ltime, const double used_time);


int main(){

    int size;
    double crate = INIT_COOKIE_RATE;
    int fnum = INIT_FACTORY;
    double ltime = DBL_MAX;

    scanf(" %d", &size);

    double cases[size][3];// = {30.0, 1.0, 2.0},{30.0, 2.0, 100.0},{30.50000, 3.14159, 1999.19990},{500.0, 4.0, 2000.0}};

    for(int i = 0;i < size;++i){

        scanf(" %lf %lf %lf", &cases[i][0], &cases[i][1], &cases[i][2]);
    }

    for(int i = 0;i < size;++i){

        Cookie_test(cases[i][0], cases[i][1], cases[i][2], &crate, &fnum, &ltime, 0);
        
        printf("Case #%d: %.7f\n", i+1, ltime);
        
        crate = INIT_COOKIE_RATE;
        fnum = INIT_FACTORY;
        ltime = DBL_MAX;
    }

    return 0;
}

int Cookie_test(const double cost, const double rate, const double goal, double * const crate, int * const fnum, double * const ltime, const double used_time){

    double ftime = cost / *crate;
    double time = used_time + (goal / *crate);

    if(time < *ltime){
        
        *crate += rate;
        *fnum += 1;
        *ltime = time;

        return Cookie_test(cost, rate, goal, crate, fnum, ltime, ftime + used_time);
    }
    else{

        return *ltime;
    }
}