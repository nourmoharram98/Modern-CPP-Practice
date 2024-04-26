#include<iostream>

using namespace std;



class Shape{

    protected:
        string color;
    public:
        Shape()
        {
            cout<<"shape defualt constructor is called"<<endl;
        }
        Shape(string copy_color)
        {
            color=copy_color;
            cout<<"shape parametrized constructor is called"<<endl;
        }
        virtual double getArea()=0;
        virtual double getPerimeter()=0;
        ~Shape()
        {
            cout<<"shape destructor is called"<<endl;
        }
};

class Rectangle:public Shape
{
    private:
        double width;
        double height;
    public:
        Rectangle()
        {
            cout<<"rectangle default instructor is called"<<endl;
        }
        Rectangle(double copy_width,double copy_height)
        {
            width=copy_width;
            height=copy_height;
            cout<<"rectangle parametrized constructor is called"<<endl;
        }
        double getArea()
        {
            double area=width*height;
            cout<<"get area of rectangle is called and area = "<<area<<endl;
            return area;
        }
        double getPerimeter()
        {
            double perimeter=2*(width+height);
            cout<<"rectangle perimter = "<<perimeter<<endl;
            return perimeter;
        }
        ~Rectangle()
        {
            cout<<"Rectangle destructor is  called"<<endl;
        }
};

class Circle:public Shape
{
    private:
        double radius;
    public:
        Circle()
        {
            cout<<"circle default constructor is called"<<endl;
        }
        Circle(double copy_radius)
        {
            radius=copy_radius;
            cout<<"circle parametrized constructor is called"<<endl;
        }
        double getArea()
        {
            double area=3.14*radius*radius;
            cout<<"get area of circle is called and area == "<<area<<endl;
            return area;
        }
        double getPerimeter()
        {
            double perimeter=2*3.14*radius;
            cout<<"perimeter of circle = "<<perimeter<<endl;
            return perimeter;
        }
        ~Circle()
        {
            cout<<"circle destructor is called"<<endl;
        }
};

class Triangle:public Shape
{   private:
        double base;
        double height;
        double side;
    public:
        Triangle()
        {
            cout<<"triangle default constructor is called"<<endl;
        }
        Triangle(double copy_base, double copy_height,double copy_side)
        {
            base=copy_base;
            height=copy_height;
            side=copy_side;
            cout<<"triangle paraemtrized constructor is called"<<endl;
        }
        double getArea()
        {
            double area=0.5*base*height;
            cout<<"get area of triangle is called and area = "<<area<<endl;
            return area;
        }
        double getPerimeter()
        {
            double perimeter=base+height+side;
            cout<<"perimeter of triangle = "<<perimeter<<endl;
            return perimeter;
        }
        ~Triangle()
        {
            cout<<"triangle destructor is called"<<endl;
        }
};

int main(void)
{
    Shape *arrayOfPtrs[3];
    Triangle T1(5,10,6);
    Rectangle R1(5,10);
    Circle C1(5);
    arrayOfPtrs[0]=&T1;
    arrayOfPtrs[1]=&R1;
    arrayOfPtrs[2]=&C1;

    for(int i=0;i<3;i++)
    {
        cout<<"***********************************"<<endl;
        arrayOfPtrs[i]->getArea();
        arrayOfPtrs[i]->getPerimeter();
    }
    return 0;
}