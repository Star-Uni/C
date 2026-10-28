#include <stdio.h>
#include <math.h>

double findcentre(const double coor[3][2], double centre[2]);
double findarea(const double r, const int side);

#define PI acos(-1.0)

int main(){

    double coor[3][2];
    double centre[2];

    for(int i = 0; i < 3;++i){

        scanf(" %lf %lf", &coor[i][0], &coor[i][1]);
    }

    /*for(int i = 0; i < 3;++i){

        printf(" %f %f", coor[i][0], coor[i][1]);
    }*/

    double r = findcentre(coor, centre);
    
    //printf("radius: %.6f\ncentre: (%.6f,%.6f)\n", r, centre[0], centre[1]);

    double d12,d23,d13;
    d12 = hypot(coor[0][0] - coor[1][0], coor[0][1] - coor[1][1]);
    d23 = hypot(coor[1][0] - coor[2][0], coor[1][1] - coor[2][1]);
    d13 = hypot(coor[0][0] - coor[2][0], coor[0][1] - coor[2][1]);

    double a12,a23,a13;
    double c12,c23,c13;
    c12 = (2*r*r - d12*d12)/(2*r*r);
    c23 = (2*r*r - d23*d23)/(2*r*r);
    c13 = (2*r*r - d13*d13)/(2*r*r);

    if (c12 > 1){

        c12 = 1;
    }
    else if (c12 < -1){

        c12 = -1;
    }
    if (c23 > 1){

        c23 = 1;
    }
    else if (c23 < -1){

        c23 = -1;
    }
    if (c13 > 1){

        c13 = 1;
    }
    else if (c13 < -1){

        c13 = -1;
    }

    a12 = acos(c12);
    a23 = acos(c23);
    a13 = acos(c13);

    //printf("d12 = %.6f\nd23 = %.6f\nd13 = %.6f\na12 = %.6f\na23 = %.6f\na13 = %.6f\n", d12,d23,d13,a12,a23,a13);

    int side = -1;
    for(int i = 3;i <= 100;++i){

        double angle = 2*PI/i;


        if( fabs(a12 / angle - round(a12 / angle)) < 1e-4 && 
            fabs(a23 / angle - round(a23 / angle)) < 1e-4 && 
            fabs(a13 / angle - round(a13 / angle)) < 1e-4){

            side = i;       
            break;
        }
    }

    //printf("sides: %d\n", side);
    printf("%.6f", findarea(r,side));

    return 0;
}

double findcentre(const double coor[3][2],double centre[2]){

    /*
    Let (x1,y1), (x2,y2), (x3,y3) be three coordinates
    Function of circle C: x^2 + y^2 + Ax + By + C = 0
    
    x1^2 + y1^2 + Ax1 + By1 + C = 0
    x2^2 + y2^2 + Ax2 + By2 + C = 0
    x3^2 + y3^2 + Ax3 + By3 + C = 0

    Get:
    x1^2 + y1^2 + Ax1 + By1 = x2^2 + y2^2 + Ax2 + By2 = x3^2 + y3^2 + Ax3 + By3

    x1^2 + y1^2 + Ax1 + By1 = x2^2 + y2^2 + Ax2 + By2
    Ax2 + By2 - Ax1 - By1 = x1^2 + y1^2 - x2^2 - y2^2
    A(x2 - x1) + B(y2 - y1) = x1^2 + y1^2 - x2^2 - y2^2
    B = (y2 - y1)^(-1)(x1^2 + y1^2 - x2^2 - y2^2 - A(x2 - x1))
    A = (x2 - x1)^(-1)(x1^2 + y1^2 - x2^2 - y2^2 - B(y2 - y1))

    By same,
    A(x3 - x1) + B(y3 - y1) = x1^2 + y1^2 - x3^2 - y3^2
    A(x3 - x1) + (y2 - y1)^(-1)(x1^2 + y1^2 - x2^2 - y2^2 - A(x2 - x1))(y3 - y1) = x1^2 + y1^2 - x3^2 - y3^2
    A(x3 - x1)(y2 - y1) + (x1^2 + y1^2 - x2^2 - y2^2 - A(x2 - x1))(y3 - y1) = (x1^2 + y1^2 - x3^2 - y3^2)(y2 - y1)
    A((x3 - x1)(y2 - y1)-(x2 - x1)(y3 - y1)) = (x1^2 + y1^2 - x3^2 - y3^2)(y2 - y1) - (x1^2 + y1^2 - x2^2 - y2^2)(y3 - y1)

    Result:
    A = ((x1^2 + y1^2 - x3^2 - y3^2)(y2 - y1) - (x1^2 + y1^2 - x2^2 - y2^2)(y3 - y1))/((x3 - x1)(y2 - y1)-(x2 - x1)(y3 - y1))
    B = (y2 - y1)^(-1)(x1^2 + y1^2 - x2^2 - y2^2 - A(x2 - x1))
    C = -(x3^2 + y3^2 + Ax3 + By3)

    As B is not exist when y2 = y1, have another formula for it

    A(x3 - x1) + B(y3 - y1) = x1^2 + y1^2 - x3^2 - y3^2
    (x2 - x1)^(-1)(x1^2 + y1^2 - x2^2 - y2^2 - B(y2 - y1))(x3 - x1) + B(y3 - y1) = x1^2 + y1^2 - x3^2 - y3^2
    (x1^2 + y1^2 - x2^2 - y2^2 - B(y2 - y1))(x3 - x1) + B(y3 - y1)(x2 - x1) = (x1^2 + y1^2 - x3^2 - y3^2)(x2 - x1)
    B(y3 - y1)(x2 - x1) - B(y2 - y1)(x3 - x1) = (x1^2 + y1^2 - x3^2 - y3^2)(x2 - x1) - (x1^2 + y1^2 - x2^2 - y2^2)(x3 - x1)
    B((y3 - y1)(x2 - x1) - (y2 - y1)(x3 - x1)) = (x1^2 + y1^2 - x3^2 - y3^2)(x2 - x1) - (x1^2 + y1^2 - x2^2 - y2^2)(x3 - x1)

    Result:
    B = ((x1^2 + y1^2 - x3^2 - y3^2)(x2 - x1) - (x1^2 + y1^2 - x2^2 - y2^2)(x3 - x1))/((y3 - y1)(x2 - x1) - (y2 - y1)(x3 - x1))
    */ 

    double x1,x2,x3,y1,y2,y3;
    x1 = coor[0][0];
    x2 = coor[1][0];
    x3 = coor[2][0];
    y1 = coor[0][1];
    y2 = coor[1][1];
    y3 = coor[2][1];

    double A,B,C;
    A = ((x1*x1 + y1*y1 - x3*x3 - y3*y3)*(y2 - y1) - (x1*x1 + y1*y1 - x2*x2 - y2*y2)*(y3 - y1))/((x3 - x1)*(y2 - y1) - (x2 - x1)*(y3 - y1));
    B = ((x1*x1 + y1*y1 - x3*x3 - y3*y3)*(x2 - x1) - (x1*x1 + y1*y1 - x2*x2 - y2*y2)*(x3 - x1))/((y3 - y1)*(x2 - x1) - (y2 - y1)*(x3 - x1));
    C = -(x3*x3 + y3*y3 + A*x3 + B*y3);

    centre[0] = -A/2;
    centre[1] = -B/2;

    return sqrt((A*A + B*B)/4 - C);
}

double findarea(const double r, const int side){

    return side*r*r/2*sin(2*PI/side);
}