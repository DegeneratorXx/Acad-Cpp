#include <iostream>
using namespace std;
class rectangle
{   private :
        int length;
        int breadth;
    public :
        void setlength(int l)
        {
            length=l;
        }
        void setbreadth(int b)
        {
            breadth=b;
        }
        int getlength()
        {
            return length;
        }
        int getbreadth()
        {
            return breadth;
        }
};
int main()
{
    rectangle r;
    r.setbreadth(10);
    r.setlength(10);
    cout<<"length of rectangle is"<<r.getlength()<<endl;
    cout<<"breadth of rectangle is"<<r.getbreadth()<<endl;
    return 0;
}