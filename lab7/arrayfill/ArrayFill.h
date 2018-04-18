//
// Created by pawelgalka on 13.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <cmath>
#include <random>
#include <memory>
#include <cstdlib>

namespace arrays{
    class ArrayFill{
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(int size, const ArrayFill &filler, std::vector<int> *v);

    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill(int start=0, int step=1);
        virtual int Value(int index) const override;

    private:
        int start_,step_;
    };


    class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution
                <int>> distribution_);
        virtual int Value(int index) const override;

    private:
        std::unique_ptr<std::default_random_engine> generator_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;
    };


    class SquaredFill : public ArrayFill{
    public:
        SquaredFill(int a=1, int b=0);
        virtual int Value(int index) const override;

    private:
        int a_,b_;
    };


    class UniformFill : public ArrayFill{
    public:
        UniformFill(int value=0);
        virtual int Value(int index) const override;

    private:
        int value_;
    };

}



#endif //JIMP_EXERCISES_ARRAYFILL_H
