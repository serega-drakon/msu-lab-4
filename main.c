#include <stdio.h>
#include "integral.h"

int main() {
    double a, b, eps;
    struct Integral intStruct;
    scanf("%lf%lf%lf", &a, &b, &eps);
    if(b < a) return 1;
    printf("Интеграл функции: y = 1 / (1 + Cos(x))\n");
    printf("метод нижних прямоугольников:\n");
    integral1(a, b, eps, &intStruct);
    printf("result = %.10lf\nN = %d\nPrecision = %.10lf\nCount of algorithm iterations = %d\n",
           intStruct.integral, intStruct.countOfDividing, intStruct.precision, intStruct.countOfIterations);
    printf("\nметод трапеций\n");
    integral2(a, b, eps, &intStruct);
    printf("result = %.10lf\nN = %d\nPrecision = %.10lf\nCount of algorithm iterations = %d\n",
           intStruct.integral, intStruct.countOfDividing, intStruct.precision, intStruct.countOfIterations);
    return 0;
}
