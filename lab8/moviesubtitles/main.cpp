//
// Created by pawelgalka on 25.04.18.
//

#include <iostream>
#include "MovieSubtitles.h"
using namespace moviesubs;
int main(){
    std::stringstream in,out;
    in << "1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n";
    SubRipSubtitles *obj = new(SubRipSubtitles);
    obj->ShiftAllSubtitlesBy(300,24,&in,&out);
    std::cout << out.str();
    delete(obj);
}