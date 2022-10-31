#ifndef MSU_LAB_4_INTEGRAL_H
#define MSU_LAB_4_INTEGRAL_H

struct Integral{
    double integral;
    double precision;
    unsigned int countOfIterations;
    unsigned int countOfDividing;
};

double f(double x);
void integral1(double a, double b, double usrPrecision, struct Integral *ptrIntegral);
void integral2(double a, double b, double usrPrecision, struct Integral *ptrIntegral);

#endif //MSU_LAB_4_INTEGRAL_H
