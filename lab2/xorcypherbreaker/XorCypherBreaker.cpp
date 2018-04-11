//
// Created by pawel on 09.03.18.
//

#include "XorCypherBreaker.h"


std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<string> &dictionary){
    string key = "";
    vector<string> possible_message;

    for (int i=0; i<128; ++i){ // assuming that key_length is 3     0-127 range as ASCII range
        for (int j=0; j<128; ++j){
            for (int k=0; k<128; ++k){
                int key_place = 0;
                key = CreateKey(key, i, j, k);

                DecryptWithKey(cryptogram, key_length, key, possible_message, key_place);

                int word_counter = CheckWithDirectory(dictionary, possible_message);

                if (word_counter > cryptogram.size()/12)  return key; // assuming that average length of word is 6 and our accuracy is ~50% that is why there is division by 12

            }
        }
    }
    return "";
}

int CheckWithDirectory(const vector<string> &dictionary, const vector<string> &possible_message) {
    int word_counter = 0;

    for (auto const& word : possible_message){
                    if (find(dictionary.begin(),dictionary.end(),word) != dictionary.end()) {
                        word_counter++;
                    }
                }
    return word_counter;
}

void DecryptWithKey(const vector<char> &cryptogram, int key_length, const string &key, vector<string> &possible_message,
int key_place) {
    possible_message.clear();
    string tmp="";
    for (auto const& value : cryptogram) {
char current = (value xor key[key_place]);
if (IsAlpha(current)) tmp += current;
else if (current == ' ' && tmp.length()!=0) {possible_message.emplace_back(tmp); tmp = "";}
key_place++;
if (key_place>=key_length) key_place = 0;
}
}

string &CreateKey(string &key, int i, int j, int k) {
    key = "";
    key += (char)i;
    key += (char)j;
    key += (char)k;
    return key;
}

bool IsAlpha(char current) { return (97 <= current && current <= 122) || (65 <= current && current <= 90); }
