//
// Created by pawelgalka on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <utility>
#include <string>
#include <memory>
#include <vector>

namespace utility{
    class IterableIterator {
    public:
        virtual ~IterableIterator() = default;
        virtual std::pair<int, std::string> Dereference()const=0;
        virtual IterableIterator &Next()=0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const=0;


        std::vector<int>::const_iterator left_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_;
        std::vector<std::string>::const_iterator right_end_;
    };


    class ZipperIterator: public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        explicit ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right);
        ~ZipperIterator() override= default;
        std::pair<int, std::string> Dereference()const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other)const override;
    };


    class IterableIteratorWrapper {
    public:
        explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();

    protected:
        std::unique_ptr<IterableIterator> iterator_;
    };


    class Iterable {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
        ~Iterable() = default;

    protected:
        std::pair <std::vector<int>,std::vector<std::string>> iterable_;
    };


    class Zipper: public Iterable {
    public:
        Zipper(std::vector<int> vi, std::vector<std::string> vs);
        /*std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;*/
    };

    class Enumerate: public Iterable {
    public:
        Enumerate(std::vector<std::string> vs);
        /*std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;*/
    };

    class Product: public Iterable {
    public:
        Product(std::vector<int> vi, std::vector<std::string> vs);
       /* std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;*/
    };

}




#endif //JIMP_EXERCISES_ITERABLE_H
