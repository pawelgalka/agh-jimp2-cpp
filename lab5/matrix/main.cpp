//
// Created by pawel on 29.03.18.
//

#include <iostream>
#include "Matrix.h"
using namespace algebra;

int main(){
    /*Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    Matrix m2{0,0};
    std::cout<<m1.Print()<<std::endl;
    std::cout << m1.Add(m2).Print();
    //std::cout<<m2.Print();*/
    Matrix m1{{1. + 3.0i, 2. + 2.0i}, {3. + 1.0i, 4. + 6.0i}, {5. + 5.i, 6. + 4.0i}};
    Matrix m2{{7. + 1.0i, 12. + 1.3i, 1.5 + 3.7i, 1.0i}, {15. + 2.0i, 2. + 4.6i, 2.1 + 3.8i, 1.4 + 0.2i}};
    std::cout<<m1.Mul(m2).Print()<<std::endl;
    Matrix m3{"[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]"};
    Matrix m4{"[7i1, 0i0, 0i0; 0i0, 0i1, 8i0; 15i2, 0i3, 4i1]"};
    std::cout << m3.Add(m4).Print();
}