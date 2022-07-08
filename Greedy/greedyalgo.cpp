#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>


bool compare(pii p1, pii p2)
{
  double v1 = (double) p1.first/p1.second;
  double v2 = (double) p2.first/p2.second;

  return v1>v2;
}
int main()
{
    // Q1. Indian Coin change problem.
    /* 
    Problem - Given an array of denominators and a value X. You need to find the minimum number of coins required to make value X.
    Note - We have Infinite supply of each coin

    eg- arr = {1,2,5,10,20,50,100,200,500,2000}   X = 388
        388=200+100+50+20+10+5+2+1
        
    Apporach - 
    1. Start from the largest value, till we can include it, take it
    2. Else move on the smaller value.
     */

    // int n,x;
    // cin>>n>>x;

    // vi a(n);
    // floop(i,0,n)
    // {
    //     cin>>a[i];
    // }

    // sort(a.begin(), a.end(), greater<int>());
    // int ans=0;

    // floop(i,0,n)
    // {
    //     ans+=x/a[i];
    //     x-=(x/a[i]) * (a[i]);
    // }

    // cout<<ans<<endl;

    // Q2. Activity Selection Problem
    /* 
      Problem - Given n activities with their start and finish times. Find the maximum activities that can be performed, if only one activity can be done at a time

      eg- 3 - number of activites 
       10 20 - start and end time 
       12 15 
       20 30

      Draw a diagram for such questions where no two activites merge 
      
      Greedy approach - 
      1. if you are at the i'th activity
      2. Take the next activity which ends first
      3. Sort the activities with respect to time
    */
  //  int n;
  //  cin>>n;
  //  vector<vector<int>> v;
  //  floop(i,0,n)
  //  {
  //    int start,end;
  //    cin>>start>>end;
  //    v.push_back({start, end});
  //  }
  // sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b){
  //    return a[1] < b[1];
  //  });
  //  int take=1;
  //  int end = v[0][1];
  // floop(i,1,n)
  // {
  //   if(v[i][0]>=end)
  //   {
  //     take++;
  //     end=v[i][1];
  //   }
  // }
  // cout<<take<<endl;

  // Q3. Fractional Knapsack
  /* 
     Problem - Given 'n' items with {weight, value} of each item and the capacity of knapsack (Sack) 'W'. We need to put these items in knapsack such that final value of items in knapsack is maximum.

     eg- value - 21  24  12  40  30
      weight(kg)- 7   4   6    5   6
    value/weight- 8   6   5    3   2

    1. Sort in decreasing order according to Value/Weight
    2. Pick from the starting till our knapsack has capacity
  */
  // int n,w;
  // cin>>n>>w;
  
  // vii a(n);

  // floop(i,0,n)
  // {
  //   cin>>a[i].first>>a[i].second;
  // }

  // sort(a.begin(), a.end(), compare);
  // int ans =0;
  // floop(i,0,n)
  // {
  //   if(w>=a[i].second)
  //   {
  //     ans+=a[i].first;
  //     w-=a[i].second;
  //     continue;
  //   }

  //   double vw = (double) a[i].first/a[i].second;
  //   ans+=vw*w;
  //   w=0;
  //   break;
  // }
  // cout<<ans<<endl;

  // Q4. Optimal Merge Pattern
  /* 
    problem - you are given n files with their computation times in an array.

    eg- arr - {5,2,4,7} 
    compute sum of two arrays - so - {5,5+2,5+2+4,5+2+4+7}= total - 36 - may not be minimum 

    first sort the array
    Approach - 1. Push all elements to a minheap
    2. Take top 2 elements one by one and add the cost to the answer. Push the merged file to the minheap
    3. When single element remains , ouput the cost
  */
// int n;
// cin>>n;

// vi a(n);
// floop(i,0,n)
// {
//   cin>>a[i];
// }
// priority_queue<int, vector<int>, greater<int> > minhe;
// floop(i,0,n)
// {
//   minhe.push(a[i]);
// }
// int ans=0;
// while(minhe.size()>1)
// {
//   int e1=minhe.top();
//   minhe.pop();
//   int e2=minhe.top();
//   minhe.pop();

//   ans+=e1+e2;
//   minhe.push(e1+e2);
// }
// cout<<ans<<endl;

// Q5. Expedi (expedition)
/* 
  Question - A group of cow grabbed a truck and ventured on a expedition deep into the jungle. The truck leaks 1 unit of fuel every unit of distance it travels.
  To repair the truck, the cows need to drive to the nearest town whose dist is < 10^6. On this road, between the town and the current location , there are N fuel stops. 
  **The cows want to make minimum possible number of stops for fuels on the way to town **
  Capacity of the tank is sufficiently large to hold any amount of fuel.
  Intial amount of fuel is P and Intial distance from town is L
  **Determine the minimum number of stops to reach the town**

  Approach -
  1. Create a maxheap. which stores the fuels available at the stops that we have traversed
  2. Sort the stops on the basis of distance of stops from initial postion of truck
  3. Keep iterating on the stops, and whenever fuel in the tank of the truck becomes empty, take the fuel from the maxheap and add it
  4. maintain the count of stops from which we have taken fuel
*/
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<pair<int,int> > a(n);
    floop(i,0,n)
    {
      cin>>a[i].first>>a[i].second;
    }
    int p,l;
    cin>>l>>p;

    floop(i,0,n)
    {
      a[i].first = l-a[i].first;
    }
    sort(a.begin(), a.end());

    int ans=0;
    int curr=p;
    bool flag=0;
    priority_queue<int, vi> pq;

    floop(i,0,n)
    {
      if(curr>=l)
      {
        break;
      }
      while(curr<a[i].first)
      {
        if(pq.empty())
        {
          flag=1;
          break;
        }
        ans++;
        curr+=pq.top();
        pq.pop();
      }
      if(flag)
      {
        break;
      }
      pq.push(a[i].second);
    }
    if(flag)
    {
      cout<<"-1 "<<endl;
      continue;
    }
    
    while(!pq.empty() && curr<l)
    {
      curr+=pq.top();
      pq.pop();
      ans++;
    }
    if(curr<l)
    {
      cout<<"-1"<<endl;
      continue;
    }
    cout<<ans<<endl;
  }


// Q6. Max and min Array difference
/*  
  Problem - given an array A of n ele. You have to remove exactly n/2 elements from array A and add it to another array B(empty)
  Find the max and Min values of difference between these 2 arrays 
  Diff- sigma of abs(A[i]-B[i])
  eg- arr= 12,-3,10,0    output-( 5  25) 
  for max diff - A= -3,0  and B = 12 10 
  for  min diff - A= -3,12  and B = 0,10

  Constraints - 1<=n<=100
  A[i]<=10^9 - keep long long

  Approach - 
  1. to max abs[A[i]-A[j]]
     i. a[i] should be as large as possible and a[j] should be as mini as possible
  
  2. to min abs(a[i]-a[j])
  i. the diff btw. a[i] and a[j] should be similar
  */
// int n;
// cin>>n;

// vi a(n);
// floop(i,0,n)
// {
//   cin>>a[i];
// }
// sort(a.begin(), a.end());
// long long mn=0,mx=0;
// floop(i,0,n/2)
// {
//   mx+=(a[i+(n/2)]-a[i]);
//   mn+=(a[2*i+1]-a[2*i]);
// }
// cout<<mn<<"  "<<mx<<endl;
  return 0;
  /* 
    Greedy Techniques - 
    Defination - At present, jo best lage wo le lo
  */
}