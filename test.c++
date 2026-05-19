#include "Black_Scholes.h"
#include <iostream>

int main(void){
    Black_Scholes s;

    double output = s.call(185.00, 180.00, 0.25, 0.036, 0.25);

    std::cout << output << std::endl;

    return 0;
}
