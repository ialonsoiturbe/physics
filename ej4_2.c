#include <stdio.h>
#include <math.h>

# define H1 0.000001
# define H2 0.000000000001


 void auxiliar( double a[], double v[] ){
    
    v[0] = pow( M_E, a[0] ) - 3*a[1] - 1;
    v[1] = pow( a[0], 2 ) + pow( a[1], 2 ) - 4;
   
    return ;
    
}



 void jacobiana( double a[], double j[][2] ){
    
    j[0][0] = pow( M_E, a[0] );
    j[0][1] = -3;
    j[1][0] = 2*a[0];
    j[1][1] = 2*a[1];
    
    return ;
    
}

 void jInversa( double j[][2], double jInv[][2] ) {
    
    jInv[0][0] = j[1][1] / ( j[0][0]*j[1][1] - j[0][1]*j[1][0] );
    jInv[0][1] = -j[0][1] / ( j[0][0]*j[1][1] - j[0][1]*j[1][0] );
    jInv[1][0] = -j[1][0] / ( j[0][0]*j[1][1] - j[0][1]*j[1][0] );
    jInv[1][1] = j[0][0] / ( j[0][0]*j[1][1] - j[0][1]*j[1][0] );
    
    return ;
    
}



 int main()	{

    FILE *fichSal;
    int N;
    double x[2];
    double v[2];
    double w[2];
    double aux[2];
    double j[2][2];
    double jInv[2][2];
    
    printf( "Introduce el valor inicial de x: " );
    scanf( "%lf", &x[0] );   

    printf( "Introduce el valor inicial de y: " );
    scanf( "%lf", &x[1] );   

    fichSal = fopen("salida2.txt","a");
    if (fichSal==NULL){
        printf( "No se puede abrir el fichero de salida.\n" );
        return 1;
    }

    // escribimos los valores iniciales en el fichero de salida
    fprintf( fichSal, "Valores iniciales.  x: %lf; y: %lf\n", x[0], x[1]);
    
    
    w[0] = 1;
    w[1] = 1;
    N = 0;

    while ( ( w[0]>H2 ) && ( w[1]>H2 ) && ( N++ < 100 ) ){

        // Metemos en aux los valores f(x,y) y g(x,y)
        auxiliar( x, aux );
        
        // Calculamos la matriz jacobiana
        jacobiana( x, j );

        // Calculamos la matriz inversa de la jacobiana
        jInversa( j, jInv ) ;
        
        // Mostramos x, y, f(x,y), g(x,y)
        printf( "x: %lf; y: %lf\n", x[0], x[1]);
        printf( "f(x,y): %lf; g(x,y): %lf\n", aux[0], aux[1]);
        


        // El algoritmo de Newton-Raphson
        v[0] = x[0] - ( jInv[0][0]*aux[0] + jInv[0][1]*aux[1] );
        v[1] = x[1] - ( jInv[1][0]*aux[0] + jInv[1][1]*aux[1] );
        
        w[0] = fabs( v[0] - x[0] );
        w[1] = fabs( v[1] - x[1] );
        
        x[0] = v[0];
        x[1] = v[1];
        
    }
    
    // Y escribimos las soluciones en el fichero de salida
    fprintf( fichSal, "Solución: x =%12.8lf; y =%12.8lf;  \n\n", x[0], x[1] );
    
    fclose( fichSal );
    
    return 0;
        
            
}   
