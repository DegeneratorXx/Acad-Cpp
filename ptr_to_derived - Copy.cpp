#include <iostream>
using namespace std;
class base{
    public:
    int v;
    void display()
    {

    cout<<"display v"<<v<<endl;
    }


};
class derived:public base{
     public:
    int v_derived;
    void display()
    {
         cout<<"display v"<<v<<endl;
    cout<<"display v_derived"<<v_derived<<endl;
    }

};
int main()
{
    base *base_ptr;
    base obj_b;
    derived obj_d;
    base_ptr = &obj_d;

    base_ptr->v=34;
    base_ptr->display();
    // it will throw error
    // base_ptr->v_derived=12; 

    derived *derived_ptr;
    derived_ptr=&obj_d;
    derived_ptr->v_derived=19;
    derived_ptr->v=49;
    derived_ptr->display();

// derived class pointer can excess child as well as parent class elements
// but base class pointer can't excess child calss elements
    
    return 0;
}