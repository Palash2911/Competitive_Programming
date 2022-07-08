#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=3;i++)
    {
       for(int j=1;j<=n;j++)
       {
           if(((i+j)%4==0) || (i==2 && j%4==0))
           {
               cout<<"*";
           }
           else
           {
               cout<<" ";
           }
       }
        cout<<endl;
    }
    // diamond shape
    // for(int i=1;i<=4;i++)
    // {
    //     for(int j=1;j<=4-i;j++)
    //     {
    //         cout<<" ";
    //     }
    //     for(int k=3;k<=2*i+1;k++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //  for(int i=4;i>=1;i--)
    // {
    //     for(int j=1;j<=4-i;j++)
    //     {
    //         cout<<" ";
    //     }
    //     for(int k=3;k<=2*i+1;k++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=1;i<=5;i++)
    // {
    //     int j;
    //     for(j=1;j<=5-i;j++)
    //     {
    //         cout<<" ";
    //     }
    //     int k=i;
    //     for(;j<=5;j++)
    //     {
    //         cout<<k--;
    //     }
    //     k=2;
    //     for(;j<=5+i-1;j++)
    //     {
    //         cout<<k++;
    //     }
    //     cout<<endl; 
    // important pattern
    // }
    // for(int i=1;i<=5;i++)
    // {
    //     for(int j=1;j<=5-i;j++)
    //     {
    //         cout<<" ";
    //     }
    //     for(int k=1;k<=5;k++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl; rhommbus
    // }
    // for(int i=1;i<=5;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         if((i+j)%2==0)
    //         {
    //             cout<<"1";
    //         }
    //         else
    //         {
    //             cout<<"0";
    //         }
            
    //     }
    //     cout<<endl; for 1,0 pyramid
    // }
}