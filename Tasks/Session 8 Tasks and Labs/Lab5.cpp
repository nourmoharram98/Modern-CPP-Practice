#include<iostream>

using namespace std;


template<typename T,int size>
class FixedSizeArray{
    private:
        int array_size=size;
        T array[size];
        int index=0;
    public:
        FixedSizeArray()
        {
            cout<<"def. constructor"<<endl;
        }
        void addelement(T data)
        {
            if(index==array_size)
            {
                cout<<"array is full"<<endl;
            }
            else
            {
                array[index]=data;
                cout<<"data = "<<data<<"inserted at index= "<<index<<endl;
                index++;
            }
        }
        void removeelement()
        {
            if(index==0)
            {
                cout<<"array is empty"<<endl;
            }
            else
            {
                cout<<"data = "<<array[index]<<"removed at index= "<<index<<endl;
                array[index]=0;
                index--;
            }
        }
        ~FixedSizeArray()
        {
            cout<<"destructor is called"<<endl;
        }
};


int main(void)
{
    FixedSizeArray<int,5>a1;
    a1.addelement(1);
    a1.addelement(2);
    a1.addelement(3);
    a1.addelement(4);
    a1.addelement(5);
    a1.addelement(6);

    return 0;
}