//
// Created by pawelgalka on 24.04.18.
//

#include "Pesel.h"

namespace academia{
    Pesel::Pesel(const char *pesel) {
        validatePESEL(pesel);
    }

    void Pesel::validatePESEL(std::string pesel) {
        for (int i=0; i<11;++i){
            if (pesel[i]=='\0') {
                throw InvalidPeselLength(pesel,i);
            }
            if (pesel[i]<48 || pesel[i]>57) throw InvalidPeselCharacter(pesel);
        }
        if (pesel.length()!=11) throw InvalidPeselLength(pesel,pesel.length());
        int list[11] = {9,7,3,1,9,7,3,1,9,7};
        int checksum=0;
        for (int i=0; i<10; ++i) checksum+=list[i]*(pesel[i]-48);
        if (abs(checksum-((int)pesel[10]-48))%10!=0) throw InvalidPeselChecksum(pesel,checksum);
        for (int i=0; i<11; ++i){
            pesel_[i] = pesel[i];
        }
    }
}