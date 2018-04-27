 //
// Created by pawelgalka on 15.04.18.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"

class Kula :public Kolo{
public:
    Kula(double x, double y, double z, double r): Kolo(x,y,r), z_(z){};
    double GetZ();
    virtual double Pole() const override ;

private:
    double z_;
};


#endif //JIMP_EXERCISES_KULA_H
