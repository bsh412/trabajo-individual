#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Declaracion de constantes  */

int main(){
    /* Declaracion de variables */
    char c;
    int n, i;
    double x, y, xant, yant, vx, vy, xsig, ysig, vxsig, vysig, vxant, vyant, prod, contP, contN;

    /* Bloque de instrucciones */
    do{ system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        /* Instrucciones del algoritmo */
        do{
        	printf ("Introduce el numero de vertices del poligono: ");
        	scanf (" %d", &n);
		} while (n<3);
		
		
		printf ("\n\nPara el vertice numero 1, introduce la abscisa y la ordenada: ");
		scanf (" %lf", &x);
		scanf (" %lf", &y);
		
		xant = x;
		yant = y;
		
		i = 2;
		
		printf ("\n\nPara el vertice numero %d, introduce la abscisa y la ordenada: ", i);
		scanf (" %lf", &xsig);
		scanf (" %lf", &ysig);
		i++;
		vx = xsig - x;
		vy = ysig - y;					//Calculo el primer vector
		
		
		contP = 0;
		contN = 0;
			
		while (i <= n) {
		
			x = xsig;
			y = ysig;
			
			printf ("\nPara el vertice numero %d, introduce la abscisa y la ordenada: ", i);
			scanf (" %lf", &xsig);
			scanf (" %lf", &ysig);
			vxsig = xsig - x;
			vysig = ysig - y;
			
			prod = vx * vysig - vy * vxsig;		//calculo el segundo vector, luego el tercero, el cuarto ...
			
			if (prod < 0) 
				contN ++;
			else{
				if(prod>0){
				contP ++;
			}
			}
			
		
			vx = vxsig;
			vy = vysig; 
			
			i++;
		}
		
	
		vxsig = xant - xsig;
		vysig = yant - ysig;
			
		prod = vx * vysig - vy * vxsig;
			
		if (prod < 0) 
			contN ++;
		else{
			if(prod>0)	
			{
				contP ++;
			}
		}
		
        
        
        if (contN  && contP )
        	printf("\n\nEl poligono es concavo");
        else{
        	if ( contN == 0 && contP == 0)
        		printf("\n\nPoligono degenerado en una linea o punto");
        	else
        		printf("\n\nEl poligono es convexo");
		}
        
        

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
