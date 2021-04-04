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
    double x = 0; double x2 = 0; double erro = 0.1;
    printf("Insira o intervalo no formato x y(somente com espaço entre os números e nada além disso)\n");
    scanf("%lf%lf", &x, &x2);

    double p1 = func(x); double p2 = func(x2);
    if (x > x2) {
        double aux = p1;
        p1 = p2;
        p2 = aux;

        aux = x;
        x = x2;
        x2 = aux;
    }

    if ((p1 > 0 && p2 < 0) || (p1 < 0 && p2 > 0)) {
        printf("a equação tem pelo menos uma solução neste intervalo");

        while (fabs(x - x2) > erro) {
            double centro = x + ((x2 - x) / 2);

            if ((func(x) > 0 && func(centro) > 0) || (func(x) < 0 && func(centro) < 0))
                x = centro;
            else
                x2 = centro;
        }
        
        printf(" [%lf,%lf]\n", x, x2);
                
    } else
        printf("não é possível afirmar que existe solução neste intervalo, tente outros dois números\n");

    return 0;
}