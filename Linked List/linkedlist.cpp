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
void insertathead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}
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
void deleteathead(node* &head)
{
    node* todelete=head;
    head=head->next;

    delete todelete;
}
void deletion(node* &head, int val)
{
    if(head==NULL) //if ll is empty
    {
        return;
    }
    if(head->next==NULL) // if only one element in ll
    {
        deleteathead(head);
        return;
    }
    //wont work for first node of the ll
    node* temp=head;
    while(temp->next->data!=val)
    {
       temp=temp->next; 
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
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
bool search(node* head, int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
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

void makecycle(node* &head, int pos)
{
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool detectcycle(node* &head)
{
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
void removecycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int length(node* &head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}
node* kappend(node* &head, int k)
{
    node* newHead;
    node* newTail;
    node* tail=head;

    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL)
    {
        if(count==(l-k))
        {
            newTail=tail;
        }
        if(count==(l-k+1))
        {
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }

    newTail->next=NULL;
    tail->next=head;
    
    return newHead;
}
void intersect(node* &head1, node* &head2, int pos)
{
    node* temp1=head1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* &head1, node* &head2)
{
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
        {
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

int main()
{
//   node* head=NULL;
//   insertattail(head,1);
//   insertattail(head,2);
//   insertattail(head,3);
//   display(head);
//   insertathead(head,4);
//   display(head);

// cout<<search(head, 4)<<endl;
// cout<<search(head, 5)<<endl;

// deletion(head,3);
// deleteathead(head);
// display(head);

// Q1. Detect and create a cycle in linkedlist. - hare and tortoise algo /or/ Floyds algo -- very important hai
//   node* head=NULL;
//   insertattail(head,1);
//   insertattail(head,2);
//   insertattail(head,3);
//   insertattail(head,4);
//   insertattail(head,5);
//   insertattail(head,6);
//     // makecycle(head,3);
//     // display(head);
//     cout<<detectcycle(head)<<endl;

// Q2. Remove a cycle in linkedlist
//   node* head=NULL;
//   insertattail(head,1);
//   insertattail(head,2);
//   insertattail(head,3);
//   insertattail(head,4);
//   insertattail(head,5);
//   insertattail(head,6);
//     makecycle(head,3); // cycle created
//     // display(head);
//     cout<<detectcycle(head)<<endl;
//     removecycle(head); // a cycle is removed 
//     cout<<detectcycle(head)<<endl;
//     display(head);

// Q3.Append last K nodes of a linked list
// node* head=NULL;
// int arr[]={1,2,3,4,5,6};
// for(int i=0;i<6;i++)
// {
//     insertattail(head,arr[i]);
// }
// display(head);
// node* newhead=kappend(head, 3);
// display(newhead);

// Q4. Find intersection of two linked list.
// node* head1=NULL;
// node* head2=NULL;
// insertattail(head1,1);
// insertattail(head1,2);
// insertattail(head1,3);
// insertattail(head1,4);
// insertattail(head1,5);
// insertattail(head1,6);
// insertattail(head2,9);
// insertattail(head2,10);
// intersect(head1,head2,5);
// display(head1);
// display(head2);
// cout<<intersection(head1, head2)<<endl;


  return 0;
}