#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define floop(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define pii pair<int, int>

void heapify(vi &a, int n, int i)
{
  int maxidx = i;
  int l = (2 * i) + 1;
  int r = 2 * i + 2;
  if (l < n && a[l] > a[maxidx])
  {
    maxidx = l;
  }
  if (r < n && a[r] > a[maxidx])
  {
    maxidx = r;
  }
  if (maxidx != i)
  {
    swap(a[i], a[maxidx]);

    heapify(a, n, maxidx);
  }
}
void heapsort(vi &a)
{
  int n = a.size();
  for (int i = (n / 2) - 1; i >= 0; i--)
  {
    heapify(a, n, i);
  }
  for (int i = (n - 1); i > 0; i--)
  {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}

// priority_queue<int, vi, greater<int>> pqmin;
// priority_queue<int, vector<int>> pqmax;

// void insert(int x)
// {
//   if(pqmin.size()==pqmax.size())
//   {
//     if(pqmax.size()==0)
//     {
//       pqmax.push(x);
//       return;
//     }

//     if(x<pqmax.top())
//     {
//       pqmax.push(x);
//     }
//     else{
//       pqmin.push(x);
//     }
//   }
//   else
//   {
//     // two cases
//     // Case 1: size of maxheap > size of minheap
//     // Case 2: size of minheap > size of maxheap

//     if(pqmax.size()>pqmin.size())
//     {
//       if(x>=pqmax.top())
//       {
//         pqmin.push(x);
//       }
//       else{
//         int temp=pqmax.top();
//         pqmax.pop();
//         pqmin.push(temp);
//         pqmax.push(x);
//       }
//     }
//     else
//     {
//       if(x<=pqmin.top())
//       {
//         pqmax.push(x);
//       }
//       else
//       {
//         int temp=pqmin.top();
//         pqmin.pop();
//         pqmax.push(temp);
//         pqmin.push(x);
//       }
//     }
//   }
// }

// double findmedian()
// {
//   if(pqmin.size()==pqmax.size())
//   {
//     return (pqmin.top()+pqmax.top())/2.0;
//   }

//   else if(pqmax.size()>pqmin.size())
//   {
//     return pqmax.top();
//   }
//   else
//   {
//     return pqmin.top();
//   }
// }
int main()
{

  // Q1. Median of running stream
  // insert(10);
  // cout<<findmedian()<<endl;
  // insert(15);
  // cout<<findmedian()<<endl;
  // insert(21);
  // cout<<findmedian()<<endl;
  // insert(30);
  // cout<<findmedian()<<endl;
  // insert(18);
  // cout<<findmedian()<<endl;
  // insert(19);
  // cout<<findmedian()<<endl;

  // Q2. Merge K sorted arrays
  /*
    eg - 1. 1,2,3    2. 4,6    3. 5,7
    final ans- 1,2,3,4,5,6,7

    1.create a minheap of pairs- Pair- {value,array number}
    2. Insert {first element, array number} of all sorted array in minheap
    3. Main Idea: We will pop elements from the minheap and store into the ans array. Insert the next element of the sorted array into the min heap
    4. we also need to keep track of the indices of the element
  */
  //  int k;
  //  cin>>k;
  //  vector<vector<int>> a(k);

  //  floop(i, 0, k)
  //  {
  //    int size;
  //    cin>>size;

  //    a[i]=vector<int>(size);
  //    floop(j,0,size)
  //    {
  //      cin>>a[i][j];
  //    }
  //  }
  //  vector<int> idx(k,0);

  //  priority_queue<pii, vector<pii>, greater<pii> >pq;

  //  floop(i,0,k)
  //  {
  //    pq.push({a[i][0], i});
  //  }

  // vi ans;

  // while(!pq.empty())
  // {
  //   pii x =pq.top();
  //   pq.pop();

  //   ans.push_back(x.first);
  //   if(idx[x.second]+1 < a[x.second].size())
  //   {
  //     pq.push({a[x.second][idx[x.second]+1], x.second});
  //   }
  //   idx[x.second]+=1;
  // }

  // floop(i,0,ans.size())
  // {
  //   cout<<ans[i]<<" ";
  // }
  // cout<<endl;

  // int n;  // HEAPSORT
  // cin>>n;

  // vi a(n);
  // floop(i, 0, n)
  // {
  //   cin>>a[i];
  // }

  // heapsort(a);
  // floop(i, 0, n)
  // {
  //   cout<<a[i]<<" ";
  // }

  // priority_queue<int, vector<int>> pq;
  // pq.push(2);
  // pq.push(3);
  // pq.push(1);

  // cout<<pq.top()<<endl;
  // pq.pop();
  // cout<<pq.top()<<endl<<endl;

  // priority_queue<int, vector<int>, greater<int> > pqm;
  // this is minheap thus 1 is output
  // pqm.push(2);
  // pqm.push(1);
  // pqm.push(3);

  // cout<<pqm.top()<<endl;
  // pqm.pop();
  // cout<<pqm.top()<<endl;

  // Q4. Smallest subsequence with sum K
  /*
    eg given and arr = {1,1,3,2,8}  k=13
    subarray - continous block of elements

    subsequence - Not necessarily continous block of
    elements but order should remain as in og array

    Approach - Keep a maxheap and insert all the elements
    2. Keep popping the elements and keep adding them to a variable sum and maintain count
    3. When sum >= k, then qoute the answer(count)
  */

  int n, k;
  cin >> n >> k;

  vi a(n);
  floop(i, 0, n)
  {
    cin >> a[i];
  }

  priority_queue<int, vi> pq;
  floop(i, 0, n)
  {
    pq.push(a[i]);
  }
  int sum = 0;
  int cnt = 0;
  while (!pq.empty())
  {
    sum += pq.top();
    pq.pop();

    cnt++;

    if (sum >= k)
    {
      break;
    }
  }
  if (sum < k)
  {
    cout << "No =  -1" << endl;
  }
  else
  {
    cout << "Yes =  " << cnt << endl;
  }
  return 0;

  /*
      HEAPS - Binary Tree based data structure
            - Not necessarily BST
            - 2 types maxheap and minheap

       Max Heap - Root > rest of the elements present in its subtree eg -
                        6-greater than all ele in the heap
                       / \
                      5   4
                     / \
                    1   2

       Min Heap - Root < rest of the elements present in its subtree eg-
                      1 - Less than all ele in the heap
                     / \
                    3   2
                   / \
                  9   8

      How to convert an Array into a Maxheap -
      arr : [10,15,21,30,18,19]
      1. convert the arr into a BT first
      2. So if we add 10 it goes like - 10
                                       /  \
      3. Now add 15 , but 15 is greater than 10, so we swap 10 with 15 in the BT - this is called heapify
      4. Now add 21, but 21>15 so heapify
      5. Now add 30, 30>10 so again heapify, 30>21 so again heapify
      6. Now add 18, 18<30 so no heapify
      7. Now add 19, 19>15 so heapify
      eg -              30
                       / \
                      21  19
                     / \   /
                    10 18 15

      POPPING ELEMENTS-
      1. Remove 30, then which ever is the last single element pick that up and put it in place of 30, so here it is 15
      2. Now compare 15 with bth its child and check which is greater, here 21 is greater so heapify.
      3. Again compare 15 with child and check if there is a greater element,, here 18 is greater to heapify
      eg -              30              21
                       / \             / \
                      21  19   ->     18  19
                     / \   /         / \
                    10 18 15        10  15
   */

  /*
    HEAPSORT - Make an array into an BT(not heap),
      10                   30
     / \                   / \
    15  21        ->      18  21
   / \   \               / \   \
  30  18  19            15  10  19

 1. choose a non leaf element-and do heapify to make maxheap
 2. chose 21 but since 19 is already less than 21 so nothing
 3. Now go to 15 and now heapify it with 30 because 30>18>15 -
 4. Now again heapify 30 with 10 as 30>21>10
 5. Now 10 heapify with 18 as 18>15>10
 6. Delete 30 now and replace it with last leaf that is 19 and heapify
 7. Heapify 19 with 21 for greater
 8. Delete 21 and now replace it with leaf that is 10
 9. Continue this process until one element is left and add it to array and continue this again and again
  */

  /*
   HEAPS STL
   1. Maxheap - priority-queue<int, vector<int>> -> vector is a container;

   2. Minheap -priority-queue<int, vector<int>, greater<int>> - greater is for reversing the maxheap to from minheap

   3. TIME COMPLEXITY - push/pop- O(log(n)), top/size = O(1)
  */

  /*
     Very Important
     Q. Median of running stream
     - Numbers are coming and we have to tell median after each input
     - eg - arr = {10,15,21,30,18,19}
            1. first input 10 thus median is 10
            2. second input 15 thus median is 10+15/2 = 12.5
            3. median - if even elements than average of 2 middle numbers and if odd elements given the middle number

     Approach - using heaps
     1. Keep one maxheap and one minheap
     2. Partition the array into two parts
     eg- before any input say(18)
     maxheap-(10,15)     Minheap -{21,30}
     18 will come in between them and go to maxheap section so 18 will become the newtop in maxheap
     3. So if size of maxheap and minheap are not equal = top of larger size heap is the median
     4.else when both are equal then avg of top of both heaps

  */
}