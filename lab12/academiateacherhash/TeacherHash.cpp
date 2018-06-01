//
// Created by pawelgalka on 23.05.18.
//

#include "TeacherHash.h"

namespace academia{
    TeacherId::operator int() const {
        return id_;
    }

    bool Teacher::operator==(const Teacher &other) const {
        return (Id()==other.Id() && Department()==other.Department() && Name()==other.Name());
    }

    bool Teacher::operator!=(const Teacher &other) const {
        return !(Id()==other.Id() && Department()==other.Department() && Name()==other.Name());
    }

    TeacherId Teacher::Id() const {
        return id_;
    }

    std::string Teacher::Department() const {
        return department_;
    }

    std::string Teacher::Name() const {
        return name_;
    }

    size_t TeacherHash::operator()(const Teacher &other) const {
        return std::hash<int>()(other.Id()) ^ std::hash<std::string>()(other.Department()) ^ std::hash<std::string>()(other.Name());
    }
}
