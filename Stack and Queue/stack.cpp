#include <iostream>
#include <stack> // a library for all functions of stack makes easier
using namespace std;

// #define n 100
// class stack
// {
//     int* arr;
//     int top;
//     public:
//     stack()
//     {
//         arr=new int [n];
//         top=-1;
//     }

//     void push(int x)
//     {
//         if(top==n-1)
//         {
//             cout<<"Stack overflow "<<endl;
//             return;
//         }
//         top++;
//         arr[top]=x;
//     }

//     void pop()
//     {
//         if(top==-1)
//         {
//             cout<<"Empty stack"<<endl;
//             return;
//         }
//         top--;
//     }
//     int Top()
//     {
//          if(top==-1)
//         {
//             cout<<"Empty stack"<<endl;
//             return -1;
//         }
//         return arr[top];
//     }
//     bool empty()
//     {
//         return top==-1;
//     }
// };

void reversesent(string s)
{
    stack<string> st;

    for(int i=0;i<s.length();i++)
    {
        string word="";
        while(s[i]!=' ' && i<s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop(); //this is necessary in order to go to the next word 
    }
    cout<<endl;
}
void insertatbottom(stack<int> &st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }

    int topele=st.top();
    st.pop();
    insertatbottom(st,ele);

    st.push(topele);
}
void reversesta(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int el=st.top();
    st.pop();
    reversesta(st);
    insertatbottom(st, el);
}
int main()
{
//   stack - stores a list of items in which the item can be added or removed from the list only at one end. 
// LIFO USED IN STACK- last in first out

//   stack st;
//   st.push(1);
//   st.push(2);
//   st.push(3);
//   cout<<st.Top()<<endl;
//   st.pop();
//   cout<<st.Top()<<endl;
//   st.pop();
//   st.pop();
//   st.pop();
//   cout<<st.empty()<<endl;

    // Q1. reverse a sentence using stack
    // stack<int> st; // declare a array stack like this to use the stack header file

    // string s="Hey, how are you doing?  ";
    // reversesent(s);

    // Q2. reverse a stack.
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);

    //  reversesta(st);

    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    return 0;
}