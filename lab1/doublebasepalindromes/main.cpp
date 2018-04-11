//
// Created by pawel galka on 03.03.18.
//
#include <iostream>
#include "DoubleBasePalindromes.h"

int main(){
    uint64_t max_value;
    std::cin >> max_value;
    std::cout << DoubleBasePalindromes(max_value) << std::endl;
    return 0;
}
