// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    public:
    Node(int val)
    {
        data= val;
        left=NULL;
        right=NULL;
    }
};

void printlevelorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        if(node!= NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);    
        }
    }
}

/*
         1
        / \
       2   3
      / \ / \
     4  5 6  7
*/

int sumatk(Node* root, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int lev=0;
    int sum=0;
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        if(node!=NULL)
        {
            if(lev==k)
            {
                sum+=node->data;
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
            lev++;
        }
    }
    return sum;
}

int countnode(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countnode(root->left) + countnode(root->right) + 1;
}

int sumnode(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sumnode(root->left) + sumnode(root->right) + root->data;
}

int heightbt(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(heightbt(root->left), heightbt(root->right)) + 1;
}

int caldia(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=heightbt(root->left);
    int rheight=heightbt(root->right);
    int currd= lheight+rheight+1;

    int ldia=caldia(root->left);
    int rdia=caldia(root->right);

    return max(currd, max(ldia,rdia));
}

int calcdia1(Node* root, int* hei)
{
    if(root==NULL)
    {
        *hei = 0;
        return 0;
    }
    int lh=0,rh=0;
    int ldia=calcdia1(root->left, &lh);
    int rdia=calcdia1(root->right, &rh);
    int currdia=lh+rh+1;
    *hei=max(lh,rh)+1;

    return max(currdia, max(ldia,rdia));
}

void sumreplace(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);

    if(root->left!=NULL)
    {
        root->data+=root->left->data;
    }
    if(root->right!=NULL)
    {
        root->data+=root->right->data;
    }
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

bool isbalance(Node* root) //method 1
{
    if(root==NULL)
    {
        return true;
    }
    if(isbalance(root->left)==false)
    {
        return false;
    }
    if(isbalance(root->right)==false)
    {
        return false;
    }
    int lh=heightbt(root->left);// checking height of each subtree or u can say depth of the subtree. like in our eg the depth of our subtree is 3 as it has both side equal nodes;
   int rh=heightbt(root->right);
    if(abs(lh-rh)<=1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool isbal(Node* root, int* height) // - Method 2 - less time complexiy -- using pointer in this
{
    if(root==NULL)
    {
        return true;
    }
    int lh=0, rh=0;
    if(isbal(root->left, &lh)==false)
    {
        return false;
    }
    if(isbal(root->right, &rh)==false)
    {
        return false;
    }

    *height= max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    //  *** LEVEL ORDER TRAVERSAL
    // here we traverse the bt level wise
    // eg- LEVELORDER- 1- level 0   2,3- level 1   4,5,6,7- level 2
    // this can be achieved by QUEUE 

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(8);
    // root->left->left->right=new Node(5); // -- for checking balance or unbalance 
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // printlevelorder(root);v

    // Q1. Find the sum of k nodes.
    // cout<<sumatk(root, 2);

    // Q2. Count all the nodes in a BT.
    // cout<<countnode(root)<<endl;

    // Q3. Sum of all nodes in BT.
    // cout<<sumnode(root)<<endl;

    //  ***HEIGHT OF THE BT
    // cout<<heightbt(root);

    // Q4. Diameter of a BT. - Diameter - Number of nodes in the longest path between any 2 leaves;
     cout<<caldia(root)<<endl; //-- method1
     int height=0;
    //  cout<<calcdia1(root,&height)<<endl; // -- method 2 -- better approach

    // Q5. Sum Replacement -- Replace the value of each node with the sum of all subtree nodes and itself
    // preorder(root);
    // cout<<endl;
    // sumreplace(root);
    // preorder(root);

    // Q6. Balanced height tree. --  for each node, the difference between the heights of the left subtree & right subtree is <=1
    /*
        eg- balanced tree
        o
       / \
      o   o
     /    
    o
        eg- unbalanced tree
        o
       / \
      o   o
     /    
    o
     \
      o
    */
    //  int height=0;
    //  if(/*isbalance(root)*/ isbal(root, &height))
    //  {
    //      cout<<"Balanced Tree "<<endl;
    //  }
    //  else
    //  {
    //      cout<<"UnBalanced Tree "<<endl;
    //  }

    return 0;
}

