//
// Created by pawel on 14.03.18.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
#include <vector>



namespace tinyurl {

    struct TinyUrlCodec{
        std::map<std::string, std::string> mapa;
        std::array<char, 6> CurrentState;

    };
    using TinyUrlCodec = struct TinyUrlCodec;
    //std::vector<char, std::string> TinyUrlCodec;
    //using TinyUrlCodec = std::array<char, 6>;
    //using TinyUrlCodec = std::map<std::string, std::string>; // url i hash
    //using TinyUrlCodec = std::vector<char, std::string>;
    //using TinyUrlCodec = std::array<char, 6>;
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}


#endif //JIMP_EXERCISES_TINYURL_H
