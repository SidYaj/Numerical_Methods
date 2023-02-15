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

Eigen::VectorXd lagrange_coefficients(Eigen::VectorXd x_vec, Eigen::VectorXd y_vec)
{
    int k = x_vec.size();
    Eigen::MatrixXd X(k, k);
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            X(i, j) = pow(x_vec(i), j);
        }
    }
    Eigen::VectorXd a = X.colPivHouseholderQr().solve(y_vec);
    return a;
}

void output_polynomial(Eigen::VectorXd a)
{
    int k = a.size();
    std::cout << "p(x) = ";
    bool flag = false; // to check for first non-zero coefficient
    for(int i = 0; i < k; i++)
    {
        if(abs(a(i)) < 1e-10)
        {
            continue;
        }
        if(i == 0)
        {
            std::cout << a(i);
        }
        else
        {
            if(flag)
            {
                if(a(i) > 0)
                {
                    std::cout << " + ";
                }
                else
                {
                    std::cout << " - ";
                }
                if(abs(abs(a(i)) - 1) > 1e-10)
                {
                    std::cout << abs(a(i));
                }
                if(i == 1)
                {
                    std::cout << "x";
                }
                else
                {
                    std::cout << "x^" << i;
                }
            }
            else
            {
                if(abs(abs(a(i)) - 1) > 1e-10)
                {
                    if(a(i) > 0)
                    {
                        std::cout << a(i);
                    }
                    else
                    {
                        std::cout << "-" << abs(a(i));
                    }
                }
                else
                {
                    if(a(i) == -1)
                    {
                        std::cout << "-";
                    }
                }
                if(i == 1)
                {
                    std::cout << "x";
                }
                else
                {
                    std::cout << "x^" << i;
                }
            }
        }
        flag = true;
    }
}