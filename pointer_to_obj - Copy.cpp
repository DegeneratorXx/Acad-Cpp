#include <iostream>
using namespace std;
class complex{
    int real,img;
    public:
    void getdata(){
        cout<<"the real part is "<<real<<endl;
        cout<<"the img part is "<<img<<endl;
    }
    void setdata(int a,int b){
        real=a;
        img=b;
    }
};
int main()
{
    complex c1;
    // complex *ptr=&c1;
    complex *ptr=new complex;  //both ways are correct 
    // (*ptr).setdata(1,54);  is exactly same as
   ptr->setdata(1,54);
   ptr->getdata();


   //Arry of objects
   complex *ptr1= new complex[4];
   ptr1->setdata(1,3);
   ptr1->getdata();
   return 0;
    
    
    return 0;
}