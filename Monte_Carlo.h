#ifndef __MONTE_CARLO__H
#define __MONTE_CARLO__H

/*
T: Time of expiry

M: Amount of simulations

I: Number simulation

K: Strike price

R: Risk Free interest

V: Volatility
*/

class Monte_Carlo
{
public:
    double call(double, double, double, double, double);
    double second_part_call(double, double, double, double, double);
    double put(double, double, double, double, double);
    double second_part_put(double, double, double, double, double);
    double st(double, double, double, double, double, double);
};

#endif