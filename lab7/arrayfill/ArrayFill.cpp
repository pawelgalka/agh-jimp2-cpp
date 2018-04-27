//
// Created by pawelgalka on 13.04.18.
//

#include "ArrayFill.h"

namespace arrays{
    void FillArray(int size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (int i=0; i<size; ++i){
            v->push_back(filler.Value(i));
        }
    }

    IncrementalFill::IncrementalFill(int start, int step) {
        start_=start;
        step_=step;
    }

    int IncrementalFill::Value(int index) const {
        return start_+step_*index;
    }


    UniformFill::UniformFill(int value) {
        value_=value;
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    SquaredFill::SquaredFill(int a, int b) {
        a_=a;
        b_=b;
    }

    int SquaredFill::Value(int index) const {
        return a_*pow(index,2)+b_;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator,
                           std::unique_ptr<std::uniform_int_distribution<int>> distribution) {
        generator_= move(generator);
        distribution_ = move(distribution);
    }

    int RandomFill::Value(int index) const {
        return (*distribution_)(*generator_);
    }
}