#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void maxsubarrsum(int arr[], int n, int k, int x)
{
    int sum= 0,ans=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }

    if(sum<x)
    {
        ans=sum;
    }
    
    for(int i=k;i<n;i++)
    {
        sum=sum-arr[i-k];
        sum+=arr[i];
        if(sum<x)
        {
            ans=max(ans, sum);
        }  
    }
    cout<<ans<<" is the max subarray sum (<x) "<<endl;
}

int minlengthofsubarr(int arr[], int n, int x)
{
    int sum=0, minlength=n+1;
    int start=0, end =0;
    while(end < n)
    {
        while(sum <= x && end<n)
        {
            sum+=arr[end++];
        }
        while(sum>x && start<n)
        {
            if(end-start<minlength)
            {
                minlength = end- start;
            }
            sum-=arr[start++];
        }
    }
    return minlength;
}

void printnumsubarray(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;

    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    bool found = false;
    if(sum%3==0)
    {
        ans=make_pair(0, k-1);
        found=true;
    }

    for(int j=k;j<arr.size();j++)
    {
        if(found)
        {
            break;
        }
        sum=sum+(arr[j]-arr[j-k]);

        if(sum%3==0)
        {
            ans=make_pair(j-k+1, j);
            found=true;
        }
    }

    if(!found)
    {
        ans= make_pair(-1, 0);
    }
    if(ans.first==-1)
    {
        cout<<"No such subarray exists "<<endl;
    }
    else{
        for(int i=ans.first;i<=ans.second;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

bool ispalindrome(int n)
{
    int temp = n, number=0;
    // reverse n -> 123... number -> 321
    while(temp>0)
    {
        number = number*10 + temp%10;
        temp = temp/10;
    }
    if(number==n)
    {
        return true;
    }
    return false;
}
int findpalindromicsubarray(vector<int> arr, int k)
{
    // returns the k size ka starting point from where palindrome begins

    int num =0;
    for(int i=0;i<k;i++)
    {
        num=num*10 + arr[i];
        cout<<num<<" ";
    }
    cout<<endl;

    if(ispalindrome(num))
    {
        return 0;
    }
    
    
    for(int j=k;j<arr.size();j++)
    {
        num = (num % (int)pow(10, k-1))*10 + arr[j];
        cout<<num<<" ";
        if(ispalindrome(num))
        {
            return j-k+1;
        }
    }
    cout<<endl;
    return -1;
}

int main()
{
    // Q1. Max sum of subarray of size = k and sum < x
    /* 
        Problem - Given array and integers k and x, find maximum subarray of size k and having sum less than x

        APPROACH 1 - Compute sum of all possible subarrays of size k - Time complexity -   O(n*k) 

        APPROACH 2 - Sliding Window approach - Time Complexitiy - O(n)
                    1. Calculate sum of first k elements 
                    2. Initialize ans with this sum
                    3. Iterate over the rest of the arr
                    4. keep adding one element in sum and removing one from start
                    5. compare new sum with ans in each itertaion

        eg- arr[] = {7,5,4,6,8,9}   k=3, x=20, ans=0
        sum of first k(3) value = 16
        - now compare 16 with x as 16 < 20 put it as ans
        - now remove 7 and add 6 - now sum = 15 which is less than ans 
        - now remove 5 and add 8 - now sum = 18 which is more than ans but also less than x and so ans = 18 and so on
     */

    // int arr[] = {7,5,4,6,8,9};
    // int k=3;
    // int x=20;
    // int n=6;
    // maxsubarrsum(arr, n, k, x);

    // Q2. Smallest subarray with sum > x
    /* 
        // Problem - Given array and int x, find minimum subarray size for which sum > x

        Approach 1 - Compute sum of all subarrays and check all of them but time complexity - O(n^2)

        Approach 2(Sliding window) - 1. Use variable ans, sum(curr sum) and start(final ans)
        2. Iterate over array and start adding element to sum 
        3. if sum>x, remove elements from the start - time complexity - O(n)

        eg- arr- {1,4,45,6,10,19} x=51,  ans= INT_MAX, 
        start put it on 1
        sum = 1 which is less than x add 4 now sum is 5 which is still less than x
        now add 45 to sum = 50 which is still less than x still less than x
        now add 6 to sum = 56 now this is more than x now compare this value to ans and ans=length of subarray
        now iterate the start pointer and remove 1 from sum so 56-1 = 55 now 55 is still > x
        55-4 = 51 is not > x thus now start is at 45
        do this for further array
    */
//    int arr[]={1,4,45,6,10,19};
//    int n=6;
//    int x=51;
//     if(minlengthofsubarr(arr, n, x)==n+1)
//     {
//         cout<<"No such subarray exists "<<endl;
//     }
//     else
//     {
//         cout<<"Smalles length subarray is : "<<minlengthofsubarr(arr, n, x)<<endl;
//     }

    // Q3. Number formed from subarray of size K, divisible by 3
    /* 
      Problem - Given array and int k, check if any subarray of size k exists in the array such that elements in the subarray from a number divisible by 3

      Approach - 1. Sum of intial K elements from the array 
            2. Use sliding window techniq and one by one, start subtracting elements from the end and adding from the end
            3. At each step, check if sum divisible by 3 or not. If it is, print the elements - time complexity = O(n)
    */
    // vector<int> arr = {84,23,45,12,56,82};
    // int k=3;

    // printnumsubarray(arr, k); 

    // Q4. Subarray of size K with palindrome concatenation
    /* 
        palindrome eg - madam, racecar, 797

        Problem - given array and int k, check if any subarray of size k exists in the array such that concatenation of elements from a palindrome 

        Approach (sliding win)- 
        1. Store concatenation of intial K elements 
        2. Iterate over the array and start deleting elements from the start and adding elements from the end
        3. At each step, check if concatenation is a palindrome - Time complexity - O(n^2)
     */

    // vector<int> arr= {2,3,4,2,2,4};  - WRONG 
    // int k=4;
    // int ans=findpalindromicsubarray(arr, k);
    // if(ans==-1)
    // {
    //     cout<<"Palindrome Not Found "<<endl<<endl;
    // }
    // else{
    //     for(int i= ans;i<ans+k;i++)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}