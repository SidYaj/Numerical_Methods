#ifndef ODE_H
#define ODE_H

#include <vector>
#include "ode.hpp"

std::vector<double> runge_kutta_4(double (*b)(double), double (*c)(double), double x0, double stop_time, double tau);

std::vector<double> runge_kutta_4(double (*b)(double), double (*c)(double), double (*d)(double), double x0, double v0, 
                                                                                            double stop_time, double tau);

#endif