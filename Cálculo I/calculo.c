#include <stdio.h>
#include <math.h>//𝑒^x = 3 -2x²
double func(int x) {
    double e = 2.71828;
    e = pow(e, x); // → e^x	
    double result = e - 3 + 2*(pow(x, 2));

    return result;
}

int main() {
    //double e = 2.71828;
    int x = 0; int x2 = 0;
    scanf("%d%d", &x, &x2);

    double p1 = func(x); double p2 = func(x2);
    if ((p1 >= 0 && p2 < 0) || (p1 < 0 && p2 >= 0)) {
        printf("a equação tem pelo menos uma solução neste intervalo\n");

        if (x <= 0)
            printf("intervalo [%d,%d]\n", x, x2);
        else 
            printf("intervalo [%d,%d]\n", x2, x);
    } else
        printf("não é possível afirmar que existe solução neste intervalo, tente outros dois números\n");

    return 0;
}