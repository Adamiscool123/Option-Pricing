#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

class Black_Scholes{
public:
    double current_price;             // S: current stock/asset price
    double strike_price;              // K: strike price
    double time_to_expiration;         // T: time in years
    double risk_free_interest_rate;    // r: annual risk-free rate as decimal
    double volatility;                 // σ: annual volatility as decimal

    double call(double, double, double, double, double);

    double put(double, double, double, double, double);

    double d1(double, double, double, double, double);

    double d2(double, double, double, double, double, double);
};

#endif