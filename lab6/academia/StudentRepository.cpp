//
// Created by pawel on 10.04.18.
//

#include "StudentRepository.h"

namespace academia{
    int ReadNumber(std::istream* is) {
            int d;
            (*is) >> d;
            return d;
        }

        void CheckNextChar(char c, std::istream* is) {
            int next_char = is->peek();
            if (next_char != c) {
                throw std::runtime_error("invalid character");

            }
            is->ignore();
        }

        int StudyYear::getYear() const {
            return year_;
        }

        StudyYear::StudyYear() {
            year_ = 1;
        }

        StudyYear::StudyYear(int year) {
            year_ = year;
        }

        StudyYear &StudyYear::operator++() {
            year_++;
            return *this;
        }

        StudyYear &StudyYear::operator--() {
            year_--;
            if (year_ < 1) year_ = 1;
            return *this;
        }

        void StudyYear::setYear(int year) {

            year_ = year;

        }

        StudyYear::operator int() const {
            return year_;
        }


        bool operator<(const StudyYear &a, const StudyYear &b) {
            if (a.getYear() < b.getYear())
                return 1;
            return 0;
        }

        bool operator==(const StudyYear &a, const int b) {
            if (a.getYear() == b)
                return true;
            return false;
        }

        bool operator==(const int b, const StudyYear &a) {
            if (a.getYear() == b)
                return true;
            return false;
        }

        std::ostream& operator<<(std::ostream &os, const StudyYear &year) {
            int rok = year.getYear();
            return os<<rok;
        }

        std::istream &operator>>(std::istream &is, StudyYear &year) {
            year.setYear(ReadNumber(&is));
            return is;
        }

        char ReadChar(std::istream *is) {
            char d;
            (*is) >> d;
            return d;
        }

        void checkString(std::string c, std::istream &is) {
            for (int i = 0; i < c.length(); i++) {
                CheckNextChar(c[i], &is);
            }

        }

        Student::Student() {}

        Student::Student(std::string id, std::string first_name, std::string last_name, std::string program,
                         StudyYear year) {
            id_ = id;
            first_name_ = first_name;
            last_name_ = last_name;
            program_ = program;
            year_ = year.getYear();
        }

        std::string Student::Id() const {
            return id_;
        }

        std::string Student::FirstName() const {
            return first_name_;
        }

        std::string Student::LastName() const {
            return last_name_;
        }

        std::string Student::Program() const {
            return program_;
        }

        int Student::Year() const {
            return year_.getYear();
        }


        void Student::ChangeId(std::string id) {
            id_ = id;
        }

        void Student::ChangeFirstName(std::string first_name) {
            first_name_ = first_name;
        }

        void Student::ChangeLastName(std::string last_name) {
            last_name_ = last_name;
        }

        void Student::ChangeProgram(std::string program) {
            program_ = program;
        }

        void Student::ChangeYear(const StudyYear &year) {
            year_ = year;
        }

        std::istream &operator>>(std::istream &is, Student &student) {
            checkString("Student {id: \"", is);
            std::string id, first, last, program;
            char c;
            do {
                c = ReadChar(&is);
                id.push_back(c);
            } while (c > 47 && c < 58);
            id = id.substr(0, id.length() - 1);
            student.ChangeId(id);

            checkString(", first_name: \"", is);
            do {
                c = ReadChar(&is);
                first.push_back(c);
            } while (c > 64 && c < 123);
            first = first.substr(0, first.length() - 1);
            student.ChangeFirstName(first);

            checkString(", last_name: \"", is);
            do {
                c = ReadChar(&is);
                last.push_back(c);
            } while (c > 64 && c < 123);
            last = last.substr(0, last.length() - 1);
            student.ChangeLastName(last);

            checkString(", program: \"", is);
            do {
                c = ReadChar(&is);
                program.push_back(c);
            } while ((c > 64 && c < 123) || (c > 47 && c < 58));
            program = program.substr(0, program.length() - 1);
            student.ChangeProgram(program);

            checkString(", year: ", is);

            c = ReadChar(&is);
            int a = c - 48;
            student.ChangeYear(StudyYear{a});
            CheckNextChar('}', &is);


            return is;
        }


        bool operator==(const Student &a, const Student &b) {
            if (a.Id() == b.Id())
                return true;
            return false;
        }

        std::ostream &operator<<(std::ostream &os, const Student &student) {
            return os << "Student {id: \"" << student.Id() << "\", first_name: \"" << student.FirstName()
                      << "\", last_name: \"" << student.LastName() << "\", program: \"" << student.Program() << "\", year: "
                      << student.Year() << "}";
        }

        StudentException::StudentException()
        {

        }

        int StudentException::StudentCount() const {
            return student_.size();
        }

        StudentException::StudentException(const std::initializer_list<Student> &list) {
            for (auto v: list)
            {
                student_.push_back(v);
            }

        }

        std::vector<Student> StudentException::get() const {
            return student_;
        }



        Student &StudentException::operator[](std::string id) {
            bool flag = true;
            int i = 0;

            while (i<student_.size() && flag)
            {
                if(student_[i].Id()==id)
                {
                    flag = false;
                    return student_[i];
                }
                i++;
            }
            std::runtime_error("Did not find");
        }


        bool operator==(const StudentException &a, const StudentException &b) {
            if(a.StudentCount() != b.StudentCount())
                return false;
            bool flag;

            for (auto u: a.get())
            {
                flag = false;
                for(auto v: b.get())
                {
                    if (u.Id() == v.Id())
                        flag = true;
                }
                if(!flag) return false;
            }
            return true;
        }

        std::ostream &operator<<(std::ostream &os, const StudentException &student) {
            os<<"[";
            for(int i=0; i<student.StudentCount()-1;i++)
            {
                os<<student.get()[i]<<", ";
            }
            os<<student.get()[student.StudentCount()-1]<<"]";
        }

        std::istream &operator>>(std::istream &is, StudentException &student) {
            CheckNextChar('[',&is);
            for(int i=0; i<student.StudentCount()-1;i++)
            {
                is>>student.student_[i];
                CheckNextChar(',',&is);
                CheckNextChar(' ',&is);
            }

            is>>student.get()[student.StudentCount()-1];

            CheckNextChar(']',&is);
            return is;
        }
}
