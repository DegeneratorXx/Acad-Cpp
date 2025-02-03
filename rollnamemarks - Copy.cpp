#include <iostream>
#include <string>
using namespace std;
class student{
    int roll;
    string name;
    int marks;
    public:
        void setmarks(int m)
        { marks=m; }
        void setroll(int r)
        { roll=r; }
        void setname(string n)
        { name=n; }
        int getmarks()
        {return marks;}
        int getroll()
        {return roll;}
        string getname()
        {return name;}
};
int main()
{
    student s;
    s.setmarks(40)
    s.setname("Harsh")
    s.setroll(25)
    cout<<"name of student is"<<s.getname()<<endl;
    cout<<"roll number of student is"<<s.getroll()<<endl;
    cout<<"marks of"<<s.getname<<" is"<<s.marks()<<endl;
    return 0;

}
