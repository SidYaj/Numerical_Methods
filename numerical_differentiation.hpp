#ifndef NUMERICAL_DIFFERENTIATION_H
#define NUMERICAL_DIFFERENTIATION_H

#include "numerical_differentiation.hpp"

double factorial(int);

double nCk(int, int);

double forward_difference(double, double (*f)(double), int);

double five_point_stencil(double, double (*f)(double), int);

#endif