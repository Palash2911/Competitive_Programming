#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

class Tries
{
    public:
        class node{
            public: 
                bool end;
                node* next[26];
                node()
                {
                    end=false;
                    floop(i,0,26)
                    {
                        next[i]=NULL;
                    }
                }
            };
    node* trie;
    Tries()
    {
        trie=new node();
    }

    void insert(string word)
    {
        int i=0;
        node* it = trie;
        while(i<word.size())
        {
            if(it->next[word[i] - 'a'] == NULL)
            {
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end=true;
    }

    bool search(string word)
    {
        int i=0;
        node* it= trie;
        while(i<word.size());
        {
            if(it->next[word[i] - 'a'] == NULL)
            {
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

class Trienode{
    public:
    Trienode *next[2];
    Trienode()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};
Trienode* buildtrie(vi &a)
{
    Trienode *root = new Trienode();
    int n = a.size();
    floop(i,0,n)
    {
        int num = a[i];
        Trienode* cur = root;
        for(int i = 31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(cur->next[bit]==NULL)
            {
                cur->next[bit]=new Trienode();
            }
            cur = cur->next[bit];
        }
    }
    return root;
}

int helper(Trienode* root, vi &a)
{
    int res=0;

    floop(i,0,a.size())
    {
        int num=a[i];
        Trienode* it= root;
        int cur_max =0;
        for(int i=31;i>=0;i--)
        {
            int bit = ((num>>i) & 1)?0:1;
            if(it->next[bit])
            {
                cur_max<<=1;
                cur_max |= 1;
                it=it->next[bit];
            }
            else
            {
                cur_max<<=1;
                cur_max|=0;
                it=it->next[bit xor 1];
            }
        }
        res = max(res,cur_max);
    }
    return res;
}

int int_size = 32;
class node{
    public:
    node* next[2];
    node()
    {
        floop(i,0,2)
        {
            next[i]=NULL;
        }
    }
};
node* trie;
void insert(int num)
{
    node* it = trie;
    for(int i=int_size-1;i>=0;i--)
    {
        int cur_bit= (num>>i)&1;
        if(!it->next[cur_bit])
        {
            it->next[cur_bit]=new node();
        }
        it=it->next[cur_bit];
    }
}
int query(int num)
{
    node* it = trie;
    int ans=0;
    for(int i=int_size-1;i>=0;i--)
    {
        int cur_bit= (num>>i)&1;
        int oppo = cur_bit xor 1;
        if(it->next[oppo])
        {
            it=it->next[oppo];
            ans |= 1<<i;
        }
        else
        {
            it=it->next[oppo xor 1];
        }
    }
    return ans;
}

class nodes{
    public:
    nodes* next[26];
    bool end;
    nodes()
    {
        floop(i,0,26)
        {
            next[i]=NULL;
        }
        end=false;
    }
};

class tries{
    private:
    nodes *root;
    public:
    tries()
    {
        root=new nodes();
    }
    void insert(string &s)
    {
        nodes* it =root;
        for(auto c: s)
        {
            if(!it->next[c-'a'])
            {
                it->next[c-'a'] = new nodes();
            }
            it = it->next[c-'a'];
        }
        it->end=true;
    }
    void find(string &s)
    {
        nodes* it = root;
        for(auto c : s)
        {
            if(!it->next[c-'a'])
            {
                cout<<"No suggestions"<<endl;
                insert(s);
                return;
            }
            it = it->next[c-'a'];
        }
        vector<string> res;
        printall(it,s,res,"");
        for(auto c : res)
        {
            cout<<s<<c<<endl;
        }
    }
    void printall(nodes* it, string &s,vector<string> &res, string cur)
    {
        if(it ==NULL)
        {
            return;
        }
        if(it->end)
        {
            res.push_back(cur);
        }
        floop(i,0,26)
        {
            if(it->next[i])
            {
                printall(it->next[i],s,res,cur+char('a'+i));
            }
        }
    }
};
int main()
{
    //  Tries - Prefix Tree

    //  Tries *mytrie= new Tries();
    //  vector<string> words = {"ayush", "daasi"};
    //  for(auto w : words)
    //  {
    //      mytrie->insert(w);
    //  }
    //  cout<<"Hi"<<endl;
    //  if(mytrie->search("Madhav"))
    //  {
    //      cout<<"Found"<<endl;
    //  }
    //  else{
    //      cout<<"Not found"<<endl;
    //  }
    //  if(mytrie->search("ayush"))
    //  {
    //      cout<<"Found"<<endl;
    //  }
    //  else{
    //      cout<<"Not found"<<endl;
    //  }


    //Q1. Maximu XOR of two Numbers in an array
    /* 
        eg - arr= 3,10,5,15,2
        max xor is 15
    */
    // vi a = {3,10,5,15,2};
    // Trienode* root = buildtrie(a);
    // int ans = helper(root, a);
    // cout<<ans<<endl;

    // Q2. Trie Bash 
    /* 
        Problem - Given an array arr. You are supposed to find the maximum value of (arr[a]^arr[a+1]...^arr[b]) + (arr[c]^arr[c+1]...^arr[d]) where 1<=a<=b<=c<=d<=n , n is size of array

        eg - n= 4;  arr={1,2,6,8}
        ans =17;
        a=1,b=2,c=3,d=4,    so(1^2)+(6^8)=17
    */
    // int n;
    // cin>>n;
    // vi a(n);
    // floop(i,0,n)
    // {
    //     cin>>a[i];
    // }
    // trie=new node();
    // insert(0);
    // vi rmax(n+1, 0);
    // int r=0;
    // for(int i=n-1;i>=0;i--)
    // {
    //     r =r xor a[i];
    //     if(i!=n-1)
    //     {
    //         rmax[i] = max(rmax[i+1], query(r));
    //         insert(r);
    //     }
    //     else
    //     {
    //         rmax[i]=query(r);
    //         insert(r);
    //     }
    // }
    // free(trie);
    // trie = new node();
    // insert(0);
    // int ans=0;
    // int l=0;
    // for(int i=0;i<n;i++)
    // {
    //     l = l xor a[i];
    //     ans= max(ans, rmax[i+1]+query(l));
    //     insert(l);
    // }
    // cout<<ans<<endl;


    // Q3. Digital Dictionary 
    /* 
        Problem - Given a digital dictionary. It has an input field in which one can search any string and the dictionary displays all the words whose prefix is that input string in lexicographical order.
        Now you have to make your own digital dictionary

        eg - n=4 dicti- pet,peter,rat,rack
        output
        pet peter rack rat


    */
   tries t;
   int n;
   cin>>n;
   vector<string> a(n);
   for(auto &i : a)
   {
       cin>>i;
       t.insert(i);
   }
   int q;
   cin>>q;
   while(q--)
   {
       string s;
       cin>>s;
       t.find(s);
   }

  return 0;
}