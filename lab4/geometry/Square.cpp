//
// Created by pawel on 21.03.18.
//
#include "Point.h"
#include "Square.h"


namespace geometry{
    Square::Square(Point p1, Point p2, Point p3, Point p4) {
        if (p1.Distance(p2)==p3.Distance(p4) && p4.Distance(p1)==p2.Distance(p3) ){
            p1_ = p1;
            p2_ = p2;
        }
        else{
            p1_ = Point(0,0);
            p2_ = Point(0,0);
        }
    }


    Square::~Square() {

    }

    double Square::Area() const {
        return p1_.Distance(p2_)*p1_.Distance(p2_);
    }

    double Square::Circumference() const {
        return 4*p1_.Distance(p2_);

    }


}