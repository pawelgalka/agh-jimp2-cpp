//
// Created by pawelgalka on 20.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <algorithm>
#include <ostream>
#include <map>
#include <iostream>

namespace factoryMethod {

    class MyType{
    public:
        std::string SayHello();
    };

    template<class T>
    T Create(){
        return T();
    }

    template <class T>
    T Sum(const T &left, const T &right){
        return left+right;
    }

    template <class T>
    auto Value(T &arg){
        return *arg;
    }

    template <class T>
    T Mean(std::vector<T> vec){
        T sum = std::accumulate(vec.begin(),vec.end(),0);
        return sum/vec.size();
    }

    template <class T>
    class Repository{
    public:
        Repository(std::pair<int,T> arg);
        size_t Size();
        T operator [](int x) const ;
        std::vector<T> FindBy();
        int NextId();

    private:
        std::map<int,T> vec;
    };

    template <class T>
    bool Query(std::pair<int, T> para, T arg){
        if (para.second==arg) return true;
        return false;
    };

    template<class T>
    Repository<T>::Repository(std::pair<int, T> arg) {
        vec.emplace(arg);
    }

    template<class T>
    size_t Repository<T>::Size() {
        return vec.size();
    }

    template<class T>
    T Repository<T>::operator[](int x) const {
        T out;
        auto tmp = vec.find(x);
        out = tmp->second;
        return out;
    }

    template<class T>
    int Repository<T>::NextId() {
        return vec.end()->second+1;
    }


};


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
