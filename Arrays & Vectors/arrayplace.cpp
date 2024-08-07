#include <iostream>
#include <climits>
using namespace std;

int main()
{
    
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // const int N = 1e6 + 2;
    // int idx[N];
    // for (int i = 0; i < N; i++)
    // {
    //     idx[i] = -1;
    // }
    // int minidx = INT_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     if (idx[a[i]] != -1)
    //     {
    //         minidx = min(minidx, idx[a[i]]);
    //     }
    //     else
    //     {
    //         idx[a[i]] = i;
    //     }
    // }
    // if (minidx == INT_MAX )
    // {
    //     cout << "-1" << endl;
    // }
    // else
    // {
    //     cout << minidx + 1 << endl;
    // }

    // Q4. Record breaking day.
    // int n;
    // cin>>n;
    // int a[n+1];
    // a[n]=-1;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // int mx = -1;
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     if(a[i]>mx && a[i]>a[i+1])
    //     {
    //         ans++;
    //     }
    //     mx=max(mx, a[i]);
    // }
    // cout<<ans<<endl;
    // Q3. Longest arithmatic subarray very important question
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans=2;
    int pd = a[1]-a[0];
    int j = 2;
    int curr = 2;
    while (j < n)
    {
        if (a[j]-a[j-1]==pd)
        {
            curr++;
        }
        else
        {
            pd = a[j]-a[j-1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    cout << ans << endl;
    // Q2. Sum of all subarrays in an array
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     int sum=0;
    //     for(int j=i;j<n;j++)
    //     {
    //         sum+=a[j];
    //         cout<<sum<<" ";
    //     }
    //     cout<<endl;
    // }
    // Q1. Max till i: output the maximum i value
    // int mx = -199999;
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    //  for(int i=0;i<n;i++)
    // {
    //     mx=max(mx, a[i]);
    //     cout<<mx<<" ";
    // }
    return 0;
}