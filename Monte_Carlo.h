#include <iostream>

/*
T: Time of expiry

M: Amount of simulations

I: Number simulation

K: Strike price
*/

class Monte_Carlo
{
    double call(double, double, double, double);
    double second_part_call(double, double, double, double);
    double put(double, double, double, double);
    double st();
};