//
// Created by pawelgalka on 12.05.18.
//

#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <sstream>
#include "Algo.h"

namespace algo{
    std::set <std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> output;
        std::transform(m.begin(),m.end(),std::inserter(output,output.begin()),[](std::pair<std::string, int> para)->std::string{ return para.first;});
        return output;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> output;
        std::transform(m.begin(),m.end(),std::back_inserter(output),[](std::pair<std::string, int> para)->int{ return para.second;});
        return output;
    }

    std::vector<int> DivisableBy(const std::vector<int> &m, int divisor) {
        std::vector<int> output;
        std::copy_if(m.begin(),m.end(),std::back_inserter(output),[divisor](int number){ return number%divisor==0;});
        return output;
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> output = v;
        std::sort(output.begin(),output.end());
        return output;
    }

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(),v->end());
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(),v->end(), [](std::pair<int, int> x, std::pair<int, int> y){return x.first<y.first;});
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(),v->end(), [](std::pair<int, int> x, std::pair<int, int> y){return x.second<y.second;});
    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(),v->end(), [](std::tuple<int, int, int> x, std::tuple<int, int, int> y){return std::get<2>(x) < std::get<2>(y);});

    }

    std::vector <std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> output;
        std::transform(v.begin(),v.end(),std::back_inserter(output),[](double t){ return std::to_string(t);});
        return output;
    }


    int Sum(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 0);
    }

    int Product(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        std::stringstream out;
        std::copy(v.begin(),v.end(),std::ostream_iterator<double>(out,joiner.c_str()));
        return out.str();
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::find(v.begin(),v.end(),element)!=v.end();
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return v.find(key) != v.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return std::find_if(v.begin(),v.end(),[value](std::pair<std::string, int> para){return para.second==value;})!=v.end();
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(),v->end(),initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> output;
        std::fill_n(std::back_inserter(output),length,initial_value);
        return output;
    }

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy(v.begin(),v.begin()+n_elements,std::back_inserter(*out));
    }

    int HowManyShortStrings(const std::vector <std::string> &v, int inclusive_short_length) {
        int ilosc = std::count_if(v.begin(),v.end(),[inclusive_short_length](std::string str){ return (str.length()<=inclusive_short_length);});
        return ilosc;
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        std::vector<std::string> output = v;
        std::sort(output.begin(),output.end());
        auto last = std::unique(output.begin(), output.end());
        output.erase(last, output.end());
        return output;
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {
        std::sort(v->begin(),v->end());
        auto last = std::unique(v->begin(), v->end());
        v->erase(last, v->end());
    }

}