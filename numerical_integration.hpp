#ifndef NUMERICAL_INTEGRATION_H
#define NUMERICAL_INTEGRATION_H

#include "numerical_integration.hpp"

double simpson_1_by_3_integration(double (*f)(double), double lower_bound, double upper_bound);

#endif