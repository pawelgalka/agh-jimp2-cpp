//
// Created by pawel on 29.03.18.
//

#include <iostream>
#include "TextPool.h"

namespace pool{
    TextPool::TextPool() {

    }

    TextPool::TextPool(const std::initializer_list<std::string> &arg) : vector_of_strings_{arg} {
        for (int i=0; i<vector_of_strings_.size()-1; ++i){
            for (int j=i+1; j<vector_of_strings_.size(); ++j){
                if (vector_of_strings_[i]==vector_of_strings_[j]) vector_of_strings_.erase(vector_of_strings_.begin()+j-1);
            }
        }
    }

    TextPool::~TextPool() {
        this->vector_of_strings_.clear();
    }

    TextPool::TextPool(TextPool &&moved_pool) {
        std::swap(vector_of_strings_,moved_pool.vector_of_strings_);
        moved_pool.vector_of_strings_.clear();
    }

    TextPool &TextPool::operator=(TextPool &&moved_pool) {
        if (this==&moved_pool){
            return moved_pool;
        }
        vector_of_strings_.clear();
        std::swap(vector_of_strings_,moved_pool.vector_of_strings_);

    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        std::experimental::string_view output;
        for (int i=0; i<vector_of_strings_.size(); ++i){
            if (str==vector_of_strings_[i]){
                output = vector_of_strings_[i];
                return output;
            }
        }
        vector_of_strings_.push_back(str);
        output = vector_of_strings_[vector_of_strings_.size()-1];
        return output;
    }

    size_t TextPool::StoredStringCount() const {
        return vector_of_strings_.size();
    }
}