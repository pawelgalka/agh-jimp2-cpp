//
// Created by pawel on 09.03.18.
//

#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <string>
#include <iostream>
#include <map>


std::string PolybiusCrypt(std::string message);
std::string PolybiusDecrypt(std::string crypted);
bool IsLowercase(const std::string &message, int current_place);
bool IsUppercase(const std::string &message, int current_place);



#endif //JIMP_EXERCISES_POLYBIUS_H
