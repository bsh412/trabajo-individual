#include <stdio.h>
#include <ctype.h>
#include <math.h>

double f1 (double x);
double f2 (double x);
double f3 (double x);
double calculararea (double (*f) (double x), double a, double b,
                     double base);

int main ()
{
    char c;
    int n;
    double a, b, base, area;

    do
    {
        do
        {
            printf ("\n1. f(x) = x^3 - 3x^2 + 5");
            printf ("\n2. f(x) = exp (-x^2)");
            printf ("\n3. f(x) = sen(x) exp (-x)");
            printf ("\nEstas son las funciones que se pueden integrar: ");
            scanf (" %d", &n);
        }
        while (n<1 || n>3);
        printf ("\nIntroduce intervalo de integracion: ");
        scanf (" %lf %lf", &a, &b);
        printf ("\nIntroduce base: ");
        scanf (" %lf", &base);
        switch (n)
        {
        case 1:
            area = calculararea (f1, a, b, base);
            break;
        case 2:
            area = calculararea (f2, a, b, base);
            break;
        case 3:
            area = calculararea (f3, a, b, base);
            break;
        }
        printf ("\nEl area del intervalo para la funcion es: %lf", area);


        printf ("\n\nDesea realizar otra operacion (S/N): ");
        c = toupper (getch());
        printf ("%c", c);
    }
    while (c!='N');
    return 0;
}

double f1 (double x)
{
    double y;

    y = x*x*x - 3*x*x + 5;
    return y;
}

double f2 (double x)
{
    double y;

    y = exp (- (x*x));
    return y;
}

double f3 (double x)
{
    double y;

    y = sin(x) * exp(-x);
    return y;
}

double calculararea (double (*f) (double x), double a, double b,
                     double base)
{
    double atotal, area, izq, der, hizq, hder;

    atotal = 0;
    izq = a;
    der = a + base;
    while (der < b)
    {
        hizq = f(izq);
        hder = f(der);
        area = base*(hizq+hder)/2;
        atotal += area;
        izq = der;
        der = der + base;
    }
    hizq = f(izq);
    hder = f(b);
    area = (b-izq)*(hizq+hder)/2;
    atotal += area;
    return atotal;
}
