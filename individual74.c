#include <stdio.h>
#include <ctype.h>

int numerocaminos (int ax, int ay, int bx, int by);

int main ()
{
    char c;
    int ax, ay, bx, by, n;

    do
    {
        printf ("\nIntroduce coordenadas del primer punto: ");
        scanf (" %d %d", &ax, &ay);
        printf ("\nIntroduce coordenadas del segundo punto: ");
        scanf (" %d %d", &bx, &by);
        if (ax==bx && ay==by)
            n = 0;
        else
            n = numerocaminos (ax, ay, bx, by);
        printf ("\nEl numero de caminos en direccion nordestes es: %d", n);


        printf ("\n\nDesea realizar otra operacion (S/N): ");
        c = toupper (getch());
        printf ("%c", c);
    }while (c!='N');
    return 0;
}

int numerocaminos (int ax, int ay, int bx, int by)
{
    if (ax > bx || ay > by)
        return 0;
    else
    {
        if (ax==bx && ay==by)
            return 1;
        else
            return numerocaminos (ax+1, ay, bx, by) + numerocaminos (ax, ay+1, bx, by);
    }
}
