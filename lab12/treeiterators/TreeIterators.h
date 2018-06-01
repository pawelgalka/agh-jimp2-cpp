//
// Created by pawelgalka on 23.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <iostream>
#include "Tree.h"

namespace tree{
    template <typename T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator(Tree<T> *root): tree_{root}{
            CreateVector(root);
            iterator_=0;
        };

        bool operator != (const PreOrderTreeIterator<T> other) const {
            return (vec_from_tree!=other.vec_from_tree || iterator_!=other.iterator_);
        }

        PreOrderTreeIterator &operator++ () {
            if (iterator_>=0) iterator_++;
            return *this;
        }

        T operator*(){
            return vec_from_tree[iterator_];
        }

        void CreateVector(Tree<T> *node) {
            vec_from_tree.push_back(node->Value());
            if (node->left_!= nullptr) CreateVector(node->left_.get());
            if (node->right_!= nullptr) CreateVector(node->right_.get());
        }

        size_t iterator_;
        std::vector<T> vec_from_tree;
    private:
        Tree<T> *tree_ = nullptr;


    };

    template <typename T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(Tree<T> *root):iter_{root->Root()}{};

        PreOrderTreeIterator<T> begin() {
            iter_.iterator_=0;
            return iter_;
        }

        PreOrderTreeIterator<T> end() {
            iter_.iterator_= iter_.vec_from_tree.size()-1;
            return iter_;
        }

        std::vector<T> vec(){
            return iter_.vec_from_tree;
        }

    private:
        PreOrderTreeIterator<T> iter_;
    };

    template <typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *root){
        return PreOrderTreeView<T>(root);
    }

    //------------------------------------------------------------------------------------------------------------//

    template <typename T>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator(Tree<T> *root): tree_{root}{
            CreateVector(root);
            iterator_=0;
        };

        bool operator != (const InOrderTreeIterator<T> other) const {
            return (vec_from_tree!=other.vec_from_tree || iterator_!=other.iterator_);
        }

        InOrderTreeIterator &operator++ () {
            if (iterator_>=0) iterator_++;
            return *this;
        }

        T operator*(){
            return vec_from_tree[iterator_];
        }

        void CreateVector(Tree<T> *node) {
            if (node->left_!= nullptr) CreateVector(node->left_.get());
            vec_from_tree.push_back(node->Value());
            if (node->right_!= nullptr) CreateVector(node->right_.get());
        }

        size_t iterator_;
        std::vector<T> vec_from_tree;
    private:
        Tree<T> *tree_ = nullptr;
    };

    template <typename T>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<T> *root):iter_{root->Root()}{};

        InOrderTreeIterator<T> begin() {
            iter_.iterator_=0;
            return iter_;
        }

        InOrderTreeIterator<T> end() {
            iter_.iterator_= iter_.vec_from_tree.size()-1;
            return iter_;
        }

        std::vector<T> vec(){
            return iter_.vec_from_tree;
        }

    private:
        InOrderTreeIterator<T> iter_;
    };

    template <typename T>
    InOrderTreeView<T> InOrder(Tree<T> *root){
        return InOrderTreeView<T>(root);
    }

    //------------------------------------------------------------------------------------------------------------//

    template <typename T>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator(Tree<T> *root): tree_{root}{
            CreateVector(root);
            iterator_=0;
        };

        bool operator != (const PostOrderTreeIterator<T> other) const {
            return (vec_from_tree!=other.vec_from_tree || iterator_!=other.iterator_);
        }

        PostOrderTreeIterator &operator++ () {
            if (iterator_>=0) iterator_++;
            return *this;
        }

        T operator*(){
            return vec_from_tree[iterator_];
        }

        void CreateVector(Tree<T> *node) {
            if (node->left_!= nullptr) CreateVector(node->left_.get());
            if (node->right_!= nullptr) CreateVector(node->right_.get());
            vec_from_tree.push_back(node->Value());
        }

        size_t iterator_;
        std::vector<T> vec_from_tree;
    private:
        Tree<T> *tree_ = nullptr;
    };

    template <typename T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView(Tree<T> *root):iter_{root->Root()}{};

        PostOrderTreeIterator<T> begin() {
            iter_.iterator_=0;
            return iter_;
        }

        PostOrderTreeIterator<T> end() {
            iter_.iterator_= iter_.vec_from_tree.size()-1;
            return iter_;
        }

        std::vector<T> vec(){
            return iter_.vec_from_tree;
        }

    private:
        PostOrderTreeIterator<T> iter_;
    };

    template <typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *root){
        return PostOrderTreeView<T>(root);
    }

}



#endif //JIMP_EXERCISES_TREEITERATORS_H
