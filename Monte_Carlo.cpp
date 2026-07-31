#include <iostream>
#include <cmath>
#include <random>

double call(double s, double k, double r, double T)
{
    double fp = std::exp(-r * T);

    double sp = second_part_call(s, k, r, T);
}

double second_part_call(double s, double k, double r, double T)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    int m = 10000;

    for (int n = 0; n < m; n++)
    {
        std::uniform_real_distribution<> dis(0.0, 1.0);

        double number = dis(gen);

        st(number);
    }
}

double st(double n)
{
    
}