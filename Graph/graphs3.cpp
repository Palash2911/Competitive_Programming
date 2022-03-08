#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

const int inf=1e7;

void change(vector<vector<char>> &a, int x, int y)
{
  a[x][y]='*';
  int dx[]={0,0,-1,1};
  int dy[]={1,-1,0,0};
  for(int i=0;i<4;i++)
  {
    int cx = x+dx[i];
    int cy = y+dy[i];
    if(cx>=0 and cx<a.size() and cy>=0 and cy<a[0].size() and a[cx][cy]=='O')
    {
      change(a,cx,cy);
    }
  }
}
int main()
{
  //DIJKSTRA'S ALGORITHM - 
  /* 
    Problem - Given a weighed grah. Find the single source shortest path from a vertex U to all the vertices in the graph. if the node is unreachable then print -1. Path here we have to see weight of the edges not the length

    Note - This is for only positive graphs

    Dijkstra's - 
    1. Assign a distance value to all vertices in the graph. Initialize all dist. value as infinite. Assign distance value as 0 for the source vertex

    2. While set is not empty 
           a. Pick a vertex u from set s that has minimum dist value.
           b. Update dist value of all adjacent vertices of u
  */
    //CODE -
    int n,m;
    cin>>n>>m;
    vi dist(n+1, inf);
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int sour;
    cin>>sour;
    dist[sour]=0;
    set<pair<int,int>> s;
    s.insert({0,sour});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : graph[x.second])
        {
            if(dist[it.first] > (dist[x.second]+it.second))
            {
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<inf)
        {
            cout<<dist[i]<<" ";
        }
        else{
            cout<<"-1  ";
        }
    }


    //BELLMAN FORD ALGORITHM - 
    /* 
        Problem - From a source Vertex V, find the shortest distance to all other nodes(vertices) in the graph

        Bellman - 
        1. initally d[v]=0 and for all other elements d[]=inf

        2. In each pass, relax all the edges. 
                i.e for edge(a,b) having weight w, 
                d[b]=min(d[b], d[a]+w)
        
        3. Assuming no negative edge cycle, since there are n vertices, shortest path can only contain 'n-1' edges. therefore, we will get our ans in at most 'n-1' passes

        Better than Dijkstra because -
        1. Negative Edges 
        2. Can detect Negative cycles also
    */
    //CODE 
    // int n,m;
    // cin>>n>>m;
    // vvi edges;
    // for(int i=0;i<m;i++)
    // {
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     edges.push_back({u,v,w}); 
    // }
    // int src;
    // cin>>src;
    // vi dist(n, inf);
    // dist[src]=0;
    // for(int it=0;it<n-1;it++)
    // {
    //     for(auto e : edges)
    //     {
    //         int u = e[0];
    //         int v = e[1];
    //         int w = e[2];
    //         dist[v]=min(dist[v],w+dist[u]);
    //     }
    // }
    // for(auto i : dist)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;


    // FLOYD WARSHALL ALGORITHM - 
    /* 
      Problem - To find all pair shortest paths. i.e. for every u,v in Graph, find the shortest path from u to v

      relax the dist between any 2 nodes by adding any third node
    */
    //CODE
    // vvi graph = {   {0,5,inf,10},
    //                 {inf,0,3,inf},
    //                 {inf,inf,0,1},
    //                 {inf,inf,inf,0} 
    //             };

    // int n=graph.size();
    // vvi dist=graph;
    // for(int k=0;k<n;k++)
    // {
    //   for(int i=0;i<n;i++)
    //   {
    //     for(int j=0;j<n;j++)
    //     {
    //       if(dist[i][k]+dist[k][j]<dist[i][j])
    //       {
    //         dist[i][j]=dist[i][k]+dist[k][j];
    //       }
    //     }
    //   }
    // }      
    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //   {
    //     if(dist[i][j]==inf)
    //     {
    //       cout<<"INF ";
    //     }
    //     else
    //     {
    //       cout<<dist[i][j]<<" ";
    //     }
    //   }
    //   cout<<endl;
    // }

    
    // Q.Surrounded Regions.
    /* 
    Problem -  Given 2D board containing 'X' and 'O', capture all regions surrounded by 'X'

    A region is captured by flipping all 'O' int 'X' in that surrounded region 

    IDEA - 
    1. Travers the 'O' components around the edges of the grid and change it to '*'
    2. the remaining 'O' components will be surrounded region that can be captured
    3. Change the '*' back to 'O'
    */
   //CODE 
  //  int n,m;
  //  cin>>n>>m;
  //  vector<vector<char>> a(n, vector<char>(m));
  //  for(int i=0;i<n;i++)
  //  {
  //    for(int j=0;j<m;j++)
  //    {
  //      cin>>a[i][j];
  //    }
  //  }
  //  for(int i=0;i<n;i++)
  //  {
  //    for(int j=0;j<m;j++)
  //    {
  //      if((i==0 or i==n-1 or j==0 or j==m-1) and a[i][j]=='O')
  //      {
  //         change(a,i,j);
  //      }
  //    }
  //  }
  //  for(int i=0;i<n;i++)
  //  {
  //    for(int j=0;j<m;j++)
  //    {
  //      if(a[i][j]=='O')
  //      {
  //        a[i][j]='X';
  //      }
  //    }
  //  }
  //  for(int i=0;i<n;i++)
  //  {
  //    for(int j=0;j<m;j++)
  //    {
  //      if(a[i][j]=='*')
  //      {
  //        a[i][j]='O';
  //      }
  //    }
  //  }
  //  for(int i=0;i<n;i++)
  //  {
  //    cout<<endl;
  //    for(int j=0;j<m;j++)
  //    {
  //      cout<<a[i][j]<<" ";
  //    }
  //  }

  // Q. Snake and ladders Problems
  /* 
    Problem - You are at square 1 and have to reach square 100. You have complete control over the die and can get any number from 1-6.
    For given snake and ladders find the minimum steps to reach 100 
    given is the number of ladders and number of snakes 

    Idea - 
    1. BFS 
    2. Push 1 into queue,
            for all possiblities in the dice:
            check if the next position is ladder, snake or empty
            Mark the square as visited and push into queue
    3. Stop the traversal, when you reached 100
  */
   // CODE
   
  //  int ladd,snake;
  //  cin>>ladd;
  //  map<int,int> lad;
  //  map<int,int> snak;
  //  for(int i=0;i<ladd;i++)
  //  {
  //    int u,v;
  //    cin>>u>>v;
  //    lad[u]=v;
  //  }
  //  cin>>snake;
  //  for(int i=0;i<snake;i++)
  //  {
  //    int u,v;
  //    cin>>u>>v;
  //    snak[u]=v;
  //  }
  //  int moves=0;
  //  queue<int> q;
  //  q.push(1);
  //  bool found =false;
  //  vi vis(101,0);
  //  vis[1]=true;
  //  while(!q.empty() and !found)
  //  {
  //    int sz = q.size();
  //    while(sz--)
  //    {
  //      int t=q.front();
  //      q.pop();
  //      for(int die=1;die<=6;die++)
  //      {
  //        if(t+die==100)
  //        {
  //          found=true;
  //        }
  //        if(t+die<=100 and lad[t+die] and !vis[lad[t+die]])
  //        {
  //           vis[lad[t+die]]=true;
  //           if(lad[t+die]==100)
  //           {
  //             found = true;
  //           }
  //           q.push(lad[t+die]);
  //        }
  //        else if(t+die<=100 and snak[t+die] and !vis[snak[t+die]])
  //        {
  //          vis[snak[t+die]]=true;
  //          if(snak[t+die]==100)
  //          {
  //            found =true;
  //          }
  //          q.push(snak[t+die]);
  //        }
  //        else if(t+die<=100 and !vis[t+die] and !snak[t+die] and !lad[t+die])
  //        {
  //          vis[t+die]=true;
  //          q.push(t+die);
  //        }
  //      }
  //    }
  //    moves++;
  //  }
  //  if(found)
  // {
  //   cout<<moves<<endl;
  // }
  // else{
  //   cout<<"-1"<<endl;
  // }
  return 0;
}