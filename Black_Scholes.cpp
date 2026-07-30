#include "Black_Scholes.h"
#include <cmath>

float Black_Scholes::call(float current_price, float strike_price, float time_expiration, float risk_free_interest_rate, float volatility)
{
    float n2 = d2(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility);

    float n1 = d1(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility, n2);

    float result = (current_price * N(n1)) - (strike_price * (std::exp((-time_expiration * risk_free_interest_rate))) * N(n2));

    return result;
}

float Black_Scholes::put(float current_price, float strike_price, float time_expiration, float risk_free_interest_rate, float volatility)
{
    float n2 = d2(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility);

    float n1 = d1(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility, n2);

    float result = (strike_price * (std::exp((-time_expiration * risk_free_interest_rate))) * N(-n2)) - (current_price * N(-n1));

    return result;
}

float Black_Scholes::d1(float current_price, float strike_price, float time_expiration, float risk_free_interest_rate, float volatility, float d2)
{
    float result = d2 + (volatility * sqrt(time_expiration));

    return result;
}

float Black_Scholes::d2(float current_price, float strike_price, float time_expiration, float risk_free_interest_rate, float volatility)
{
    float volatilitySquared = volatility * volatility;

    float first_part = (std::log((current_price / strike_price)) + (risk_free_interest_rate - (volatilitySquared / 2)) * time_expiration);

    float second_part = volatility * sqrt(time_expiration);

    float result = first_part / second_part;

    return result;
}

float Black_Scholes::N(float x)
{
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}