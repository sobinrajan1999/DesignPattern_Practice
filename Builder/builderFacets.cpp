#include<iostream>

class PersonBaseBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;
class PersonPersonalDetailsBuilder;

class Person{
    private:
        int age;
        std::string gender;
        std::string city;
        std::string district;
        std::string state;
        std::string company;
        std::string designation;
        Person(){}
    public:
        std::string name;
        static PersonBaseBuilder Build();
        friend class PersonBaseBuilder;
        friend class PersonAddressBuilder;
        friend class PersonPersonalDetailsBuilder;
        friend class PersonJobBuilder;
};

class PersonBaseBuilder{
    protected:
        Person person;
    public:
        PersonBaseBuilder(Person &person):person(person){}
        PersonPersonalDetailsBuilder personalDetail();
        PersonAddressBuilder address();
        PersonJobBuilder job();
        operator Person(){
            return this->person;
        }
};

class PersonAddressBuilder: public PersonBaseBuilder{
    public:
        PersonAddressBuilder(Person &person):PersonBaseBuilder(person){}
        
        PersonAddressBuilder& city(std::string city){
            this->person.city = city;
            return *this;
        }
        
        PersonAddressBuilder& district(std::string district){
            this->person.district = district;
            return *this;
        }
        
         PersonAddressBuilder& state(std::string state){
            this->person.state = state;
            return *this;
        }
};

class PersonPersonalDetailsBuilder: public PersonBaseBuilder{
    public:
        PersonPersonalDetailsBuilder(Person &person):PersonBaseBuilder(person){}
        
        PersonPersonalDetailsBuilder& age(int age){
            this->person.age = age;
            return *this;
        }
        
        PersonPersonalDetailsBuilder& name(std::string name){
            this->person.name = name;
            return *this;
        }
        
        PersonPersonalDetailsBuilder& gender(std::string gender){
            this->person.gender = gender;
            return *this;
        }
};

class PersonJobBuilder: public PersonBaseBuilder{
    public:
        PersonJobBuilder(Person &person):PersonBaseBuilder(person){}
        
        PersonJobBuilder& company(std::string company){
            this->person.company = company;
            return *this;
        }
        
        PersonJobBuilder& designation(std::string designation){
            this->person.designation = designation;
            return *this;
        }
};

PersonBaseBuilder Person::Build(){
    Person p;
    return {p};
}

PersonPersonalDetailsBuilder PersonBaseBuilder::personalDetail(){
     return PersonPersonalDetailsBuilder(this->person);
}
 
PersonAddressBuilder PersonBaseBuilder::address(){
     return PersonAddressBuilder(this->person);
}
  
PersonJobBuilder PersonBaseBuilder::job(){
     return PersonJobBuilder(this->person);
}



int main(){
    Person p = Person::Build()
        .personalDetail()
            .age(25)
            .name("Sobin")
            .gender("Male")
        .address()
            .city("Bengaluru")
            .district("Bengaluru")
            .state("Karnataka")
        .job()
            .company("LG")
            .designation("Software Engineer");
            std::cout<<p.name<<std::endl;
    return 0;
}