#ifndef POLYNOMIAL_INTERPOLATION_H
#define POLYNOMIAL_INTERPOLATION_H

#include<vector>
#include "polynomial_interpolation.hpp"

double lagrange_interpolation(std::vector<double> x_vec, std::vector<double> y_vec, double x);

#endif