//
// Created by pawel on 08.03.18.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value){
    ForwardList *NewNode = new ForwardList;
    NewNode->value = value;
    NewNode->next = nullptr;
    return NewNode;
}

void DestroyList(ForwardList *list){
    ForwardList *pointer = list, *tmp;
    while (pointer!= nullptr){
        tmp = pointer->next;
        delete pointer;
        pointer = tmp;
    }
}

ForwardList *PushFront(ForwardList *list, int value){
    ForwardList *NewNode = CreateNode(value);
    if (list == nullptr){
        list = NewNode;
    }
    else{
        NewNode->next = list;
        list = NewNode;
    }

}
