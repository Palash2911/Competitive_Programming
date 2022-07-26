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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};

Info largestbst(Node* root)
{
    if(root==NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftinfo= largestbst(root->left);
    Info rightinfo = largestbst(root->right);

    Info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);

    if(leftinfo.isbst && rightinfo.isbst && leftinfo.max< root->data && rightinfo.min > root->data)
    {
        curr.min = min(leftinfo.min, min(rightinfo.min, root->data));
        curr.max= max(rightinfo.max, max(leftinfo.max, root->data));

        curr.ans= curr.size;
        curr.isbst =true;

        return curr;
    }

    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isbst= false;
    return curr;
}

Node* insertbst(Node* root, int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val< root->data)
    {
        root->left=insertbst(root->left, val);
    }
    else{
        // val > root->data
        root->right=insertbst(root->right, val);
    }
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* searchinbst(Node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    // data>key
    if(root->data > key)
    {
        return searchinbst(root->left, key);
    }
    // data< key
    return searchinbst(root->right, key);
}

Node* inodersucc(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
Node* deleteinbst(Node* root, int del)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(del < root->data)
    {
        root->left=deleteinbst(root->left, del);
    }
    else if(del > root->data)
    {
        root->right=deleteinbst(root->right, del);
    }
    else
    {
        if(root->left==NULL)
        {
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        //case 3
        Node* temp = inodersucc(root->right);
        root->data= temp->data;
        root->right= deleteinbst(root->right, temp->data);
    }
    return root;
}

Node* constructbst(int preorder[], int* preoderidx, int key, int min, int max, int n)
{
    if(*preoderidx >= n)
    {
        return NULL;
    }
    Node* root=NULL;
    if(key > min && key < max)
    {
        root= new Node(key);
        *preoderidx= *preoderidx+1;

        if(*preoderidx < n)
        {
            root->left=constructbst(preorder, preoderidx, preorder[*preoderidx], min, key, n);
        }
        if(*preoderidx < n)
        {
            root->right=constructbst(preorder, preoderidx, preorder[*preoderidx], key, max, n);
        }
    }
    return root;
}
void printpreoder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpreoder(root->left);
    printpreoder(root->right);
}

bool checkbst(Node* root, Node* min=NULL, Node* max=NULL)
{
    if(root==NULL)
    {
        return true;
    }
    if(min !=NULL && root->data<=min->data)
    {
        return false;
    }
    if(max!=NULL && root->data>=max->data)
    {
        return false;
    }

    bool leftvalid=checkbst(root->left, min, root);
    bool rightvalid=checkbst(root->right, root, max);

    return leftvalid and rightvalid;
}

Node* sortedarrtobst(int arr[], int start, int end)
{
    int mid = (start+end)/2;
     if(start>end)
    {
        return NULL;
    }
    Node* root= new Node(arr[mid]);
    
    root->left=sortedarrtobst(arr, start, mid-1);
    root->right=sortedarrtobst(arr, mid+1, end);

    return root;
}

bool checkidenticalbst(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else{
        bool cond1= root1->data == root2->data;
        bool leftcheck= checkidenticalbst(root1->left, root2->left);
        bool rightcheck= checkidenticalbst(root1->right, root2->right);
        if(cond1 && leftcheck && rightcheck)
         {
            return true;
         }
        }
    return false;
}

