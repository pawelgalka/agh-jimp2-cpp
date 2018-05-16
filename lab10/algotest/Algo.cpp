//
// Created by pawelgalka on 12.05.18.
//

#include <set>
#include <vector>
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

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(),v->end());
    }


    std::vector <std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> output;
        std::transform(v.begin(),v.end(),std::back_inserter(output),[](double t) -> std::string { return std::to_string(t);});
        return output;
    }


    int Sum(const std::vector<int> &v) {
        std::vector<int> output;
        int suma=0;
        std::for_each(v.begin(), v.end(), [&suma] (int n) { suma += n; });
        return suma;
    }

    int Product(const std::vector<int> &v) {
        std::vector<int> output;
        int product=1;
        std::for_each(v.begin(), v.end(), [&product] (int n) { product *= n; });
        return product;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::__cxx11::string();
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::find(v.begin(),v.end(),element)!=v.end();
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return v.find(key) != v.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return std::find_if(v.begin(),v.end(),[value](std::pair<std::string, int> para)->bool{ return para.second==value;})!=v.end();
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
        int ilosc = std::count_if(v.begin(),v.end(),[inclusive_short_length](std::string str){ return (str.length()<inclusive_short_length);});
        return ilosc;
    }
}