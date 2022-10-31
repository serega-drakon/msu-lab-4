#include <stdio.h>
#include <math.h>
#include "integral.h"

void integral2(double a, double b, double usrPrecision, struct Integral *ptrIntegral){ //нижние прямоугольники
    double buffer;
    double value;
    unsigned int n = 1;
    double integral;
    double buffIntegral;
    double precision;
    double eps;
    int i = 0;
    value = f(b);
    buffer = f(a);
    buffIntegral = (value + buffer) / 2 * (b - a);
    do {
        n *= 2;
        integral = 0;
        eps = (b - a) / (double)n;
        value = f(a);
        for (int j = 1; j <= n; j++) {
            buffer = value;
            value = f(a + eps * (double) j);
            integral += (value + buffer) / 2 * eps;
        }
        precision = fabs(buffIntegral - integral);
        buffIntegral = integral;
        i++;
    } while(usrPrecision < precision);
    //output
    ptrIntegral->integral = integral;
    ptrIntegral->precision = precision;
    ptrIntegral->countOfIterations = i;
    ptrIntegral->countOfDividing = n;
}