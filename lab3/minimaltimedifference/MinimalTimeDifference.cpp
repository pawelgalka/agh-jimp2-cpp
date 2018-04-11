//
// Created by pawel on 14.03.18.
//

#include "MinimalTimeDifference.h"


namespace minimaltimedifference {

    regex pattern{R"(([0-9]|0[0-9]|1[0-9]|2[0-3]):([0-5][0-9]))"};

    unsigned int ToMinutes(std::string time_HH_MM) {
        std::smatch result;
        if (!std::regex_match(time_HH_MM, result, pattern)) {
            std::cerr << "Invalid hour format \n";
        }
        string hours = (string)result[1], minutes = (string)result[2];
        int hour = 0, minute = 0;
        int i = 0;
        while (i< hours.length()){
            hour += (hours[i]-(int)'0')*pow(10,hours.length()-i-1);
            ++i;
        }
        i = 0;
        while (i< minutes.length()){
            minute += (minutes[i]-(int)'0')*pow(10,minutes.length()-i-1);
            ++i;
        }
        unsigned int min = hour*60 + minute;
        return min;
    }

    unsigned int DifferenceCounter(unsigned int minutes1, unsigned int minutes2);

    void CountDifference(const vector<int> &minutes, vector<int> &difference);

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        vector<int> minutes;
        vector<int> difference;
        for (auto const& value:times){
            minutes.emplace_back(ToMinutes(value));
        }
        CountDifference(minutes, difference);
        unsigned int min_difference = difference[0];
        for (int i=1; i<difference.size(); ++i){
            if (min_difference > difference[i]) min_difference = difference[i];
        }
        return min_difference;
    }

    void CountDifference(const vector<int> &minutes, vector<int> &difference) {
        for (int i=0; i < minutes.size(); ++i){
            for (int j=0; j<i+1; ++j){
                if (i!=j){
                    difference.emplace_back(DifferenceCounter(minutes[i], minutes[j]));
                }
            }
        }
    }

    unsigned int DifferenceCounter(unsigned int minutes1, unsigned int minutes2) {
        unsigned int difference1 = abs(minutes1 - minutes2);
        if (difference1>720) return 1440-difference1;
        else return difference1;
    }
}