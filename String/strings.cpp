#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{   
    // most number of character in a string
    string s= "Palash is the best";
    int fr[26];
    for(int i=0; i<26; i++)
    {
        fr[i]=0;
    }
    for(int i=0; i<s.size(); i++)
    {
        fr[s[i]-'a']++;
    }
    char ans='a';
    int maxf=0;

    for(int i=0;i<26;i++)
    {
        if(fr[i] > maxf)
        {
            maxf=fr[i];
            ans=i+'a';
        }
    }
    cout<<maxf<<"   "<<ans<<endl;

    // Form the biggest number from numeric string
    // string s= "28410985";
    // sort(s.begin(), s.end(), greater<int>()); to sort in decreasing order write greater
    // cout<<s<<endl;

    // uppercase and lower case
    // string st = "FHASHFLAHFOIAHASFSV";
    // for(int i=0;i<st.size ();i++)
    // {
    //     if(st[i] <= 90)
    //     {
    //         st[i]=st[i]+32;
    //     }
    // }
    // transform(st.begin(), st.end(), st.begin(), ::toupper);
    // transform(st.begin(), st.end(), st.begin(), ::tolower); second begin is from where you want to start the function 
    // cout<<st<<endl;

    // string str;
    // cin>>str;
    // cout<<str;

    // string str1(5, 'p');
    // cout<<str1<<endl;

    // string str = "PalashRambhia";
    // cout<<str<<endl;
     
    //  string str;
    //  getline(cin, str);  //use this for spaces or for a sentence.
    //  cout<<str<<endl;

     // append means jodna 
    // string s1="Fam";
    // string s2="ily";

    // s1.append(s2);
    // // s1=s1 + s2;
    // cout<<s1<<endl; // same as append 

    // cout<< s1[1]<<endl; same as array if u want to output

    // abc.clear() this function clears the whole string

    // string s1="abc";
    // string s2="xyz";
    // string s2="abc";
    // equal values =0, larger string = postive value
    // if(s2.compare(s1)==0)
    // {
    //     cout<<"Equal"<<endl;
    // }

    // string s1 = "nincompoop";
    // cout<<s1<<endl;
    // s1.clear();

    // if(!s1.empty())
    // {
    //     cout<<" Not Empty"<<endl;
    // }

    // s1.erase(3, 3); // first 3 is from which index next 3 is how many characters want to delete

    // cout<<s1<<endl;
    // cout<<s1.find("com")<<endl; gives the index from where the string starts 

    // string s1 = "nincompoop";
    // s1.insert(2, "lol");
    // cout<<s1<<endl;

    // cout<<s1.size()<<endl;
    // cout<<s1.length()<<endl;

    // for(int i=0; i<s1.length();i++)
    // {
    //     cout<<s1[i]<<endl;
    // }

    // string s1 = "nincompoop";
    // string s = s1.substr(6, 4); used for displaying substring. 6 is index number and 4 is number of character from index 
    // cout<<s<<endl;

    // string s2 = "786";

    // int x = stoi(s2);
    // cout<<x+2<<endl; from string to number

    // int x=786;
    // cout<< to_string(x) + "2" + 2 append karega<<endl;

    // string s1 = "hsoifhasoifhsfbasifhaoa";
    // sort(s1.begin(), s1.end()); //begin gives starting iterator, and end gives last iterator
    // cout<<s1<<endl;
    return 0;
}
