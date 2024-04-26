#include<iostream>
#include <vector>
using namespace std;

class Animal
{
    private:
        double size;
    public:
        Animal()
        {

        }
        virtual void PrintInfo(void){

        }
        ~Animal()
        {

        }

};

class Mammal:public Animal
{
    private:
        double size;
        string color;
        string name;
        int age;
    public:
        Mammal(double copy_size,string copy_color,string copy_name,int copy_age)
        {
            size=copy_size;
            color=copy_color;
            name=copy_name;
            age=copy_age;
            cout<<"mammal paremtrized constructor"<<endl;
        }
        void PrintInfo(void)
        {
            cout<<"Mammal size = "<<size<<endl;
            cout<<"Mammal name = "<<name<<endl;
            cout<<"Mammal age = "<<age<<endl;
            cout<<"Mammal color = "<<color<<endl;
        }
        ~Mammal()
        {
            cout<<"Mammal destructor is called"<<endl;
        }
};

class Bird:public Animal
{
    private:
        string name;
        string color;
        double speed;
        double heightoffly;
    public:
        Bird()
        {
            cout<<"bird default constructor"<<endl;
        }
        Bird(string copy_name,string copy_color,double copy_speed,double copy_heightoffly)
        {
            name=copy_name;
            color=copy_color;
            speed=copy_speed;
            heightoffly=copy_heightoffly;
            cout<<"bird parametrized constructor is called"<<endl;
        }
        void PrintInfo(void)
        {
            cout<<"Bird name = "<<name<<endl;
            cout<<"Bird color = "<<color<<endl;
            cout<<"Bird speed = "<<speed<<endl;
            cout<<"Bird height of fly = "<<heightoffly<<endl;
        }
        ~Bird()
        {
            cout<<"bird Destructor is called"<<endl;
        }
};

class Reptile:public Animal
{
    private:
        string name;
        string color;
        double size;
        int age;
    public:
        Reptile(string copy_name,string copy_color, double copy_size,int copy_age)
        {
            name=copy_name;
            color=copy_color;
            size=copy_size;
            age=copy_age;
            cout<<"reptile parametrized constructor is called"<<endl;
        }
        void PrintInfo(void)
        {
            cout<<"reptile name = "<<name<<endl;
            cout<<"reptile color = "<<color<<endl;
            cout<<"reptile size = "<<size<<endl;
            cout<<"reptile age = "<<age<<endl;
        }
        ~Reptile()
        {
            cout<<"reptile destructor is called"<<endl;
        }
};


int main(void)
{
    Mammal M1(3000,"BLUE","ELEPHANT",30);
    Bird B1("EAGLE","Grey",120,5000);
    Reptile R1("Turtle","green",350,35);

    vector<Animal*> Animals;
    Animals.push_back(&M1);
    Animals.push_back(&B1);
    Animals.push_back(&R1);
    for(int index=0;index<Animals.size();index++)
    {
        Animals[index]->PrintInfo();    
    }
    return 0;
}