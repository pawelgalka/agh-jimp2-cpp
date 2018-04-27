//
// Created by pawel on 10.04.18.
//

#include "StudentRepository.h"

namespace academia{
    StudyYear::StudyYear() {
        this->year_=1;
    }

    StudyYear::~StudyYear() {

    }

    StudyYear::StudyYear(const int &year) {
        this->year_=year;
    }

    void StudyYear::SetYear(int year) {
        this->year_=year;
    }

    int StudyYear::GetYear() const {
        return this->year_;
    }

    StudyYear &StudyYear::operator++() {
        this->year_++;
        return *this;
    }

    StudyYear StudyYear::operator++(int a) {
        StudyYear tmp(this->year_);
        this->year_++;
        return tmp;
    }

    StudyYear::operator int() const {
        return this->year_;
    }

    istream &operator>>(istream &is, StudyYear &year) {
        int liczba;
        is >> liczba;
        year.SetYear(liczba);
    }

    ostream &operator<<(ostream &os, StudyYear &year) {
        os << year.GetYear();
    }

    Student::Student() {
        this->id_="";
        this->firstName_="";
        this->lastName_="";
        this->program_="";
        this->year_;
    }

    Student::Student(const string &id, const string &first_name, const string &last_name, const string &program, int year) {
        this->id_=id;
        this->firstName_=first_name;
        this->lastName_=last_name;
        this->program_=program;
        this->year_.SetYear(year);
    }

    Student::~Student() {

    }

    string Student::Id() const {
        return this->id_;
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

    StudyYear Student::Year() const {
        return this->year_.GetYear();
    }

    void Student::ChangeLastName(const string &newLastName) {
        this->lastName_=newLastName;
    }


    bool Student::operator==(Student s1) const
    {
        return (this->Id()==s1.Id() && this->FirstName()==s1.FirstName() && this->LastName()==s1.LastName() &&
                this->Program()==s1.Program() && this->Year()==s1.Year());
    }

    void Student::ChangeFirstName(string new_name) {
        this->firstName_=new_name;
    }

    istream &operator>>(istream &is, Student &year) {

    }

    ostream &operator<<(ostream &os, Student &year) {
        os << "{id: \"" << year.Id() << "\", first_name: " << year.FirstName() << "\", last_name: " << year.LastName() << "\", program: "
 << year.Program() << "\", year: " << (int)year.Year()  ;  }


    StudentException::StudentException() {

    }

    StudentException::StudentException(std::initializer_list<Student> arg) {
        for (auto const & value: arg){
            students_.push_back(value);
        }
    }

    StudentException::~StudentException() {

    }

    int StudentException::StudentCount() const {
        return students_.size();
    }

    Student &StudentException::operator[](const string &id) {
        for (int i=0; i<students_.size(); ++i){
            if (students_[i].Id()==id) return students_[i];
        }
        Student result=Student();
        return result;
    }

    bool StudentException::operator==(StudentException s) const {
        for (int i=0; i<10; ++i){
            if (!(this->students_[i]==s.students_[i])){
                return false;
            }
        }
        return true;
    }

    bool operator>(const StudyYear a, const StudyYear b){
        return (a.GetYear()>b.GetYear());
    }
    bool operator<(const StudyYear a, const StudyYear b){
        return (a.GetYear()<b.GetYear());
    }
    bool operator==(const StudyYear a, const StudyYear b){
        return (a.GetYear()==b.GetYear());
    }
    bool operator==(const int y, const StudyYear s){
        return y==s.GetYear();
    }
    bool operator==(const StudyYear s, const int y){
        return y==s.GetYear();
    }
    bool operator>=(const StudyYear a, const StudyYear b){
        return (a.GetYear()>=b.GetYear());
    }
    bool operator<=(const StudyYear a, const StudyYear b){
        return (a.GetYear()<=b.GetYear());
    }
}
