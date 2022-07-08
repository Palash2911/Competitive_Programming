#include <bits/stdc++.h>
using namespace std;


int main()
{
    // deque<int> dq;
    // dq.push_back(1);
    // dq.push_back(2);
    // dq.push_front(3);
    // dq.push_front(4);
    // for(auto i : dq) // just like for loop for deque and another method to dispay deque
    //     cout<<i<<" ";
    // cout<<endl;
    //     dq.pop_back();// 2 got deleted from the back
    //     dq.pop_front();// 4 got deleted from the front
    //     for(auto i : dq)
    //         cout<<i<<" ";
    //     cout<<endl;
    //     cout<<dq.size()<<endl; // gives size for deque
    

        // QUESTIONS

    // 1.sliding window maximum - method 1
    //     int n,k;
    //     cin>>n>>k;
    //     vector<int> a(n);
    //     for(auto &i: a)
    //         cin>>i;
        
    //     multiset<int,greater<int>> s;
    //     vector<int> ans;
    //     for(int i=0;i<k;i++)
    //     {
    //         s.insert(a[i]);
    //     }
    //     ans.push_back(*s.begin());
    //     for(int i=k;i<n;i++)
    //     {
    //         s.erase(s.lower_bound(a[i-k]));
    //         s.insert(a[i]);
    //         ans.push_back(*s.begin());
    //     }
    //     for(auto i: ans)
    //         cout<<i<<" ";

   

    return 0;

// DEQUE - NOTES
//  1. also called double ended queue
//  2. is a combination of stacks and queues
//  3. can push and pop from the end like stack
//  4. can insert and delete from the start like queue
//  5. *** header file = <deque> *** 
//  6. EG -  if we create a deque as - deque<int> dq
//           dq.push_front(1)- will push the value to the front of deque
//           dq.push_back(2)- will push the value to the back or u can say after the value 1 , 2 will be pushed
//           dq.front()- display front value and dq.back()- display back value
//           dq.pop_front() -  pop the front value similarly dq.pop_back()

}