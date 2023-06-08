#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "generador.h"


/* Método de Montecarlo con cinco dimensiones */

double f(double x1, double x2, double x3, double x4, double x5) {
    double f1 = (x1 + x2 + x3 + x4 + x5)*(x1 + x2 + x3 + x4 + x5);
    return f1;
}


int main() {

    long long i, N, Nreal;
    double x1, x2, x3, x4, x5;
    double integral, error, square, V; 
     
    double tini,tend,ttot;


    double x1i = 0.0;
    double x1e = 1.0;
    double x2i = 0.0;
    double x2e = 1.0;
    double x3i = 0.0;
    double x3e = 1.0;
    double x4i = 0.0;
    double x4e = 1.0;
    double x5i = 0.0;
    double x5e = 1.0;

    integral = 0.0;
    square = 0.0;

    printf("Cantidad de ensayos: \n"); 
    scanf("%lld",&N);

    Nreal = (double)N;

    srand48(seed()); // Set the seed

    tini = timeinseconds();

    for (i=0;i<N;i++){
        x1=scalerandom(drand48(),x1i,x1e);
        x2=scalerandom(drand48(),x2i,x2e);
        x3=scalerandom(drand48(),x3i,x3e);
        x4=scalerandom(drand48(),x4i,x4e);
        x5=scalerandom(drand48(),x5i,x5e);
        integral = integral + f(x1,x2,x3,x4,x5)/Nreal;
        square = square + (pow(f(x1,x2,x3,x4,x5),2)/Nreal);
    }

    V = (x1e-x1i)*(x2e-x2i)*(x3e-x3i)*(x4e-x4i)*(x5e-x5i);
    error = V*sqrt((square-pow(integral,2))/Nreal);
    integral = V*integral;
    printf("Integral: %18.14lf \n",integral);
    printf("Error: %18.14lf \n",error); 

    tend = timeinseconds();
    ttot = tend - tini;
    printf("Tiempo de calculo: %lf segundos \n",ttot);

    return 0; 
    

}
