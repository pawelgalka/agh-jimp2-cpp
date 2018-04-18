//
// Created by pawelgalka on 15.04.18.
//

#include "Kula.h"

double Kula::GetZ() {
    return z_;
}

double Kula::Pole() const {
    return M_PI*4*GetR()*GetR();
}
