#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>

const int N = 1e5+2;
vector<int> adj[N];
bool vis[N];

void dfs(int node)
{
  //preorder
  vis[node]=1;
  // cout<<node<<" "<<endl;

  //inorder
  vector<int> :: iterator it;

  for(it=adj[node].begin();it!=adj[node].end();it++)
  {
      if(vis[*it]);
      else
      {
        dfs(*it);
      }
  }

  //postorder
  cout<<node<<" ";
}

bool iscycle(int src, vvi &adj, vector<bool> &visited, int parent)
{
  visited[src]=true;
  for(auto i : adj[src])
  {
    if(i!=parent)
    {
      if(visited[i])
      {
        return true;
      }
      if(!visited[i] and iscycle(i,adj,visited,src))
      {
        return true;
      }
    }
  }
  return false;
}

bool iscycle1(int src, vvi &Adj, vector<bool> &visited, vi &stack)
{
  stack[src]=true;

  if(!visited[src])
  {
    visited[src]=true;
    for(auto i : Adj[src])
    {
      if(!visited[i] and iscycle1(i,Adj,visited,stack))
      {
        return true;
      }
      if(stack[i])
      {
        return true;
      }
    }
  }
  stack[src]=false;
  return false;
}
int main()
{
    // Adjacency Matrix
    // int n,m;
    // cin>>n>>m;  // n is  number of nodes and m no. of edges 

    // vvi adjm(n+1, vi(n+1, 0));

    // floop(i,0,m)
    // {
    //   int x,y;
    //   cin>>x>>y;

    //   adjm[x][y]=1;
    //   adjm[y][x]=1;

    // }
    // cout<<"Adjacency Matrix of Above Graph:  "<<endl;
    // floop(i,1,n+1)
    // {
    //   floop(j,1,n+1)
    //   {
    //     cout<<adjm[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }

    // if(adjm[3][7]==1)
    // {
    //   cout<<"There is a edge between 3 and 7 "<<endl;
    // }
    // else{
    //   cout<<"Nope"<<endl;
    // }

    // cout<<endl<<endl;

    // // Adjacency List
    // cin>>n>>m;

    // vi adj[N];
    // floop(i,0,m)
    // {
    //   int x,y;
    //   cin>>x>>y;

    //   adj[x].push_back(y);
    //   adj[y].push_back(x);
    // }

    // cout<<"Adjacency List of above Graph:  "<<endl;
    // floop(i,1,n+1)
    // {
    //   cout<<i<<" -> ";
    //   vector<int> :: iterator it;
    //   for(it=adj[i].begin();it!=adj[i].end();it++)
    //   {
    //     cout<<*it<<" ";
    //   }
    //   cout<<endl;
    // }

    //BREADTH FIRST SEARCH -
    // bool vis[N];
    // vector<int> adj[N];

    // floop(i,0,N)
    // {
    //   vis[i]=0;
    // }
    // int n,m;
    // cin>>n>>m;
    
    // int x,y;
    // floop(i,0,m)
    // {
    //   cin>>x>>y;

    //   adj[x].push_back(y);
    //   adj[y].push_back(x);
    // }

    // queue<int> q;
    // q.push(1);
    // vis[1]=true;

    // while(!q.empty())
    // {
    //   int node = q.front();
    //   q.pop();
    //   cout<<node<<endl;

    //   vector<int> :: iterator it;
    //   for(it=adj[node].begin();it!=adj[node].end();it++)
    //   {
    //     if(!vis[*it])
    //     {
    //       vis[*it]=1;
    //       q.push(*it);
    //     }
    //   }
    // }

    //Q. Depth First Search - DFS
  //   int n,m;
  //   cin>>n>>m;

  // for(int i=0;i<=n;i++)
  //   {
  //     vis[i] = false;
  //   }

  //   int x,y;
  //   floop(i,0,m)
  //   {
  //     cin>>x>>y;
  //     adj[x].push_back(y);
  //     adj[y].push_back(x);
  //   }

  // dfs(1);

  // Topological Sort
  /* 
    A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering

    Note: Topological ordering are NOT UNIQUE and not every graph has a Topological sort 

    1. Directed cyclic graph cannot have a topological sort
    2. Only DAG have a valid topological sort

    eg-        A
             / | \
            B  C  D
           / \  \
          E  F   G

    Topological Sort - E F G D B C A

    Indegree - the number of inward directed edges on a vertex in a directed graph
  */

  // int n,m;
  // cin>>n>>m;

  // int cnt=0;
  // vvi adj_list(n);
  // vector<int> indeg(n,0);

  // floop(i,0,m)
  // {
  //   int u,v;
  //   cin>>u>>v;
  //   adj[u].push_back(v);
  //   indeg[v]++;
  // }
  // queue<int> pq;
  // floop(i,0,n)
  // {
  //   if(indeg[i]==0)
  //   {
  //     pq.push(i);
  //   }
  // }
  // while(!pq.empty())
  // {
  //   cnt++;
  //   int x=pq.front();
  //   pq.pop();
  //   cout<<x<<" ";
  //   for(auto it : adj[x])
  //   {
  //     indeg[it]--;
  //     if(indeg[it]==0)
  //     {
  //       pq.push(it);
  //     }
  //   }
  // }

  // Cycle Detection in a Undirected Graph
  /* 
     keep on traversing the graph 
     if you found an edge pointing to an already visited node(except the parent node), a cycle is found
  */
  //  int n,m;
  // cin>>n>>m;

  // vvi adj(n);
  // floop(i,0,m)
  // {
  //   int u,v;
  //   cin>>u>>v;
  //   adj[u].push_back(v);
  //   adj[v].push_back(u);
  // }
  // bool cycle=false;
  // vector<bool> visited(n,false);
  // floop(i,0,n)
  // {
  //   if(!visited[i] and iscycle(i,adj,visited,-1))
  //   {
  //     cycle=true;
  //   }
  // }
  // if(cycle)
  // {
  //   cout<<"Cycle is present  "<<endl;
  // }
  // else
  // {
  //   cout<<"Cycle is not present  "<<endl;
  // }


  // Cycle Detection in a Directed Graph
  /* 
    1. Mark the current node as visited and also mark the index in recursion stack
    2. Find all the vertices which are not visited and are adjacent to the current node.
    3. If the adjacent vertices are already marked in the recursion stack then a cycle is found
  */
  // int n,m;
  // cin>>n>>m;

  // vvi Adj(n);
  // floop(i,0,m)
  // {
  //   int u,v;
  //   cin>>u>>v;
  //   Adj[u].push_back(v);
  // }
  // bool cycle = false;
  // vi stack(n,0);
  // vector<bool> visited(n,0);
  // floop(i,0,n)
  // {
  //   if(!visited[i] and iscycle1(i,Adj,visited,stack))
  //   {
  //     cycle=true;
  //   }
  // }
  // if(cycle)
  // {
  //   cout<<"Cycle is present  "<<endl;
  // }
  // else
  // {
  //   cout<<"Cycle is not present  "<<endl;
  // }
  return 0;


  /*                ***NOTES***
    Nodes - These are the states or vertex
    Edges - Links between states in a graph 
            1. Undirected edge - Two way
            2. Directed edge - One way 
    
    Representation - 1. Adjacency Matrix              2. Adjacency List
                  2D array, where a[i][j]=1              Array of lists, 
                 if there is an edge from             where each a[i] is a
                  i to j else a[i][j]=0                list of nodes xi that
                                                  are reachable from i

    Searches - 
    1. Depth first Search - go to depth of one node first - implemented by using stacks
        eg-       1  
                /   \
               2    3
             / | \ \ /
            4  5 6  7
      three types to traverse - pre,in and post order 
      preorder print - 1,2,4,5,6,7,3
      postorder - 4,5,6,3,7,2,1

    2. Breadth First search - go level wise - implemented using queue
        eg-       1
                /   \
               2    3
             / | \ \ /
            4  5 6  7
    
  Different properties of components of Graph -
  1. Weighted Nodes - values are associated with nodes
  2. Weighted Edges - values are associated with edges

  TERMINOLOGIES in Graph -
  1. Directed Graph - A graph with directed edges

  2. UnDirected Graph - A graph with undirected edges

  3. Adjacent Vertices - these are two vertices with a direct edge connecting them. 
  eg - A - B 
          / \
          D - C 
    here AV are(A,B);(B,C);(B,D);(C,D)

  4. Degree of a vertex - these are two types of degress -
                  1. Indegree                                  2. Outdegree
               Number of incoming edges to a node          Number of outgoing edges from a node

  5. Path between two vertices - All vertices which come in the path of two given vertices 
  
  6. Connected Graph - each Node has path from every other Node.

  7. Disconnected Graph - each Node does not have path from every other node.

  8. Connected Components - each connected graph in a disconnected graph 

  9. Cycles in a Graph - Path from a vertex to the same vertex in a graph
            1. Cyclic graph - Graph which contains cycle
            2. Acyclic graph - No cycle 
      
  10. Tree - It is connected acyclic graph
              properties - 
                1. Number of edges = n-1
                2. No cycle present
                3. Each node has path from every other vertex

  11. Directed Acyclic Graph (DAG) - As the name suggest 
      Properties -
        1. It has directed edges 
        2. No cycles present

  12. Complete Graph - A graph in which each vertex is connected to every other vertex by a direct edge.
      Number of Edges - (n*(n-1))/2 - nC2

  13. Weighted graph - A graph with weighted graph
  */
}