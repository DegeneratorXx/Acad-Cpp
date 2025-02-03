#include <bits/stdc++.h>
using namespace std;
class Array{
    public:
    int n;
    int a[100];
    

    void input()
    {   system("cls");
        cout<<"set the size of array : ";
        cin>>n;
        cout<<"Enter "<< n <<" elements for the input of array: ";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<endl;
        
    }
    void display()
    {
        cout<<"The array is : ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void search()
    {   int s;
        cout<<"Enter the number you want to search: ";
        cin>>s;
        cout<<endl;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==s)
            {cout<<"The number "<<s<<" is present at "<<i<<" index"<<endl;
            break;}
            else 
            {c++;}
        }
        if(c==n)
        cout<<"ELEMENT DOES NOT EXIST IN THE ARRAY ";
        cout<<endl;
    }
    void max()
    {
        int max=*max_element(a,a+n);
        
    
            cout<<" The biggest number in the array is "<<max<<endl;
            cout<<endl;
    }
    void min()
    {
    
         int min=*min_element(a,a+n);
       
    
            cout<<" The smallest number in the array is "<<min<<endl;
            cout<<endl;

    }
    void asc()
    {
        sort(a,a+n);
         cout<<"The array in ascending order is : ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
    void desc()
    {
        sort(a,a+n ,greater<int>());
        cout<<"The array in descending order is : ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void diff()
    {
      sort(a,a+n);
      int diff=a[n-1]-a[n-2];
      cout<<diff-1 <<" numbers is/are missing between nth and n-1th array in ascending array";  
    }
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
void mergesortt()
{
    mergesort(0,n-1);
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void quick()
{
    quickSort(a,0,n-1);
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}



};

int main()
{   
   
    Array ar;
    
    ar.input();
    ar.display();
    int t=1;
    while(t>0)
    {

    
    cout<<"SELECT THE OPERATION TO BE PERFORMED:"<<endl;
    cout<<"1. Search"<<endl;
    cout<<"2. Maximum element"<<endl;
    cout<<"3. Minimum element"<<endl;
    cout<<"4. Ascending order"<<endl;
    cout<<"5. Descending order"<<endl;
    cout<<"6. No of missing elements"<<endl;
    cout<<"7. Sort array using mergesort"<<endl;
    cout<<"8. Sort array usinng quicksort"<<endl;
    int t;cin>>t;
    if(t==1)
    ar.search();
    else if(t==2)
    ar.max();
    else if(t==3)
    ar.min();
    else if(t==4)
    ar.asc();
    else if(t==5)
    ar.desc();
    else if(t==6)
    ar.diff();
    else if(t==7)
    ar.mergesortt();
    else if(t==8)
    ar.quick();

    else 
    {
    cout<<"INCORRECT CHOICE !!! START THE PROGRAM AGAIN";
    break;
    }
    cout<<endl;
    }

    
    
    return 0;
}