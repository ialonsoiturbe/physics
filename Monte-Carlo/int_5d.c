#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "generador.h"


/* Método del paralelepípedo con cinco dimensiones */

double f(double x1, double x2,double x3, double x4,double x5) {
    double f1 = (x1 + x2 + x3 + x4 + x5)*(x1 + x2 + x3 + x4 + x5);
return f1;
}


int main() {

    int i1, i2,i3,i4,i5;
    int N1, N2,N3,N4,N5;  
    double x1, x2, x3, x4, x5; 
    double h;
    double h1, h2,h3,h4,h5;

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


    double tini,tend,ttot;

    double integral;

    printf("Introduzca el paso de integracion:\n");
    scanf("%lf",&h);


    tini = timeinseconds();

    N1 = ((x1e-x1i)/h);
    N2 = ((x2e-x2i)/h);
    N3 = ((x3e-x3i)/h);
    N4 = ((x4e-x4i)/h);
    N5 = ((x5e-x5i)/h);


    // recalculamos h para que el intervalo sea exacto
    h1 = ((x1e-x1i)/N1);
    h2 = ((x2e-x2i)/N2);
    h3 = ((x3e-x3i)/N3);
    h4 = ((x4e-x4i)/N4);
    h5 = ((x5e-x5i)/N5);


    integral = 0;


    for (i1=0;i1<=N1;i1++) {
        for (i2=0;i2<=N2;i2++) {
            for (i3=0;i3<=N3;i3++) {
                for (i4=0;i4<=N4;i4++) {
                    for (i5=0;i5<=N5;i5++) {
                        x1 = x1i + i1*h1;
                        x2 = x2i + i2*h2;
                        x3 = x3i + i3*h3;
                        x4 = x4i + i4*h4;
                        x5 = x5i + i5*h5;

                        integral = integral + f(x1,x2,x3,x4,x5);  
                    }
                }
            }
        }
    } 


    integral = integral*h1*h2*h3*h4*h5;

    tend = timeinseconds();
    ttot = tend - tini;


    printf(" N1 = %d  N2 = %d  N3 = %d  N4 = %d  N5 = %d    I = %18.14lf \n",N1,N2,N3,N4,N5,integral);
    printf("Tiempo de calculo: %lf segundos \n",ttot);

    return 0;

}

