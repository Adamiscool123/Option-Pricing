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