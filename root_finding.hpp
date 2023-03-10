#ifndef ROOT_FINDING_H
#define ROOT_FINDING_H

#include "root_finding.hpp"

double newton_method(double (*f)(double), double initial_guess, double error_bound);

#endif