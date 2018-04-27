//
// Created by pawel on 10.04.18.
//

#include "StudentException.h"
using namespace academia;
int main(){
    try{
        Student st{"Pawel Galka", "fizyka", 13};
    } catch (const InvalidNameSurname &a){
        std::cerr << a.what();
    }
    catch (const InvalidProgram &b){
        std::cerr << b.what();
    }
    catch (const InvalidAge &c) {
        std::cerr << c.what();
    }

    return 0;
}