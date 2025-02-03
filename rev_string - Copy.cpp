#include <bits/stdc++.h>
        
using namespace std;
int main()
{
    string s;
    cin>>s;
    string sr;
    for(int i=s.size();i>=0;--i)
    {
        sr=sr+s[i];
    }
    cout<<sr;
    return 0;
}