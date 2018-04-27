//
// Created by pawelgalka on 18.04.18.
//

#include "Comparable.h"

namespace academia{
    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) const {
        return left.FirstName()<right.FirstName();
    }

    bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) const {
        if (left.Program().empty()) return true;
        if (right.Program().empty()) return false;
        return left.Program()<right.Program();

    }

    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) const {
        return left.FirstName()>right.FirstName();
    }

    bool StudentComparator::operator()(const Student &left, const Student &right) {
        IsLess(left, right);
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) const {
        if (left.Program().empty()) return false;
        if (right.Program().empty()) return true;
        return left.Program()<right.Program();
    }

    bool ByLastNameAscending::IsLess(const Student &left, const Student &right) const {
        return left.LastName()<right.LastName();
    }
}