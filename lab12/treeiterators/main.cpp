//
// Created by pawelgalka on 23.05.18.
//

#include <iostream>
#include "TreeIterators.h"
using namespace tree;
int main(){
    Tree<int> tree1(5);
    tree1.Insert(2);
    tree1.Insert(6);
    PreOrderTreeView<int > iterator(tree1.Root());
    std::vector<int> vec = iterator.vec();
    for (auto v:vec){
        std::cout << v << std::endl;
    }
    std::cout<< iterator.end().iterator_;
}