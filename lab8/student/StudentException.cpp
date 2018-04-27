//
// Created by pawel on 10.04.18.
//

#include "StudentException.h"

namespace academia{

    Student::Student() {
        this->firstName_="";
        this->lastName_="";
        this->program_="";
    }

    Student::Student(const string &info, const string &program, const int &year) {
        validateInfo(info,program,year);
    }

    void Student::validateInfo(std::string info, std::string program, int year) {
        std::regex r{R"([A-Z](\w+)\s[A-Z](\w+))"};
        std::vector<std::string> set_of_programs{"informatyka","ekonomia","matematyka","filozofia","fizyka"};
        std::smatch s;
        if (!std::regex_match(info,s,r)){
            throw InvalidNameSurname("Invalid format of name and surname");
        }
        if (std::find(set_of_programs.begin(),set_of_programs.end(),program)==set_of_programs.end()) {
            throw InvalidProgram("Invalid program");
        }
        if (year>100 || year<10) throw InvalidAge("Invalid age");
        firstName_=s[1];
        lastName_=s[2];
        program_=program;
        year_=year;
    }

    Student::~Student() {

    }

    string Student::FirstName() const {
        return this->firstName_;
    }

    string Student::LastName() const {
        return this->lastName_;
    }

    string Student::Program() const {
        return this->program_;
    }

    int Student::Year() const {
        return this->year_;
    }

    void Student::ChangeLastName(const string &newLastName) {
        this->lastName_=newLastName;
    }


    void Student::ChangeFirstName(string new_name) {
        this->firstName_=new_name;
    }

    istream &operator>>(istream &is, Student &year) {

    }



}
