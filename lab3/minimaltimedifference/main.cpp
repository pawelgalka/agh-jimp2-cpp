//
// Created by pawel on 14.03.18.
//
#include "MinimalTimeDifference.h"
using namespace minimaltimedifference;
int main(){
    //ToMinutes("2:45");
    vector<string> times={"1:00", "23:59", "17:56", "14:13", "15:40"};
    MinimalTimeDifference(times);
}