#include <iostream>
using namespace std;
class complex{
    int a,b;
    public:
    complex() //default constructor
    {a=0;
    b=0;}
    complex(int x, int y) //parametrized constructor
    {a=x;
    b=y;}
    complex(int x) //parametrized constructor
    {a=x;
    b=0;}
    void printn()
    {cout<<"your number is "<<a<<" + "<<b<<"i"<<endl;}

};
int main()
{
    complex c1(4,6);//respective constructor in line 6
    c1.printn();
    complex c2(5);//only for real number respective const in line 9
    c2.printn();
    complex c3;
    c3.printn();

    //more then 1 constructor is present the it is called cosntructor overloading..!
    
    return 0;
}