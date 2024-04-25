#include<iostream>
using namespace std;


class Person
{
    private:
        string name;
    public:
        Person()
        {
            cout<<"Person default constructor"<<endl;
        }
        Person(string copy_name)
        {
            name=copy_name;
            cout<<"Person paremtrized constructor"<<endl;
        }
        string getName()
        {
            cout<<"person name ="<<name<<endl;
            return name;
        }
        ~Person()
        {
            cout<<"Person destructor is called"<<endl;
        }
};

class Student:public Person{
    private:
        int studentID;
    public:
        Student()
        {
            cout<<"Student default constructor"<<endl;
        }
        Student(int copy_studentID):Person("Momen")
        {
            studentID=copy_studentID;
            cout<<"Student parametrized constructor"<<endl;
        }
        int getStudentID(void)
        {
            cout<<"student id = "<<studentID<<endl;
            return studentID;
        }
        ~Student()
        {
            cout<<"Student destructor"<<endl;
        }
};

class Teacher:public Person{
    private:
        int teacherID;
    public:
        Teacher()
        {
            cout<<"Teacher default constructor"<<endl;
        }
        Teacher(int copy_teacherID):Person("Momen")
        {
            teacherID=copy_teacherID;
            cout<<"Teacher parametrized constructor"<<endl;
        }
        int getTeacherID()
        {
            cout<<"teacher id = "<<teacherID<<endl;
            return teacherID;
        }
        ~Teacher()
        {
            cout<<"Teacher destructor"<<endl;
        }
};

class TeachingAssistant:public Student, public Teacher
{
    private:
        string course;
    public:
        TeachingAssistant()
        {
            cout<<"teaching assistant default constructor"<<endl;
        }
        TeachingAssistant(string copy_course)
        {
            course=copy_course;
            cout<<"teaching assistant parametrized constructor"<<endl;
        }
        string getCourse()
        {
            cout<<"course name = "<<course<<endl;
            return course;
        }
        ~TeachingAssistant()
        {
            cout<<"teaching assistant destructor"<<endl;
        }
};

int main(void)
{
    Person p1("Nour");
    Student s1(182963);
    Teacher t1(1234);
    TeachingAssistant ta1("math");
    p1.getName();
    s1.getName();
    s1.getStudentID();
    t1.getName();
    t1.getTeacherID();
    ta1.getCourse();
    ta1.getStudentID();
    ta1.getTeacherID();
    return 0;
}