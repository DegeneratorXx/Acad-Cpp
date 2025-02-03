#include <iostream>
using namespace std;
class shop{
    int id;
    float price;
    public:
    void setdata(int a,int b)
    {
        id=a;
        price=b;
    }
    void getdata()
    {
        cout<<"Id of this item is :"<<id<<endl;
        cout<<"Price of this item is :"<<price<<endl;
    }
};
int main()
{
    int size=3;
    shop *ptr= new shop[size]; 
    // 1.general item
    // 2.veggies item 
    // 3.hardware item 
    int p,i ;
    shop *ptrtemp=ptr;
    float q;
    for ( i = 0; i < size; i++)
    {
        cout<<"Enter Id and price of item "<<i+1<<endl;
        cout<<"Id :";
        cin>>p;
        cout<<"Price :";
        cin>>q;
        ptr->setdata(p,q);
        ptr++;
    }
    for( i=0;i<size;i++)
    {
        cout<<"item number : "<<i+1<<endl;

        ptrtemp->getdata();
        ptrtemp++;
    }
    
    
    return 0;
}