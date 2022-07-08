#include <iostream>
using namespace std;

typedef struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;

    public:
    tnode(int val)
    {
        data= val;
        left=NULL;
        right=NULL;
    }
} tnode;

class tree
{
    tnode *t;

public:
    tree()
    {
        t = NULL;
    }

    tnode *insert(tnode* root, int val)
    {
        if(root==NULL)
        {
            return new tnode(val);
        }
        if(val< root->data)
        {
            root->left=insert(root->left, val);
        }
        else{
        // val > root->data
            root->right=insert(root->right, val);
        }
        return root;
    }

    void inorder(tnode *t)
    {
        if (t != NULL)
        {
            inorder(t->left);
            cout << "\t" << t->data;
            inorder(t->right);
        }
    }
    
    tnode *search(tnode* root,int val)
    {
         if(root==NULL){
        return NULL;
        }
        if(val>root->data){
        return search(root->right, val);
        }
        else if(val<root->data){
        return search(root->left, val);
        }
        else{
        return root;
        }
    }

    tnode *find_min(tnode *r)
    {
        while (r->left != NULL)
        {
            r = r->left;
        }
        return r;
    }
    tnode *find_max(tnode *r)
    {
        while (r->right != NULL)
        {
            r = r->right;
        }
        return r;
    }

    tnode* inorderSucc(tnode* root){
        tnode* curr=root;
        while(curr && curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    tnode *delet(tnode* root, int key)
    {
        if(key<root->data){
            root->left=delet(root->left, key);
        }
        else if(key>root->data){
            root->right=delet(root->right,key);
        }
        //if key==root->data
        else{
            if(root->left==NULL){
                tnode* temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                tnode* temp=root->left;
                free(root);
                return temp;
            }
            tnode* temp=inorderSucc(root->right);
            root->data=temp->data;
            root->right=delet(root->right, temp->data);
        }
        return root;
    }
    
    void mirror(tnode *root)
    {
        if(root==NULL){
            return ;
        }
        else{
            mirror(root->left);
            mirror(root->right);
            swap(root->left,root->right);       
        } 
    }

    int height(tnode *root)
    {
          if(root==NULL){
            return 0;
        }
    int lheight=height(root->left);
    int rheight=height(root->right);
    return max(lheight,rheight)+1;
    }
    void leaf(tnode *T)
    {
        if (T == NULL)
            return;
        if (T->left == NULL && T->right == NULL)
        {
            cout << "\t" << T->data;
        }
        leaf(T->left);
        leaf(T->right);
    }

    tnode *copy(tnode *root)
    {
    tnode *temp=NULL;
    if(root!=NULL){
        temp=new tnode(root->data);
        temp->left=copy(root->left);
        temp->right=copy(root->right);
    }
    return temp;
}
    
};

int main()
{
    int ch, key, cnt;
    tnode *root=NULL, *result, *rt;
    tree t;
    do
    {
        cout<<endl<<endl<<"******Main Menu******"<<endl;
        cout<< "1. Insert BST"<<endl;
        cout<< "2. Display BST"<<endl;
        cout<< "3. Search in BST"<<endl;
        cout<< "4. Delete node in BST"<<endl;
        cout<< "5. Mirror image of BST"<<endl;
        cout<< "6. Create copy of BST"<<endl;
        cout<< "7. Find Height of BST"<<endl;
        cout<< "8. Minimum node in BST"<<endl;
        cout<< "9. Maximum node in BST"<<endl;
        cout<< "10. Display Leaf nodes "<<endl;
        cout<< "11. Exit  "<<endl;
        cout<<"\nEnter your choice :  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout <<endl<< "Enter the number to insert in BST :  ";
            cin >> key;
            root = t.insert(root, key);
            break;
        case 2:
            cout <<endl<< "Binary tree :  ";
            t.inorder(root);
            break;
        case 3:
            cout<<endl<<"Enter the node to search :  ";
            cin >> key;
            result = t.search(root, key);
            if (result == NULL)
            {
                cout <<endl<< "Element " << key << " not present" << endl;
            }
            else
            {
                cout<<endl << "Element " << key << " is present" << endl;
            }
            break;
        case 4:
            cout <<endl<< "Enter the node to delete :  ";
            cin >> key;
            result = t.delet(root, key);
            root = result;
            cout <<endl<< "Element deleted successfully!!" << endl;
            break;
        case 5:
            t.mirror(root);
            cout<<endl << "Mirror image of the BST is :  ";
            t.inorder(root);
            break;
        case 6:
            root=t.copy(root);
            cout<<endl<<"Tree Copied :  ";
            t.inorder(root);
            break;
        case 7:
            cnt = t.height(root);
            cout <<endl<< "Height of tree :  " << cnt;
            break;
        case 8:
            result = t.find_min(root);
            cout <<endl<< "Minimum node is :  " << result->data << endl;
            break;
        case 9:
            result = t.find_max(root);
            cout <<endl<< " Maximum node is :  " << result->data << endl;
            break;
        case 10:
            cout <<endl<< "Leaf Nodes are  :  ";
            t.leaf(root);
            break;
        case 11: cout<<endl<<"Thank You "<<endl;
        break;
        default:
            cout << "\nInvalid choice !!"<< endl;
            break;
        }
    } while (ch != 11);
}