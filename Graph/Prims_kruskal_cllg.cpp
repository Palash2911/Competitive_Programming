#include <iostream>
using namespace std;
class graph
{
    int G[20][20], n;

public:
    void accept()
    {
        int i, j, e;
        int src, dest, cost;
        cout << "\nEnter the no. of vertices:  ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                G[i][j] = 0;
            }
        }
        cout << "Enter the no. of Edges:  ";
        cin >> e;
        for (i = 0; i < e; i++)
        {
            cout << "\nEnter Source:  ";
            cin >> src;
            cout << "Destination:  ";
            cin >> dest;
            cout << "Cost:  ";
            cin >> cost;
            G[src][dest] = cost;
            G[dest][src] = cost;
        }
    }
    void display()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            cout <<endl;
            for (j = 0; j < n; j++)
            {
                cout << G[i][j] << "\t";
            }
        }
    }
    void prims()
    {
        int i, j, R[20][20];
        int src, dest, cost, count, min;
        int total = 0;
        int visited[20];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (G[i][j] == 0)
                {
                    R[i][j] = 9999;
                }
                else
                    R[i][j] = G[i][j];
            }
            visited[i] = 0;
        }
        cout << "\nEnter start vertex:  ";
        cin >> src;
        visited[src] = 1;
        count = 0;
        while (count < n - 1)
        {
            min = 9999;
            for (i = 0; i < n; i++)
            {
                if (visited[i] == 1)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (visited[j] != 1)
                        {
                            if (min > R[i][j])
                            {
                                min = R[i][j];
                                src = i;
                                dest = j;
                            }
                        }
                    }
                }
            }
            cout << "\nEdge from " << src << " to " << dest << " with cost:  " << min ;
            total+= min;
            visited[dest] = 1;
            count++;
        }
        cout << "\nTotal Cost: " << total << "\n";
    }
};
int main()
{
    graph g;
    g.accept();
    g.display();
    g.prims();
}

// #include <iostream>
// #define INFINITY 999
// using namespace std;
// class kruskal{
//     typedef struct graph{
//         int v1, v2, cost;
//     }GR;
//     GR G[20];
//     public:
//         int tot_edges , tot_nodes;
//         void create();
//         void Spanning_tree();
//         void get_input();
//         int minimum(int);
// };
// void kruskal::get_input(){
//     cout<<"\nEnter total number of vertices:  ";
//     cin>>tot_nodes;
//     cout<<"Enter total number of edges:  ";
//     cin>>tot_edges;
// }
// void kruskal::create(){
//     for(int k=0; k<tot_edges; k++){
//         cout<<"\nEnter edge v1:  ";
//         cin>>G[k].v1;
//         cout<<"Enter edge v2:  ";
//         cin>>G[k].v2;
//         cout<<"Enter corresponding cost: ";
//         cin>>G[k].cost;
//     }
// }
// int kruskal::minimum(int n){
//     int i,small, pos;
//     small=INFINITY;
//     pos=-1;
//     for(i=0; i<n; i++){
//         if(G[i].cost<small){
//             small=G[i].cost;
//             pos=i;
//         }
//     }
//     return pos;
// }
// void un(int i, int j, int parent[]){
//     if(i<j)
//         parent[j]=i;
//     else
//         parent[i]=j;
// }
// int find(int v2, int parent[]){
//     while(parent[v2]!=v2){
//         v2=parent[v2];
//     }
//     return v2;
// }
// void kruskal:: Spanning_tree(){
//     int count, k, v1, v2, i, j, tree[10][10], pos, parent[10];
//     int sum;
//     count=0;
//     k=0;
//     sum=0;
//     for(i=0; i<tot_nodes; i++)
//     {
//         parent[i]=i;
//     }
//     while(count<tot_nodes-1){
//         pos=minimum(tot_edges);
//         if(pos==-1)
//         {
//             break;
//         }
//         v1=G[pos].v1;
//         v2=G[pos].v2;
//         i=find(v1,parent);
//         j=find(v2,parent);
//         if(i!=j){
//             tree[k][0]=v1;
//             tree[k][1]=v2;
//             k++;
//             count++;
//             sum+=G[pos].cost;
//             un(i,j,parent);
//         }
//         G[pos].cost=INFINITY;
//     }
//     if(count==tot_nodes-1){
//         cout<<"\nSpanning tree is:  "<<endl;
//         for(i=0; i<tot_nodes-1; i++){
//             cout<<"|"<<tree[i][0];
//             cout<<" ";
//             cout<<tree[i][1]<<"|"<<endl;
//         }
//         cout<<"cost of spanning tree is: "<<sum<<endl;
//     }
//     else{
//         cout<<"There is no spanning tree"<<endl;
//     }
// }
// int main()
// {
//     kruskal obj;
//     obj.get_input();
//     obj.create();
//     obj.Spanning_tree();
//    return 0;
// }