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


void rightview(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size(); 
        cout<<n<<"*"<<endl;
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==n-1)
            {
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftview(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

      while(!q.empty())
    {
        int n=q.size(); 
        for(int i=1;i<=n;i++)
        {
            Node* curr=q.front();
            q.pop();

            if(i==1)
            {
                cout<<curr->data<<" ";
            }
             if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

Node* LCA(Node* root, int n1, int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data == n2)
    {
        return root; // here the lca or common root of both n1 and n2 is returned
    }
    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right, n1,n2);
    
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    if(left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right, n1,n2);
}
int finddist(Node* root, int k, int dist)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==k)
    {
        return dist;
    }
    
    int left=finddist(root->left,k,dist+1);
    if(left!=-1)
    {
        return left;
    }
    return finddist(root->right,k,dist+1);
}
int distbtwnodes(Node* root, int n1, int n2)
{
    Node* lca=LCA(root,n1,n2);

    int d1=finddist(lca,n1,0);
    int d2=finddist(lca,n2,0);

    return d1+d2;
}

void flatten(Node* root)
{
    if(root==NULL || root->left==NULL && root->right==NULL)
    {
        return;
    }
    if(root->left!=NULL)
    {
        flatten(root->left);
        Node* temp= root->right;
        root->right=root->left;
        root->left=NULL;
        // cout<<temp->data<<" "<<root->right->data<<endl;
        Node* t=root->right;
        while(t->right!=NULL)
        {
            t=t->right;
        }

        t->right=temp;
    }

    flatten(root->right);
}

void inorderprint(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

//case 1- to find the nodes below or in the subtree of the target nodes
void printsubtreenodes(Node* root, int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }

    printsubtreenodes(root->left, k-1);
    printsubtreenodes(root->right, k-1);
}
//Case 2- to find the nodes above or in subtree of the ancestor of the target node
int printnodesatk(Node* root, Node* target, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        printsubtreenodes(root,k);
        return 0;
    }
    
    int dl=printnodesatk(root->left,target, k); // for left subtree of ancestor
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->right, k-dl-2);
        }
        return 1+dl;
    }
    int dr=printnodesatk(root->right,target, k); // for right subtree of ancestor
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->left, k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

bool getpath(Node* root, int key, vector<int> &path)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data==key)
    {
        return true;
    }

    if(getpath(root->left, key, path) || getpath(root->right ,key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int LCA1OG(Node* root, int n1, int n2) // OG function for LCA
{
    vector<int> p1;
    vector<int> p2;
    //p1 and p2 are the paths to the nodes n1 and n2 from the root (starting point)
    
    if(!getpath(root, n1, p1) || !getpath(root, n2, p2))
    {
        return -1;
    }
    
    int pc;
    for(pc=0;pc<p1.size() && p2.size();pc++)
    {
        if(p1[pc]!=p2[pc])
        {
            break;
        }
    }

    return p1[pc-1];
}

Node* LCA2OG(Node* root,int n1, int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    Node* leftlca= LCA2OG(root->left, n2, n1);
    Node* rightlca= LCA2OG(root->right, n2, n1);

    if(leftlca && rightlca)
    {
        return root;
    }
    if(leftlca!=NULL)
    {
        return leftlca;
    }
    return rightlca;

}
int maxsumpathutil(Node* root, int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    int left= maxsumpathutil(root->left, ans);
    int right= maxsumpathutil(root->right, ans);
    // cout<<left<<" "<<right<<" "<<ans<<" "<<root->data<<endl;
    int nodemax= max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    // cout<<nodemax<<endl;
    ans=max(ans, nodemax);

    int singlepathsum = max(root->data, max(root->data +right , root->data+left));
    return singlepathsum;
}
int maxsumpath(Node* root)
{
    int ans= INT_MIN;
    maxsumpathutil(root, ans);
    return ans;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // root->right->left->right=new Node(8);
    // Q1. Right View of a BT. -- display all right nodes in the bt --  it will not print the right node of the left node of the og root thus 5 will not print but 8 will
    // rightview(root);
    
    // root->left->right->left=new Node(9);
    //Q2. Left View
    // leftview(root);

    // Q3. Find distance between two nodes in a BT. --- distance between two nodes is the minimum number of edges to be traversed to reach one node from another.
    /*
    eg- 
            1
           / \
          2   3
         / \ / \
        4  5 6  7 - SUPPOSE n1 is 6 and n2 is 7 than the lines are egdes so, 2 lines thus distance is 2
    */
     
     // SOLUTION-  1. Find the LCA - lowest common ancestor
                // 2.Find the distance of n1(d1)and n2(d2) from LCA.  3. return (d1+d2)

    //  Node* root2=new Node(1);
    // root2->left=new Node(2);
    // root2->right=new Node(3);
    // root2->left->left=new Node(4);
    // root2->right->right=new Node(5);

    // cout<<distbtwnodes(root2,4,5)<<endl;

    // Q4. Flatten a BT. -- flatten the BT in form of a Linked list-- we can't create a new ll and store the BT in it , we have to join and reattach the nodes of BT to form the LL -- Left of each node will become NULL and right should contain next node in preorder
    
    //SOLUTION - 1. Recursively, flatten the left and right subtree.
    // 2. Store the left tail and right tail.  - last node on both left and right is the tail
    // 3. Store right subtree in 'temp' and make left subtree as right subtree.
    // 4. Join the right suubtree with left tail
    // 5. Return right tail

    // flatten(root);
    // inorderprint(root);
    // cout<<endl;

    // Q5. Print all Nodes at distance K.
    //eg- if root is 1 ,target node is 5,and dist is 3. so go below the target till distance 3 and take those in answer and go above (to the ancestor), till distance 3 and take those also in the answer
     Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);

    printnodesatk(root2, root2->left,2);
    cout<<endl;

    // Q6. Lowest Common Ancestor -- as the name suggest LCA is the first common node for any given nodes
    // root->right->left=new Node(5);
    // root->right->right=new Node(6);
    // root->right->left->left=new Node(7);

    // if(LCA1OG(root, 4, 8)==-1) //method 1 - here return value is a int
    // {
    //     cout<<"LCA doesn't exist "<<endl;
    // }
    // else{
    //     cout<<"LCA : "<<LCA1OG(root, 4, 6)<<endl;
    // }

    // Node* lca=LCA2OG(root, 7, 6);
    // if(lca == NULL) //method 2 - here return value is a node
    // {
    //     cout<<"LCA doesn't exist "<<endl;
    // }
    // else{
    //     cout<<"LCA : "<<lca->data<<endl;
    // }

    // Q7. Maximum Path Sum --  
    // 1. Node val  
    // 2. Max path through left child + node val  
    // 3. Max path through right child + node val   
    // 4. Max path through left child+ Max path through right child + node val
    root->right->right=new Node(5);
    
    // int n=0;
    cout<<maxsumpath(root)<<endl;
    // cout<<maxsumpathutil(root, n)<<endl;

    return 0;
}