//
// Created by pawel on 08.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

struct ForwardList{
    int value;
    struct ForwardList *next;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);
ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
