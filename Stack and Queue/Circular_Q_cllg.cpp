#include <bits/stdc++.h>
using namespace std;

#define floop(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vpi vector<pii>

int cq[5];
int fr=-1, re=1, n=5;

void insertcq(int val){
    if((fr==0 && re==n-1) || (fr==re+1))
    {
        cout<<"Circular Queue Is Full "<<endl;
        return;
    }
    if(fr==-1){
        fr=0;
        re=0;
    }
    else{
        if(re==n-1){
            re=0;
        }
        else{
            re++;
        }
    }
    cq[re]=val;
}

void deletec(){
    if(fr==-1){
        cout<<"Queue is Empty "<<endl;
        return;
    }
    cout<<"Element deleted from queue is : "<<cq[fr]<<endl;
    if(fr==re){
        fr=-1;
        re=-1;
    }
    else{
        if(fr==n-1){
            fr=0;
        }
        else{
            fr++;
        }
    }
}

void dispc(){
    if(fr==-1){
        cout<<"Queue is Empty "<<endl;
        return;
    }
    int temp=fr;
    if(temp<=re){
        while(temp<=re){
        cout<<cq[temp]<<" ";
        temp++;
        }
        cout<<endl;
    }
    else{
        while(temp<=n-1){
            cout<<cq[temp]<<" ";
            temp++;
        }
        temp=0;
        while(temp<=re){
            cout<<cq[temp]<<" ";
            temp++;
        }
        cout<<endl;
    }
}

void displrc(){
    if(fr==-1){
        cout<<"Queue is Empty "<<endl;
        return;
    }
    if(fr<=re){
        int temp=re;
        while(temp>=fr){
        cout<<cq[temp]<<" ";
        temp--;
        }
        cout<<endl;
    }
    else{
        int temp=re;
        while(temp>=0){
            cout<<cq[temp]<<" ";
            temp--;
        }
        temp=n-1;
        while(temp>=fr){
            cout<<cq[temp]<<" ";
            temp--;
        }
        cout<<endl;
    } 
}

int main()
{
  int ch;
  do
  {
        cout<<endl<<"1. Insert in CQueue"<<endl;
        cout<<"2. Delete in CQueue"<<endl;
        cout<<"3. Display Forward"<<endl;
        cout<<"4. Display Reverse"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>ch;
    switch (ch)
    {
        case 1: int val;
            cout<<endl<<"Enter the Value : ";
            cin>>val;
            insertcq(val);
            break;
        case 2: deletec();
        break;
        case 3: dispc();
        break;
        case 4: displrc();
        break;
        case 5: cout<<"\n\nThank You !!"<<endl;
        break;
        default: cout<<"Wrong Choice !!\n"<<endl;
        break;
    }
  } while (ch!=5);
  
  return 0;
}