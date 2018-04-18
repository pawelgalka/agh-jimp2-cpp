//
// Created by pawelgalka on 15.04.18.
//

#include "Kolo.h"

double Kolo::GetX() {
    return x_;
}

double Kolo::GetY() {
    return y_;
}

double Kolo::GetR() const {
    return r_;
}

double Kolo::Pole() const {
    return M_PI*r_*r_;
}
