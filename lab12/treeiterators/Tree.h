//
// Created by pawelgalka on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <vector>
#include <bits/unique_ptr.h>

namespace tree {
    template <typename T>
    class Tree {
    public:
        Tree();
        ~Tree();
        explicit Tree(T val){value_=val, size_=1;};
        void Insert(const T &e);
        T Value(){ return value_;};
        bool Find(const T &e);
        size_t Size() const ;
        size_t Depth() const ;
        auto Root() ;
        std::unique_ptr<Tree<T>> left_ = nullptr;
        std::unique_ptr<Tree<T>> right_ = nullptr;

    private:
        T value_;
        size_t size_;

    };

    template<typename T>
    Tree<T>::Tree() {
        size_=0;
    }



    template<typename T>
    void Tree<T>::Insert(const T &e) {
        if (e >=value_){
            if (right_== nullptr){
                std::unique_ptr<Tree<T>> newnode = std::make_unique<Tree<T>>();
                newnode->value_=e;
                right_=std::move(newnode);
            }
            else
                right_->Insert(e);
        }
        else{
            if (left_== nullptr){
                std::unique_ptr<Tree<T>> newnode = std::make_unique<Tree<T>>();
                newnode->value_=e;
                left_=std::move(newnode);
            }
            else
                left_->Insert(e);
        }
        size_++;
    }

    template<typename T>
    Tree<T>::~Tree() {

    }


    template<typename T>
    bool Tree<T>::Find(const T &e) {
        if (left_!= nullptr || right_!= nullptr){
            if (e==value_) return true;
            else if (e>value_) right_->Find(e);
            else left_->Find(e);
        }
        return false;
    }

    template<typename T>
    size_t Tree<T>::Size() const {
        return size_;
    }

    template<typename T>
    size_t Tree<T>::Depth() const {
        if (this!= nullptr){ return 1+ std::max(left_->Depth(),right_->Depth());};
        return 0;
    }

    template<typename T>
    auto Tree<T>::Root()  {
        return this;
    }
}

#endif //JIMP_EXERCISES_TREE_H
