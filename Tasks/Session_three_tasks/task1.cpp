#include<iostream>

using namespace std;

class Integer
{
    int *ptrInteger=new int;
    public:
    Integer()
    {
        cout<<"default constructor is called"<<endl;
    };
    Integer(int value)
    {
        *ptrInteger=value;
        cout<<"parametriezed constructor is called"<<endl;
    }
    Integer(const Integer &var)
    {
        if(this!=&var)
        {
            *ptrInteger=*(var.ptrInteger);
            cout<<"user defined copy constructor is called"<<endl;
        }
        
    }
    Integer(Integer &&var)
    {
        if(this != &var)
        {
            ptrInteger=var.ptrInteger;
            var.ptrInteger=nullptr;
            cout<<"move constructor is called"<<endl;
        }
      
    }
    void Set_value(int value)
    {
        *ptrInteger=value;
    }
    int Get_value()
    {
        return *ptrInteger;
    }
    Integer &operator= (const Integer &var)
    {
        if(this == &var)
        {
            return *this;
        }
        delete ptrInteger;
        ptrInteger=new int;
        *ptrInteger=*var.ptrInteger;
        cout<<"copy assignment operator is called"<<endl;
        return *this;
    }
    Integer &operator=(Integer &&var)
    {
        if(this == &var)
        {
            return *this;
        }
        delete ptrInteger;
        ptrInteger=var.ptrInteger;
        var.ptrInteger=nullptr;
        cout<<"move assignment is called"<<endl;
        return *this;        
    }
    ~Integer()
    {
        if (ptrInteger != nullptr) {
            delete ptrInteger;
        }
    }

};

int main(void)
{
     Integer obj1(10); // parametriezed constructor is called
    Integer obj2(obj1); // user defined copy constructor is called
    Integer obj3(std::move(obj1)); // move constructor is called
    Integer obj4(12);
    cout<<"the value of obj4 before assignment = "<<obj4.Get_value()<<endl;
    obj4=obj2;
    cout<<"the value of obj4 after assignment = "<<obj4.Get_value()<<endl;
    obj4=5;
    cout<<"the value of obj4 after move assignment = "<<obj4.Get_value()<<endl;

    obj4=Integer{12};
    cout<<"the value of obj4 after move assignment = "<<obj4.Get_value()<<endl;

    return 0;
}
