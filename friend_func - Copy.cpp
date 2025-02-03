#include <iostream>
using namespace std;
class a2;
class a1
{
private:
int a;
public:
 void num1(int x)
{
   a=x;;
    
}
friend void max(a1,a2);
};

class a2{
    private :
    int b;
    public:
 void num2(int y)
{
   b=y;
    
}
friend void max(a1,a2);
};

void max(a1 u,a2 v)
{
   if(u.a>v.b)
   cout<<"max number is:"<<u.a;
else
cout<<"max num is:"<<v.b;

}
int main()
{
    a1 c;
    a2 d;
    c.num1(100);
    d.num2(50);
    max(c,d);
    return 0;
}