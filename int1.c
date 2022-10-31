#include <stdio.h>
#include <math.h>
#include "integral.h"

void integral1(double a, double b, double usrPrecision, struct Integral *ptrIntegral){ //нижние прямоугольники
    double buffer;
    double value;
    unsigned int n = 1;
    double integralDown;
    double buffIntegral;
    double precision;
    double eps;
    int i = 0;
    value = f(b);
    buffer = f(a);
    buffIntegral = (value < buffer ? value : buffer) * (b - a);
    do {
        n *= 2;
        integralDown = 0;
        eps = (b - a) / (double)n;
        value = f(a);
        for (int j = 1; j <= n; j++) {
            buffer = value;
            value = f(a + eps * (double) j);
            integralDown += (value < buffer ? value : buffer) * eps;
        }
        precision = fabs(buffIntegral - integralDown);
        buffIntegral = integralDown;
        i++;
    } while(usrPrecision < precision);
    //output
    ptrIntegral->integral = integralDown;
    ptrIntegral->precision = precision;
    ptrIntegral->countOfIterations = i;
    ptrIntegral->countOfDividing = n;
}