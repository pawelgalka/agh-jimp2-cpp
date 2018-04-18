//
// Created by pawelgalka on 15.04.18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H

#include <math.h>

class Kolo {
public:
    Kolo(double x=0, double y=0, double r=0) : x_(x), y_(y), r_(r){};
    double GetX();
    double GetY();
    double GetR() const ;
    virtual double Pole() const;

private:
    double x_,y_,r_;

};


#endif //JIMP_EXERCISES_KOLO_H
