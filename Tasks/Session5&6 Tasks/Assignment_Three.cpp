#include<iostream>
using namespace std;


class Shape
{
    protected:
        string name;
    public:
        Shape()
        {
            cout<<"Shape default constructor is called"<<endl;
        }
        Shape(string copy_name)
        {
            name=copy_name;
            cout<<"Shape paremtrized constructor is called"<<endl;
        }
        string getName(){
            return name;
        }
        virtual double calculateArea()=0;
        ~Shape()
        {
            cout<<"Shape destructor is called"<<endl;
        }
};



