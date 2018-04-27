//
// Created by pawel on 10.04.18.
//

#include "StudentRepository.h"
using namespace academia;
int main(){
    StudyYear year{2};
    Student st{"1","p","g","i",2};
    StudentException s{st};
    s["2"].ChangeFirstName("Pawel");
    std::cout << s["1"].FirstName();
    return 0;
}