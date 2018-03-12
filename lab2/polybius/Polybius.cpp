//
// Created by pawel on 09.03.18.
//

#include "Polybius.h"

std::map<char, std::string> crypt = {{' ',""},{'a',"11"},{'b',"12"},{'c',"13"},{'d',"14"},{'e',"15"},{'f',"21"},{'g',"22"},{'h',"23"},{'i',"24"},{'j',"24"},{'k',"25"},{'l',"31"},{'m',"32"},{'n',"33"},{'o',"34"},{'p',"35"},{'q',"41"},{'r',"42"},{'s',"43"},{'t',"44"},{'u',"45"},{'v',"51"},{'w',"52"},{'x',"53"},{'y',"54"},{'z',"55"}};
std::map<std::string, char> decrypt = {{"",' '},{"11",'a'},{"12",'b'},{"13",'c'},{"14",'d'},{"15",'e'},{"21",'f'},{"22",'g'},{"23",'h'},{"24",'i'},{"24",'j'},{"25",'k'},{"31",'l'},{"32",'m'},{"33",'n'},{"34",'o'},{"35",'p'},{"41",'q'},{"42",'r'},{"43",'s'},{"44",'t'},{"45",'u'},{"51",'v'},{"52",'w'},{"53",'x'},{"54",'y'},{"55",'z'}};



std::string PolybiusCrypt(std::string message){
    std::string crypted = "";
    int current_place = 0;

    while (message[current_place] != '\0'){
        if (message[current_place] == ' ') crypted += crypt[message[current_place]];
        if (IsLowercase(message, current_place)) crypted += crypt[message[current_place]];
        else if (IsUppercase(message, current_place)) crypted += crypt[tolower(message[current_place])];
        current_place++;
    }

    return crypted;
}

bool IsUppercase(const std::string &message, int current_place) { return (int)message[current_place] >= 65 && (int)message[current_place] <= 90; }

bool IsLowercase(const std::string &message, int current_place) { return (int)message[current_place] >= 97 && (int)message[current_place] <= 122; }

std::string PolybiusDecrypt(std::string crypted){
    std::string message = "";
    std::string key;
    int current_place = 0;
    unsigned long len = crypted.length();
    if (len <= 1) return "";
    do{
        key = crypted[current_place];
        key += crypted[current_place+1];
        message += decrypt[key];
        current_place+=2;
    }
    while (crypted[current_place] != '\0' || crypted[current_place+1] != '\0');
    return message;
}

