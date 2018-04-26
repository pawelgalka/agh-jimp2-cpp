//
// Created by pawelgalka on 21.04.18.
//

#include <iostream>
#include "Iterable.h"
using namespace utility;

int main(){
    std::vector<int> vi ={1,2,3,4};
    std::vector<std::string> vs={"a","b","c","d"};
    auto it = ZipperIterator(vi.begin(),vs.begin(),vi.end(),vs.end());
    std::cout << it.Next().Dereference().first;
    auto zip = Zipper(vi,vs);
}