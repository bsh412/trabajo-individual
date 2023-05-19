#include <stdio.h>
#include <ctype.h>
#include <math.h>

int multiplicacionrusa (int a, int b);

int main ()
{
    char c;
    int a, b, m;

    do
    {
        printf ("\nIntroduce dos numeros: ");
        scanf (" %d %d", &a, &b);
        m = multiplicacionrusa (a, b);
        printf ("\nEl resultado de la multiplicacion es: %d", m);

        printf ("\n\nDesea realizar otra operacion (S/N): ");
        c = toupper (getch());
        printf ("%c", c);
    }while (c!='N');
    return 0;
}

int multiplicacionrusa (int a, int b)
{
    if (a == 0)
        return 0;
    else
    {
        if (a % 2 == 0)
            return multiplicacionrusa (a/2, 2*b);
        else
            return b + multiplicacionrusa (a/2, 2*b);
    }
}
