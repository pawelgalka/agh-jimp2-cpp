//
// Created by pawel on 09.03.18.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::find;
using std::vector;
using std::string;


bool IsAlpha(char current);

string &CreateKey(string &key, int i, int j, int k);

void DecryptWithKey(const vector<char> &cryptogram, int key_length, const string &key, vector<string> &possible_message,
                    int key_place);

int CheckWithDirectory(const vector<string> &dictionary, const vector<string> &possible_message);

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
