#include <iostream>
#include <vector>
#include <bits/stdc++.h> //use this header file to use sort function in vectors
using namespace std;

//        VECTORS
// int main()
// {
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(42);
//     v.push_back(0);
//     v.push_back(33);  //push back ends 3 after 2 which adds after 1
 

//     for(int i=0;i<v.size();i++)  //method one to print elements in a vector
//     {
//         cout<<v[i]<<endl;
//         // output 1 2 3
//     }

//     vector<int>::iterator it;  //method 2 to print elements in a vector, v.begin-beginning of vectro, v.end- end of vector, it is a pointer therefore *it 
//     for(it=v.begin();it!=v.end();it++)
//     {
//         cout<<*it<<endl;
//     }

//     for(auto element:v) //method 3 element is not a pointer here it is a element of an vector; auto itself finds the datatype of the vector
//     {
//         cout<<element<<endl;
//     }

//     // v.pop_back(); //end element pops out of the vector, eg-first 3 will pop

//     vector<int> v2 (3,50);  // this means 50 will be added to the vector 3 times, used if same elements present 

//     swap(v,v2); //as the name suggest
//     for(auto element:v)
//     {
//         cout<<element<<endl; //3 is popped out and here the elements are replaced by v2
//     }
//     for(auto element:v2)
//     {
//         cout<<element<<endl;
//     }

//     sort(v2.begin(), v2.end());
//     return 0;
// }

//   PAIR
bool myCompare(pair<int, int> p1, pair <int, int> p2)
{
    return p1.first<p2.first; 
}
int main()
{
    pair <int,char> p; //can specify any datatype 
    p.first = 3; //first element is int and second is a character
    p.second = 'f';
    
    // Q. write the array in its shortest form.
    int arr[]={10,16,7,14,5,3,12,9};
    vector< pair<int, int> > v;
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0]));i++)
    {
        v.push_back(make_pair(arr[i],i));
    }
    
    sort(v.begin(), v.end(), myCompare);
    for(int i=0;i<v.size();i++)
    {
        arr[v[i].second]=i;
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}