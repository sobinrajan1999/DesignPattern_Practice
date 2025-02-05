// single responsibility principle is acheived by moving the saving responsibiliy to persistence manager and adding the journal entry to journal class. One class has one single responsibility.

#include <bits/stdc++.h>
using namespace std;

class journal
{
private:
    std::vector<string> dailyjournal;
public:
    journal() = default;
    ~journal() = default;
    void add(std::string str)
    {
        dailyjournal.push_back(str);
    }

    vector<string> entries()
    {
        return dailyjournal;
    }
};

class persistenceManager
{
public:
    void save_journal(journal& j, std::string filename)
    {
        ofstream ofs(filename);
        for(auto it: j.entries())
        {
            ofs << it << std::endl;
        }
    }
};

int main()
{
    journal j;
    j.add("Hi, My name is Sobin.");
    j.add("Hi there, How are you?");
    persistenceManager p;
    p.save_journal(j, "dairy.txt");
}