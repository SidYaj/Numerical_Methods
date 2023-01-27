#include <cmath>
#include <iostream>
#include "numerical_differentiation.hpp"

double factorial(int n)
{
    int product = 1;
    for(int i = 2; i <= n; i++)
        product *= i;
    return product;
}

double nCk(int n, int k)
{
    return factorial(n)/(factorial(k) * factorial(n - k));
}

double forward_difference(double x, double (*f)(double), int order)
{
    double eps = pow(10, -4);
    int n = order;
    double h = sqrt(eps) * x;
    double sum;
    
    for(int k = 0; k <= n; k++)
    {
        int multiplier = (k + n) % 2 == 0 ? 1 : -1;
        sum += multiplier * nCk(n, k) * f(x + k * h);
    }
    
    double h_inv = 1./h;
    sum *= pow(h_inv, n);
    return sum;
}

double five_point_stencil(double x, double (*f)(double), int order)
{
    double eps = pow(10, -4);
    int n = order;
    double h = sqrt(eps) * x;
    double h_inv = 1./h;

    if (order == 1)
    {
        return 1./12. * h_inv * (-f(x + 2*h) + 8*f(x + h) - 8*f(x - h) + f(x - 2*h));
    }
    else 
    if (order == 2)
    {
        return 1./12. * pow(h_inv, 2) * (-f(x + 2*h) + 16*f(x + h) - 30*f(x) + 16*f(x - h) - f(x - 2*h));
    }
    else
    if (order == 3)
    {
        return 1./2. * pow(h_inv, 3) * (f(x + 2*h) - 2*f(x + h) + 2*f(x - h) - f(x - 2*h));
    }
    else
    if (order == 4)
    {
        return pow(h_inv, 4) * (f(x + 2*h) - 4*f(x + h) + 6*f(x) - 4*f(x - h) + f(x - 2*h));
    }
    else
    {
        return forward_difference(x, f, order);
    }
}