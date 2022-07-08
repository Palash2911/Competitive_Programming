#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

class graph{
    int gr[20][20];
    int e,v;
    public:
        void input()
        {
            int s,d,cost,i,j;
            cout<<endl<<"Enter No. Of Vertices :  ";
            cin>>v;
            cout<<"Enter No. of Edges :  ";
            cin>>e;
            for(i=0;i<v;i++)
            {
                for(j=0;j<v;j++)
                {
                    gr[i][j]=0;
                }
            }

            for(i=0;i<e;i++)
            {
                cout<<endl<<"Enter Source :  ";
                cin>>s;
                cout<<"Enter Destination :  ";
                cin>>d;
                cout<<"Enter Cost of Edge :  ";
                cin>>cost;
                gr[s][d]=cost;
            }    
        }

        void displaygrid()
        {
            for(int i=0;i<v;i++)
            {
                cout<<endl;
                for(int j=0;j<v;j++)
                {
                    cout<<gr[i][j]<<"\t";
                }
            }
        }

        void djikstra(int start)
        {
            int r[20][20], mindst, next,cnt,i,j,vis[20],dist[20],from[20];
            //intialization of r matrix
            for(i=0;i<v;i++)
            {
                for(j=0;j<v;j++)
                {
                    if(gr[i][j]==0)
                    {
                        r[i][j]=9999;
                    }
                    else{
                        r[i][j]=gr[i][j];
                    }
                }
            }

            //intialization of visited, distance and from matrix
            for(i=0;i<v;i++)
            {
                vis[i]=0;
                from[i]=start;
                dist[i]=r[start][i];
            }
            dist[start]=0;

            cnt=v;
            while(cnt>0)
            {
                mindst=9999;
                for(i=0;i<v;i++)
                {
                    if((mindst > dist[i]) && vis[i]==0)
                    {
                        cout<<i<<endl;
                        mindst=dist[i];
                        next=i;
                    }
                    // cout<<dist[i]<<endl;
                }
                // cout<<endl<<next<<endl;
                vis[next]=1;
                // cout<<vis[next]<<" ";
                // cout<<mindst<<endl;
                for(i=0;i<v;i++)
                {
                    if(vis[i==0] && dist[i]>(mindst+r[next][i]))
                    {
                        dist[i]=mindst+r[next][i];
                        from[i]=next;
                    }
                }
                cnt--;
            }
            for(i=0;i<v;i++)
            {
                if(dist[i]==9999)
                {
                   cout<<endl<<"Distance of "<<i<<" from "<<start<<" is Not possible"<<endl; 
                }
                else{
                    cout<<endl<<"Distance of "<<i<<" from "<<start<<" is "<<dist[i]<<endl;
                }
                cout<<"Path "<<i;
                j=i;
                do
                {
                    j=from[j];
                    cout<<" <- "<<j;
                } while (j!=start); 
            }
        }
};
int main()
{
    int s;
    graph g;
    g.input();
    g.displaygrid();
    cout<<endl<<"\nEnter the Starting Vertex :  ";
    cin>>s;
    g.djikstra(s);
    cout<<endl;
    return 0;
}
