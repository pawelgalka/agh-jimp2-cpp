//
// Created by pawel on 27.03.18.
//

#include <cstring>
#include "MemoryChunk.h"

namespace memorychunk{
    MemoryChunk::MemoryChunk() {
        this->begin_of_memory_= nullptr;
        this->memsize_=0;
    }

    MemoryChunk::MemoryChunk(size_t sz) {

        if (sz>0){
            this->memsize_=sz;
            this->begin_of_memory_ = new int8_t[this->memsize_/sizeof(int8_t)];

        }
        else{
            this->begin_of_memory_ = nullptr;
            this->memsize_=0;
        }
    }

    MemoryChunk::~MemoryChunk() {
        delete[] begin_of_memory_;
    }

    MemoryChunk::MemoryChunk(const MemoryChunk &other) {
        this->memsize_ = other.memsize_;
        this->begin_of_memory_ = new int8_t[memsize_/sizeof(int8_t)];
        memcpy(begin_of_memory_,other.begin_of_memory_,memsize_);
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&other) {
        begin_of_memory_= nullptr;
        memsize_=0;
        std::swap(begin_of_memory_,other.begin_of_memory_);
        std::swap(memsize_,other.memsize_);
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &other) {
        if(this==&other){
            return *this;
        }
        delete[] begin_of_memory_;
        memsize_ = other.memsize_;
        this->begin_of_memory_=new int8_t[memsize_/ sizeof(int8_t)];
        memcpy(begin_of_memory_,other.begin_of_memory_,other.memsize_);
    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&other) {
        if (this==&other){
            return other;
        }
        else{
            delete[] begin_of_memory_;
            begin_of_memory_ = nullptr;
            std::swap(begin_of_memory_,other.begin_of_memory_);
            std::swap(memsize_,other.memsize_);
        }
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return begin_of_memory_+offset;
    }

    size_t MemoryChunk::ChunkSize() const {
        return memsize_;
    }
}