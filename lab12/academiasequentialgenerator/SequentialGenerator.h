//
// Created by pawelgalka on 23.05.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <typename T, typename U>
class SequentialIdGenerator {
public:
    SequentialIdGenerator():iterator_{0}{};
    SequentialIdGenerator(U arg):iterator_{arg}{};
    T NextValue();
private:
    U iterator_;
};

template<typename T, typename U>
T SequentialIdGenerator<T, U>::NextValue() {
    U current = iterator_;
    ++iterator_;
    return T(current);
}


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
