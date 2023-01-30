#include <cmath>
#include <limits>
#include <iostream>
#include "root_finding.hpp"
#include "numerical_differentiation.hpp"

#define MAX_ITER 100

double newton_method(double (*f)(double), double x0, double eps) // assumes that there is a root and that the initial guess is in the vicinity of the root
{
    int iter = 0;
    double x = x0;
    double prev = std::numeric_limits<double>::infinity();
    while(iter <= MAX_ITER && abs(x - prev) > eps)
    {
        prev = x;        
        double dfdx_x = five_point_stencil(f, x, 1);
        double f_x = f(x);
        x = x - f_x/dfdx_x;        
        iter++;
    }
    return x;
}