//
// Created by pawelgalka on 23.05.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia{
    class TeacherId{
    public:
        TeacherId(int id):id_{id}{};
        operator int() const;
    private:
        int id_;
    };

    class Teacher{
    public:
        Teacher(TeacherId id, std::string name, std::string dep): id_{id}, name_{name}, department_{dep}{};
        bool operator ==(const Teacher &other) const;
        bool operator !=(const Teacher &other) const;
        TeacherId Id() const ;
        std::string Department() const ;
        std::string Name() const ;

    private:
        std::string department_,name_;
        TeacherId id_;
    };


    class TeacherHash {
    public:
        TeacherHash(){};
        size_t operator()(const Teacher &other) const ;
    };
}



#endif //JIMP_EXERCISES_TEACHERHASH_H
