//
// Created by pawelgalka on 23.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling{
    template <class T>
    auto TimeRecorder (T obj){
        std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
        auto  res = obj();
        std::chrono::duration<double, std::milli> time = std::chrono::system_clock::now()-begin;
        return std::make_pair(res, time.count());
    };

}



#endif //JIMP_EXERCISES_TIMERECORDER_H
