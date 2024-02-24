#include<iostream>
#include<strings.h>
using namespace std;


class Book
{   
    string title;
    string author;
    int year;
    public:
     Book() {
        title = "";
        author = "";
        year = 0;
        cout << "Default constructor for Book is called" << endl;
    }
    Book(string book_title, string author_name, int yearofpub)
    {
        cout<<"parametrized constructor is called"<<endl;
        title=book_title;
        author=author_name;
        year=yearofpub;
    }
    string Get_author()
    {
        return author;
    }
    string Get_title()
    {
        return title;
    }
    int Get_year()
    {
        return year;
    }
    friend void Display_Info(const Book &Copybook);
    ~Book()
    {
        cout<<"destructor is called"<<endl;
    }
   

};

class library
{
    const int size=3;
    Book number_of_books[3];
    public:
    library()
    {
        cout<<"the constructor of library class is called"<<endl;
    }
    static int counter;
    void Add_book(Book Copy_book);
    void Search_book_byauthor(string author_name);
    void Search_book_bytitle(string book_title);
    void Search_book_byyear(int year_of_pub);
    void Display_Catalog(void);
    ~library()
    {
        cout<<"the destructor of library class is called"<<endl;
    }

};

int library::counter=0;

void library::Add_book(Book Copy_book)
{
    if(counter>=size)
    {
        cout<<"the library is full"<<endl;
    }
    else
    {
        number_of_books[counter]=Copy_book;
        counter++;
    }
}
void library::Display_Catalog(void)
{
    if(counter==0)
    {
        cout<<"the library catalog is empty"<<endl;
    }
    else
    {
        cout<<"the library catalog data is : "<<endl;
        for(int i=0;i<counter;i++)
        {
            Display_Info(number_of_books[i]);
        }
    }
   
}
void Display_Info(const Book &Copybook)
{
    cout<<"the book found and its information is :"<<'\n'<<
    "author is "<<Copybook.author<<'\n'<<"title is "<<Copybook.title
    <<'\n'<<"year of publication is "<<Copybook.year<<endl;
}
void library::Search_book_byauthor(string author_name)
{
    char flag=0;
    for(int index=0;index<counter;index++)
    {
        if(!(author_name.compare(number_of_books[index].Get_author())))
        {
            Display_Info(number_of_books[index]);
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<"the book not found"<<endl;
    }
}
void library::Search_book_bytitle(string book_title)
{
    char flag=0;
    for(int index=0;index<counter;index++)
    {
        if(!(book_title.compare(number_of_books[index].Get_title())))
        {
            Display_Info(number_of_books[index]);
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<"the book not found"<<endl;
    }
}
void library::Search_book_byyear(int year_of_pub)
{
    char flag=0;
    for(int index=0;index<counter;index++)
    {
        if((year_of_pub==number_of_books[index].Get_year()))
        {
            Display_Info(number_of_books[index]);
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<"the book not found"<<endl;
    }
}

int main()
{
    library library1;
    Book b1("hello","nour",1998);
    Book b2("my sins","nourmoharram",2022);
    Book b3("no way back","myself",2023);
    Book b4("not allowed","no chance",2024);
    library1.Add_book(b1);
    library1.Add_book(b2);
    library1.Add_book(b3);
    library1.Add_book(b4);

    library1.Search_book_byauthor("nour");
    library1.Search_book_bytitle("my sins");
    library1.Search_book_byyear(2023);
    library1.Search_book_byauthor("medhat");
    library1.Search_book_bytitle("my goods");
    library1.Search_book_byyear(2025);
    return 0;
}