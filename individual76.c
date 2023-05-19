#include <stdio.h>
#include <ctype.h>
#include <math.h>

double f1 (double x, double y);
double f2 (double x, double y);
double f3 (double x, double y);
double f4 (double x, double y);
double calcularvolumen (double (*f) (double x, double y), double xmin, double xmax, double ymin, double ymax, int m, int n);

int main ()
{
    char c;
    double xmin, xmax, ymin, ymax, volumen;
    int m, n, numfuncion;

    do
    {
        do
        {
            printf ("\n1. f(x) = log (x + 2y)");
            printf ("\n2. f(x) = x^2 + y^2");
            printf ("\n3. f(x) = x + y");
            printf ("\n4. f(x) = 1");
            printf ("\nEstas son las funciones que se pueden integrar: ");
            scanf (" %d", &numfuncion);
        }
        while (numfuncion<1 || numfuncion>4);
        do
        {
            printf ("\nIntroduce minimo valor de x: ");
            scanf (" %lf", &xmin);
            printf ("\nIntroduce maximo valor de x: ");
            scanf (" %lf", &xmax);
        }while (xmin >= xmax);
        do
        {
            printf ("\nIntroduce minimo valor de y: ");
            scanf (" %lf", &ymin);
            printf ("\nIntroduce maximo valor de y: ");
            scanf (" %lf", &ymax);
        }while (ymin >= ymax);
        printf ("\nIntroduce cantidad de trozos en x: ");
        scanf (" %d", &m);
        printf ("\nIntroduce cantidad de trozos en y: ");
        scanf (" %d", &n);
        
        switch (numfuncion)
        {
            case 1:
                volumen = calcularvolumen (f1, xmin, xmax, ymin, ymax, m, n);
                break;
            case 2:
                volumen = calcularvolumen (f2, xmin, xmax, ymin, ymax, m, n);
                break;
            case 3:
                volumen = calcularvolumen (f3, xmin, xmax, ymin, ymax, m, n);
                break;
            case 4:
                volumen = calcularvolumen (f4, xmin, xmax, ymin, ymax, m, n);
                break;
        }
        printf ("\nEl volumen encerrado por la superficie es: %.15lf", volumen);


        printf ("\n\nDesea realizar otra operacion (S/N): ");
        c = toupper (getch());
        printf ("%c", c);
    }while (c!='N');
    return 0;
}

double f1 (double x, double y)
{
    double resul;

    resul = log(x + 2*y);
    return resul;
}

double f2 (double x, double y)
{
    double resul;

    resul = x*x + y*y;
    return resul;
}

double f3 (double x, double y)
{
    double resul;

    resul = x + y;
    return resul;
}

double f4 (double x, double y)
{
    double resul;

    resul = 1;
    return resul;
}

double calcularvolumen (double (*f) (double x, double y),
        double xmin, double xmax, double ymin,
        double ymax, int m, int n)
{
    int i, j;
    double ladox, ladoy, area, suma, xi, yj;

    ladox = (xmax-xmin) / m;
    ladoy = (ymax-ymin) / n;
    area = ladox * ladoy;
    suma = 0;
    
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            xi = xmin + i*ladox + ladox/2;
            yj = ymin + j*ladoy + ladoy/2;
            suma = suma + f(xi, yj) * area;
        }
    }
    
    return suma;
}
