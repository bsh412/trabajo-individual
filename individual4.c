include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Declaracion de constantes  */

int main(){
    /* Declaracion de variables */
    char c;
    double determinante, a11, a12, a13, a21, a22, a23, a31, a32, a33, a42, a43, a52, a53, a62, a63, a73, a83, a93, b1, b2, b3, b4, b5, b6, b7, b8, b9, x, y, z;

    /* Bloque de instrucciones */
    do{ system("cls");  
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        /* Instrucciones del algoritmo */
        
        printf ("Introduce los coeficientes de la primera ecuacion: ");
        scanf (" %lf %lf %lf %lf", &a11, &a12 , &a13, &b1 );
        printf ("\nIntroduce los coeficientes de la segunda ecuacion: ");
        scanf (" %lf %lf %lf %lf", &a21, &a22 , &a23, &b2 );
        printf ("\nIntroduce los coeficientes de la tercera ecuacion: ");
        scanf (" %lf %lf %lf %lf", &a31, &a32 , &a33, &b3 );
        
        printf ("\nEcuaciones: ");
        printf ("\n%.0lf x  +  %.0lf y  +  %.0lf z  =  %.0lf", a11, a12, a13, b1);
        printf ("\n%.0lf x  +  %.0lf y  +  %.0lf z  =  %.0lf", a21, a22, a23, b2);
        printf ("\n%.0lf x  +  %.0lf y  +  %.0lf z  =  %.0lf", a31, a32, a33, b3);
        
        determinante = a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - (a13*a22*a31 + a12*a21*a33 + a11*a23*a32);
        
        if (determinante == 0){
	
        	printf ("\n\nNo tiene solucion unica, puesto que no es un SCD.");
       	}
        else {
        	
        /* Eliminacion de la variable X*/
        			
        	a42 = a21 * a12 - a11 * a22;
        	a43 = a21 * a13 - a11 * a23;
        	b4 = a21 * b1 - a11 * b2;
        	
        	a52 = a11 * a22 - a21 * a12;
        	a53 = a11 * a23 - a21 * a13;
			b5 = a11 * b2 - a21 * b1;
				
        	a62 = a21 * a32 - a31 * a22;
        	a63 = a21 * a33 - a31 * a23;
			b6 = a21 * b1 - a31 * b2;	
			
			printf ("\n\nEcuaciones:");
            printf ("\n%.0lf y + %.0lf z = %.0lf", a42, a43, b4);
            printf ("\n%.0lf y + %.0lf z = %.0lf", a52, a53, b5);
            printf ("\n%.0lf y + %.0lf z = %.0lf", a62, a63, b6);
		
        	
        	
        /* Eliminacion de la variable Y*/
        
        	a73 = a52 * a43 - a42 * a53;
        	b7 = a52 * b4 - a42 * b5;
        	
        	       
        	a83 = a62 * a53 - a52 * a63;
        	b8 = a62 * b5 - a52 * b6;				/*cuidado el signo aqui*/
				
        	
        	a93 = a42 * a63 - a62 * a43;
        	b9 = a42 * b6 - a62 * b4;
        	
        	printf ("\n\nEcuaciones:");
            printf ("\n%lf z = %lf", a73, b7);
            printf ("\n%lf z = %lf", a83, b8);
            printf ("\n%lf z = %lf", a93, b9);
        	
        /* Calculo de la variable Z*/
		
		if (a73 != 0)
                z = b7 / a73;
            else
            {
                if (a83 != 0)
                    z = b8 / a83;
                else
                    z = b9 / a93;
            }

		/* Calculo de la variable Y */
        
		    if (a42 != 0)
                y = (b4 - a43 * z) / a42;
            else
            {
                if (a52 != 0)
                    y = (b5 - a53 * z) / a52;
                else
                    y = (b6 - a63 * z) / a62;
            }

		/* Calculo de la variable X */
		
            if (a11 != 0)
                x = (b1 - a12 * y - a13 * z) / a11;
            else
            {
                if (a21 != 0)
                    x = (b2 - a22 * y - a23 * z) / a21;
                else
                    x = (b3 - a32 * y - a33 * z) / a31;
            }
		
		
		printf ("\n\nSolucion: x = %lf , y = %lf , z = %lf", x, y, z);
		}

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
