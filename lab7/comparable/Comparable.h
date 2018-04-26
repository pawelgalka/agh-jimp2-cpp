//
// Created by pawelgalka on 18.04.18.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include "../../lab6/academia/StudentRepository.h"

namespace academia{
    class StudentComparator{
    public:
        virtual bool IsLess(const Student &left, const Student &right)const =0;
        bool operator()(const Student &left, const Student &right);
    };

    class ByFirstNameAscending : public StudentComparator{
    public:
        ByFirstNameAscending();
        virtual bool IsLess(const Student &left, const Student &right)const override ;
    };

    class ByFirstNameDescending : public StudentComparator{
    public:
        virtual bool IsLess(const Student &left, const Student &right)const override ;
    };

    class ByLastNameAscending : public StudentComparator{
    public:
        virtual bool IsLess(const Student &left, const Student &right)const override ;
    };

    class ByProgramAscendingEmptyFirst : public StudentComparator{
    public:
        virtual bool IsLess(const Student &left, const Student &right)const override ;
    };

    class ByProgramAscendingEmptyLast : public StudentComparator{
    public:
        virtual bool IsLess(const Student &left, const Student &right)const override ;
    };

}


#endif //JIMP_EXERCISES_COMPARABLE_H
