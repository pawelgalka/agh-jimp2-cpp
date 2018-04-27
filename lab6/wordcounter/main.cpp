//
// Created by pawelgalka on 11.04.18.
//

#include <iostream>
#include "WordCounter.h"
using namespace datastructures;
int main(){
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")}, counter1{"/home/pawelgalka/1"};
    std::cout << counter;
    std::cout << counter1;
    return 0;
}