#include <iostream>

using namespace std;

class Person
{
public:
    void introduce()
    {
        cout<<"this is person"<<endl;
    }
};

class Student: public Person
{
public:
    void introduce()
    {
        cout<<"this is student"<<endl;
    }
};

class Farmer: public Person
{
public:
    void introduce()
    {
        cout<<"this is farmer"<<endl;
    }
};

void whosthis(Person &p)
{
    p.introduce();
}

int main()
{
    Farmer farmer;
    Student student;
    whosthis(farmer);
    return 0;
}
