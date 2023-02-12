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

## Ordinary Differential Equations

Algorithms for solving ordinary differential equations are declared in the header file ode.hpp and implemented in the C++ file ode.cpp.

For solving ordinary differential equations, I have implemented a single method, the fourth order Runge-Kutta method. The method is overloaded so that based on the number of parameters specified the order of the differential equation is inferred. At this point it is not possible to solve higher-order differential equations.

For first-order ODEs, the equation is in the form $\dot{x} = b(t)x + c(t)$. For second-order ODEs, the equation is in the form $\ddot{x} = b(t)\dot{x} + c(t)x + d(t)$.

## Polynomial Interpolation

Algorithms for finding the interpolating polynomial are declared in the header file polynomial_interpolation.hpp and implemented in the C++ file polynomial_interpolation.cpp.

For finding the interpolating polynomial, I have as of now implemented a single method, the Lagrange interpolation method. The user inputs a set of $n + 1$ $(x, y)$ points as well as the $x$ value for which they want to find the interpolated $y$ value. Functionality will be added later which returns the coefficients of the interpolated polynomial. 