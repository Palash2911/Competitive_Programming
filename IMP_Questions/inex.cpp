#include <iostream>
using namespace std;
// int inex(int n, int a, int b)
// {
//     int c1=n/a;
//     int c2=n/b;
//     int c3=n/(a*b);

//     return c1+c2-c3;
// }

int gcd(int a, int b)
{
    while(b!=0)
    {
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main()
{
    // used when finding number of ways of doing something

    // Q1. Numbers divisible by 5 or 7 btw 1-1000
    // int n,a,b;
    // cin>>n>>a>>b;
    // cout<<inex(n,a,b)<<endl; 

    // Q2. Euclid algorithm to find GCD(greatest common divisor).  
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;

    return 0;
}