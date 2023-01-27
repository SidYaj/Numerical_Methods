#include <cmath>
#include "numerical_integration.hpp"

double simpson_1_by_3_integration(double (*f)(double), double a, double b)
{
    const int n = 32;
    double h = (b - a)/n;
    double sum_odd = 0;
    double sum_even = 0;
    double sum;
    
    for(int i = 1; i < n; i += 2)
    {
        sum_odd += f(a + i * h);
    }
    
    for(int i = 2; i < n; i += 2)
    {
        sum_even += f(a + i * h);
    }

    sum = 1./3. * h * (f(a) + 4 * sum_odd + 2 * sum_even + f(b));

    return sum;
}