#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

const int N = 1e5+2, MOD=1e9+7,N1=1e3+2,N2=102;
const int inf=1e9;

int dp[N];
int dp1[N1][N1];
int a[N2];
int dp2[N2][N2];
int dp3[100][100];

vector<int> a1;

int lis(vi &a, int n)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=1;//single elements is also a longest increasing subsequence

    floop(i,0,n)
    {
        if(a[n]>a[i])
        {
            dp[n]=max(dp[n], 1+lis(a,i));
        }
    }
    return dp[n];
}

int lcs(string &s1, string &s2, int n, int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(dp1[n][m]!=-1)
    {
        return dp1[n][m];
    }
    if(s1[n-1] == s2[m-1])
    {
        // return 1+lcs(s1,s2,n-1,m-1);
        dp1[n][m]=1+lcs(s1,s2,n-1,m-1);
    }
    else{
        // return max(lcs(s1,s2,n,m-1), lcs(s1,s2,n-1,m));
        dp1[n][m]=max(lcs(s1,s2,n,m-1), lcs(s1,s2,n-1,m));
    }
    return dp1[n][m];
}

int mcm(int i,int j)
{
    if(i==j)
    {
        return 0;
    }

    if(dp2[i][j]!=-1)
    {
        return dp2[i][j];
    }

    dp2[i][j]=MOD;
    floop(k,i,j)
    {
        dp2[i][j]=min(dp2[i][j], mcm(i,k) +mcm(k+1,j) + a[i-1]*a[k]*a[j]);
    }
    return dp2[i][j];
}

