#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

class Black_Scholes
{
public:
    float current_price;           // S: current stock/asset price
    float strike_price;            // K: strike price
    float time_to_expiration;      // T: time in years
    float risk_free_interest_rate; // r: annual risk-free rate as decimal
    float volatility;              // σ: annual volatility as decimal

    float call(float, float, float, float, float);

    float put(float, float, float, float, float);

    float d1(float, float, float, float, float, float);

    float d2(float, float, float, float, float);

    float N(float x);
};

#endif

/*
Explantion:

You have 2 types of equtions call and put.

Call = S * N(d1) - K * e^-rT * N(d2)

d1 = d2 + O*sqrt(T)

d2 = (ln(S/K) + (r - 1/2 * O^2) * T) / O * sqrt(T)

You have 2 parts of the equation the left and right.

Left: Expected value of what you recieve

Right: Expected value of what you pay

d1 represents delta meaning how much the option's price moves every dollar a stock price moves.

- This happens when wrapped around N(), d1 output is a Z score.

d2 represents the probability of the option's price being over the strike price.

- This happens when wrapped around N(), d2 output is a Z score.

In d2 you have (r - 1/2 * O^2) * T this means risk free rate - volatility correction * T which gives the adjusted growth

So risk free (rate - 1/2 * Variance)* Time of expiry

1/2 * o^2 = Volatility correction

r - volatility correction = adjusted annual growth

In both d1 and d2 you have O * sqrt(T) meaning volatility * the sqrt(time of expiry).

Key note: Variance (The spread of numbers from the mean) = Volaility^2

Volaility = sqrt(variance) = O.

This means O*sqrt(T) = variance over time = O^2 * T = O*sqrt(T).

---------------------------------------------------

Put = K * e^-rT * N(-d2) - S * N(-d1)

Left: Expected value for what you pay

Right: Expected value for what you earn

d1 = d2 + O*sqrt(T)

d2 = (ln(S/K) + (r - 1/2 * O^2) * T) / O * sqrt(T)

*/