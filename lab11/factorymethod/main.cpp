//
// Created by pawelgalka on 20.05.18.
//

#include <iostream>
#include <memory>
#include "FactoryMethod.h"

using namespace factoryMethod;

int main(){

    std::vector<int> v1{1,2,3,4,5,6};
   // std::cout << Mean<int>(v1);
    std::unique_ptr<int> v = std::make_unique<int>();
    *v=3;
    int *v11 = new int;
    *v11=3;

    std::cout << Value(v);
    std::cout << Value(v11);
    delete v11;

    Repository<int> repo{std::make_pair(2,2)};
    int i = repo[2];
    std::cout << repo.NextId();


}