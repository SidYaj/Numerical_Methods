#ifndef POLYNOMIAL_INTERPOLATION_HPP
#define POLYNOMIAL_INTERPOLATION_HPP

#include<vector>
#include "polynomial_interpolation.hpp"

double lagrange_interpolation(std::vector<double> x_vec, std::vector<double> y_vec, double x);

#endif