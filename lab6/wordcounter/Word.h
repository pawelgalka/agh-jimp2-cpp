//
// Created by pawelgalka on 11.04.18.
//

#include<string>
using std::string;

namespace datastructures {
    class Word {
    public:
        // constructors:
        Word();
        Word(string str);

        string GetWord() const;

        bool operator==(const Word &other) const;
        bool operator<(const Word &other) const;
        bool operator>(const Word &other) const;;
        operator string() const;

    private:
        std::string word_;
    };
}



