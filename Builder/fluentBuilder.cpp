#include <bits/stdc++.h>

using namespace std;

class HTMLBuilder;

class HTMLElement
{
public:
    friend HTMLBuilder;
    std::string name, text;
    vector<HTMLElement> elements;
    const int indent_size = 2;
    HTMLElement() = default;
    HTMLElement(const string &name, const string& text) : name(name), text(text){}
private:
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size* indent, ' ');
        oss << i << "<" << name<< ">" << endl;
        if(text.size() > 0)
        {
            oss << string(indent_size*(indent + 1), ' ') << text <<endl;
        }
        for(const auto& e : elements)
        {
            oss << e.str(indent+1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
};

class HTMLBuilder
{
public:
    HTMLElement root;
    HTMLBuilder(string rootstr)
    {
        root.name = rootstr;
    }
    HTMLBuilder& add_child(std::string child_name, std::string child_text)
    {
        HTMLElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }
    string str()
    {
        return root.str();
    }

    static const HTMLBuilder build(std::string root)
    {
        return {root};
    }
};

int main()
{
    auto builder = HTMLBuilder::build("Hello");
    builder.add_child("li", "sobin").add_child("li", "rakesh").add_child("li", "arvind");
    //or
    //HTMLBuilder::build("Hello").add_child("li", "sobin").add_child("li", "rakesh").add_child("li", "arvind");
    std::cout<< builder.str()<<std::endl;
}