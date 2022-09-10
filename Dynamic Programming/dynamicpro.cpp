#include <bits/stdc++.h>
using namespace std;

#define floop(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

const int N = 1e5 + 2, MOD = 1e9 + 7, N1 = 1e3 + 2;
int dp[N];
int dp1[N1][N1];
int val[N], wt[N];

int fib(int n)
{
    if (n==1)
    {
      return 0;
    }
    if (n == 2)
    {
      return 1;
    }
    if (dp[n] != -1)
    {
      return dp[n];
    }
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int minsq(int n)
{
  if (n == 1 || n == 2 || n == 3 || n == 0)
  {
    return n;
  }
  if (dp[n] != MOD)
  {
    return dp[n];
  }
  int ans = MOD;
  for (int i = 1; i * i <= n; i++)
  {
    dp[n] = min(dp[n], 1 + minsq(n - i * i));
  }
  return dp[n];
}

int coinchan(vi &a, int n, int x)
{
  if (x == 0)
  {
    return 1;
  }
  if (x < 0)
  {
    return 0;
  }
  if (n <= 0)
  {
    return 0;
  }

  if (dp1[n][x] != -1)
  {
    return dp1[n][x];
  }
  dp1[n][x] = coinchan(a, n, x - a[n - 1]) + coinchan(a, n - 1, x);
  return dp1[n][x];
}

int knapsack(int n, int w)
{
  if (w <= 0)
  {
    return 0;
  }
  if (n <= 0)
  {
    return 0;
  }
  if (dp1[n][w] != -1)
  {
    return dp1[n][w];
  }
  if (wt[n - 1] > w)
  {
    // return knapsack(n-1,w);
    dp1[n][w] = knapsack(n - 1, w);
  }
  // return max(knapsack(n-1,w), knapsack(n-1, w-wt[n-1]) + val[n-1]);
  else
  {
    dp1[n][w] = max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
  }

  return dp1[n][w];
}
int main()
{

  vector<vector<double>> ch;
  floop(i,0,100)
  {
    floop(j,0,100)
    {
        ch[i][j]=(i+1)/2;
    }
  }
  // Q1. Fibonacci Number
  /*
       Sequence - 0,1,1,2,3,5,8,13,21
       recurrence - fib[n]=fib[n-1]+fib[n-2]
       Optimal Substructure
    */
  // CODE
  //   int n;
  //   cin>>n;

  // floop(i,0,N)
  // {
  //   dp[i]=-1;
  // }
  //  cout<<fib(n)<<endl;

  // TABULATION METHOD FOR FIBO-
  //  int n;
  //  cin>>n;
  //  vi dp(n+1);
  //  dp[0]=0;
  //  dp[1]=0;
  //  dp[2]=1;

  // floop (i,3,n+1)
  // {
  //   dp[i]=dp[i-1]+dp[i-2];
  // }
  // cout<<dp[n]<<endl;

  // Q2. Minimum numbers of squares whose sum equals to given number 'n'
  /*
    Eg- X=26 = 4^2 + 3^2 + 1^2 (3 numbers)
      or 26 = 5^2 + 1^2(2 numbers )
      thus minimum numbers = 2
      Overlapping Subproblem

      Algo -
      1. Write Recursion solution
      2. Memoize it in dp table
  */
  // CODE
  //  int n;
  //  cin >> n;

  // floop(i,0,N)
  // {
  //   dp[i]=MOD;
  // }
  // cout << minsq(n) << endl;

  // Tabulation method
  //  int n;
  //  cin>>n;

  // vi dp(n+1, MOD);

  // dp[0]=0;
  // dp[1]=1;
  // dp[2]=2;
  // dp[3]=3;

  // for(int i=1;i*i<=n;i++)
  // {
  //   for(int j=0;i*i+j<=n;j++)
  //   {
  //     dp[i*i+j]=min(dp[i*i+j], 1+dp[j]);
  //   }
  // }
  // cout<<dp[n]<<endl;

  // Q3.Coin Change Problem
  /*
    Very imp topic to clear basic

    Problem- Given a set of coins and a value 'V'. Find the numbers of ways we can make change of 'V'

    eg- S={1,2,3}  V=3
      possible ways to make change are: {3}, {2,1}, {1,1,1}
      Note {1,2} is same as {2,1}

    To make ways with every coin, we have 2 options
    1.Take it
    2. Do not take it

    Approach 1 - using memoization
      1. write the recurrence solution
      2. Memorize it - basically means, create a DP table and store the results.

    Approach 2 - Tabulation
      1. Take each coin one by one and fill DP table till that coin, for all the values from 0 to V

    Approach 3 - Tabulation with Space efficiency
      1. just a minor change in approach 2
      2. We knew for every cell, we have 2 options;
        1. Take that coin
        2. Do not take that coin (we do not take an extra row, update on the same cell)

  */
  // CODE
  //  int n;
  //  cin>>n;

  // floop(i,0,N1)
  // {
  //   floop(j,0,N1)
  //   {
  //     dp1[i][j]=-1;
  //   }
  // }

  // vi a(n);
  // floop(i,0,n)
  // {
  //   cin>>a[i];
  // }

  // int x;
  // cin>>x;

  // cout<<coinchan(a,n,x)<<endl;

  // TABULATION METHOD
  //  int n;
  //  cin>>n;

  // vi a(n);
  // floop(i,0,n)
  // {
  //   cin>>a[i];
  // }

  // int x;
  // cin>>x;

  // vvi dp(n+1, vi(x+1, 0));
  // dp[0][0]=1;
  // floop(i,1,n+1)
  // {
  //   floop(j,0,x+1)
  //   {
  //     if(j-a[i-1]>=0)
  //     {
  //       dp[i][j]+=dp[i][j-a[i-1]];
  //     }
  //     dp[i][j]+=dp[i-1][j];
  //   }
  // }
  // cout<<dp[n][x]<<endl;

  // Q4. Knapsack
  /*
    Problem -given an array of items with their{weight, value, and a knapsack} with weight W. Find maximum value of items that can be stolen and put into knapsack

  Note - we either have to pick full item(i) or no item(0)

    we iterate from left to right in items array and we 2 choices
    1. take it = remaining capacity of knapsack
    2. Not take it =  Capacity remains same
  */
  // CODE
  //  int n;
  //  cin>>n;

  // floop(i,0,n)
  // {
  //   cin>>wt[i];
  // }
  // floop(i,0,n)
  // {
  //   cin>>val[i];
  // }
  // int w;
  // cin>>w;
  // cout<<knapsack(n,w)<<endl;

  // MEMOIZATION -
  //  floop(i,0,N1)
  //  {
  //    floop(j,0,N1)
  //    {
  //      dp1[i][j]=-1;;
  //    }
  //  }
  //  int n;
  //  cin>>n;

  // floop(i,0,n)
  // {
  //   cin>>wt[i];
  // }
  // floop(i,0,n)
  // {
  //   cin>>val[i];
  // }

  // int w;
  // cin>>w;

  // cout<<knapsack(n,w)<<endl;

  // Q5. Maximum Subarray Sum - {Kadane's Algorithm}
  /*
    Problem - Given an array, find the maximum sum of subarray in the array

    eg - arr={-5,-1,5,-3,-1,2,3,-6}
    approach - 1.Maintain 2 variables Curr and max till_now
      intialize, curr=0 and max till_now =0
    2.Iterate from i=0 to i=n-1 and do curr+=a[i]
    3. If curr<0, then do curr=0 {basically neglecting the elements contributing to negative sum}
    4. When loop ends, output max till_now
  */
  // CODE
  //  int n;
  //  cin>>n;

  // vi a(n);
  // floop(i,0,n)
  // {
  //   cin>>a[i];
  // }
  // int curr=0,maxtilnow=0;
  // floop(i,0,n)
  // {
  //   curr+=a[i];
  //   maxtilnow=max(maxtilnow,curr);
  //   if(curr<0)
  //   {
  //     curr=0;
  //   }
  // }
  // cout<<maxtilnow<<endl;

  return 0;

  /*      ****NOTES****

    Properties of DYNAMIC PROGRAMMING --

    1. Optimal Substructure  - If we can write a recurrence relation, then a problem is said to have optimal substructure

    2. Overlapping Subproblem - if our subproblems repeat, then a problem is said to have Overlapping subproblem

        1. ways to handle Overlapping Subproblem -

            a. Memoization(Top-Down) - A lookup table is maintaned and checked befor computation of any state. Recursion is involved

            b. Tabulation(Bottom-Up) - Solution is built from base. It is an iterrative process

    Key Points in DP -
    1. Minimization and maximization problems are generally solved with dp where we want exhaustive solution

    2. "Find the number of ways" is also a very popular type of DP problems

    3. Wherever we can form recurrence relation or given in question can be solved using DP.(sometimes with matrix exponentiation)
  */
}