#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;


int main()
{
    // set<int> s;
    // set<int, greater<int>> s;
    // s.insert(1); 
    // s.insert(2); 
    // s.insert(2); 
    // s.insert(3);
    // for(auto i : s)
    //         cout<<i<<" ";
    // cout<<*s.lower_bound(4)<<endl;
    // cout<<*s.lower_bound(3)<<endl;
    // cout<<*s.upper_bound(1)<<endl;

    //  cout<<endl;
    //  cout<<s.size()<<endl; 
    //  s.erase(2);
    //  for(auto i : s)
    //        cout<<i<<" ";
    //  cout<<endl;

    // multiset<int> s;
    // s.insert(1);
    // s.insert(1);
    // s.insert(3);
    // s.insert(4);
    // s.insert(3);
    // s.insert(5);
    // s.erase(3);  // all 3 are erased at not only one 
    // s.erase(s.find(3)); // find operation gives the pointer of the first 3 only and hence only first 3 is deleted and not all. we can use also lower_bound
    // for(auto i : s)
    //     cout<<i<<" ";
    

    unordered_set<int> s;
    s.insert(1); 
    s.insert(4); 
    s.insert(3); 
    s.insert(3);
    for(auto i : s)
        cout<<i<<" ";
    s.erase(s.find(3));
    cout<<endl;
     for(auto i : s)
        cout<<i<<" ";

 return 0;

  /* 
  Types of Sets - Ordered and unordered

  1. Ordered SET - Contains unique elements 
                   - implemented using balanced BST
                   - Elements are in sorted order
                   - Random access not possible
                   - Present in #include <set>
                   - use s.insert() for insertion
                   - rbegin() and rend() for reverse printing
                   - if set<int, greater<int> s; 
                   - lower/upper_bound(k) -  lower bound points at k in the set , if k is not present it will point to the next value.
                   upper bound points at value greater than k
                   - Erase element - s.erase(2)- 2 erased
                    s.erase(s.begin())- erases first element 

     Multiset is basically Set but it can contain duplicate elements - can use all function like lower bound and erase, etc.

    Time complexities -
    Insertion - O(logn)
    Deletion - O(logn)
    Lower/upper_bound - O(Logn)
    print- o(nlogn)

    2. Unordered SET - Contains unique elements 
                     - implemented using hashing
                     - Elements are not in sorted order
                     - Random access not possible
                     - Present in #include <unordered_set>
                     - all function of set can be used except lower/upper_bound
                     - advantage is followed in time complexity
   */

}