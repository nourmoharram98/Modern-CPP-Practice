#include<iostream>

using namespace std;


template<typename T1,typename T2, int size>
class Stack
{
    private:
        int stack_size=size;
        T2 index=0;
        T1 StackElements[size];
    public:
        Stack()
        {
            cout<<"defualt constructor is called"<<endl;
        }
       void Push_element(T1 data)
        {
            if(index==stack_size)
            {
                cout<<"stack is full"<<endl;
            }
            else
            {
                StackElements[index]=data;
                index++;
                cout<<"data = "<<data<<"pushed at index"<<index-1<<endl;
            }
        }
       void Pop_element()
        {
            if(index==0)
            {
                cout<<"stack is empty"<<endl;
            }
            else
            {
                cout<<"data = "<<StackElements[index-1]<<"poped at index"<<index-1<<endl;
                StackElements[index-1]=0;
                index--;

            }
        }
        void IsEmpty()
        {
            if(index==0)
            {
                cout<<"stack is empty"<<endl;
            }
            else
            {
                cout<<"stack is not empty"<<endl;
            }
        }
        ~Stack()
        {
            cout<<"stack destructor is called"<<endl;
        }
};

int main(void)
{
    Stack<int,int,5>s1;
    s1.IsEmpty();
    s1.Push_element(5);
    s1.Push_element(4);
    s1.Push_element(3);
    s1.Push_element(2);
    s1.Push_element(1);
    s1.Push_element(0);
    s1.Pop_element();
    s1.Pop_element();
    s1.Pop_element();
    s1.Pop_element();
    s1.Pop_element();
    s1.Pop_element();
    return 0;
}