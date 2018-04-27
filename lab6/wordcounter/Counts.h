//
// Created by pawelgalka on 11.04.18.
//

namespace datastructures{
    class Counts {
    public:
        Counts();
        Counts(int number);

        int GetCounts() const;

        operator int() const ; //rzutowanie
        bool operator<(const Counts &other); //operacje boolean
        bool operator==(const Counts &other);
        bool operator>(const Counts &other);
        Counts &operator++();
        Counts operator++(int foo);


    private:
        int counter_;
    };
}



