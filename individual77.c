#include <stdio.h>
#include <ctype.h>
#include <math.h>

double f1 (double x);
double f1derivada (double x);
double f2 (double x);
double f3 (double x);
double f2f3derivada (double x);
double f4 (double x);
double f4derivada (double x);
double f5 (double x);
double f5derivada (double x);
void calcularraiz (double (*f) (double x), double (*fderivada) (double x), double x0, double e, int n, double *raiz, char *resul);

int main ()
{
    char c, resul;
    double x0, e, raiz;
    int n, numfuncion;

    do
    {
        do
        {
            printf ("\n1. f(x) = x^3 - 3x^2 + 5");
            printf ("\n2. f(x) = x^2 - 1");
            printf ("\n3. f(x) = x^2 + 1");
            printf ("\n4. f(x) = exp (- x^2)");
            printf ("\n5. f(x) = seno(x) * exp(-x)");
            printf ("\nEstas son las funciones que se pueden integrar: ");
            scanf (" %d", &numfuncion);
        }while (numfuncion<1 || numfuncion>5);
        printf ("\nIntroduce valor inicial de x: ");
        scanf (" %lf", &x0);
        printf ("\nIntroduce error maximo: ");
        scanf (" %lf", &e);
        printf ("\nIntroduce numero maximo de iteraciones: ");
        scanf (" %d", &n);
        switch (numfuncion)
        {
            case 1:
                calcularraiz (f1, f1derivada, x0, e, n, &raiz, &resul);
                break;
            case 2:
                calcularraiz (f2, f2f3derivada, x0, e, n, &raiz, &resul);
                break;
            case 3:
                calcularraiz (f3, f2f3derivada, x0, e, n, &raiz, &resul);
                break;
            case 4:
                calcularraiz (f4, f4derivada, x0, e, n, &raiz, &resul);
                break;
            case 5:
                calcularraiz (f5, f5derivada, x0, e, n, &raiz, &resul);
                break;
        }
        switch (resul)
        {
            case 'r':
                printf ("\nLa raiz es: %lf", raiz);
                break;
            case 'd':
                printf ("\nDerivada nula");
                //printf ("\nUltimo valor: %lf", raiz);
                break;
            case 'i':
                printf ("\nExcedido numero iteraciones");
                //printf ("\nUltimo valor: %lf", raiz);
                break;
        }


        printf ("\n\nDesea realizar otra operacion (S/N): ");
        c = toupper (getch());
        printf ("%c", c);
    }while (c!='N');
    return 0;
}

double f1 (double x)
{
    double resul;

    resul = x*x*x - 3*x*x + 5;
    return resul;
}

double f1derivada (double x)
{
    double resul;

    resul = 3*x*x - 6*x;
    return resul;
}

double f2 (double x)
{
    double resul;

    resul = x*x - 1;
    return resul;
}

double f2f3derivada (double x)
{
    double resul;

    resul = 2*x;
    return resul;
}

double f3 (double x)
{
    double resul;

    resul = x*x + 1;
    return resul;
}

double f4 (double x)
{
    double resul;

    resul = exp(-x*x);
    return resul;
}

double f4derivada (double x)
{
    double resul;

    resul = -2*x * exp(-x*x);
    return resul;
}

double f5 (double x)
{
    double resul;

    resul = sin(x) * exp(-x);
    return resul;
}

double f5derivada (double x)
{
    double resul;

    resul = cos(x) * exp(-x) + sin(x) * (-1)*exp(-x) ;
    return resul;
}


void calcularraiz (double (*f) (double x), double (*fderivada) (double x), double x0, double e, int n, double *raiz, char *resul)
{
    double xi, ximas1;
    int cont;

    *resul = ' ';
    xi = x0;
    cont = 0;
    while (*resul == ' ')
    {
        if (fderivada(xi) == 0)
            *resul = 'd';
        else
        {
            ximas1 = xi - f(xi) / fderivada(xi);
            if (fabs(ximas1 - xi) < e)
            {
                *resul = 'r';
                *raiz = ximas1;
            }
            else
            {
                cont++;
                if (cont == n)
                    *resul = 'i';
                else
                    xi = ximas1;
            }
        }
    }
}
