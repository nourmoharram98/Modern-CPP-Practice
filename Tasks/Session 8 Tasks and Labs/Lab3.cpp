#include<iostream>

using namespace std;


template<typename T1>
class Basic{
    private:
        static T1 index;
    public:
        Basic()
        {
            cout<<"def. constructor"<<endl;
            index++;
        }
        void PrintIndex()
        {
            cout<<"number of instances created = "<<index<<endl;
        }
};
// Define the static member variable outside the class
template<typename T1>
T1 Basic<T1>::index = 0;
int main(void)
{
    Basic<int>b1;
    b1.PrintIndex();
    Basic<int>b2;
    Basic<int>b3;
    Basic<int>b4;
    Basic<double>c1;
    Basic<double>c2;
    Basic<int>b5;
    b1.PrintIndex();
    c1.PrintIndex();



    return 0;
}