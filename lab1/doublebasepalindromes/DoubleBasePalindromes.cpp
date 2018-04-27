//
// Created by pawel galka on 03.03.18.
//

#include "DoubleBasePalindromes.h"

std::string intToBin (int value){
    std::string result,res ;
    while (value != 0) {
        result += (value%2+48);
        value /= 2;
    }
    size_t size = result.size();
    for (int i=0; i<size; i++){
        res += result[size-i-1]; //reverse binary string
    }
    return res;
}

bool is_palindrome(std::string str){
    size_t size = str.size();
    const char *characters = str.c_str();
    for (int i=0; i<size; i++)  if (*(characters+i) != *(characters+size-i-1)) return false; // compares letters with same lenghts to adequate end of the word
    return true;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum = 0;
    if (max_vaule_exculsive < 0) return 0;
    for (int i=0; i<max_vaule_exculsive; i++){
        if (is_palindrome(std::to_string(i)) && is_palindrome(intToBin(i))) sum+=i;
    }

    return sum;
}