#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

bool isfeasible(int mid, int arr[], int n, int k)
{
  int pos=arr[0], elements = 1; //elements are the number of elements that satisfy k
  for(int i=1;i<n;i++)
  {
    if(arr[i]-pos >= mid)
    {
      pos=arr[i];
      elements++;
      if(elements==k)
      {
        return true;
      }
    }
  }
  return false;
}
int largestminidist(int arr[], int n, int k)
{
  sort(arr, arr+n);

  int result = -1;
  int left = 1, right = arr[n-1];

  while(left<right)
  {
    int mid=(left+right)/2;
    if(isfeasible(mid, arr, n, k))
    {
      result = max(result, mid);
      left=mid+1;
    }
    else{
      right=mid;
    }
  }
  return result;
}

bool ispossible(int arr[], int n, int m, int min)
{
  int studentrequired=1, sum=0;

  for(int i=0;i<n;i++)
  {
    if(arr[i]>min)
    {
      return false;
    }
    if(sum+arr[i]>min)
    {
      studentrequired++;
      sum=arr[i];
      if(studentrequired>m)
      {
        return false;
      }
    }
    else{
      sum+=arr[i];
    }
  }
  return true;
}
int allocatemin(int a[], int n, int m)
{
  int sum=0;
  if(n<m)
  {
    return -1;
  }

  for(int i=0;i<n;i++)
  {
    sum+=a[i];
  }

  int st=0, end=sum, ans=INT_MAX;
  while(st<=end)
  {
    int mid = (st+end)/2;
    if(ispossible(a, n, m, mid))
    {
      ans= min(ans, mid);
      end=mid-1;
    }
    else
    {
      st=mid+1;
    }
  }
  return ans;
}

int findnumberofpainters(int boards[], int n, int limit)
{
  int sum=0, painter=1;  // sum is totallength of boards given to a painter
  for(int i=0;i<n;i++)
  {
    sum+=boards[i];
    if(sum>limit)
    {
      sum=boards[i];
      painter++;
    }
  }
  return painter;
}
int paintersparti(int boards[], int n, int m)
{
  int totaltime=0, k=0; // max board size
  for(int i=0;i<n;i++)
  {
    k=max(k, boards[i]);
    totaltime+=boards[i];
  }

  int low=k, high=totaltime;
  while(low<high)
  {
    int mid=(low+high)/2;
    int painters=findnumberofpainters(boards, n, mid);
    if(painters<=m)
    {
      high=mid;
    }
    else{
      low=mid+1;
    }
  }
  return low;
}

int findrotatedinarray(int arr[], int x, int left, int right)
{
  if(left>right)
  {
    return -1;
  }

  int mid=(left+right)/2;
  if(arr[mid]==x)
  {
    return mid;
  }
  if(arr[left]<=arr[mid])
  {
    if(x>=arr[left] && x<=arr[mid])
    {
      return findrotatedinarray(arr, x, left, mid-1);
    }
    return findrotatedinarray(arr, x, mid+1, right);
  }

  if(x>=arr[mid] && x<=arr[right])
  {
      return findrotatedinarray(arr, x, mid+1, right);
  }
  return findrotatedinarray(arr, x, left, mid-1);
}

int findpeakele(int arr[], int min, int max, int n)
{
  int mid=min+(max-min)/2;

  if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
  {
    return mid;
  }

  else if(mid>0 && arr[mid-1]>arr[mid])
  {
    return findpeakele(arr, min, mid-1, n);
  }
  else
  {
    return findpeakele(arr, mid+1, max, n);
  }
}

