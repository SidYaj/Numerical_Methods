#include "polynomial_interpolation.hpp"
#include <iostream>

double lagrange_interpolation(std::vector<double> x_vec, std::vector<double> y_vec, double x)
{
    double L = 0;
    int k = x_vec.size();
    for(int j = 0; j < k; j++)
    {
        double l = 1;
        for(int i = 0; i < k; i++)
        {
            if(i == j)
                continue;
            l *= (x - x_vec[i])/(x_vec[j] - x_vec[i]);
        }
        L += y_vec[j] * l;
    }
    return L;
}