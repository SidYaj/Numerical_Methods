# Numerical Methods

This is intended to be a personal project where I implement some elementary numerical methods in C++. I will update this README as and when I add new functionality.

## Numerical Differentiation

Algorithms for numerical differentiation are declared in the header file numerical_differentiation.hpp and implemented in the C++ file numerical_differentiation.cpp

I have implemented two methods. The standard forward difference method can compute numerical derivatives of any order (if they exist). However, it is not a very accurate method of computing the derivatives. The five-point stencil method is significantly more accurate and is implemented for derivatives up to the fourth order.

## Numerical Integration

Algorithms for numerical integration are declared in the header file numerical_integration.hpp and implemented in the C++ file numerical_integration.cpp

For numerical integration, I have implemented a single method, the 1/3 Simpson's rule.

## Root Finding

Algorithms for root finding are declared in the header file root_finding.hpp and implemented in the C++ file root_finding.cpp

For root finding, I have implemented a single method, the Newton-Rhapson method.
