#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

int dp[205][205][205];

int dp1[2005][2005][7];
int n,m,k;
vi a;
vi b;

int lcs(string &s1,string &s2,string &s3, int i,int j, int k)
{
    if(i==0 or j==0 or k==0)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    if(s1[i-1]==s2[j-1] and s2[j-1]==s3[k-1])
    {
        // return 1 + lcs(s1,s2,s3,i-1,j-1,k-1);
        return dp[i][j][k] = (1 + lcs(s1,s2,s3,i-1,j-1,k-1));
    }
    int l=lcs(s1,s2,s3,i-1,j,k);
    int r=lcs(s1,s2,s3,i,j-1,k);
    int p=lcs(s1,s2,s3,i,j,k-1);
    
    return dp[i][j][k] = max({l,r,p});
}

int solvelcs(int i,int j, int k)
{
    if(i==n or j==m)
    {
        return 0;
    }
    if(dp1[i][j][k]!=-1)
    {
        return dp1[i][j][k];
    }
    int c1(0),c2(0),c3(0);
    if(a[i]==b[j])
    {
        c1=1+solvelcs(i+1,j+1,k);
    }
    if(k>0)
    {
        c2=1+solvelcs(i+1,j+1,k-1);
    }
    c3=max(solvelcs(i+1,j,k), solvelcs(i,j+1,k));
    return dp1[i][j][k]=max({c1,c2,c3});
}
int main()
{
    // Q1. LCS in 3 strings.
    /* 
        Problem - Print the length of LCS(Longest common subsequence) of 3 strings 

        eg - s1 = GHQWNV , s2 = SJNSDGH,  s3 = CPGMAH
        answer = 2  i.e. is GH
    */
   // CODE
    //   string s1;
    //   string s2;
    //   string s3;
    //   cin>>s1>>s2>>s3;
    //   cout<<lcs(s1,s2,s3,s1.size(),s2.size(),s3.size())<<endl;

      //Memoization
    //   memset(dp, -1, sizeof dp);
    //   string s1;
    //   string s2;
    //   string s3;
    //   cin>>s1>>s2>>s3;
    //   cout<<lcs(s1,s2,s3,s1.size(),s2.size(),s3.size())<<endl;


    //Q2. K-ordered LCS
    /* 
        Problem - Print the LCS of 2 sequences given that you are allowed to change atmost k elements in the first sequence to any value you wish to

          eg -  n = 5 and k=1
            l1 = 1 2 3 4 5,  l2 = 5 3 1 4 2
           ouput 3 
    */
   //CODE 
    // cin>>n>>m>>k;

    // memset(dp1,-1, sizeof dp1);
    // a=vector<int>(n);
    // b=vector<int>(m);
    // floop(i,0,n)
    // {
    //     cin>>a[i];
    // }
    // floop(i,0,m)
    // {
    //     cin>>b[i];
    // }

    // cout<<solvelcs(0,0,k)<<endl;


    //Q3. UGLY numbers
    /* 
       Ugly nos are nos whose prime factors are 2,3 or 5
       the first 10 ugly nos are 1,2,3,4,5,6,8,9,10,12

       By convention, 1 is included

       Problem - Given a number n, print the n'th ugly number

        eg - n=15
        output = 24

    */
   //CODE
    // int n;
    // cin>>n;
    // int c2(0),c3(0),c5(0);
    // vi dps(n+1);
    // dps[0]=1;
    // for(int i=1;i<=n;i++)
    // {
    //     dps[i]=min({2*dps[c2], 3*dps[c3], 5*dps[c5]});
    //     if(2 * dps[c2] == dps[i])
    //     {
    //         c2++;
    //     }
    //     if(3 * dps[c3] == dps[i])
    //     {
    //         c3++;
    //     }
    //     if(5 * dps[c5] == dps[i])
    //     {
    //         c5++;
    //     }
    // }
    // cout<<dps[n-1]<<endl;


    // Q4.Maximum Length bitonic subsequences
    /* 
        Problem - given an array of n numbers. Find the maximum length bitonic subseq. A subsequence is bitonic if it is first strictly increasing and then strictly decreasing or entirely increasing or decreasing

        eg - n=8 , arr= {1,11,2,10,4,5,2,1}
        answer - 6;
        Maximum length = 1,2,4,5,2,1
    */
    //CODE
    //   int n;
    //   cin>>n;
    //   vi a(n);
    //   floop(i,0,n)
    //   {
    //       cin>>a[i];
    //   }
    //   vi forward(n,1), backward(n,1);
    //   floop(i,0,n)
    //   {
    //       floop(j,0,i)
    //       {
    //           if(a[i] > a[j])
    //           {
    //             forward[i] = max(forward[i], 1+forward[j]);
    //           }
    //       }
    //   }

    //   for(int i=n-1;i>=0;i--)
    //   {
    //       for(int j=n-1;j>i;j--)
    //       {
    //           if(a[i]>a[j])
    //           {
    //         backward[i] = max(backward[i], 1+backward[j]);
    //           }
    //       }
    //   }
    //   int ans=0;
    //   floop(i,0,n)
    //   {
    //       ans=max(ans,forward[i]+backward[i]-1);
    //   }
    //   cout<<ans<<endl;


    // Q5. Friends pairing problem 
    /* 
        Problem - given n friends , each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired

        eg -  n=3 
        answer = 4
        explanantion -
        1,2,3 all single 
        1, {2,3} : 2 and 3 paired but 1 is single 
        {1,2}, 3 : 1 and 2 paired
        {1,3}, 2 : 1 and 3 paired 
        Note - 1,2 is same as 2,1
    */
    //CODE
    //   int n;
    //   cin>>n;
    //   vi dp2(n+1,0);

    //   dp2[0]=1;
    //   dp2[1]=1;

    //   floop(i,2,n+1)
    //   {
    //       dp2[i]=(dp2[i-1] + (i-1)*dp2[i-2]);
    //   }
    //   cout<<dp2[n]<<endl;



  return 0;
}