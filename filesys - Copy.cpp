#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    string s,ss;
    s= "lakshit lasdkdad";
    ss="gillu sadadad";
    ofstream out;
    out.open("sample.txt");
    out<<s<<endl;
    out<<ss<<endl;
    out.close();
    ifstream in;
    in.open("sample.txt");
    string s2;
    getline(in,s2);
    cout<<s2<<endl;
    getline(in,s2);
    cout<<s2;

    in.close();

    return 0;
}