//
// Created by kaszalek on 09.05.18.
//

#include "Serialization.h"

namespace academia{

    Serializer::Serializer(std::ostream *out){
        out_ = out;
    }

    std::string Room::TypeToString(Room::Type type) const{
        switch(type) {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    Room::Room(int id, const std::string &name, Type room_type){
        id_=id;
        name_=name;
        type_=room_type;
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id",id_);
        serializer->StringField("name",name_);
        serializer->StringField("type",TypeToString(type_));
        serializer->Footer("room");
    }

    Building::Building(const int &id, const std::string &name, const std::initializer_list<Room> &list_of_rooms) {
        id_ = id;
        name_ = name;
        for (auto const &v: list_of_rooms){
            vector_of_rooms_.push_back(v);
        }
    }
    void Building::Serialize(Serializer *serializer) const {
        std::vector<std::reference_wrapper<const academia::Serializable>> value(vector_of_rooms_.begin(), vector_of_rooms_.end());
        serializer->Header("building");
        serializer->IntegerField("id",id_);
        serializer->StringField("name",name_);
        serializer->ArrayField("rooms",value);
        serializer->Footer("building");
    }

    int Building::Id() {
        return id_;
    }

    BuildingRepository::BuildingRepository(const std::initializer_list<Building> &list_of_buildings) {
        for (auto const &val: list_of_buildings){
            vector_of_buildings.push_back(val);
        }
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        std::vector<std::reference_wrapper<const academia::Serializable>> value;
        for (auto const &v : vector_of_buildings){
            value.emplace_back(std::cref(v));
        }
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", value);
        serializer->Footer("building_repository");
    }

    void BuildingRepository::Add(Building building) {
        vector_of_buildings.push_back(building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int number) const {
        for (auto val: vector_of_buildings){
            if (val.Id()==number)
                return val;
        }
    }
///////////////////////////////////JSON///////////////////////////////////////////////

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        PutComma(first);
        *out_ << "\"" << field_name << "\": " << value;
       // PutComma(first);
    }


    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        PutComma(first);
        *out_ << "\"" << field_name << "\": " << value;
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        PutComma(first);
        *out_ << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        PutComma(first);
        *out_ << "\"" << field_name << "\": " << value;
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        PutComma(first);
        *out_ << "\"" << field_name << "\": " ;
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        PutComma(first);
        *out_ << "\"" << field_name << "\": [" ;
        bool first_room = true;
        for (const Serializable &val: value){
            first=true;
            PutComma(first_room);
            val.Serialize(this);

        }
        *out_ << "]" ;
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }

    void JsonSerializer::PutComma(bool &first) {
        if (first) first=false;
        else *out_ << ", ";
    }

////////////////////////////////XML///////////////////////////////////////////////


    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" << field_name << ">" << "<\\" << field_name << ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";

        for (const Serializable &val : value){
            val.Serialize(this);
        }

        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_<< "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<< "<\\" << object_name << ">";
    }
}