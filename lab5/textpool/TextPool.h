//
// Created by pawel on 29.03.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <vector>
#include <experimental/string_view>
#include <set>

namespace pool{
    class TextPool {
    public:
        TextPool(); //domyślny konstruktor
        TextPool(const std::initializer_list<std::string> &arg);
        ~TextPool();
        TextPool(const TextPool &copied_pool)= delete;
        TextPool(TextPool &&moved_pool);
        TextPool &operator=(const TextPool &copied_pool)= delete;
        TextPool &operator=(TextPool &&moved_pool);

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::vector<std::string> vector_of_strings_;
    };
}



#endif //JIMP_EXERCISES_TEXTPOOL_H
