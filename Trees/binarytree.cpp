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

void preorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int search(int inorder[], int s, int e, int curr)
{
    for(int i=s;i<=e;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
Node* buildtree(int preorder[], int inorder[], int s, int e)
{
    static int idx = 0;
    if(s>e)
    {
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if(s==e)
    {
        return node;
    }
    int pos = search(inorder, s, e, curr);
    node->left = buildtree(preorder, inorder, s, pos-1);
    node->right = buildtree(preorder, inorder, pos+1, e);

    return node;
}

void inorderPrint(Node* root)//use for both postorder and preorder
{
    if(root==NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int search1(int ino[], int s, int e, int val)
{
    for(int i=s;i<=e;i++)
    {
        if(ino[i]==val)
        {
            return i;
        }
    }
    return -1;
}
Node* buildtree2(int post[], int ino[], int s, int e)
{
    static int idx=4;
    if(s>e)
    {
        return NULL;
    }
    int val =post[idx];
    idx--;
    Node* curr= new Node(val);
    if(s==e)
    {
        return curr;
    }

    int pos= search1(ino, s, e ,val);
    curr->right= buildtree2(post, ino, pos+1, e);
    curr->left= buildtree2(post, ino, s, pos-1);
    return curr;
}
int main()
{

    // NO TREE CAN BE MADE FROM POSTORDER AND PREORDER

    //     ***BUILD A BT USING PREORDER AND INORDER 
    // TRAVERSE IN PREORDER AND CHECK THE SQUENCE IN INORDER
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    // //build tree
    Node* root= buildtree(preorder, inorder, 0, 4);
    inorderPrint(root);


    //     ***BUILD A BT USING POSTORDER AND INORDER
    // int postorder[]={4,2,5,3,1};
    // int inorder[]={4,2,1,5,3};

    //build tree
    // Node* root= buildtree2(postorder, inorder, 0, 4);
    // inorderPrint(root);

    //    ***BINARY TREE TRAVERSALS***
    // struct Node* root= new Node(1);
    // root->left=new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);

    // preorder(root); cout<<endl; // preorder traversal
    // inorder(root); cout<<endl;// inorder traversal
    // postorder(root); //postorder traversal


    //   ** BT BASIC
    // struct Node* root= new Node(1);
    // root->left=new Node(2);
    // root->right=new Node(3);

    // root->left->left=new Node(4);
    // root->right->left=new Node(5);

     return 0;


    //         -------NOTES-------
    //  BINARY TREE - data here is stored herically unlike vector , array where data is stored linearly
    // nodes are levels 
    // first level-  root
    // next level -  branches and then subbranches
    // final level or end nodes - leaf 
    // branches and leaf are children nodes
    // speaciality of binary tree- only two nodes of each parent node - left child and right child

    //PROPERTIES OF BINARY TRESS: - 
    // 1. Maximum nodes at level L = 2^L;  EG - level 0 has 2^0 that is 1 node, level 1 has 2^1 nodes that is 2 nodes and so on
    // 2. Maximum nodes in a tree of height(total number of levels) H is (2^H)-1 ;  eg- if a BT has 3 levels its height is 3 and number of nodes in it are 2^3 -1 = 7
    // 3. For N nodes, minimum possible height or minimum number of levels are Log2(N+1); 
    // 4. A BT with L leaves has at least log2(N+1)+1 number of levels;

    /*
    eg - BT
        1
       / \
      2   3
     */
 
    // TRAVERSALS -

    // 1. PREORDER-- From root go to the left subtree and then go to back to the root again then traverse the right subtree
    //  eg -  first go to 1 add that to predorder
            //then go to 2 add that as it is on left then go to 4 add this. after 4 go back to 2 as 2 is already added go to now right part that is 5 similarly do it for right subtree that is 3 wala
            // thus PREDORDER= 1,2,4,5,3,6,7
    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */

   // 2. INORDER- Left subtree to Root then to Right subtree
   // eg-  from 1 go to its left subtree 2 now go to 2's    left subtree that is 4 ,as 4 has no further subtree add 4 to the row. now go to 2 as it was the root add that now go to 5 which is right subtree. now go to 2 and go back to 1 as it is the root add that in the order

   //thus  INORDER- 4,2,5,1,6,3,7

    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */

   // 3. POSTORDER - Left subtree to Right subtree to Root
   // eg - from 1 go to its left subtree 2 then goto 2's left subtree that is 4 add 4 to the order. Now go to right subtree of 2 i.e. 5 add 5. now go to the root that is 2 add 2 to it. Now go to 3 and repeat the same process and at end add 1 the final root

   // thus POSTORDER- 4,5,2,6,7,3,1

   /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */
}