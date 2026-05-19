cmake_minimum_required(VERSION 3.16)

project(OptionsPricing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(options_pricing STATIC
    Black_Scholes.c++
    Binomial_Tree.c++
    Monte_Carlo.c++
)

target_include_directories(options_pricing
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(options_pricing_app
    test.c++
)

target_link_libraries(options_pricing_app
    PRIVATE
        options_pricing
)
