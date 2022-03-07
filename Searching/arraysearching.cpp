#include<iostream>
using namespace std;

// int lis(int p[],int n, int k)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(p[i]==k)
//         {
//             return i+1;
//         }
//     }
//     return -1;
// }
int bins(int d[], int n, int k)
{
    int up=n,lo=0;
    while(lo<=up)
    {
        int mid=(up+lo)/2;
        if(d[mid]==k)
        {
            return mid+1;
        }
        else if(d[mid]>k)
        {
            up=mid-1;
        }
        else
        {
           lo=mid+1; 
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int a[n];
    cout<<"Enter array in ascending order : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cout<<"Enter element to be search : ";
    cin>>key;
    cout<<"Element present at : "<<bins(a,n,key)<<endl;
    // int n;
    // cout<<"Enter array size : ";
    // cin>>n;
    // int a[n];
    // cout<<"Enter array : ";
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // int key;
    // cout<<"Enter element to be search : ";
    // cin>>key;
    // cout<<"Element present at : "<<lis(a,n,key)<<endl;
    // int n;
    
    // cout<<"Enter array size : ";
    // cin>>n;
    // int a[n];
    // cout<<"Enter array : ";
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // int max=a[0],min=a[0];
    //  for(int i=0;i<n;i++)
    // {
    //     if(a[i]>max)
    //     {
    //         max=a[i];
    //     }
    //     if(a[i]<min)
    //     {
    //         min=a[i];
    //     }
    // }
    // cout<<"Maximum : "<<max<<endl;
    // cout<<"Minimum : "<<min<<endl;
    
}