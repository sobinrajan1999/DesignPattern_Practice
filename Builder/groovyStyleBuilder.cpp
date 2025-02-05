
#include <bits/stdc++.h>
using namespace std;

class Tag
{
public:
    std::string name, text;
    vector<Tag> children;
    vector<pair<string, string>> attributes;
protected:
    Tag(string root, vector<Tag> child) : name(root), children(child) {};
    Tag(string root, string text) : name(root), text(text) {};
public:
    friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
    {
        os << "<" << tag.name;
        for(const auto& it : tag.attributes)
        {
            os << " "<<it.first<<"=\""<<it.second<<"\"";
        }
        if(tag.children.size() == 0 and tag.text.size() == 0)
        {
            os << ">" <<endl;
        }
        else{
            os << ">"<<endl;
            if(tag.text.length())
            {
                os << tag.text <<endl;
            }
            for(const auto&  child : tag.children)
            {
                os << child;
            }
            os << "</"<<tag.name<<">"<<endl;
        }
        return os;
    }
};

class P : public Tag
{
public:
    explicit P(string text) : Tag("p", text){};
    P(initializer_list<Tag> children) : Tag("p", children){};
    
};

struct IMG : public Tag
{
public:
    explicit IMG(const std::string& url) : Tag{"img", ""}
    {
        attributes.emplace_back(make_pair("src", url));
    }
};

int main()
{
    std::cout<<
    P{
        IMG{
            "http://pokemon.com/pikachu.png"
        }
    } << endl;
}