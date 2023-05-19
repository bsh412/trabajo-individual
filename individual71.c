#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Declaracion de constantes  */

//Cabeceras de los subprogramas
int sumacifras (int n);

int main(){
    /* Declaracion de variables */
    char c;
    int n, i;

    /* Bloque de instrucciones */
    do{ system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        /* Instrucciones del algoritmo */ 
        do {
        printf ("Introduce el numero: ");
        scanf (" %d", &n);
		} while (n < 0);
		
		i = sumacifras (n);
		
		printf ("\n\nEl valor de la suma de las cifras de %d es: %d", n, i);
	

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

int sumacifras (int n)
{
	if (n==0)
	return 0;
	else
		return sumacifras (n/10) + n%10;
}
