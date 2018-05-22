//
// Created by pawelgalka on 12.05.18.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include "Scheduler.h"

namespace academia{
    Schedule::Schedule() {

    }

    Schedule::~Schedule() {

    }

    SchedulingItem::SchedulingItem() {

    }

    SchedulingItem::~SchedulingItem() {

    }

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

    Schedule::Schedule(const std::initializer_list<SchedulingItem> &list) {
        for (auto const &v:list){
            vector_of_items_.push_back(v);
        }
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        vector_of_items_.push_back(item);
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule teacher;
        std::copy_if(vector_of_items_.begin(),vector_of_items_.end(),std::back_inserter(teacher.vector_of_items_),
                     [teacher_id](SchedulingItem item){return item.TeacherId()==teacher_id;});
        return teacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room;
        std::copy_if(vector_of_items_.begin(),vector_of_items_.end(),std::back_inserter(room.vector_of_items_),
                     [room_id](SchedulingItem item){return item.RoomId()==room_id;});
        return room;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule year_schedule;
        std::copy_if(vector_of_items_.begin(),vector_of_items_.end(),std::back_inserter(year_schedule.vector_of_items_),
                     [year](SchedulingItem item){return item.Year()==year;});
        return year_schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> time_slots,output(n_time_slots);
        std::iota(output.begin(),output.end(),1);
        std::transform(vector_of_items_.begin(),vector_of_items_.end(),std::back_inserter(time_slots),
                       [](SchedulingItem item){return item.TimeSlot();});
        output.erase(std::remove_if(output.begin(),output.end(),[time_slots](int number)
        {return std::find(time_slots.begin(),time_slots.end(),number)!=time_slots.end();}),output.end());
        return output;
    }

    size_t Schedule::Size() const {
        return vector_of_items_.size();
    }

    SchedulingItem Schedule::operator[](int index) const {
        return vector_of_items_[index];
    }

    Scheduler::Scheduler() {

    }

    Scheduler::~Scheduler() {

    }

    std::ostream &operator<<(std::ostream &os, SchedulingItem item) {
        os << item.CourseId() << " " << item.TeacherId() << " " << item.RoomId() << " " << item.TimeSlot() << " " << item.Year() << std::endl;
        return os;
    }

    std::ostream &operator<<(std::ostream &os, Schedule schedule) {
        for (int i=0; i<schedule.Size(); ++i){
            os << schedule[i];
        }
        return os;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule rozklad;
        int room=0, time_slot=n_time_slots,counter =0;
        for (auto teacher : teacher_courses_assignment){
            for (auto subject: teacher.second){
                if (time_slot==0){
                    time_slot=n_time_slots;
                    room++; //cały pokój zarezerowany w planie
                    if (room>rooms.size()-1) throw NoViableSolutionFound();
                }
                for (auto year:courses_of_year){
                    for (auto course: year.second){
                        if (course==subject){
                            rozklad.InsertScheduleItem(SchedulingItem {course,teacher.first,rooms[room],time_slot,year.first});
                        }
                    }
                }
                time_slot--;
            }
        }
       for (auto year : courses_of_year){
            for (auto lesson: year.second){
                counter=0;
                for (auto teacher : teacher_courses_assignment){
                    for (auto course : teacher.second){
                        if (lesson==course) counter++;
                        if (counter>n_time_slots) throw NoViableSolutionFound();
                    }
                }
            }
        }
        return rozklad;

    }

    GreedyScheduler::GreedyScheduler() {

    }

    GreedyScheduler::~GreedyScheduler() {

    }
}