void calcpointer(Node* root, Node** first, Node** mid, Node* *last, Node** prev)
{
    if(root==NULL)
    {
        return;
    }

    calcpointer(root->left, first, mid, last, prev);
    if(*prev && root->data < (*prev)->data)
    {
        if(!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcpointer(root->right, first, mid, last, prev);
}
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void restoreBST(Node* root)
{
    Node* first, *mid, *last, *prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;

    calcpointer(root, &first, &mid, &last, &prev);
    //Case 1
    if(first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if(first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

int main()
{
  
   //Q1. Binary Search Tree - special tree.- fast insertion and deletion - time complexity- O(logN)

   /*      RULES
   1. The left subtree of a node contains only nodes with keys lesser than the node's key.

   2. The right subtree of a node contains only nodes with greater than the nodes key

   3. The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.

   eg-      3
           / \
          2   7
         /   / \
        1   5   8
           / \
          4   6
   */

    // *****BUILD a BST from an array
    // Node* root1=NULL;
    // root1=insertbst(root1, 5);
    // insertbst(root1, 1);
    // insertbst(root1, 3);
    // insertbst(root1, 4);
    // insertbst(root1, 2);
    // insertbst(root1, 7);

    // print inorder - inorder of BST gives the a perfectly sorted BT
    
    // inorder(root1);
    // cout<<endl;

    // Q2. Search and Delete in BST --
 
    // Search - In BT time complexity is O(n) but for BST it is O(logn) -- explanition in BST - if value is greater you discard the right subtree and if lesser than the node discard the left subtree -- thus for each level the nodes become n/2, n/4, n/8, .. thus node=n and height = h   
    // 1+2+2^2+.. 2^h-1=n    thus h=logn 
    
    // Node* l=searchinbst(root1, 2);
    // if(l==NULL)
    // {
    //     cout<<"Key Doesn't exist "<<endl;
    // }
    // else{
    //     cout<<"Key Found : "<<l->data<<endl;  // output of l is optional
    // }

    //Delete - after you delete a node make sure the rules of BST are maintained.
    /*          ***Cases***
        Case 1: Node is leaf - that is an end node - directly delete no special thing

        Case 2: Node has only one child - Replace the node with child and delete the node 

        Case 3: Node has two children - 1. Find the Inorder successor of the node, as we know that in inorder the nodes in BST are printed in ascending order.   2. Replace node with Inorder succesor  3. Delete the Node

    */
    //   inorder(root1);
    //   cout<<endl;
    //   root1=deleteinbst(root1, 4);
    //   inorder(root1);
    //   cout<<endl;

    // Q3. Build BST from preorder
    // int preorder[] = {10, 2, 1, 13, 11};
    // int n = 5;
    // int preorderidx = 0;
    // Node* root = constructbst(preorder, &preorderidx, preorder[0], INT_MIN, INT_MAX, n);
    // printpreoder(root);
    

    // Q4. Check if BST exist in a given BT 

    /*
        Approach 1- Max of left subtree and min of right subtree and compare them

        Approach 2- Max allowed and Min allowed - traverse only once    -     Node (min, max)
                            /          \
                    left(min, node)   right(node, max)
    */
    //  Node* root= new Node(1);
    //  root->left= new Node(2);         - Invalid
    //  root->right= new Node(3);

    //  Node* root= new Node(5);
    // root->left= new Node(2);             - Valid
    // root->right= new Node(8);

    // if(checkbst(root, NULL, NULL))
    // {
    //     cout<<"Valid BST "<<endl;
    // }
    // else
    // {
    //     cout<<"InValid BST  "<<endl;
    // }


    // Q5. Sorted array to balanced BST. - balanced BST is basically where height of each level of BST is same for both subtree

    /* 
        Strategy - 
        1. Make Middle element the root

        2. Recursively, do the same for subtree
                a. Start to mid-1 for Left subtree
                b. mid + 1 to end for right subtree
     */

    // int arr[]={10,20,30,40,50};
    // Node* root= sortedarrtobst(arr, 0, 4);
    // printpreoder(root);
    // cout<<endl;

    // Q6. Are BST ideentical.
    /* 
        Problem - Given 2 root nodes of 2 BST, print if the BST's are identical or not.
        Identical BST - are structurally identical and have equal values for the nodes in the structure.

        Strategy : 
        1. If both are empty, return true
        2. if both are non empty -
            a. check that the data at nodes is equal
            b. check if left subtree are same
            c. Check if right subtree are same
        3. if (a,b,c) are true , return true or return false
     */

    //    Node* root1= new Node(3);        
    //     root1->right= new Node(4);
    //     root1->right->right=new Node(5);
    //     root1->right->left=new Node(2);

    //    Node* root2= new Node(3);        
    //     root2->right= new Node(4);
    //     root2->right->right=new Node(6);
    //     root2->right->left=new Node(2);

    //     if(checkidenticalbst(root1, root2))
    //     {
    //         cout<<"Identical BST "<<endl;
    //     }
    //     else
    //     {
    //         cout<<"Non-Identical BST "<<endl;
    //     }

    // Q7. Largest BST in a binary tree.
    /* 
       Problem - return thr size of the largest BST in a BT
       
       Stragtegy - For each node store the following. 
       1. min in subtree
       2. max in subtree
       3. subtree size
       4. size of largest BST
       5. isbst

       Recursively, treaverse in a bottom-up manner and find out the size of the largest BST;
    */

        // Node* root = new Node(15);
        // root->left= new Node(20);
        // root->right= new Node(30);
        // root->left->left= new Node(5);

        // cout<<"Largest BST in BT : "<<largestbst(root).ans<<endl;

    // Q8. RECOVER BST - 2 nodes of a BST are swapped. Our task is to restore the BST

    /* 
        Strategy - 1. Inorder of a Bst is sorted - 2 elements in a sorted array are swapped

        Case 1: Swapped elements are not adjacent to each other
        Case 2: Swapped elements are adjacent to each other 

        eg- {1,8,3,4,5,6,7,2}

        Maintain 3 pointers- First, mid and last
        First : previous node where 1st number < previous[8]
        Mid : number where 1st number < previous[3]
        Last : 2nd node where number < previous[2]
        For case 1 : Swap First with Last

        For case 2 : First - previous node where 1st number < previous[4]
        Mid : number where 1st number < previous[3]
        Last : NULL 
        Swap First and Mid

                6
               / \
              3   9
             / \   \
            1   4  13
     */

    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(9);
    root->left->left = new Node(1);
    root->left->right= new Node(3);
    root->right->right= new Node(13);

    inorder(root);
    cout<<endl;
    restoreBST(root);
    inorder(root);
    cout<<endl;
      return 0;
}