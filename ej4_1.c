#include <stdio.h>
#include <math.h>

# define H1 0.000001
# define H2 0.000000000001


 double derivadaSenoMenosXDiv10( long double x ){
    double y;
    
    y = ( sin(x+H1) - (x+H1)/10 - sin(x-H1) + (x-H1)/10 ) / ( 2*H1 );
    
    return y;
    
}



int newtonRaphson( double u)	{
    double v, w;
    FILE *fichSal;
    

    fichSal = fopen("salida.txt","a");
    if (fichSal==NULL){
        printf( "No se puede abrir el fichero de salida.\n" );
        return 1;
    }

    // escribimos el valor inicial en el fichero de salida
    fprintf( fichSal, "Valor inicial: %12.8lf \n", u );
    
    w = 1;
    while ( w > H2 ){
        // El algoritmo de Newton-Raphson
        v = u - ( sin( u ) - u/10 ) / derivadaSenoMenosXDiv10( u ) ;
        
        w = fabs( v -u );
        u = v;
        
    }
    
    // Y escribimos la solucion en el fichero de salida
    fprintf( fichSal, "Solución: %12.8lf \n\n", u );
    
    fclose( fichSal );
    
    return 0;
        
            
}   



int main()	{
	double u= 1;
    
    while ( u != 0 ){
        printf( "Introduce el valor inicial, 0 para salir: " );
        scanf( "%lf", &u );
    
        if ( u != 0 ) {
            if ( newtonRaphson( u ) != 0 ){
                return 1;
            }
            
        }
        
    }
    
    return 0;
    
 }
