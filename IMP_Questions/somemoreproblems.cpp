#include <bits/stdc++.h>
using namespace std;

int get_maxarea(vector<int> a)
{
    int n=a.size(), ans=0, i=0;
    a.push_back(0);
    stack<int> st;
    while(i<n)
    {
        while(!st.empty() && a[st.top()]>a[i])
        {
            int t=st.top();
            int h=a[t];
            st.pop();
            if(st.empty())
            {
                ans=max(ans, h*i);
            }
            else
            {
                int len=(i-st.top()-1);
                ans=max(ans, h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int rain_water(vector<int> a)
{
    stack<int> st;
    int n=a.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and a[st.top()] < a[i])
        {
            int cur=st.top();
            st.pop();
            if(st.empty())
            {
                break;
            }
            int diff=(i-st.top()-1);
            ans += (min(a[st.top()],a[i])-a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}

bool find_redun(string s)
{
    stack<char> st;
    bool ans=false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                ans=true;
            }
           while(st.top()=='+' || st.top()=='-' || st.top()=='/' || st.top()=='*') 
           {
               st.pop();
           }
        }
    }
    return ans;
}

vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int,int>> s;
    for(auto price : prices)
    {
        int days=1;
        while(!s.empty() && s.top().first <= price)
        {
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
     // 1. Find the largest rectangle in a histogram using stack- histogram is a bar graph 
    // given - height of all bar graphs.
    // stack approach- important 
    // vector<int> a={2,1,5,6,7,3};
    // cout<<get_maxarea(a)<<endl;

    // 2. trapping Rainwater harvesting - how much water will be stored between the bars whose height is given - important
    // vector<int> a= {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<rain_water(a);

    // 3. Reduandant Paranthesis 
    // Mathematical expression will be given- find if extra brackets are there or not
    // output - 0 if reduandant not present
    // else output -1 if present
    // string s;
    // cin>>s;
    // cout<<find_redun(s)<<endl; 

    // 4. Stock Span Problem
    //   find - the span(price jo aaj hai usse kam hona chaiye) of the stock for all the days
    // imporatant- CREATE A STACK OF PAIR(VECTOR VALA PAIR)
    // We create a pair to push input + answer(or the span) in the stack
    // vector<int> a= {100,80,60,70,60,75,85};
    // vector<int> res=stockspan(a);
    // for(auto i: res)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // 5. Three sum problem - using two pointer technique
    // find in an array if there exist three numbers whose sum is equal to the given value.
    // int n;
    // cin>>n;
    // int target;
    // cin>>target; 
    // vector<int> a(n);
    // for(auto&i : a)
    //     cin>>i;
    
    // bool found =false;
    // sort(a.begin(),a.end());
    // for(int i=0;i<n;i++)
    // {
    //     int lo=(i+1), hi=(n-1);
    //     while(lo<hi)
    //     {
    //         int curr=a[i]+a[lo]+a[hi];
    //         if(curr==target)
    //         {
    //             found=true;
    //         }
    //         if(curr< target)
    //         {
    //             lo++;
    //         }
    //         else{
    //             hi--;
    //         }
    //     }
    // }
    // if(found)
    // {
    //     cout<<"True"<<endl;
    // }
    // else
    // {
    //     cout<<"False"<<endl;
    // }
    
    // 6. Maximum Consecutive Ones.
    // find longest subarray that contains 1;
    // also we may change up to K values from 0 to 1
    // int n;
    // cin>>n;
    // int k;
    // cin>>k;
    // vector<int> a(n);
    // for(auto &i : a)
    // {
    //     cin>>i;
    // }
    // int zc=0,i=0,ans=0;
    // for(int j=0;j<n;j++)
    // {
    //     if(a[j]==0)
    //     {
    //         zc++;
    //     }
    //     while(zc>k)
    //     {
    //         if(a[i]==0)
    //         {
    //             zc--;
    //         }
    //         i++;
    //     }
    //     //zerocount(zc)<=k
    //     ans=max(ans,(j-i+1));
    // }
    // cout<<ans<<endl;

    // 7. Longest substring
    // find longest substring where no character is repeated.
    string s;
    cin>>s;
    vector<int> dict(256,-1);// all 256 elements in dict are declared as -1
    int maxlen=0, start=-1;
    for(int i=0;i<s.size();i++)
    {
        if(dict[s[i]]>start)
        {
            start=dict[s[i]];
        }
        dict[s[i]]=i;
        maxlen=max(maxlen,(i-start));
    }
    cout<<maxlen<<endl;
    return 0;
}