#include <iostream>
using namespace std;
// void primesieve(int n)
// {
//    int prime[100]={0};
//    for(int i=2; i<=n; i++)
//    {
//        if(prime[i]==0)
//        {
//            for(int j=i*i; j<=n; j+=i)
//            {
//                prime[j]=1;
//            }
//        }
//    }
//    for(int i=2; i<=n; i++)
//    {
//        if(prime[i]==0)
//        {
//            cout<<i<<" ";
//        }
//    }
// }
 void primefactor(int n)
 {
     int spf[500]={0};
     for(int i=2; i<=n; i++)
     {
         spf[i]=i;
     }
     for(int i=2; i<=n; i++)
     {
         if(spf[i]==i)
         {
             for(int j=i*i; j<=n; j+=i)
             {
                 if(spf[j]==j)
                 {
                     spf[j]=i;
                 }
             }
         }
     }
     while(n!=1)
     {
         cout<<spf[n]<<" ";
         n=n/spf[n];
     }
 }
int main()
{
    // sieve helps to print prime numbers in a different way.
    // in sieve u mark all the multiples of the numbers and the remaining numbers at the end are prime.

    // int n;
    // cin>>n;
    // primesieve(n);

    // Q1. Prime factoristion using sieve
    int n;
    cin>>n;
    primefactor(n);
    return 0;
}