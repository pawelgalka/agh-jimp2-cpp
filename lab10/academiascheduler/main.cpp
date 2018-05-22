//
// Created by pawelgalka on 12.05.18.
//

#include <iostream>
#include <memory>
#include "Scheduler.h"

using namespace academia;
using namespace std;
int main(){
    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
    schedule.InsertScheduleItem(SchedulingItem {5, 6, 7, 8, 9});
    schedule.AvailableTimeSlots(10);
    std::unique_ptr<Scheduler> scheduler = std::make_unique<GreedyScheduler>();
    vector<int> rooms{1000};
    map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 10, 10}), make_pair(200, vector<int>{10, 10})};
    map<int, set<int>> years{make_pair(1, set<int>{10})};
    /*vector<int> rooms{1000, 2000};
    map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 10, 10}), make_pair(200, vector<int>{10, 10})};
    map<int, set<int>> years{make_pair(1, set<int>{10})};*/
    /*vector<int> rooms{1000};
    map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 20}), make_pair(200, vector<int>{30}),
                                   make_pair(300, vector<int> {40})};
    map<int, set<int>> years{make_pair(1, set<int>{10, 20}), make_pair(2, set<int>{30, 40})};*/


    Schedule sch = scheduler->PrepareNewSchedule(rooms,teachers,years,5);
    cout << sch;

}

