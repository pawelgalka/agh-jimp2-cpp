//
// Created by pawel on 24.03.18.
//

#include "SimpleJson.h"

namespace nets{
    JsonValue::JsonValue() {

    }

    JsonValue::JsonValue(int value_integer) {
        json_integer_ = value_integer;
    }

    JsonValue::JsonValue(double value_float) {
        json_float_ = value_float;
    }

    JsonValue::JsonValue(string value_string) {
        json_string_ = value_string;
    }

    JsonValue::JsonValue(bool value_bool) {
        json_bool_ = value_bool;
    }

    JsonValue::JsonValue(std::vector<JsonValue> value_vector) {
        json_vector_ = value_vector;
    }

    JsonValue::JsonValue(std::map<string, JsonValue> value_object) {
        json_object_ = value_object;
    }

    JsonValue::~JsonValue() {

    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        for (auto const& value : *json_object_){
            if (value.first==name) return value.second;
        }
        return optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {
        if (json_integer_) return std::to_string(*json_integer_);

        else if (json_float_){
            std::stringstream stringstream;
            stringstream << std::fixed << std::setprecision(2) << *json_float_;
            return stringstream.str();
        }

        else if (json_string_) {
            string current = *json_string_;
            for (int i = 0; i<current.length();++i){
                if (current[i] == '\"' || current[i] == '\\'){
                    current.insert(i,1,'\\'); // to regex convention
                    ++i;
                }
            }
            return "\""+current+"\"";
        }

        else if (json_bool_){
            if (*json_bool_== true) return "true";
            else return "false";
        }

        else if (json_vector_){
            string output = "[";
            bool first = true;
            for (auto const& value : *json_vector_){
                if (!first) output+=", ";
                else first= false;
                output+=value.ToString();
            }
            output+="]";
            return output;
        }

        else if (json_object_){
            string output = "{";
            for (auto const& value : *json_object_){
                string current = value.first;
                for (int i = 0; i<current.length();++i){
                    if (current[i] == '\"' || current[i] == '\\'){
                        current.insert(i,1,'\\'); // to regex convention
                        ++i;
                    }
                }
                output+="\"" + current + "\": "+value.second.ToString()+", ";
            }
            output=output.substr(0,output.length()-2)+'}';
            return output;
        }
    }
}