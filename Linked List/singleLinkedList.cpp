#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
}*head,*p;
 //-------------------------------------------------------------------------------------------------- 
void get_data(int n)
{
    int element;
    node *temp=new node();
    cout<<"enter the 1st element in the list:";
    cin>>element;
    temp->data=element;
    temp->next=NULL;
    if(temp!=NULL)
    {
        p=temp;
        head=temp;
        for(int i=2;i<=n;i++)
        {
            cout<<"enter the "<<i<<" element in the list:";
            cin>>element;
            temp=new node();
            temp->data=element;
            temp->next=NULL;
            p->next=temp;//this can also be write like this (*p).next=temp
            p=p->next;
        }
    }
    else
    {
        exit(0);
    }
}
//--------------------------------------------------------------------------------------------------   

void rotate()
{
    int k,count=1;
    cout<<"enter the no of rotation in a linked list";
    cin>>k;
    if(k==0)
    {
        cout<<"Since value of k is 0 means no rotation can be allowed";
        return;
    }
    node *current=head;
    while(count<k && current!=NULL)
    {
        current=current->next;
        count++;
    }
    if(current==NULL)
    {
        return;
    }
    node *kthNode=current;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=head;
    head=kthNode->next;
    kthNode->next=NULL;
}
void insert_atHead()
{
    int element;
    cout<<"enter the new element in the list:";
    cin>>element;
    node *new_node=new node();
    new_node->data=element;
    new_node->next=head;
    head=new_node; 
}
 //-------------------------------------------------------------------------------------------------- 
void insert_atEnd()
{
    int element;
    cout<<"enter the new element in the list:";
    cin>>element;
    node *new_node=new node();
    p->next=new_node;
    new_node->data=element;
    new_node->next=NULL;
}
 //-------------------------------------------------------------------------------------------------- 
void insert_atPosition()
{
    int position,element;
    cout<<"enter the position of new element:";
    cin>>position;
    cout<<"enter the new element in the list at position "<<position<<":";
    cin>>element;
    node *new_node=new node();
    new_node->data=element;
    p=head;
    for(int i=1;i<position-1 && position!=0;i++)
    {
        p=p->next;
    }
    new_node->next=p->next;
    p->next=new_node;
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atHead()
{
    node *store;
    store=head;
    head=head->next;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atEnd()
{
    node *store;
    p=head;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    store=p->next;
    p->next=NULL;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atPosition()
{
    node *store;
    p=head;
    int position;
    cout<<"enter the position of element to be deleted:";
    cin>>position;
    for(int i=1;i<position-1 && position!=0;i++)
    {
        p=p->next;
    }
    store=p->next;
    p->next=store->next;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
 void reverse()
 {
     node *current,*prev,*next1;
     current=head;
     prev=NULL;
     next1=NULL;
     while(current!=NULL)
     {
        next1=current->next;
        current->next=prev;
        prev=current;
        current=next1;
     }
     head=prev;
 }
 //-------------------------------------------------------------------------------------------------- 
void show_data()
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
 //-------------------------------------------------------------------------------------------------- 
int main()
{
    int n,choice;
    cout<<"enter the no of elements in a linked list:";
    cin>>n;
    get_data(n);
    cout<<"Single Linked List\n";
    cout<<"1)Normal Linked list\n 2)Insert_atHead\n 3)Insert_atEnd\n 4)Insert_atPosititon\n 5)Delete_atHead\n 6)Delete_atEnd\n 7)Delete_atPosition\n8)Rotate around a Node\n9)Reverse LinkedList\n";
    cout<<"enter the choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
            show_data();
            break;
        case 2:
            insert_atHead();
            break;
        case 3:
            insert_atEnd();
            break;
        case 4:
            insert_atPosition();
            break;
        case 5:
            delete_atHead();
            break;
        case 6:
            delete_atEnd();
            break;
        case 7:
            delete_atPosition();
            break;
        case 8:
            rotate();
            break;
        case 9:
            reverse();
            break;
        default:
            cout<<"Ooops.. choose another one.";                    
    }
    cout<<"The Linked List is";
    show_data();
    return 0;
}