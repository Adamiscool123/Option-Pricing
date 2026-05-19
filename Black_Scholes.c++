#include "Black_Scholes.h"
#include <cmath>

double Black_Scholes::call(double current_price, double strike_price, double time_expiration, double risk_free_interest_rate, double volatility){
    double n1 = d1(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility);

    double n2 = d2(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility, n1);

    double result = (current_price*n1)-(strike_price*(std::exp((-time_expiration*risk_free_interest_rate)))*n2);

    return result;
}

double Black_Scholes::put(double current_price, double strike_price, double time_expiration, double risk_free_interest_rate, double volatility){
    double n1 = d1(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility);

    double n2 = d2(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility, n1);

    double result = (strike_price*(std::exp((-time_expiration*risk_free_interest_rate)))*n2)-(current_price*n1);

    return result;

}

double Black_Scholes::d1(double current_price, double strike_price, double time_expiration, double risk_free_interest_rate, double volatility){
    double volatilitySquared = volatility * volatility;

    double first_part = (std::log((current_price/strike_price))+(risk_free_interest_rate+(volatilitySquared/2))*time_expiration);

    double second_part = volatility*sqrt(time_expiration);

    return (first_part/second_part);

}

double Black_Scholes::d2(double current_price, double strike_price, double time_expiration, double risk_free_interest_rate, double volatility, double d1){
    double result = d1-(volatility*sqrt(time_expiration));

    return result;
}
