#include <iostream>
using namespace std;
int addn(int n)
{
    if(n==0)
    {
        return 0;
    }
    int prev = addn(n-1);
    return n + prev;
}
int power(int n, int p)
{
    if(p==0)
    {
        return 1;
    }
    int prevp = power(n, p-1);
    return n*prevp;
}
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    // int prevf = fact(n-1);
    // return n*prevf;   OR
    return n*fact(n-1);
}

int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}
bool sorted(int arr[], int n)
{
    if(n==1)
    {
        return true;
    }
    bool resta=sorted(arr+1, n-1);
    return (arr[0]<arr[1] && resta);
}
void dec(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
void inc(int n)
{
     if(n==0)
    {
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
int firstocc(int arr[], int n , int  i, int key)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return firstocc(arr, n, i+1, key);
}
int lastocc(int arr[], int n, int i, int key)
{
    if(i==n)
    {
        return -1;
    }
    int resta= lastocc(arr, n, i+1, key);
    if(resta!=-1)
    {
        return resta;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return -1;
}
void reverse(string p)
{
    if(p.length()==0)
    {
        return;
    }
    string ros = p.substr(1);
    reverse(ros);
    cout<<p[0]<<endl;
}
void replace(string s)
{
    if(s.length()==0)
    {
        return;
    }
    if(s[0]=='p' && s[1]=='i')
    {
        cout<<3.14;
         replace(s.substr(2));
    }
    else
    {
        cout<<s[0];
        replace(s.substr(1));
    }
       
}

void toh(int n, char src, char dest, char help)
{
    if(n==0)
    {
        return; //base case
    }
    toh(n-1, src, help, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    toh(n-1, help, dest, src);
}

string rd(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch=s[0];
    string ans = rd(s.substr(1));
    if(ch==ans[0])
    {
        return ans;
    }
    return (ch+ans);

}
string movex(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch=s[0];
    string ans = movex(s.substr(1));

    if(ch=='x')
    {
        return (ans+ch);
    }
    return (ch+ans);
}
void subs(string s, string ans)
{
      if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros=s.substr(1);

    subs(ros, ans);
    subs(ros, ans+ch);
}
void subascii(string s, string ans)
{
      if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code=ch;
    string ros= s.substr(1);

    subascii(ros, ans);
    subascii(ros, ans+ch);
    subascii(ros, ans+ to_string(code));
}
string keypadArr[]={"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans)
{
       if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code = keypadArr[ch-'0'];
    string ros =s.substr(1);
    for (int i=0; i<code.length(); i++)
    {
        keypad(ros, ans+code[i]);
    }
}

int main()
{
    // recursion means when a function calls itself.
    // Q1. sum of all numbers
    // int n;
    // cin>>n;
    // cout<<addn(n)<<endl;

    // Q2. find n raise to power p.
    // int n,p;
    // cin>>n>>p;
    // cout<<power( n, p);

    // Q3. Factorial of a number.
    // int n;
    // cin>>n;
    // cout<<fact(n);

    // Q4. Print the nth Fibonacci number.
    // int n;
    // cin>>n;
    // cout<<fibo(n);

    // Q5. Check if an array is sorted or not
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0; i<n; i++)
    // {
    //     cin>>arr[i];
    // }
    // if(sorted(arr, n)==1)
    // {
    //     cout<<"Array sorted"<<endl;
    // }
    // else
    // {
    //    cout<<"Array not sorted"<<endl;
    // }
    
    // Q6. Print numbers in incresing or decreasing order 
    // int n;
    // cin>>n;
    // dec(n);
    // inc(n);

    // Q7. Find first and last occurence of a number 
    // int arr[]= {4, 2, 1, 2, 5, 2, 7, 11, 2, 5};
    // cout<<firstocc(arr, 10,0,5)<<endl;
    // cout<<lastocc(arr, 10, 0, 5)<<endl;

    // Q8. Reverse a string
    // string name;
    // cin>>name;
    // reverse(name);

    // Q9. replace pi with 3.14
    // string pie;
    // cin>>pie;
    // replace(pie);

    // Q10. Tower of Hanoi   (Not understood)
    toh(2, 'A', 'C', 'B');

    // Q11. Remove duplicates from the string.
    // cout<<rd("aaabbbbbccccddddeeeee")<<endl;

    // Q12. Move all X to the end.
    // cout<<movex("pxaxlxaxsxhx")<<endl;

    // Q13. Generate all substrings of a string
    // subs("ABC", "");

    // Q14. Generate all substrings with ASCII number
    // subascii("AB", "");

    // Q15. Keypad problem
    // keypad("23", "");
    return 0;
}