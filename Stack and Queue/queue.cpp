#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define p 20

class queue1 // for array implementation
{
    int* arr;
    int front;
    int back;

    public:
    queue1()
    {
      arr=new int[p];
      front=-1;
      back=-1;
    }

    void enquepush(int x)
    {
      if(back==p-1)
      {
        cout<<"Queue Overflow"<<endl;
        return;
      }
      back++;
      arr[back]=x;

      if(front==-1)
      {
        front++;
      }
    }
    void dequepop()
    {
      if(front>back || front==-1)
      {
        cout<<"Queue Empty"<<endl;
        return;
      }
      front++;
    } 
    int peek()
    {
      if(front>back || front==-1)
      {
        return -1;
      }
    return arr[front];
    }
    bool empty()
    {
      if(front>back || front==-1)
      {
        cout<<"Queue Empty"<<endl;
        return true;
      }
      return false;
    }
};

class node // for ll implementation
{
  public:
  int data;
  node* next;
  
  node(int val)
  {
    data=val;
    next=NULL;
  }
};
class queue2 // for ll implementation
{
  node* front;
  node* back;

  public:
  queue2()
  {
    front=NULL;
    back=NULL;
  }

  void enqueupush(int x)
  {
    node* n=new node(x);
    if(front==NULL)
    {
      back=n;
      front=n;
      return;
    }
    back->next=n;
    back=n;
  }

  void dequeupop()
  {
    if(front==NULL)
    {
      cout<<"Queue Empty"<<endl;
      return;
    }
    node* temp=front;
    front=front->next;
    delete temp;
  }

  int peek1()
  {
     if(front==NULL)
    {
      // cout<<"Queue Empty"<<endl;
      return-1;
    }
    return front->data;
  }

  bool empty1()
  {
     if(front==NULL)
    {
      cout<<"Queue Empty"<<endl;
      return true;
    }
    return false;
  }
};

class queue3
{
  stack<int> st1;
  stack<int> st2;

  public:
  void stackenque(int x)
  {
    st1.push(x);
  }

  int stackdequ()
  {
    if(st1.empty() && st2.empty())
    {
      cout<<"Queue is empty"<<endl;
      return -1;
    }
    if(st2.empty())
    {
      while(!st1.empty())
      {
        st2.push(st1.top());
        st1.pop();
      }
    }
    int topval=st2.top();
    st2.pop();
    return topval;
  }

  bool empty()
  {
     if(st1.empty() && st2.empty())
    {
      cout<<"Queue is empty"<<endl;
      return true;
    }
    return false;
  }
};

class STACK
{
  int N;
  queue<int> q1;
  queue<int> q2;

public:
  STACK(){
   N=0;
  }
  void push2(int val)
  {
    q2.push(val);
    N++;
    while(!q2.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }

    queue<int> temp=q1;
    q1=q2;
    q2=temp;
  }
  void pop2()
  {
    q1.pop();
    N--;
  }
  int top2()
  {
    return q1.front();
  }
  int size2()
  {
    return N;
  }
};

class Stack
{
  int N;
  queue<int> qu1;
  queue<int> qu2;

public:
  Stack()
  {
    N=0;
  }

  void pop1()
  {
    if(qu1.empty())
    {
      cout<<"Empty"<<endl;
      return;
    }
    while(qu1.size()!=1)
    {
      qu2.push(qu1.front());
      qu1.pop();
    }

    qu1.pop();
    N--;
   queue<int> temp=qu1;
    qu1=qu2;
    qu2=temp;
  }

  void push1(int x)
  {
    qu1.push(x);
    N++;
  }
  int top1()
  {
    if(qu1.empty())
    {
      return -1;
    }
    while(qu1.size()!=1)
    {
      qu2.push(qu1.front());
      qu1.pop();
    }

    int ans=qu1.front();
    qu2.push(ans);
     queue<int> temp=qu1;
    qu1=qu2;
    qu2=temp;

    return ans;
  }

  int size1()
  {
    return N;
  }
};

int main()
{
  // queue- FIFO=first in first out
  // enqueue - same as push in stack
  // dequeue - same as pop in stack
  // peek - check which value will be removed from the queue.
  // empty- tells whether queue is empty

  // 1. ARRAY IMPLEMENTATION

  // queue1 q;
  // cout<<q.peek()<<endl;

  // q.enquepush(3);
  // q.enquepush(4);
  // q.enquepush(5);

  // cout<<q.peek()<<endl;
  // q.dequepop();

  // cout<<q.peek()<<endl;
  // q.dequepop();
  // cout<<q.empty()<<endl;

  // cout<<q.peek()<<endl;
  // q.dequepop();

  // 2. LINKED LIST IMPLEMENTATION

  // queue2 q;
  // q.empty1();
  // q.enqueupush(1);
  // q.enqueupush(2);
  // q.enqueupush(3);
  // q.enqueupush(4);

  // cout<<q.peek1()<<endl;
  // q.dequeupop();

  // cout<<q.peek1()<<endl;
  // q.dequeupop();
  // cout<<q.empty1()<<endl;

  // cout<<q.peek1()<<endl;
  // q.dequeupop();
  // cout<<q.empty1()<<endl;

  // 3. QUEUE USING STACK
  // queue3 q;
  // q.stackenque(1);
  // q.stackenque(2);
  // q.stackenque(3);
  // q.stackenque(4);
  // cout<<q.stackdequ()<<endl;
  // cout<<q.stackdequ()<<endl;
  // cout<<q.empty()<<endl;
  // cout<<q.stackdequ()<<endl;
  // cout<<q.stackdequ()<<endl;
  // cout<<q.empty();
  

  // 4. STACK USING QUEUE - METHOD 1 (BUG) - making push costly 
  // STACK k;
  // k.push2(1);
  // k.push2(2);
  // k.push2(3);
  // k.push2(4);

  // cout<<k.top2();
  // k.pop2();
  
  //5. STACK USING QUEUE - METHOD 2 - making pop costly
  // Stack st;
  // st.push1(1);
  // st.push1(2);
  // st.push1(3);
  // st.push1(4);

  // cout<<st.top1()<<endl;
  // st.pop1();
  // cout<<st.top1()<<endl;
  // cout<<st.size1()<<endl;

  return 0;
}