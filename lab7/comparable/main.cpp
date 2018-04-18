//
// Created by pawelgalka on 18.04.18.
//

#include <algorithm>
#include "Comparable.h"
using namespace academia;
int main(){
    StudentRepository repository      {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
                                        {"2035", "Orson", "Sabach", "górnictwo", 2}};
    ByFirstNameDescending *wsk;
    ByFirstNameDescending obj;
    wsk = &obj;

    std::sort(repository.students_.begin(), repository.students_.end(), static_cast<bool>(wsk->IsLess));
    return 0;
}