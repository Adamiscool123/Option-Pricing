#include "Black_Scholes.h"
#include <iostream>

int main(void){
    Black_Scholes s;

    int call_put;

    double output;

    double current_price;

    double strike_price;

    double time_expiration;

    double risk_free_interest_rate;

    double volatility;

    std::cout << "Call (0) or Put (1): ";

    std::cin >> call_put;
    
    std::cout << std::endl << "Current price: ";

    std::cin >> current_price;

    std::cout << std::endl << "Strike price: ";

    std::cin >> strike_price;

    std::cout << std::endl << "Expiration date: ";

    std::cin >> time_expiration;

    std::cout << std::endl << "Risk free interest rate: ";

    std::cin >> risk_free_interest_rate;

    std::cout << std::endl << "Volatility: ";

    std::cin >> volatility;

    if(call_put == 0){
        output = s.call(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility);

        std::cout << std::endl << "Call Price: " << output << std::endl;
    }
    else{
        output = s.put(current_price, strike_price, time_expiration, risk_free_interest_rate, volatility);  
        
        std::cout << std::endl << "Put Price: " << output << std::endl;
    }

    return 0;
}
