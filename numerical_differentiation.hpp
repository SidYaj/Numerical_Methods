#ifndef NUMERICAL_DIFFERENTIATION_H
#define NUMERICAL_DIFFERENTIATION_H

#include "numerical_differentiation.hpp"

double factorial(int);

double nCk(int n, int k);

double forward_difference(double (*f)(double), double x, int order);

double five_point_stencil(double (*f)(double), double x, int order);

#endif