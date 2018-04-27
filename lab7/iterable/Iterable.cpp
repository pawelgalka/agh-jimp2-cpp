//
// Created by pawelgalka on 21.04.18.
//

#include "Iterable.h"

namespace utility{

    //ZipperIterator//
    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                   std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end) {
        left_ = left;
        left_end = left_end;
        right_ = right;

    }
    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right) {

        left_ = left;
        right_ = right;

    }

    std::pair<int, std::string> ZipperIterator::Dereference() const {
        return std::make_pair(*left_, *right_);
    }

    IterableIterator &ZipperIterator::Next() {
        left_++;
        right_++;
        return *this;
    }


    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        return (left_ != other->left_ || right_ != other->right_);

    }


    //IterableIteratorWrapper//
    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator) {
        iterator_=std::move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {

        return iterator_->NotEquals(other.iterator_);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() {
        return iterator_->Dereference();
    }

    IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
        iterator_->Next();
        return *this;
    }

    IterableIteratorWrapper Iterable::cbegin() const {
        return IterableIteratorWrapper{ConstBegin()};
    }

    IterableIteratorWrapper Iterable::cend() const {
        return IterableIteratorWrapper{ConstEnd()};
    }

    IterableIteratorWrapper Iterable::begin() const {
        return cbegin();
    }

    IterableIteratorWrapper Iterable::end() const {
        return cend();
    }

    std::unique_ptr<IterableIterator> Iterable::ConstBegin() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.begin(),iterable_.second.begin()));
    }

    std::unique_ptr<IterableIterator> Iterable::ConstEnd() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.end(),iterable_.second.end()));
    }

    //Zipper//
    Zipper::Zipper(std::vector<int> vi, std::vector<std::string> vs) {
        if (vi.size()>vs.size()){
            for (auto i=vs.size(); i<vi.size(); ++i) vs.emplace_back(vs.back());
        }
        else{
            for (auto i=vi.size(); i<vs.size(); ++i) vi.emplace_back(vi.back());
        }
        iterable_=std::make_pair(vi,vs);
    }

    /*std::unique_ptr<IterableIterator> Zipper::ConstBegin() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.begin(),iterable_.second.begin()));
    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        return std::make_unique<ZipperIterator>( ZipperIterator(iterable_.first.end(),iterable_.second.end()));
    }*/

    Enumerate::Enumerate(std::vector<std::string> vs) {
        std::vector<int> vi;
        for (auto i=1; i<=vs.size(); ++i)vi.emplace_back(i);
        iterable_ = std::make_pair(vi,vs);
    }

    /*std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.begin(),iterable_.second.begin()));
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.end(),iterable_.second.end()));
    }*/

    Product::Product(std::vector<int> vi, std::vector<std::string> vs) {
       std::vector<int> v1;
       std::vector<std::string> v2;

       for (auto i : vi){
           for (auto j : vs){
               v1.emplace_back(i);
               v2.emplace_back(j);
           }
       }
       iterable_=std::make_pair(v1,v2);
    }

    /*std::unique_ptr<IterableIterator> Product::ConstBegin() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.begin(),iterable_.second.begin()));
    }

    std::unique_ptr<IterableIterator> Product::ConstEnd() const {
        return std::make_unique<ZipperIterator>(ZipperIterator(iterable_.first.end(),iterable_.second.end()));
    }*/
}