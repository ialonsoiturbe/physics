#include <stdio.h>
#include <math.h>


double F(double t, double x[], double f[]) {
// Insertar aqui las definiciones de las funciones f_i(t, x0, x1, ..., x_M-1) 
// que constituyen el sistema de ecuaciones diferenciales. 
// Tener en cuenta que los indices van de 0 a M-1    
f[0] = 10*(x[1] - x[0]);
f[1] = 28*x[0] - x[0]*x[2]-x[1];
f[2] = x[0]*x[1] - (8.0/3.0)*x[2];

} 


int main() {

// Tamaño del sistema 
int M = 3;

long long N, i;
int j;  
double h, t0, tf, tmax;
double x0[M], xf[M], f[M], xaux[M];
double k1[M], k2[M], k3[M], k4[M];


FILE *datos;
datos = fopen("solucion.dat", "w");

printf("Introduzca el valor del incremento h:\n");
scanf("%lf",&h);
printf("\n");

printf("Introduzca el valor inicial de t:\n");
scanf("%lf",&t0);
printf("\n");

printf("Introduzca el valor máximo de t a calcular\n");
scanf("%lf",&tmax);
printf("\n");

for(j=0;j<M;j++) {
printf("Introduzca el valor inicial de x[%d]: \n",j);
scanf("%lf",&x0[j]);
}

// Calculamos el numero de puntos donde evaluar, segun 
// los valores x0, xmax y h 
N = ((tmax-t0)/h)+1.2;

// Escribimos datos del primer punto en fichero auxiliar 
// Se sigue el formato multicolumna: 
//  t    x[0]    x[1]  ...  x[M-1]  
fprintf(datos, "%lf ",t0);
for(j=0;j<M;j++) {
fprintf(datos, "%lf ", x0[j]);  }
fprintf(datos, "\n");

// Bucle principal RK4 
for (i=1;i<N;i++) {

tf=t0+h;

// Calculo componentes vector K1 
F(t0,x0,f);
for(j=0;j<M;j++) {
k1[j] = f[j];  }

// Calculo componentes vector K2 
for(j=0;j<M;j++) {
xaux[j] = x0[j] + 0.5*h*k1[j];  }
F(t0+0.5*h,xaux,f);
for(j=0;j<M;j++) {
k2[j] = f[j];  }

// Calculo componentes vector K3 
for(j=0;j<M;j++) {
xaux[j] = x0[j] + 0.5*h*k2[j];  }
F(t0+0.5*h,xaux,f);
for(j=0;j<M;j++) {
k3[j] = f[j];  }

// Calculo componentes vector K4 
for(j=0;j<M;j++) {
xaux[j] = x0[j] + h*k3[j];  }
F(t0+h,xaux,f);
for(j=0;j<M;j++) {
k4[j] = f[j];  }

// Calculo componentes vector xf
for(j=0;j<M;j++) {
xf[j] = x0[j] + h*((k1[j]+2.0*k2[j]+2.0*k3[j]+k4[j])/6.0);  }

// Escribimos resultados en fichero externo
fprintf(datos, "%lf ",tf);
for(j=0;j<M;j++) {
fprintf(datos, "%lf ", xf[j]);  }
fprintf(datos, "\n");

// Copiamos valores finales en iniciales para la siguiente iteracion 
t0 = tf;
for(j=0;j<M;j++) {
x0[j] = xf[j];  }

}

fclose(datos);

return 0;
}

