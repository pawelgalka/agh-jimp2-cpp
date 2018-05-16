//
// Created by pawelgalka on 12.05.18.
//

#include <iostream>
#include "Algo.h"

int main(){
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    std::vector<std::vector<int>> output;

    output.push_back(algo::DivisableBy(v,2));
    output.push_back(algo::DivisableBy(v,7));
    output.push_back(algo::DivisableBy(v,8));

    for (auto v : output){
        for (auto x : v) {
            std::cout << x << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    std::vector<int> xd{2,4,1,12,23,13,134,21};
    algo::SortInPlace(&xd);
    for (auto x : xd) {
        std::cout << x << " ";
    }
    std::cout<<std::endl;
    std::cout << algo::Sum(v) <<"   " << algo::Product(v) << std::endl;
    std::vector<std::string> xd1{"abc","def","x","xdddd","efwweg"};
    std::cout << algo::HowManyShortStrings(xd1,4);


}
