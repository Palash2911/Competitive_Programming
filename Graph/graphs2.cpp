#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vii vector<pii>

int n,m;
vector<bool> vis;
vvi adj;
vi comp;
vi col;
bool bipart;
const int N=1e+5,INF=1e9;
vector<int> parent(N);
vector<int> sz(N);
int n1,m1,cost=0;
vvi g[N];
vi p(N);
vi dist(N);
vector<bool> vis1(N);

int get_comp(int idx)
{
    if(vis[idx])
    {
        return 0;
    }
    vis[idx]=true;
    int ans=1;
    for(auto i : adj[idx])
    {
        if(!vis[i])
        {
            ans+=get_comp(i);
            vis[i]=true;
        }
    }
    return ans;
}

void color(int u,int curr)
{
    if(col[u]!=-1 and col[u]!=curr)
    {
        bipart=false;
        return;
    }
    col[u]=curr;
    if(vis[u])
    {
        return;
    }
    vis[u]=true;
    for(auto i : adj[u])
    {
        color(i, curr xor 1);
        // switch karta rahega from 0 to 1
        // 0 xor 1 = 1
        // 1 xor 0 = 0
    }
}

void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    {
        return v;        
    }
    return parent[v]=find_set(parent[v]);//compression of path
}
void union_set(int a, int b)
{
    a=find_set(a);
    b=find_set(b);
  
    if(a!=b)
    {
        if(sz[a]<sz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

void primsMST(int sour)
{
    for(int i=0;i<n1;i++)
    {
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[sour]=0;
    s.insert({0,sour});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis1[x[1]]=true;
        int u=x[1];
        int v=p[x[1]];
        int w=x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto it : g[x[1]])
        {
            if(vis1[it[0]])
            {
                continue;
            }
            if(dist[it[0]]>it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]]=it[1];
                s.insert({dist[it[0]],it[0]});
                p[it[0]] = x[1];
            }
        }
    }
}
int main()
{
    //Q. Find the no of connected components in a graph and its size
    // cin>>n>>m;
    // adj=vvi(n);
    // vis= vector<bool>(n);
    // floop(i,0,m)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // floop(i,0,n)
    // {
    //     if(!vis[i])
    //     {
    //         comp.push_back(get_comp(i));
    //     }
    // }
    // for(auto i : comp)
    // {
    //     cout<<i<<" ";
    // }

    /* 
    Q. There are N friends numbered from 0 to N-1. You have to choose 2 person such that they are not related to each other. You are given information in the form of M pairs(x,y) there is a link between friend X AND Y
    Find out number of ways in which 2 person from different grps can be chosen

    Idea - Find the components and their sizes. At i'th component, choose one person from it and other person from the rest of the grp.
    */
    //  cin>>n>>m;
    // adj=vvi(n);
    // vis= vector<bool>(n);
    // floop(i,0,m)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // floop(i,0,n)
    // {
    //     if(!vis[i])
    //     {
    //         comp.push_back(get_comp(i));
    //     }
    // }
    // long long ans=0;
    // for(auto i : comp)
    // {
    //     ans+=i*(n-i);
    // }
    // cout<<ans/2<<endl; // to remove overcounting divide by 2

    //Bipartite Graph
    // int n,m;
    // cin>>n>>m;
    // adj=vvi(n);
    // vis=vector<bool>(n,false);
    // col=vi(n,-1);
    // bipart=true;
    // floop(i,0,m)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // for(int i=0;i<n;i++)
    // {
    //     if(!vis[i])
    //     {
    //         color(i,0);
    //     }
    // }
    // if(bipart)
    // {
    //     cout<<"Graph is Bipart"<<endl;
    // }
    // else
    // {
    //    cout<<"Graph is not Bipart"<<endl; 
    // }

    //DSU - Q. detect cycle in a undirected graph
    //  for(int i=0;i<N;i++)
    //  {
    //      make_set(i);
    //  }
    //  cin>>n>>m;
    //  vvi edges;
    //  for(int i=0;i<m;i++)
    //  {
    //      int u,v;
    //      cin>>u>>v;
    //      edges.push_back({u,v});
    //  }
    //  bool cycle=false;
    //  for(auto i : edges)
    //  {
    //      int u=i[0];
    //      int v=i[1];
    //      int x=find_set(u);
    //      int y=find_set(v);
    //      if(x==y)
    //      {
    //          cycle=true;
    //      }
    //      else
    //      {
    //          union_set(u,v);
    //      }
    //  }
    //  if(cycle)
    //  {
    //      cout<<"Cycle is Found "<<endl;
    //  }
    //  else
    //  {
    //      cout<<"No cycle Found "<<endl;
    //  }

    // KRUSKAL'S Algorithm
    // Q. Minimum Spanning Tree(ST) - Use the Disjoint Set ka code
    //  for(int i=0;i<N;i++)
    // {
    //     make_set(i);
    // }
    // int n,m;
    // cout<<"Enter Number Of Nodes and Edges :  "; 
    // cin>>n>>m;
    // vvi edges;
    // for(int i=0;i<m;i++)
    // {
    //     int u,v,w;//w is the weight
    //     cin>>u>>v>>w;
    //     edges.push_back({w,u,v});
    // }
    // sort(edges.begin(),edges.end());
    // int cost=0;
    // for(auto i : edges)
    // {
    //     int w=i[0];
    //     int u=i[1];
    //     int v=i[2];
    //     int x=find_set(u);
    //     int y=find_set(v);
    //     if(x==y)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         cout<<u<<" "<<v<<endl;
    //         cost+=w;
    //         union_set(u,v);
    //     }
    // }
    // cout<<"Cost is :  "<<cost<<endl; 

    //PRIMS ALGO FOR MST -
    // cin>>n1>>m1;
    // for(int i=0;i<m1;i++)
    // {
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     g[u].push_back({v,w});
    //     g[v].push_back({u,w});
    // }
    // primsMST(0);
    // cout<<cost<<endl;

    return 0;


  /*    *** NOTES ***
  //Connected Components of a graph
    A connected components is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph

    Idea 
    1. Visit the nodes in a depth-first fashion
    2. If the node is not visited, visit that node and its neighbour recursively 
    Each time a unvisited node is found, a new component will be found


     *** Bipartite Graph.***
    1. Its vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U one in V
    2. The graph does not contain any odd-lengths cycles
    3. The graph is 2 colorable
    traverse the graph 
    if the current node is of red color, paint its neighbours as blue.
    if the graph can be colored perfectly it is bipartited


    DISJOINT SET UNION(union find) -
    parent of set in computer is a number - this is used to identify sets 
    basic implementation 0f DSU - 
    S - 1 2  - parent or leader is 2
    P - 3 4 - parent or leader is 4

    so if u say union of 1, 2 - 1<-2 ; 3,4 - 3<-4; but if you say union of 2,4- so here leaders union will happen
    as     1
          / \
         2   3
              \
               4 
    time complexity - O(n)
    path compression - 
            eg -        1                 1          
                        |               / | \ \
                        2              2  3  5 7
                       / \       ->    |  |    
                      3   4            4  6
                     / \                  |
                    5   6                 8
                    |   |
                    7   8 
    suppose now i want to compress path from 7 then i will break every node from 7 to 1 and add it directly to 1 , so 3 will add to 1, 5 will add to 1 , etc.

    Union by size/rank - time complexity - O(alpha(n)) - give answer shortly - solve for long chains problems

    // KRUSKAL'S Algorithm
    // Q. Minimum Spanning Tree(ST)

        Problem - Given an undirected and connected Graph with vertex A and edges E, a spanning tree of the graph G is a tree that spans G(i.e. it includes every vertex of G) and is a subgraph of G(every edge in the tree belongs to tree)

        Cost - Cost of the ST is the sum of the weights of all the edges in the tree

        Minimum Spanning Tree - where cost of ST is minimum

        There can be many ST and MST for a graph
        
        Kruskal Algo - 
        1.Sort the edges in increasing order of their weights
        2. Iterate in the sorted edges ,
                IF inclusion of i'th edge leads to a cycle, then skip this edge.
                ELSE include the edge in the MST
        Time Complexity - O(E logV)
  */
}