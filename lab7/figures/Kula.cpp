//
// Created by pawelgalka on 15.04.18.
//

#include "Kula.h"

double Kula::GetZ() {
    return z_;
}

double Kula::Pole() const {
    return 4*Kolo::Pole();
}
