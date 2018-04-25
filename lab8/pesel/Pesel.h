//
// Created by pawelgalka on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>
#include <cstring>

namespace academia{
    class Pesel {
    public:
        Pesel(const char* pesel);

    private:
        int pesel_[11];
        void validatePESEL(std::string pesel);
    };

    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(std::string mes): std::runtime_error{mes} {};
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string pesel, int length): AcademiaDataValidationError{"Invalid PESEL("+pesel+") length: "+std::to_string(length)} {

        };
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(std::string pesel): AcademiaDataValidationError{"Invalid PESEL("+pesel+") character set"} {};
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(std::string pesel, int checksum): AcademiaDataValidationError{"Invalid PESEL("+pesel+") checksum: "+std::to_string(checksum)} {};
    };


}



#endif //JIMP_EXERCISES_PESEL_H
