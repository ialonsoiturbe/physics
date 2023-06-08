#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "generador.h"


/* Método de Montecarlo con dos dimensiones */

double f(double x1, double x2) {
double f1 = (x1 + x2)*(x1 + x2);
return f1;
}


int main() {

long long i, N, Nreal;
double x1, x2;
double integral, error, square, V; 
 
double tini,tend,ttot;


double x1i = 0.0;
double x1e = 1.0;
double x2i = 0.0;
double x2e = 1.0;

integral = 0.0;
square = 0.0;

printf("Cantidad de ensayos: \n"); 
scanf("%lld",&N);

Nreal = (double)N;

srand48(seed()); // Set the seed

tini = timeinseconds();

for (i=0;i<N;i++) {
    x1=scalerandom(drand48(),x1i,x1e);
    x2=scalerandom(drand48(),x2i,x2e);
    integral = integral + f(x1,x2)/Nreal;
    square = square + (pow(f(x1,x2),2)/Nreal);
    }

V = (x1e-x1i)*(x2e-x2i);
error = V*sqrt((square-pow(integral,2))/Nreal);
integral = V*integral;
printf("Integral: %18.14lf \n",integral);
printf("Error: %18.14lf \n",error); 

tend = timeinseconds();
ttot = tend - tini;
printf("Tiempo de calculo: %lf segundos \n",ttot);

return 0; 
}
