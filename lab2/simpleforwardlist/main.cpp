//
// Created by pawel on 08.03.18.
//

#include <iostream>
#include "SimpleForwardList.h"

int main(){
    ForwardList *head = CreateNode(5);
    std::cout << head->value;
}