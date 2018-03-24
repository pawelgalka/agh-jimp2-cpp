//
// Created by pawel on 21.03.18.
//

#include <regex>
#include <iostream>
#include "SimpleTemplateEngine.h"
using std::string;
using std::regex;
using std::smatch;

namespace nets{
    View::View() {

    }

    View::View(std::string string_input) {
        input_ = string_input;
    }

    View::~View() {

    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        string output ="",current=input_;
        smatch matches;
        regex pattern {R"(\{\{\w+\}\})"};

        while (std::regex_search(current, matches, pattern)){ //if not empty then replace
            for (auto value: matches){
                string word = value.str().substr(2,value.str().length()-4);//after {{ and before }}
                output+=matches.prefix().str();
                if (model.find(word)!=model.end()) output+=model.find(word)->second;
            }
            current=matches.suffix(); // works like iterator; if checked then go on
        }
        output+=current;

        return output;
    }

    std::string View::Output() const {
        return this->input_;
    }

}
