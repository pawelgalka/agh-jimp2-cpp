//
// Created by pawel on 14.03.18.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <vector>
#include <sstream>
#include <regex>
#include <iostream>
#include <cmath>

using ::std::string;
using ::std::unique_ptr;
using ::std::map;
using ::std::pair;
using ::std::vector;
using std::cout;
using std::endl;
using std::regex;

namespace minimaltimedifference{
    unsigned int ToMinutes(std::string time_HH_MM);
    unsigned int MinimalTimeDifference(std::vector<std::string> times);
}




#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
