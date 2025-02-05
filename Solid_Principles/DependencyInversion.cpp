#include <bits/stdc++.h>
using namespace std;

enum Relationship
{
    parent, child, sibling
};

struct Person
{
    string name;
};

class RelationshipBrowser
{
public:
    virtual vector<Person> find_child_of(std::string name) = 0;
};

class Relationships : public RelationshipBrowser
{
private:
    vector<tuple<Person, Relationship, Person>> relations;
public:

    void add_parent_child(Person& parent, Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_child_of(std::string name) override
    {
        vector<Person> result;
        for(auto& [first, rel, second] : relations)
        {
            if(first.name == name and rel == Relationship::parent)
                result.push_back(second);
        }
        return result;
    }
};

class RelationshipManager
{
public:
    RelationshipManager(RelationshipBrowser& relations)
    {
        for(auto& child : relations.find_child_of("John"))
        {
            std::cout<<"John has a child called "<<child.name<<std::endl;
        }
    }
};

int main()
{
    Person parent{"John"};
    Person child1{"Chris"} ,child2{"Matt"};
    Relationships relationships;
    relationships.add_parent_child(parent, child1);
    relationships.add_parent_child(parent, child2);

    RelationshipManager manager(relationships);
}