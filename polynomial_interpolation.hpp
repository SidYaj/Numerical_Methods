#ifndef POLYNOMIAL_INTERPOLATION_HPP
#define POLYNOMIAL_INTERPOLATION_HPP

#include <vector>
#include <Eigen/Dense>
#include "polynomial_interpolation.hpp"

double lagrange_interpolation(std::vector<double> x_vec, std::vector<double> y_vec, double x);

Eigen::VectorXd lagrange_coefficients(Eigen::VectorXd x_vec, Eigen::VectorXd y_vec);

void output_polynomial(Eigen::VectorXd a);

#endif