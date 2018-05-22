//
// Created by pawelgalka on 12.05.18.
//

#ifndef JIMP_EXERCISES_ACADEMIASCHEDULER_H
#define JIMP_EXERCISES_ACADEMIASCHEDULER_H


#include <stdexcept>
#include <vector>
#include <map>
#include <set>

namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem();
        SchedulingItem(int course, int teacher, int room, int time, int year):
                course_id_{course}, teacher_id_{teacher}, room_id_{room}, time_slot_{time}, year_{year}{};
        ~SchedulingItem();

        int CourseId() const ;
        int TeacherId() const ;
        int RoomId() const ;
        int TimeSlot() const ;
        int Year() const ;
        friend std::ostream &operator<<(std::ostream &os, SchedulingItem item);

    private:
        int course_id_, teacher_id_, room_id_, time_slot_, year_;
    };

    std::ostream &operator<<(std::ostream &os, SchedulingItem item);

    class Schedule{
    public:
        Schedule();
        Schedule(const std::initializer_list<SchedulingItem> &list);
        ~Schedule();

        void InsertScheduleItem(const SchedulingItem &item);
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        size_t Size() const;
        SchedulingItem operator[](int index) const;
        friend std::ostream &operator<<(std::ostream &os, Schedule schedule);

    private:
        std::vector<SchedulingItem> vector_of_items_;
    };
    std::ostream &operator<<(std::ostream &os, Schedule schedule);

    class Scheduler{
    public:
        Scheduler();
        virtual ~Scheduler();
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class NoViableSolutionFound : public std::invalid_argument{
    public:
        NoViableSolutionFound() : invalid_argument("No solution found"){};
    };

    class GreedyScheduler : public Scheduler{
    public:
        GreedyScheduler();
        virtual ~GreedyScheduler();

        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;

    };
}


#endif //JIMP_EXERCISES_ACADEMIASCHEDULER_H
