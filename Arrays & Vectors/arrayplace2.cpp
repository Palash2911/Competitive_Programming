#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Q9. Maximum sum of a subarray
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int maxsum=INT_MIN;
//   for(int i=0;i<n;i++)
//   {
//       for(int j=i;j<n;j++)
//       {
//           int sum=0;
//           for(int k=i;k<=j;k++)
//           {
//               sum+=a[k];
//           }
//           maxsum=max(maxsum, sum);
//       }
//   }
//   cout<<maxsum<<endl;
// Q8. (Important) Print all subarrays in an array
//      int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//   for(int i=0;i<n;i++)
//   {
//       for(int j=i;j<n;j++)
//       {
//           for(int k=i;k<=j;k++)
//           {
//               cout<<a[k]<<" ";
//           }
//            cout<<endl;
//       }
//   }
// Q7. smallest positive missing number
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//    const int p = 1e6 + 2;
//     bool check[p];
//     for (int i = 0; i < p; i++)
//     {
//         check[i] = false;
//     }
//     for(int j=0;j<n;j++)
//     {
//         if(a[j] >= 0)
//         {
//             check[a[j]] = true;
//         }
//     }
//     int ans = -1;
//     for(int i=1;i<p;i++)
//     {
//         if(check[i]==false)
//         {
//             ans=i;
//             break;
//         }
//     }
//     cout<<ans<<endl;
    // Q6. Subarray with given sum
    // int n,s;
    // cout<<"N :";
    // cin>>n;
    // cout<<"S :";
    // cin>>s;
    // int a[n];
    // for(int i=0; i<n; i++)
    // {
    //     cin>>a[i];
    // }
    // int j=0, i=0, st=-1, en=-1, sum=0;
    // while(j<n && sum+a[j] <= s)
    // {
    //     sum+=a[j];
    //     j++;
    // }
    // if(sum==s)
    // {
    //     cout<< i+1<<" "<<j<<endl;
    //     return 0;
    // }
    // while(j<n)
    // {
    //     sum+=a[j];
    //     while(sum>s)
    //     {
    //         sum-=a[i];
    //         i++;
    //     }
    //     if(sum==s)
    //     {
    //        st=i+1;
    //        en=j+1;
    //        break; 
    //     }
    //     j++;
    // }
    // cout<<st<<" "<<en<<endl;
    return 0;
}