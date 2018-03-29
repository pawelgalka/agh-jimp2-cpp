//
// Created by pawel on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>

namespace memorychunk{
    class MemoryChunk {
    public:
        MemoryChunk();
        MemoryChunk(size_t sz);
        ~MemoryChunk();
        MemoryChunk(const MemoryChunk &other);
        MemoryChunk(MemoryChunk &&other);
        MemoryChunk &operator=(const MemoryChunk &other);
        MemoryChunk &operator=(MemoryChunk &&other);

        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;

    private:
        size_t memsize_;
        int8_t *begin_of_memory_;
    };

}


#endif //JIMP_EXERCISES_MEMORYCHUNK_H
