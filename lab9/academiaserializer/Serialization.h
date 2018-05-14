//
// Created by kaszalek on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H
#include<iostream>
#include <string>
#include<functional>
#include<vector>
#include <experimental/optional>


namespace academia{
    class Serializable;

    class Serializer{
    public:
        Serializer(){};
        explicit Serializer(std::ostream *out);
        virtual ~Serializer(){};

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

    protected:
        std::ostream *out_;
    };

    class XmlSerializer: public Serializer{
    public:
        XmlSerializer(){};
        explicit XmlSerializer(std::ostream *out):Serializer(out){};
        virtual ~XmlSerializer(){};

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class JsonSerializer: public Serializer{
    public:
        JsonSerializer(){};
        JsonSerializer(std::ostream *out):Serializer(out){};
        virtual ~JsonSerializer(){};

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    protected:
        bool first = true;
        void PutComma(bool &first);
    };

    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer)const =0;
    private:

    };

    class Room:public Serializable{
    public:
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM,
        };
        Room(int id, const std::string &name, Type room_type);
        void Serialize(Serializer *serializer) const override;

        std::string TypeToString(Room::Type type)const;
    private:
        int id_;
        std::string name_;
        Type type_;
    };

    class Building:public Serializable{
    public:
        Building();
        Building(const int &id,const std::string &name,const std::initializer_list<Room> &list_of_rooms);

        void Serialize(Serializer *serializer) const override;
        int Id();

    private:
        int id_;
        std::string name_;
        std::vector<Room> vector_of_rooms_;
    };

    class BuildingRepository{
    public:
        explicit BuildingRepository(const std::initializer_list<Building> &list_of_buildings);
        void StoreAll(Serializer *serializer) const ;
        void Add(Building building);
        std::experimental::optional<Building> operator [](int number) const ;

    private:
        std::vector<Building> vector_of_buildings;
    };


}


#endif //JIMP_EXERCISES_SERIALIZATION_H
