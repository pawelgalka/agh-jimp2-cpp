//
// Created by pawelgalka on 18.04.18.
//

#include <algorithm>
#include <memory>
#include "Comparable.h"
using namespace academia;
int main(){
    StudentException repository      {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
                                        {"2035", "Orson", "Sabach", "górnictwo", 2}};
    std::unique_ptr<ByFirstNameDescending> wsk = std::make_unique<ByFirstNameDescending>();

    std::sort(repository.students_.begin(), repository.students_.end(), *wsk);
    for (auto v:repository.students_){
        std::cout << v ;
        std::cout << std::endl;
    }

    return 0;
}