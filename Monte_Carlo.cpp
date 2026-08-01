#include <iostream>
#include <cmath>
#include <random>

double call(double s, double k, double r, double T, double V)
{
    double fp = std::exp(-r * T);

    double sp = second_part_call(s, k, r, T, V);
}

double second_part_call(double s, double k, double r, double T, double V)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    int m = 10000;

    for (int n = 0; n < m; n++)
    {
        std::uniform_real_distribution<> dis(0.0, 1.0);

        double number = dis(gen);

        double s = st(number, s, k, r, T, V);

        if (s <= k)
        {
            return 0;
        }
        else
        {
            return (s - k);
        }
    }
}

double st(double n, double s, double k, double r, double T, double V)
{
    double v_sqr = V * V;

    double first_part = (r - (v_sqr / 2)) * T;

    double second_Part = V * std::sqrt(T) * n;

    double e_part = std::exp(first_part + second_Part);

    double result = s * e_part;

    return result;
}