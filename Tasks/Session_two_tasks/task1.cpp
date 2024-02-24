#include<iostream>

using namespace std;



class Date
{
    int day;
    int month;
    int year;
    public:
    Date()
    {
        cout<<"default constructor is called"<<endl;
    }
    void Set_day(int Copy_day );
    void Set_month(int Copy_month);
    void Set_year(int Copy_year);
    void Get_day(void);
    void Get_month(void);
    void Get_year(void);
    void validate_date(void);
    void Print_date(void)
    {
        cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
    }
    ~Date()
    {
        cout<<"destructor is called"<<endl;
    }
};

void Date::Set_day(int Copy_day )
{
    day=Copy_day;
}
void Date::Set_month(int Copy_month)
{
    month=Copy_month;
}
void Date::Set_year(int Copy_year)
{
    year=Copy_year;
}
void Date::Get_day(void)
{
    cout<<"day = "<<day<<endl;
}
void Date::Get_month(void)
{
    cout<<"month = "<<month<<endl;
}
void Date::Get_year(void)
{
    cout<<"year = "<<year<<endl;
}
void Date::validate_date(void)
{
    char flag=1;
    if(day<0 || day>31)
    {
        cout<<"day format is wrong "<<endl;
        flag=0;
    }
    if(month<0 || month >12)
    {
        cout<<"month format is wrong"<<endl;
        flag=0;
    }
    if(year<0)
    {
        cout<<"year format is wrong"<<endl;
        flag=0;
    }
    if(month==2 && day>29)
    {
        cout<<"feburary has days more than 29!"<<endl;
        flag=0;
    }
    if(flag)
    {
        cout<<"the date is valid"<<endl;
    }
    else
    {
        cout<<"the date is invalid"<<endl;
    }
}

int main()
{
    Date d1;
    d1.Set_day(30);
    d1.Set_month(15);
    d1.Set_year(-1232);

    d1.Get_day();
    d1.Get_month();
    d1.Get_year();

    d1.validate_date();

    d1.Print_date();
}