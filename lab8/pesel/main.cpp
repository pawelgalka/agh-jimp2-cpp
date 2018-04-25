//
// Created by pawelgalka on 24.04.18.
//
#include "Pesel.h"
#include <exception>
#include <iostream>

using namespace academia;
int main(){
    try{
        Pesel("00000000000");
    }
    catch (InvalidPeselLength a){
        std::cout << a.what();
    }
    catch (InvalidPeselCharacter b){
        std::cout << b.what();
    }
    catch (InvalidPeselChecksum c){
        std::cout << c.what();
    }
    return 0;

}