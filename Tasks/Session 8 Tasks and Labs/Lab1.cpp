#include<iostream>

using namespace std;

template<typename T1, int max>
T1 Multiplies(T1 num)
{
    T1 sum=1;
    int i=1;
    while(i<=max)
    {
        sum += num*i;
        i++;
    }
    return sum;
}



int main(void)
{
    cout<<Multiplies<int,5>(5)<<endl;
    return 0;
}