#include <stdio.h>
#include <math.h>

void main () {
    printf ("Coloque a: ");
    int a;
    scanf ("%d", a);

    int resposta = 169 + 30 * a + (7/2) * pow(a,2) * pow(2, a) + (a-6) * pow(3,a+3) ;
    printf("\n%d",resposta);
}