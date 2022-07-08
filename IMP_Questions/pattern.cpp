#include <iostream>
using namespace std;

int main()
{
    // for (int i=1;i<=5;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     int s=10-2*i;
    //     for(int j=1;j<=s;j++)
    //     {
    //         cout<<" ";
    //     }
    //      for(int j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //     for (int i=5;i>=1;i--)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     int s=10-2*i;
    //     for(int j=1;j<=s;j++)
    //     {
    //         cout<<" ";
    //     }
    //      for(int j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    // int i,j,count=1;
    // for (i=1;i<=5;i++)
    // {
    //     for (j=1;j<=i;j++)
    //     {
    //         cout<<count<<" ";
    //         count++;
    //     }
    //     cout<<endl;
    // }
    // int i,j,n;
    // cin>>n;
    // for (i=1;i<=n;i++)
    // {
    //     for (j=1;j<=i;j++)
    //     {
    //         cout<<i;
    //     }
    //     cout<<endl;
    // }
    
    // for(i=1;i<=5;i++)
    // {
    //     for(j=1;j<=5;j++)
    //     {
    //         if(j<=5-i)
    //         {
    //             cout<<" ";
    //         }
    //         else
    //         {
    //             cout<<"*";
    //         }
            
    //     }
    //     cout<<endl;
    // }
    // int i,j;
    // for (i=5;i>0;i--)
    // {
    //     for (j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    // int i,j,r,c;
    // cin>>r>>c;
    // for (i=1;i<=r;i++)
    // {
    //     for (j=1; j<=c; j++)
    //     {
    //         if(i==1 || i==r || j==1 || j==c){
    //             cout<<"*";
    //         }
    //         else
    //         {
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    
//         for (int j=1;j<=5;j++)
//         {
//             for (int k=1;k<=j;k++)
//             {
//                 cout<<"*";
//             }
//            cout<<endl; 
//         }

    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }        
        cout<<endl;

        for(int k=i;k<=5;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
     return 0;   
}