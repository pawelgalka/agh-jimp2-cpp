//
// Created by pawel on 03.03.18.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){
    size_t size = str.size();
    const char *characters = str.c_str();
    for (int i=0; i<size; i++)  if (*(characters+i) != *(characters+size-i-1)) return false; //compares letters with same lenghts to adequate end of the word
    return true;
}