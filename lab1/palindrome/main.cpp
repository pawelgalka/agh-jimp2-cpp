//
// Created by pawel on 03.03.18.
//
#include <iostream>
#include "Palindrome.h"

int main() {
    int wybor;
    std::cout << "1.Sprawdz palindrom" << std::endl;
    std::cout << "0.Wyjscie" << std::endl;
    std::cin >> wybor;
    switch(wybor) {
        case 1: {
            std::string str;
            std::cin >> str;
            if (is_palindrome(str)) std::cout << "Jest" << std::endl;
            else std::cout << "Nie jest" << std::endl;
        }
            break;

        case 0:
            return 0;

        default:
            break;
    }
    return 0;
}


