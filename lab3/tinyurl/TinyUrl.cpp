//
// Created by pawel on 14.03.18.
//

#include "TinyUrl.h"

namespace tinyurl {

    std::string d = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    std::map<std::string, std::string> results;
    std::unique_ptr<TinyUrlCodec> Init(){
        std::unique_ptr<TinyUrlCodec> pointer = std::make_unique<TinyUrlCodec>();

        if (results.empty()) {
            for (int i=0; i<=5; ++i){
                pointer->CurrentState[i] = '0';
            }
        }
        else {
            std::array<char ,6> current;
            auto it = --(results).end();
            int i;
            for (i=0; i<=5; ++i){
                current[i] = it->first[i];
            }
            NextHash(&current);
            pointer->CurrentState = current;
        }
        return pointer;
    }


    void NextHash(std::array<char, 6> *state){
        int i=5,j;
        if ((*state)[5]!=d[25] && (*state)[5]!=d[51] && (*state)[5]!=d[61]){
            (*state)[5] += 1;
        }

        else{
            if ((*state)[i]==d[51]) {
                (*state)[i] = d[(d.find((*state)[i])+1)%d.length()];
                for (j=i-1; j>=0; --j){
                    if ((*state)[j+1]!=d[26] && (*state)[j+1]!=d[52] && (*state)[j+1]!=d[0]) break;
                    (*state)[j] = d[(d.find((*state)[j])+1)%d.length()];
                }
            }
            else {
                (*state)[i] = d[(d.find((*state)[i])+1)%d.length()];
            }
        }
    }



    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string code ="";
        for (int i=0; i<=5; ++i) code += (*codec)->CurrentState[i];
        NextHash(&((**codec).CurrentState));
        (*codec)->mapa.insert((std::make_pair(code,url)));
        return code;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        auto it = (*codec).mapa.find(hash);
        std::string url = it->second;
        return url;
    }

}
