#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Declaracion de constantes  */

int main(){
    /* Declaracion de variables */
    char c;
    int ultimafila, n, m, i, num, den, valor, espacios;

    /* Bloque de instrucciones */
    do{ system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        /* Instrucciones del algoritmo */
        do
        {
            printf ("\nIntroduce valor ultima fila: ");
            scanf (" %d", &ultimafila);
        }while (ultimafila < 0);
        
        espacios = 3*ultimafila;
        
		n= 0;
		while (n <= ultimafila)
        {
            //al principio de cada fila me dejo los espacios
            for (i=1; i<=espacios; i++)
                printf (" "); 	
				
		//imprimir primero el 1 aparte
							
						
			printf ("1");			
            for (m=1; m<=n; m++)
            {
                //calculo de n sobre m
                if (m==0 || m==n)
                    valor = 1;
                else
                {
                    valor = valor*(n-m+1)/m;
                }
                printf ("%6d", valor);
            }
            printf ("\n");
            espacios -= 3;
            
            n++;
        }

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
