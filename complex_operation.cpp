#include <iostream>
using namespace std;
class complex()
 int real, imaginary;
   public:
      comp() {
         real = 0; imaginary = 0;
      }
      comp(int r, int i) {
         real = r; imaginary = i;
      }
    Complex cadd(complex c1,complex c2){
    Complex t;
    t.img = c1.imaginary+c2.imaginary;
    t.real = c2.real + c2.real
    return t;
  }
      
int main()
{
    complex c1(2,2);
    complex c2(4,4);
    complex c3;
    c3=c3.cadd;
    cout<<"addition of complex numbers are:"<<c3.real<<"+ i"<<c3.imaginary;

    return 0;
}