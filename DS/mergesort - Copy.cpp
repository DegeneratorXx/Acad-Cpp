#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];

void merge(int l, int r, int mid)
{
    //its given that we have to sort only between l & r 
int ls= mid -l+1;
int rs= r-mid;
int R[rs + 1];
int L[ls +1];
for(int i=0; i< ls ; i++)
{
    L[i]=a[i+l];

}
for(int i=0;i<rs;i++)
{
    R[i]=a[i+mid+1];
}

L[ls]=R[rs]=INT_MAX;
int l_i=0;
int r_i=0;
for(int i=l;i<=r;i++)
{
    if(L[l_i] <= R[r_i])
    {
        a[i]= L[l_i];  
        l_i++;
    }
    else
    {
        a[i]= R[r_i];
        r_i++;
    }
}
}
void mergesort(int l, int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    mergesort(l , mid);

    mergesort(mid +1 , r);

    merge(l,r,mid);
}
int main()
{   
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}