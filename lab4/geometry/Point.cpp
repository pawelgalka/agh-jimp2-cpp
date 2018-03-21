//
// Created by pawel on 21.03.18.
//

#include <iosfwd>
#include "Point.h"

 namespace geometry{
     Point::Point():x_(0),y_(0){

     }

     Point::Point(double x, double y){
         x_ = x;
         y_ = y;
     }

     Point::~Point(){

     }

     double Point::Distance(const Point &other) const{
         return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
     }

     void Point::ToString(ostream *out) const{
         (*out) << "(" << GetX() << ";" << GetY() << ")";
     }


     double Point::GetX() const {
         return this->x_;
     }

     double Point::GetY() const {
         return this->y_;
     }

     void Point::SetX(double x) {
        this->x_ = x;
     }

     void Point::SetY(double y) {
        this->y_ = y;
     }
 }