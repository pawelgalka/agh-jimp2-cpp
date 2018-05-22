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
    int ReadNumber(std::istream* is);
    void CheckNextChar(char c, std::istream* is);


    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);
        int getYear() const;
        void setYear(int year);

        StudyYear &operator++();
        StudyYear &operator--();

        operator int() const;

    private:
        int year_;
    };

    bool operator<(const StudyYear &a, const StudyYear &b);
    bool operator==(const StudyYear &a, const int b);
    bool operator==(const int b, const StudyYear &a);
    std::ostream &operator <<(std::ostream &os, const StudyYear &year);
    std::istream &operator>>(std::istream &is, StudyYear &year);

    void checkString(std::string c, std::istream &is);
    char ReadChar(std::istream *is);

    class Student {
    public:
        Student();
        Student(std::string id, std::string first_name, std::string last_name, std::string program, StudyYear year);


        std::string Id()const;
        std::string FirstName()const;
        std::string LastName()const;
        std::string Program()const;
        int Year()const;

        void ChangeId(std::string id);
        void ChangeFirstName(std::string first_name);
        void ChangeLastName(std::string last_name);
        void ChangeProgram(std::string program);
        void ChangeYear(const StudyYear &year);




    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;



    };
    bool operator==(const Student &a , const Student &b);
    std::ostream &operator<<(std::ostream &os, const Student &student);
    std::istream &operator>>(std::istream &is, Student &student);


    class StudentException
    {
    public:
        StudentException();
        StudentException(const std::initializer_list<Student> &list);
        int StudentCount()const;
        std::vector<Student> get() const;
        Student &operator [] (std::string id);

        friend std::istream &operator>>(std::istream &is, StudentException &student);
    private:
        std::vector<Student> student_;
    };



    bool operator==(const StudentException &a, const StudentException &b);

    std::ostream &operator<<(std::ostream &os, const StudentException &student);
    std::istream &operator>>(std::istream &is, StudentException &student);


}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
