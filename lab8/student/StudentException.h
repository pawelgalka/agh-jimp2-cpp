//
// Created by pawel on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>
#include <regex>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

namespace academia{
    class Student {
    public:
        Student();
        Student(const string &info, const string &program, const int &year);
        ~Student();
        string FirstName() const ;
        string LastName() const ;
        string Program() const ;
        int Year() const ;
        friend ostream &operator<<(ostream &os, Student &year);
        void ChangeLastName(const string &newLastName);
        bool operator==(Student s1) const ;
        void ChangeFirstName(string new_name);


    private:
        string firstName_,lastName_,program_;
        int year_;
        void validateInfo(std::string info, std::string program, int year);

    };

    class InvalidNameSurname : public std::invalid_argument{
    public:
        InvalidNameSurname(std::string mes) : invalid_argument(mes) {};
    };

    class InvalidNameCharacter : public std::invalid_argument{
    public:
        InvalidNameCharacter(std::string mes) : invalid_argument(mes) {};
    };

    class InvalidAge : public std::invalid_argument{
    public:
        InvalidAge(std::string mes) : invalid_argument(mes) {};
    };

    class InvalidProgram: public std::invalid_argument{
    public:
        InvalidProgram(std::string mes) : invalid_argument(mes) {};
    };

    istream &operator>>(istream &is, Student &year);

    ostream &operator<<(ostream &os, Student &year);

    class StudentRepository{
    public:
        StudentRepository();
        StudentRepository(std::initializer_list<Student> arg);
        ~StudentRepository();

        int StudentCount() const ;
        Student &operator[](const string &id);
        bool operator==(StudentRepository s) const ;
        std::vector<Student> students_;
    private:

    };
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
