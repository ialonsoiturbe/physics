#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "generador.h"


/* Método del paralelepípedo con dos dimensiones */

double f(double x1, double x2) {
double f1 = (x1 + x2)*(x1 + x2);
return f1;
}


int main() {

int i1, i2;
int N1, N2;  
double x1, x2; 
double h;
double h1, h2;

double x1i = 0.0;
double x1e = 1.0;
double x2i = 0.0; 
double x2e = 1.0;


double tini,tend,ttot;

double integral;

printf("Introduzca el paso de integracion:\n");
scanf("%lf",&h);


tini = timeinseconds();

N1 = ((x1e-x1i)/h);
N2 = ((x2e-x2i)/h);


// recalculamos h para que el intervalo sea exacto
h1 = ((x1e-x1i)/N1);
h2 = ((x2e-x2i)/N2);


integral = 0;


for (i1=0;i1<=N1;i1++) {
  for (i2=0;i2<=N2;i2++) {
            x1 = x1i + i1*h1;
            x2 = x2i + i2*h2;
            integral = integral + f(x1,x2);  }  } 


integral = integral*h1*h2;

tend = timeinseconds();
ttot = tend - tini;


printf(" N1 = %d  N2 = %d    I = %18.14lf \n",N1,N2,integral);
printf("Tiempo de calculo: %lf segundos \n",ttot);

return 0;
}

