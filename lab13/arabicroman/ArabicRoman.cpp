//
// Created by galkpawe on 06.06.18.
//

#include "ArabicRoman.h"

//std::map<int,std::string> decimal = {{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"}};
//std::map<int,std::string> big = {{10,"X"}};


std::string ArabicToRoman(int arabic) {
    if (arabic >= 4000) throw std::invalid_argument("Too big number");
    if (arabic <= 0 ) throw std::invalid_argument("Too small number");
    std::string M[]={"","M","MM","MMM"};
    std::string C[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","DM"};
    std::string X[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    std::string I[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    return M[arabic/1000]+C[(arabic%1000)/100]+X[(arabic%100)/10]+I[arabic%10];
}

int RomanToArabic(std::string roman) {
    std::regex pattern{R"(M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3}))"};
    std::smatch out;
    if (!std::regex_match(roman,out,pattern)) throw std::invalid_argument("");
    std::map<char, int> mapa = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int output=0;
    for (int i=0; i<roman.length(); ++i){
        int current = mapa[roman[i]];
        if (i+1 < roman.length()){
            int cur1 = mapa[roman[i+1]];
            if (cur1>current) {output+=-current+cur1; ++i;}
            else output+=current;
        }
        else {
            output += current;
            ++i;
        }
    }
    return output;
}
