#include "ode.hpp"

std::vector<double> runge_kutta_4(double (*b)(double), double (*c)(double), double x0, double stop_time, double tau)
{
    std::vector<double> t;
    std::vector<double> x;
    int length = stop_time/tau + 1;
    t.push_back(0.);
    x.push_back(x0);
    for(int i = 0; i < length; i++)
    {    
        double k1 = tau * (b(t.back()) * x.back() + c(t.back()));
        double k2 = tau * (b(t.back() + 0.5*tau) * (x.back() + 0.5*k1) + c(t.back() + 0.5*tau));
        double k3 = tau * (b(t.back() + 0.5*tau) * (x.back() + 0.5*k2) + c(t.back() + 0.5*tau));
        double k4 = tau * (b(t.back() + tau) * (x.back() + k3) + c(t.back() + tau));
        t.push_back((i+1) * tau);
        double x_next = x.back() + 1./6. * (k1 + 2 * k2 + 2 * k3 + k4);
        x.push_back(x_next);
    }
    return x;
}

std::vector<double> runge_kutta_4(double (*b)(double), double (*c)(double), double (*d)(double), double x0, double v0, 
                                                                                            double stop_time, double tau)
{
    std::vector<double> t;
    std::vector<double> x;
    std::vector<double> v;
    int length = stop_time/tau + 1;
    t.push_back(0);
    x.push_back(x0);
    v.push_back(v0);
    for(int i = 0; i < length; i++)
    {
        double k1 = tau * v.back();
        double l1 = tau * (b(t.back()) * v.back() + c(t.back()) * x.back() + d(t.back()));
        double k2 = tau * (v.back() + 0.5 * l1);
        double l2 = tau * (b(t.back() + 0.5*tau) * (v.back() + 0.5*l1) + c(t.back() + 0.5*tau) * (x.back() + 0.5 * k1) + d(t.back() + 0.5*tau));
        double k3 = tau * (v.back() + 0.5 * l2);
        double l3 = tau * (b(t.back() + 0.5*tau) * (v.back() + 0.5*l2) + c(t.back() + 0.5*tau) * (x.back() + 0.5 * k2) + d(t.back() + 0.5*tau));
        double k4 = tau * (v.back() + l3);
        double l4 = tau * (b(t.back() + tau) * (v.back() + l3) + c(t.back() + tau) * (x.back() + k3 + d(t.back() + tau)));
        t.push_back((i + 1) * tau);
        double x_next = x.back() + 1./6. * (k1 + 2 * k2 + 2 * k3 + k4);
        x.push_back(x_next);
        double v_next = v.back() + 1./6. * (l1 + 2 * l2 + 2 * l3 + l4);
        v.push_back(v_next);
    }
    return x;
}