int solve(int i, int j)
{
    if(i==j)
    {
        return a[i];
    }
    if(i>j)
    {
        return 0;
    }
    if(dp3[i][j]!=-1)
    {
        return dp3[i][j];
    }
    int l = a[i] + min(solve(i+2,j), solve(i+1,j-1));
    int r = a[j] + min(solve(i,j-2), solve(i+1,j-1));

    return dp3[i][j]=max(l,r);
}
int main()
{
  //Q1. Longest Increasing Subsequence
  /* 
    Problem - given an array. Find the length of longest increasing subsequence

    eg - arr- 1,4,2,5,3 
    ans =3(length) as seqeunce can be - 1,4,5 or 1,2,3 

    we define lis[i]=lenght of longest increasing subsequence 
  */
    //CODE
    //floop(i,0,N)
    // {
    //     dp[i]=-1;
    // }
   //int n;
   //cin>>n;

   //vi a(n);
   //floop(i,0,n)
   // {
   //  cin>>a[i];
   // }
   //cout<<lis(a,n-1)<<endl;

   //BOTTOM -UP METHOD -
    // int n;
    // cin>>n;

    // vi a(n);
    // floop(i,0,n)
    // {
    //     cin>>a[i];
    // }
    // vi dp(n,1);
    // int ans=0;

    // floop(i,1,n)
    // {
    //     floop(j,0,i)
    //     {
    //         if(a[i]>a[j])
    //         {
    //             dp[i]=max(dp[i],1+dp[j]);
    //         }
    //     }
    //     ans=max(ans,dp[i]);
    // }
    // cout<<ans<<endl;


    // Q2. Longest Common Subsequence
    /* 
        Probem - Given 2 strings S1 and S2. output length of longest common subseq

        eg - s1= 'RISHABH'   S2= 'SHUBHI'
        Largest common subseq. - "SHBH"
        length of LCS - 4

        Approach -
    1.Let f(i,j) denotes the length of LCS of s1[0...i-1]
    and s2[0..j-1]
    */
   //CODE
    //   floop(i,0,N1)  //memoization method -
    // {
    //     floop(j,0,N1)
    //     {
    //         dp1[i][j]=-1;
    //     }
    // }
    // string s1,s2;
    // cin>>s1>>s2;

    // int n=s1.size(), m=s2.size();

    // cout<<lcs(s1,s2,n,m)<<endl;

    //memoization Method- 
    // string s1,s2;
    // cin>>s1>>s2;

    // int n=s1.size(), m=s2.size();

    // vvi dp2(n+1, vi(m+1, -1));

    // floop(i,0,n+1)
    // {
    //     floop(j,0,m+1)
    //     {
    //         if(i==0 || j==0)
    //         {
    //             dp2[i][j]=0;
    //             continue;
    //         }
    //         if(s1[i-1]==s2[j-1])
    //         {
    //             dp2[i][j]=1+dp2[i-1][j-1];
    //         }
    //         else
    //         {
    //             dp2[i][j]=max(dp2[i-1][j], dp2[i][j-1]);
    //         }
    //     }
    // }
    // cout<<dp2[n][m]<<endl;


    //Q3. Matrix Chain Multiplication 
    /* 
        Problem - Given 'n' Matrices, we have to multiply them in such a way that total no. of operations is minimum

        eg - A=[1x2]   B[2x3]   C[3x4]
            Since multiplication of matrices is associative, hence  A(BC) = (AB)C
        A(BC) = operations for BC are = 2x3x4 thus BC will become of size [2x4]
        and then if we multiply A with BC we get = 1x2x4
        thus total operation are 2x3x4 + 1x2x4 = 32

        Now for (AB)C
        AB= 1x2x3
        (AB)C= 1x3x4
        Answer will be 1x2x3 + 1x3x4 = 18 thus out of 18 and 32 18 is our ans
    */
   //CODE
   //Memoization - Method  
    //  int n;
    //  cin>>n;

    //   memset(dp2, -1, sizeof dp2);
    //   floop(i,0,n)
    //   {
    //      cin>>a[i];
    //   }
    //   cout<<mcm(1,n-1)<<endl;

    //Tabulation Method 
    // int n;
    // cin>>n;
    // floop(i,0,n)
    // {
    //     cin>>a[i];
    // }
    // floop(i,1,n)
    // {
    //     dp2[i][i]=0;
    // }
    // floop(l,2,n)
    // {
    //     floop(i,1,n-1+1)
    //     {
    //         int j=i+l-1;
    //         dp2[i][j]=MOD;
    //         floop(k,i,j)
    //         {
    //             dp2[i][j]=min(dp2[i][j], dp2[i][k] + dp2[k+1][j] + a[i-1]*a[k]*a[j]);
    //         }
    //     }
    // }

    // cout<<dp2[1][n-1]<<endl;


    // Q4. Minimum jumps to reach end
    /* 
        Problem - Given an array of integers where each element representsthe max number of steps that can be made forward from that element. Find the minimum number o fjumps to reach the end of the array(starting from the first element). If an element is 0, they cannot move through that element

        eg - arr=[1,3,5,8,9,2,6,7,6,8,9]
        ouput ans =3
        as jumps = 1->3->8->9
    */
   //CODE 
    // int n;
    // cin>>n;

    // vi arr(n);
    // for(auto &i : arr)
    // {
    //     cin>>i;
    // }
    // vi jumps(n,inf);
    // if(arr[0]==0)
    // {
    //     cout<<inf<<" ";
    //     return 0;
    // }
    // jumps[0]=0;
    // floop(i,1,n)
    // {
    //     floop(j,0,i)
    //     {
    //         if(i<=(j+arr[j]))
    //         {
    //             jumps[i]=min(jumps[i], jumps[j] + 1);
    //         }
    //     }
    // }

    // cout<<jumps[n-1]<<endl;


    // Q5. Optimal Game Strategy
    /* 
        Problem - Rahul and Neha are playing coin Game. given n coins with values x1,x2,x3...xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. the value of coin is received by that player. Determine the maximum value that rahul cna win if he moves first. Both the players play optimally.

        eg - n= 4 and coins={1,2,3,4}
        max rahul cna win = 6
        as rahul takes 4,
        Neha takes 3,
        rahul takes 2,
        neha takes 1,
        total rahul =6

        Idea = 
        1.Minimax concept - kuch toh loss hoga but apko wo loss minimize karna hai 
        2. What choice will you make?
        3. WHat choice will oppenent make?
    */
    // CODE
    // memset(dp3, -1 ,sizeof dp3);
    // int n;
    // cin>>n;
    // a1 = vector<int>(n);
    // floop(i,0,n)
    // {
    //     cin>>a[i];
    // }
    // cout<<solve(0,n-1)<<endl;


    //Q6. Number of Subsequences
    /* 
        given string s consisting of lower case latin letters 'a' to 'z' and some '?'
        find no of subsequeces 'abc' in all strings '?' should be replaces by either of 'a' 'b' or 'c'

        eg - a c ? b ? c

        possible strings after replacing ? with 'a' 'b' or 'c'
                             no of subsequence with 'abc'
        are - a c a b a c  - 2
              a c a b b c  - 4
              a c a b c c  - 4
              a c b b a c  - 2
              a c b b b c  - 3
              a c b b c c  - 4
              a c c b a c  - 1
              a c c b b c  - 2
              a c c b c c  - 2
            Total =         24
        
        Approach - Declare 4 variables
        1. e - denoting count of all possible strings upto current element 
        2. a - denoting coutn of subsequences 'a' in all the strings upto current elements
        3. ab - denoting coutn of subsequences ('a b') in all the strings upto current elements
        4. abc - denoting coutn of subsequences ('a b c') in all the strings upto current elements
    */
   //CODE
    // int n;
    // cin>>n;

    // string s;
    // cin>>s;

    // int e=1,a=0,ab=0,abc=0;

    // floop(i,0,n)
    // {
    //     if(s[i]=='a')
    //     {
    //         a+=e;
    //     }
    //     else if(s[i]=='b')
    //     {
    //         ab+=a;
    //     }
    //     else if(s[i]=='c')
    //     {
    //         abc+=ab;
    //     }
    //     else if(s[i]=='?')
    //     {
    //         abc = (3*abc) + ab;
    //         ab = (3*ab) + a;
    //         a = 3*a + e;
    //     }
    // }
    // cout<<"No of subsequences =   "<<abc<<endl;


    //  Q7. Count Binary Strings.
    /* 
        Problem - Given a positive integer N, count all possible distinct binary strings of lenght N such that there are no consecutive 1's

        eg - N=3 
        output - 5
        the 5 strings are 000,001,010,100,101         
    */
    //CODE
    // int n;
    // cin>>n;
    // vi fib(n+2, 0);
    // fib[0]=1;
    // fib[1]=1;

    // floop(i,2,(n+2))
    // {
    //     fib[i]=fib[i-1]+fib[i-2];
    // }
    // cout<<fib[n+1]<<endl;

    //Q8. O-N knapsack
    /* 
        Problem - Given an array of items with their weight and value. Find the maximum value of items that can be stolen using a knapsack of capacity W.

        Note - You can choose infinite items of each type.

        eg - n=5, W=11
        wt={3,2,4,5,1}
        val={4,3,5,6,1}

        answer=16;
     we can take second item 5 times, weight = 2*5, val = 3*5
        fifth item one time , weight = 1, val =1
        total value =16
    */
    //CODE
    //  int n,w;
    //  cin>>n>>w;

    //  vi val(n);
    //  vi wt(n);
    //  floop(i,0,n)
    //  {
    //      cin>>val[i];
    //  }
    //  floop(i,0,n)
    //  {
    //      cin>>wt[i];
    //  }
    //  vi dp(w+1, 0);
    //  floop(j,0,w+1)
    //  {
    //      floop(i,0,n)
    //      {
    //          if(j-wt[i]>=0)
    //          {
    //             dp[j]=max(dp[j], val[i] + dp[j-wt[i]]);
    //          }
    //      }
    //  }
    //  cout<<dp[w]<<endl;
  return 0;
}