int main()
{
  // Q1. Given an array with n elements that represents n position on a straight line. Find k elements such that the minimum distance btw any 2 elements isthe maximum possible
  /* 
    Approach 1- Find all possible subsets of size K and compare the minimum distance btw all of them

    Approach 2 - Binary search approach -  
              1. Sort the array for binary search
              2. Pick mid element as result and check its feacibility
              3. if feasible, search the right half of the array with larger minimum dist.
              4. else, search the left half of the array
          
    eg- arr- {11,2,7,5,1,12}  k=3;
    1. sort - {1,2,5,7,11,12}  
    left =1 and right = 12
    2. mid = 6; - 3 elements where pair wise their diff. is 6
    3. mid = 6 - not feasible 
    4. so now right =6 and mid = 3
    5. (1,5,11). here minimum diff btw them is equal to or more than 3
    6. Now after we got a feasible solution update left = 3
    and mid = 4;
    7. again check = {1,5,11}
    8. left =4 and right = 6 and mid =5;
    9. now ans= {1,7,12};
   */
  // int n,k;
  // cin>>n>>k;
  // int arr[n];
  // for(int i=0;i<n;i++)
  // {
  //   cin>>arr[i];
  // }
  // cout<<"Largest minimum distance is  :  "<<largestminidist(arr, n, k)<<endl;  // function return the maximum possible value where the diff is minimum
  

  // Q2. Allocate Minimum Pages - 
  /* 
    Problem- n - number of pages in n different books (ascending order) m- number of students 
    All th books have to be divided among m students, consecutively. Allocate the pages such a way that maximum pages allocated to a student is minimum
     eg- pages = [12,34,67,90] students = 2;
                              1      2
     possible allocations - [12][34,67,90] - 191  - maximum pages allocated to a student, here 12 is not counted as it is with student 1
                          - [12,34][67,90] - 157
                          - [12,34,67][90] - 113 - minimum of all maxi pages
                          ans= 113

    strategy - Apply binary search for minimum and maximum possible values of 'max' pages

    check the feasiblity of this chosen - means check if our solution is right - Assign pages to each student in a sequential in a sequential manner, while the current number of allocate pages don't exceed the values set by binary search - if during allocation the number of students don't exceed the limit of 'm' then the solution is feasible - else it is not
   */ 
  // int n,m;
  // cin>>n>>m;
  // int arr[n];
  // for(int i=0;i<n;i++)
  // {
  //   cin>>arr[i];
  // }
  // cout<<"Maimum pages allocated to minimum student is  :  "<<allocatemin(arr, n, m)<<endl;

  // Q3. Painter's partition problem - same as question 2
  /* 
     n - length pf n different boards ,  m- painters available 
     A painter paints 1 unit of board in 1 unit of time and each painter will paint consecutive boards. Find the minimum time that will be required to paint the boards;

     eg- boards - [10,20,30,40], painters- 2;
     possible partition -   1       2
                          [10] [20,30,40] - 90
                          [10,20] [30,40] - 70
                          [10,20,30] [40] - 60 - ans 
    
    apply binary search for minimum and maximum values of 'min' length of boards to be painted and then check feasbility
   */
  // int arr[]= {10,20,30,40};
  // int n=4, m=2;
  // cout<<"Minimum time to paint boards : "<<paintersparti(arr, n, m)<<endl;

  // Q4. Search element in sorted and rotated array.
  /* 
     problem- We are given an ascending sorted array that has been rotated from a pivot point(unknown) and an element X. Search for x in the array with complexity less than that of linear search (O(n));

    eg - arr[] = {10, 20, 30 ,40, 50}
      rotated arr from 50 = {30, 40, 50, 10, 20}; still sorted but divied in left and right 

      strat= 1. Find the pivot point    2. Apply BS in left half   3. Apply BS in right half

      1. Pivot point - arr[i] > arr[i+1];
  */
  // int arr[]={6,7,8,9,10,1,2,5};
  // int n=8;
  // int key;
  // cin>>key;
  // int idx=findrotatedinarray(arr, key, 0, n-1);
  // if(idx==-1)
  // {
  //   cout<<"Key doesn't exist  "<<endl;
  // }
  // else{
  //   cout<<"Key exist at :  "<<idx<<endl;
  // }

  // Q5. Find the peak element .
  /*  
    Problem - For a given array, find the peak element. Peak ele is one which is greater than both, left and right neighbours itself

    Corner cases - Ascending array - last element is peak
                   Descending array - first element is peak
                   for all same elements-each element is peak

    eg- arr=[10,20,15,2,23,90,67] - 2 peak ele - 20 and 90

    strat - use BS - min=0, max=n-1;
    mid=min+max/2; and check if mid is the peak;
    1. if(arr[mid-1]>arr[mid]) - check left for peak
    2. if(arr[mid]<arr[mid+1]) - check for right peak
  */
    // int arr[] ={0, 6, 8, 5, 7, 9};
    // int n=6;
    // cout<<"Peak Element index : "<<findpeakele(arr, 0, n-1, n)<<endl;

    
  return 0;
}