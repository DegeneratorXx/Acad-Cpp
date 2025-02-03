#include <iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {

    string s;
    int n,q;
    cin>>n>>q;
    cin>>s;
    while(q--)
    {    int l,r;
       cin>>l>>r;
    int a[26];
    for(int i=0;i<=26;i++)
    {
        a[i]=0;
    }

    if(l-r==1)
    cout<<"Yes";
    else
    {
        for(int i=l;i<=r;i++)
        {
            a[s[i]-'a']++;
        }
        int c;
        for(int i=0;i<26;i++)
        {
        if(a[i]%2!=0)
        {c++;}
        }

        if(c>1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }

    }
    }


    
    return 0;
}