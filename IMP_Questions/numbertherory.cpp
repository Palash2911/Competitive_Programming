#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

const int N = 1e5+2;

int totient[N];

struct triplet
{
    int x,y,gcd;

};
triplet extendedeuclid(int a,int b)
{
    //gcd(d,0) = d;
    if(b==0)
    {
        triplet ans;
        ans.x=1;
        ans.gcd=a;
        ans.y=0;
        return ans;
    }

    triplet sans = extendedeuclid(b,a%b);
    triplet ans;
    ans.gcd=sans.gcd;
    ans.x=sans.y;
    ans.y=sans.x - (a/b)*sans.y;
    return ans;
}

int multimodinv(int a, int m)
{
    triplet temp = extendedeuclid(a,m);
    return temp.x;
    /* 
        17*(-1)%3 = -2
        -2%3 = (-2+3)%3 = -1
        as a%m= (a+m)%m
    */
}

const int MOD = 1e9+7;
int powers(int a, int n)
{
    // iterative version
    // a %= MOD;
    // int ans=1;
    // while(n>0)
    // {
    //     if(n&1)
    //     {
    //         ans=(ans*a)%MOD;
    //     }
    //     a=(a*a)%MOD;
    //     n=n>>1;
    // }
    // return ans;

    //recursive version
    if(n==0)
    {
        return 1;
    }
    int p=(powers(a,n/2)%MOD);
    if(n&1)
    {
        return (((p*p)%MOD)*a)%MOD;
    }
    else{
        return (p*p)%MOD;
    }
}
int main()
{
    //Q1. Extended Euclid Algorithm : 
    // int a,b;
    // cin>>a>>b;

    // triplet ans = extendedeuclid(a,b);
    // cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;


    // Q2. Multiplicative Modulo Inverse : use extended euclid algo
    //  int a,m;
    //  cin>>a>>m;

    //  cout<<multimodinv(a,m)<<endl;


    // Q3. Euler Totient Function.
    // floop(i,0,N)
    // {
    //     totient[i]=i;
    // }

    // for(int i=2;i<N;i++)
    // {
    //     if(totient[i]==i)
    //     {
    //         totient[i] -= 1;
    //         for(int j=2*i;j<N;j+=i)
    //         {
    //             totient[j] *= i-1;
    //             totient[j] /= i;
    //         }
    //     }
    // }

    // floop(i,2,11)
    // {
    //     cout<<totient[i]<<" ";
    // }


    // Q4. Binary Exponentiation.
    //  int a,n;
    //  cin>>a>>n;

    // // iterative version
    // // cout<<powers(a,n)<<endl;

    // //  recursive version :
    // a%=MOD;
    // cout<<powers(a,n)<<endl;


    // Q5. Fermat's little Theroem
    /* 
        - FLT states that if p is a prime number, then for any integer a, the number a^P-a is an integer multiple of p.
        a^p=a(mod p)

        - if a is not divisible by p, FLT is equivalent to that statement that a^(p-1) -1 is an integer multiple of p. a^(p-1) = 1(mod p)
    */

   //Q6. Wilson's Theorem 
   /* 
        - A positive integer n>1 is a prime if and only if 
        (n-1)!=-1(mod n) or  (n-1)!=n-1(mod n)
   */


    // Q. Boring Factorials using above two algo
    /* 
        - Neha gives you a prime number P and an integer N close to P, and asks you to find N! modulo P.
    */


   return 0;
  /* 
    NOTES

    1. Diophantine Equations
     - these are the polynomial equations for which integral solutions exists 
     - eg - 3x + 7y =1 or x^2-y^2=z^3
     - in competitive programming - ax+by=c;
     Note - a,b,c belong to Integers
     - solutions to these equations exist only if gcd(a,b) divides c

     - Exteneded Euclid Algorithm -
        GCD(a,b) has the property - ax+by=gcd(a,b)
        thus to find x,y
        ax+by=gcd(a,b)=gcd(b,a%b)=bx1+(a%b)y1;
        a%b=a-(a/b)*b

        thus in og property
        ax+by=bx1+(a%b)y1=bx1+(a-(a/b)*b)y1
        thus now by comparing coeffcients

        x=y1;
        y=x1-(a/b)*y1;

    2. Multiplicative Modulo Inverse 
        - (A x B)%m=1
        - where we have to find B
        eg- a= 17, m=3  thus (17xB)%3=1  answer = 2
        - NOTE -  For multiplicative modulo inverse to exist A and m are coprime i.e. gcd(A,m)=1.
        - Math - 
        A*B=1   (mod m) -that is it should be a multiple of m
        (A*B-1)=0 (mod m)
        (A*B-1)=mq - that is it should be a multiple of m

        (A*B + mq)=1    B- it is x in euclid extended algo

    3. Euler Totient Function 
        -Represented as phi(n) - 1<=m<n and gcd(m,n)=1
        - n is number of numbers from 1 to n-1 which are coprime with n

        - FORMULA - 
        phi(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)...*(1-1/pk)
        where p1,p2,p3..pk are distinct prime factors of n

        -if A and B are coprime or gcd(A,B)= 1 then phi(A*B)=phi(A)*phi(B)


    4. Binary Exponentiation 
        - Many times, our ans is out of range of int. To avoid this we use modulo operation to overcome this problem.Some properties of the modulo operations are-
        -  (a+b)%m = (a%m)+(b%m)
        -  (a*b)%m = (a%m)*(b%m)
        -  (a-b)%m = (a%m)-(b%m)
        -  (a/b)%m = (a%m)*((b^-1)%m)

        - Recursive Version : to calculate a^n
            Cases : 
            1. If n is odd - a^n = a^(n/2) * (a^n/2) * a
            2. If n is even - a^n = a^(n/2) * (a^n/2)

        Iterative Version - To find a^45
        we can write -
        45= 1*2^5 + 0*2^4 + ..
        45 in binary = (101101)
        7^45 = can be calculated easily
        thus 2^3=2^2+2^2
   */
}