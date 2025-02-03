#include <iostream>
using namespace std;
class base{
    public:
    int v=1;
   virtual void display()
    {
    cout<<"1 display v"<<v<<endl;
    }
};
class derived:public base{
     public:
    int v_derived=2;
    void display()
    {
         cout<<"2 display v"<<v<<endl;
    cout<<"2 display v_derived"<<v_derived<<endl;
    }
};

int main()
{
    base *baseptr;
    base objb;
    derived objd;

    baseptr=&objd;
    baseptr->display();
    
    return 0;
}