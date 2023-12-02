#include <stdio.h>
#include <math.h>

int main()
{
    int t, cont;
    double A, i, V = 0;
    
    scanf("%d", &t);
    scanf("%lf", &A);
    scanf("%lf", &i);

    for (cont = 1; cont <= t; cont++)
    {
        V = V + A;
        V = V * (1 + i);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", cont, V);
}return 0;}