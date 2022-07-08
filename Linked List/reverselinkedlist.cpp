#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertattail(node* &head, int val) //head by refernce because we want to change permanently
{
    node* n=new node(val);

    if(head==NULL)
    {
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reversell(node* &head)
{
    node* prevptr=NULL;
    node* curr=head;
    node* nextptr;

    while(curr!=NULL)
    {
        nextptr=curr->next;
        curr->next=prevptr;

        prevptr=curr;
        curr=nextptr;
    }

return prevptr;
}
// method 2 using recursion
node* recurever(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* newhead=recurever(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}
node* reversek(node* &head,int k)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next=reversek(nextptr, k);
    }
    return prevptr;
}

int main()
{
    // Q1.Normal Reverse;
//    node* head=NULL;
//   insertattail(head,1);
//   insertattail(head,2);
//   insertattail(head,3);
//   insertattail(head,4);
//     display(head);
    // node* newhead=recurever(head);
//     display(newhead);

// Q2. Reverse K nodes.
node* head=NULL;
//   insertattail(head,1);
//   insertattail(head,2);
//   insertattail(head,3);
//   insertattail(head,4);
//   insertattail(head,5);
//   insertattail(head,6);

//   display(head);
//   int k=4;
//  node* newhead= reversek(head,k);
//   display(newhead);
  return 0;
}