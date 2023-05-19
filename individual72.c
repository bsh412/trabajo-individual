#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Declaracion de constantes  */

//Cabeceras de los subprogramas
int binario (int n);

int main(){
    /* Declaracion de variables */
    char c;
    int n;

    /* Bloque de instrucciones */
    do{ system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        /* Instrucciones del algoritmo */ 
        do {
        printf ("Introduce el numero: ");
        scanf (" %d", &n);
		} while (n < 0);
		
		binario (n);
		

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

int binario (int n)
{
	if (n == 0 || n == 1)
		printf ("%d", n);
	else
	{	
		binario (n/2);
		printf ("%d", n%2);
	}
}
