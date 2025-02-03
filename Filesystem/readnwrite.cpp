#include <iostream>
#include <fstream>
//  the useful classes for working with files in c++ are-
// 1. fstreambase
// 2.ifstream--->derived from fstreambase
// 3.ofstream--->derived from fstreambase

// 2ways to open a file
// 1.using the constructor
// 2.using member function open() of the class

using namespace std;

int main()
{   string st="lakshit";
    string st2;

    // opening files using constructor and writing it
    ofstream out("sample1.txt");   //wrtie operation
    out<<st;

    // opening files using constructor and reading it
    ifstream in("readsample2.txt"); //read operation
    // in>>st2;
    getline(in,st2); //takes 1st line in input
    getline(in,st2); //takes 2nd line in input

    cout<<st2;
    return 0;
}