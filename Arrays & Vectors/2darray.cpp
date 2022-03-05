#include <iostream>
using namespace std;

int main()
{
    // Matrix search
    // int n,m;
    // cin>>n>>m;
    // int a[n][m];
    // bool ans=false;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cin>>a[i][j];
    //     }
    // }
    // int s;
    // cout<<"Search :  ";
    // cin>>s;
    //  for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //        if(a[i][j]==s)
    //        {
    //            ans=true;
    //        }
    //     }
    // } OR Follow the below code ::
    // int r=0,c=m-1;
    // while(r<n && c>=0)
    // {
    //       if(a[r][c]==s)
    //        {
    //            ans=true;
    //        }
    //        if(a[r][c] > s)
    //        {
    //            c--;
    //        }
    //        else
    //        {
    //            r++;
    //        }
    // }
    // if(ans==true)
    // {
    //     cout<<"Found element "<<endl;
    // }
    // else
    // {
    //     cout<<"Not found "<<endl;
    // }

    // Multiplication Question
    //      int n1,n2,n3;
    // cin>>n1>>n2>>n3;
    // int a[n1][n2];
    // int b[n2][n3];
    // int c[n1][n3];
    // for(int i=0;i<n1;i++)
    // {
    //     for(int j=0;j<n2;j++)
    //     {
    //         cin>>a[i][j];
    //     }
    // }
    // for(int i=0;i<n2;i++)
    // {
    //     for(int j=0;j<n3;j++)
    //     {
    //         cin>>b[i][j];
    //     }
    // }
    // for(int i=0;i<n1;i++)
    // {
    //     for(int j=0;j<n3;j++)
    //     {
    //         c[i][j]=0;
    //     }
    // }
    // for(int i=0;i<n1;i++)
    // {
    //     for(int j=0;j<n3;j++)
    //     {
    //         for(int k=0;k<n2;k++)
    //         {
    //             c[i][j]+=a[i][k]*b[k][j];
    //         }
    //     }
    // }
    //    for(int i=0;i<n1;i++)
    // {
    //     for(int j=0;j<n3;j++)
    //     {
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // transpose question
    //  int n,m;
    // cin>>n>>m;
    // int a[n][m];
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cin>>a[i][j];
    //     }
    // }

    //     cout<<"Transpose of the above matrix is : "<<endl;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j<m;j++)
    //         {
    //             int temp =a[i][j];
    //             a[i][j]=a[j][i];
    //             a[j][i]=temp;
    //         }
    //     }
    //   for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             cout<<a[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // spiral question
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int rs = 0, re = n - 1, cs = 0, ce = m - 1;
    cout << endl;

    while (rs <= re && cs <= ce)
    {
        for (int col = cs; col <= ce; col++)
        {
            cout << a[rs][col] << " ";
        }
        rs++;
        for (int row = rs; row <= re; row++)
        {
            cout << a[row][ce] << " ";
        }
        ce--;
        for (int col = ce; col >= cs; col--)
        {
            cout << a[re][col] << " ";
        }
        re--;
        for (int row = re; row >= rs; row--)
        {
            cout << a[row][cs] << " ";
        }
        cs++;
    }

    return 0;
}

