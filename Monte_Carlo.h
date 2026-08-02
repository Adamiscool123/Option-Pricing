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

/*
The base equation is e^-rT * right side.

Right side depends on if it is a call or put

Call right side = 1/m (M top, i=1 bottom) sum_of(S(i)t - k, 0)

Put right side = 1/m (M top, i=1 bottom) sum_of(k - S(i)t, 0)

S(i)t is a function which takes i representing what number simulation it is.

S(i)t = S0 * e^(r - 1/2 O^2)*T + O*sqrt(T)*Z

Z represents a random number from 0 - 1

S0 basically just represents current price

We have two parts left and right.

Left: the adjusted annual growth.

(r - 1/2 O^2)*T we have two parts here the r - risk free rate and 1/2 O^2 meaning volatility correction

So when you minus both you get adjusted growth then times it by Time getting annual growth.

Right: This gives Volatility * sqrt(time) * Random number.

O * sqrt(T) = O^2 * T = Variance * T = Spread of numbers from mean * T

O * sqrt(T) so that is where we get sqrt(t) we are using this form to get the spread of possible returns
which is standard deviation.

Z the random number changes the direction and strength when we times that to O we are going to change
the standard deviation getting a different stock price.

The output gives a log return and that e converts it to a normal multiplyer.

Then we times that to the stock getting random numbers.

After we minus that new price to k or reverse depending on call or put

*/