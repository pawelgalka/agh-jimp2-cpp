//
// Created by pawel on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

namespace academia{
    class StudyYear{
    public:
        StudyYear();
        StudyYear(const int &year);
        ~StudyYear();

        int GetYear() const;
        void SetYear(int year);

        StudyYear& operator++();
        StudyYear operator++(int a);
        operator int() const;


    private:
        int year_;
    };


    istream &operator>>(istream &is, StudyYear &year);

    ostream &operator<<(ostream &os, StudyYear &year);

    class Student {
    public:
        Student();
        Student(const string &id, const string &first_name, const string &last_name, const string &program, int year);
        ~Student();
        string Id() const ;
        string FirstName() const ;
        string LastName() const ;
        string Program() const ;
        StudyYear Year() const ;
        void ChangeLastName(const string &newLastName);
        bool operator==(Student s1) const ;
        void ChangeFirstName(string new_name);


    private:
        string id_,firstName_,lastName_,program_;
        StudyYear year_{};

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
    private:
        std::vector<Student> students_;
    };

    bool operator>(const StudyYear, const StudyYear);
    bool operator>=(const StudyYear, const StudyYear);
    bool operator<(const StudyYear, const StudyYear);
    bool operator<=(const StudyYear, const StudyYear);
    bool operator==(const StudyYear, const StudyYear);
    bool operator==(const int , const StudyYear);
    bool operator==(const StudyYear, const int);
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
