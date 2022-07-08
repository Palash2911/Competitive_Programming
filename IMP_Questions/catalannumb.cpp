#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int catalan(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int res=0;
    for(int i =0;i<=n-1;i++)
    {
        res+=catalan(i)*catalan(n-i-1);
    }

    return res;
}

vector<Node*>constructtree(int start, int end) 
{
    vector<Node*> tree;

    if(start>end)
    {
        tree.push_back(NULL);
        return tree;
    }
    for(int i=start;i<=end;i++)
    {
        vector<Node*> leftsubtr=constructtree(start, i-1);
        vector<Node*> rightsubtr=constructtree(i+1, end);

        for(int j=0;j<leftsubtr.size();j++)
        {
            Node* lefti= leftsubtr[j];
            for(int k=0;k<rightsubtr.size();k++)
            {
                Node* righti= rightsubtr[k];
                Node* node= new Node(i);
                node->left= lefti;
                node->right= righti;
                tree.push_back(node);
            }
        }
    }

    return tree;
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
        // for(int i=0;i<5;i++)
        // {
        //     cout<<catalan(i)<<" ";
        // }
        // cout<<endl;

        // Q1. Possible BST's
        vector<Node*> totaltree= constructtree(1,3);
        for(int i=0;i<totaltree.size();i++)
        {
            cout<<(i+1)<<" : ";
            preorder(totaltree[i]);
            cout<<endl;
            // output is all the BST which is formed
        }
        
        return 0;
    /* 
        Catalan Numbers -  they are a sequence of natural numbers that occur in various counting problems, often involving recursively defined objects.

        Their closed form is in terms of binomial coefficients. 
        Cn = (1/n+1)Cn^2n = ∑ Ci*Cn-i  (i=0 to n-1)
                                | - imp

        C0 = 1, C1= 1, C2= C0*C1 + C1*C0 = 2
        C3= C0*C2 + C1*C1 + C2*C0 = 5

        APPLICATIONS OF CATALAN NUM - 
        1. Possible BST's
        2. Paranthesis combinations
        3. Possible forests
        4. Ways of triangulations
        5. Possible paths in matrix
        6. Dividing a circle using N chords
        7. Dych words of given length , etc.
    */
}