// One of the classic examples of this principle is a rectangle having four sides. 
// A rectangle’s height can be any value and width can be any value. A square is a
// rectangle with equal width and height. So we can say that we can extend the properties
// of the rectangle class into square class. 

#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    int width, height;
public:
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    int setWidth(int a)
    {
        width = a;
    }

    int setHeight(int a)
    {
        height = a;
    }

    int area()
    {
        return width*height;
    }
};

class Square: public Rectangle
{
public:
    Square(int size) : Rectangle(size, size)
    {

    }

    void setSize(int size)
    {
        setWidth(size);
        setHeight(size);
    }
};

int main()
{
    Square sq(5);
    int a = sq.area();
    std::cout<<a<<std::endl;
}