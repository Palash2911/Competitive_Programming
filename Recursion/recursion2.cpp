#include <iostream>
using namespace std;
void permu(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permu(ros, ans + ch);
    }
}
int cp(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += cp(s + i, e);
    }
    return count;
}
int maze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    return maze(n, i + 1, j) + maze(n, i, j + 1);
}
int main()
{
    // Q1. Print all possible permutations of a string
    // permu("ABC", "");

    // Q2. Board game type.
    // int s,e;
    // cin>>s>>e;
    // cout<<cp(s, e)<<endl;

    // Q3. paths in maze.
    cout << maze(3,0,0) << endl;

    return 0;
}