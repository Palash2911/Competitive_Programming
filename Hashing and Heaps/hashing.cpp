#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int> 
#define pii pair<int,int>
#define vii vector<pii>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;

    public:
    Node(int val)
    {
        key= val;
        left=NULL;
        right=NULL;
    }
};


void getverticalorder(Node* root, int hdis, map<int, vi> &m)
{
  if(root==NULL)
  {
    return;
  }
  m[hdis].push_back(root->key);
  getverticalorder(root->left, hdis-1, m);
  getverticalorder(root->right, hdis+1, m);

}
int main()
{
    // map<int, int>m;
    // m[8]=2;  // this is the key value
    // cout<<m[8]<<endl;

    // Q1. Maintain frequency of each element 
    /*  
    eg - arr={2,2,2,1,1,4,3,4}
    key elements -      2,3,4,1
    value(frequency) - {3,1,2,2} 
    */
   int n;
   cin>>n;

   vi a(n);
   floop(i,0,n)
   {
     cin>>a[i];
   }
   map<int, int> freq;
   floop(i,0,n)
   {
     freq[a[i]]++;
   }

  map<int, int> :: iterator it;
  for(it=freq.begin();it!=freq.end();it++)
  {
    cout<<it->first<<" "<<it->second<<endl;
    //it first is key and it second is value(frequency)
  }

  // Q2. Print Vertical Order of a Binary Tree.
  /* 
    Bt left child - 2*i+1
    Bt right child - 2*i+2

    given - arr representation of a BT 
    eg -           10
                  / \
                 7   4
                / \  / \
               3  11 14 6
    vertical order - 3, 7, 10, 11, 14, 4, 6
  HORIZONTAL DIST - -2, -1,   0      , 1, 2

    Approach (Using Hashing)- 
    1.Starting from root node
    2. Recursively call left and right with(HD-1) AND (HD+1) as arguments
    3. Base Case: When current node = NULL (return )

    Create Map -
    Key - HD - 0,-1, -2, -1,2 
    Value- arr in Order of HD  - 10 11 14, 7, 3, 4, 6
   */

  // Node* root=new Node(10);
  // root->left =new Node(7);
  // root->right=new Node(4);
  // root->left->left=new Node(3);
  // root->left->right=new Node(11);
  // root->right->left=new Node(14);
  // root->right->right=new Node(6);

  // map<int, vi> m;
  // int hdis=0;

  // getverticalorder(root, hdis, m);

  // map<int, vi> :: iterator it;
  // for(it=m.begin();it!=m.end();it++)
  // {
  //   floop(i,0,it->second.size())
  //   {
  //     cout<<(it->second)[i]<<" ";
  //   }
  //   cout<<endl;
  // }

  // Q3. Count Number of Subarrays with sum zero
  /* 
    eg- arr={1,-1,1,-1}
    Hashing method- 
    1. Map prefix sum to a map
    2. For every key, choose 2 values from all the occurrence particular prefsum(MC2)
    3. Special Case : for prefsu 0, we have to also include them
    */

//    int n;
//    cin>>n;

//    vi a(n);
//    floop(i,0,n)
//    {
//      cin>>a[i];
//    }
//    map<int, int> cnt;
//    int prefsum=0;
//    floop(i,0,n)
//    {
//      prefsum+=a[i];
//      cout<<cnt[prefsum]++<<" ";
//    }
// cout<<endl;
//    int ans=0;
//    map<int, int> :: iterator it;

//    for(it=cnt.begin();it!=cnt.end();it++)
//    {
//      int c=it->second;
    
//      ans+=(c*(c-1))/2;
//       cout<<c<<" "<<ans<<" "<<it->first<<endl;
//      if(it->first == 0)
//      {
//        ans+=it->second;
//      }
//    }
//    cout<<ans<<endl;

  // Q4. Sliding Window technique in hashing
  /* 
    Problem - Given an array with n elements, calculate the minimum sum of k, consecutive elements 

    eg- arr = {-2,10,1,3,2,-1,4,5} , k=3

    Various sum = 9, 14, 6, 4, 5, 8 = answer is 4 = these are sums of 3 elements taken consecutively
    
    Hashing approach - 
    1. Compute sum of the first k elements (i=0 to k)
    2. While increasing i, subtract a[i-1] and add a[i+k-1] in the previous sum, which will become current sum
    3. Do the above process till i=5 and maintain the minimum answer
    4. Time complexity- O(n)
   */
  // int n,k;
  // cin>>n>>k;

  // vi a(n);

  // floop(i,0,n)
  // {
  //   cin>>a[i];
  // }

  // int s=0, ans=INT_MAX;
  // floop(i,0,k)
  // {
  //   s+=a[i];
  // }

  // ans=min(ans,s);
  // // cout<<s<<" ";
  // floop(i,1,n-k+1)
  // {
  //   s-=a[i-1];
  //   s+=a[i+k-1];
  //   ans=min(ans, s);
  //   // cout<<s<<" ";
  // }
  // cout<<endl<<ans<<endl;

  // Q5. Top K most frquency element in the  array
  /* 
    Arr- {1,2,2,2,3,4} and k=2

    We have to output element in decreasing frequency till we reach (k+1)th distinct elements

    eg- 1 -> 1
        2 -> 3
        3 -> (k+1)th element so break

      1. Create a map
      2. While travelling, keep track of elements and when we find (k+1)th without element = break
      3. Output the elements and frequency using map
   */

  // int n,k;
  // cin>>n>>k;

  // vi a(n);
  // floop(i,0,n)
  // {
  //   cin>>a[i];
  // }

  // map<int, int> freq;

  // floop(i,0,n)
  // {
  //   int presentsize=freq.size();
  //   if(freq[a[i]]==0 && presentsize==k)
  //   {
  //     break;
  //   }
  //   freq[a[i]]++;
  // }

  // vii ans;
  // map<int,int> ::iterator it;
  // for(it=freq.begin();it!=freq.end();it++)
  // {
  //   if(it->second!=0)
  //   {
  //     pii p;
  //     p.first=it->second;
  //     p.second=it->first;
  //     ans.push_back(p);
  //   }
  // }

  // sort(ans.begin(), ans.end(), greater<pii>());

  // vii :: iterator it1;

  // for(it1=ans.begin(); it1!=ans.end();it1++)
  // {
  //   cout<<it1->second<<" "<<it->first<<endl;
  // }

  
  return 0;
  /* 
                        NOTES
    Why Hashing ? - Play with element's indices.

    2 Option - 1 Traverse the whole array
               2 thodi si extra memory ke dam pe elements aur indices ko map kare

    Problem - Storing indices of such large elements cuz array's limit is only 10^8(that too global)
     |
     Solution (Hashing) - Converting elements into smaller elements using some functions (hash functions)

     Collision - If two elements have same key or hash
     2 methods to solve collision
     1. Seperate Chaining - If collision, create chain of values at same key using linked list.
         Load Factor - n/b 
     2. Open addressing - if collision , do probing 
        using a second argument called probe number in the hash function, 
        Probe Number depends on key, hence given by p(k)

        Linear Proabing - p(k)= a*k+b
        Quadratic Probing P(k)= a*k^2 +b*k + c
        Double Hashing is a secondary hash function

    STL FOR HASHING - Maps     and    Unordererd Maps
          Insertion - O(log(n))          O(1)
          Assertion - O(log(n))          O(1)
          Deletion -  O(log(n))          O(n)
 Implemented using - Red-black trees     Hash Tables

 declaration -    map<int,int>mp    unordered_map<int,int>ump


  */
}