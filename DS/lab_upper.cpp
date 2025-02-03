#include <bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cout<<"ENTER THE SIZE OF ARRAY(N*N) :";
    cin>>n;
    int a[n][n];
    cout<<"ENTER THE UPPER TRIANGULAR ARRAY :"<<endl;
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    
    }
    cout<<"UPPER TRIANGULAR ARRAY AS FOLLOWS :"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"TOTAL NUMBER OF NON ZERO ELEMENT ARE :";
    cout<<(n*(n+1))/2<<endl;

    int b[(n*(n+1))/2];
    
    int k = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= j; i++) {
            b[k] = a[i][j];
            k++;
        }
    }
    sort(b,b+(n*(n+1))/2);
    cout<<"SORTED ELEMENTS ARE :";
    for(int i=0;i<(n*(n+1))/2;i++)
    {
        cout<<b[i]<<" ";
    }

    return 0;
}