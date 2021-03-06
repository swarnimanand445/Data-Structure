#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head,*p;
 //-------------------------------------------------------------------------------------------------- 
void show_data();
void get_data(int n)
{
    int element;
    node *temp=new node();
    cout<<"enter the 1st element in the list:";
    cin>>element;
    temp->data=element;
    temp->next=NULL;
    temp->prev=NULL;
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
            temp->prev=p;
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
void rotate_anticlokwise()
{
    int k,count=1;
    cout<<"enter the no of rotation in double linked list";
    cin>>k;
    if(k==0)
    {
        cout<<"Since value of k is 0 so no rotation is allowed";
        return;
    }
    node *current=head;
    while(count<k && current!=NULL)
    {
        current=current->next;
        count++;
    }
    if(current==NULL)//means k>=n(which is not allowed in programming,its a bad programming)
    return;
    node *kthNode=current;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=head;
    head->prev=current;
    head=kthNode->next;
    head->prev=NULL;
    kthNode->next=NULL;
}
//-------------------------------------------------------------------------------------------------- 
void rotate_clockwise()
{
    int k,count=1;
    cout<<"enter the no of rotation in double linked list";
    cin>>k;
    if(k==0)
    {
        cout<<"Since value of k is 0 so no rotation is allowed";
        return;
    }
    node *current=p;
    while(count<k && current!=NULL)
    {
        current=current->prev;
        count++;
    }
    if(current==NULL)//means k>=n(which is not allowed in programming,its a bad programming)
    return;
    node *kthNode=current;
    while(current->prev!=NULL)
    {
        current=current->prev;
    }
    current->prev=p;
    p->next=current;
    kthNode->prev->next=NULL;
    head=kthNode;
    head->prev=NULL;
    
}
//-------------------------------------------------------------------------------------------------- 
void insert_atHead()
{
    int element;
    cout<<"enter the new element in the list:";
    cin>>element;
    node *new_node=new node();
    new_node->data=element;
    new_node->next=head;
    new_node->prev=NULL;
    head->prev=new_node;
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
    new_node->prev=p;
    new_node->data=element;
    new_node->next=NULL;
}
 //-------------------------------------------------------------------------------------------------- 
  void checkValidPosition_after(int position,int n)
    {
        if(position<n+1)
        {
            for(int i=1;i<position-1 && position!=0;i++)
            {
                p=p->next;
            }
            cout<<"enter the new element in the list at position "<<position<<":";
        }
        else
        {
            cout<<"This position is not valid..Please try some other position ";
            cin>>position;
            checkValidPosition_after(position,n);
        }
    }
void insert_atPositionAfter(int n)
{
    int position,element;
    cout<<"enter the position of new element:";
    cin>>position;
    
    p=head;
    node *new_node=new node();
    checkValidPosition_after(position,n);
    // for(int i=1;i<position-1 && position!=0;i++)
    // {
    //     p=p->next;
    // }
    cin>>element;
    new_node->next=p->next;
    new_node->prev=p;
    p->next->prev=new_node;
    p->next=new_node;
    new_node->data=element;
}
//-------------------------------------------------------------------------------------------------- 
void checkValidPosition_before(int position,int n)
    {
        if(position<n+1)
        {
            for(int i=1;i<position-1 && position!=0;i++)
            {
                p=p->prev;
            }
            cout<<"enter the new element in the list at position "<<position<<":";
        }
        else
        {
            cout<<"This position is not valid..Please try some other position ";
            cin>>position;
            checkValidPosition_before(position,n);
        }
    }
void insert_atPositionBefore(int n)
{
    int position,element;
    cout<<"enter the position of new node:";
    cin>>position;
    node *new_node=new node();
    checkValidPosition_before(position,n);
    
    cin>>element;
    
    new_node->next=p;
    new_node->prev=p->prev;
    p->prev->next=new_node;
    p->prev=new_node;
    new_node->data=element;
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atHead()
{
    node *store;
    store=head;
    head->next->prev=NULL;
    head=head->next;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atEnd()
{
    node *store;
    store=p;
    p->prev->next=NULL;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
 void checkValidPosition_after1(int position,int n)
    {
        if(position<n)
        {
            for(int i=1;i<position-1 && position!=0;i++)
            {
                p=p->next;
            }
           cout<<"The element is deleted at position "<<position<<":";
        }
        else
        {
            cout<<"This position is not valid..Please try some other position ";
            cin>>position;
            checkValidPosition_after1(position,n);
        }
    }
 void delete_atPositionAfter(int n)
{
    node *store;
    p=head;
    int position;
    cout<<"enter the position of element to be deleted:";
    cin>>position;
    // for(int i=1;i<position-1 && position!=0;i++)
    // {
    //     p=p->next;
    // }
    checkValidPosition_after1(position, n);
    store=p->next;
    p->next=store->next;
    store->next->prev=p;
    free(store);
}
//-------------------------------------------------------------------------------------------------- 
void checkValidPosition_before1(int position,int n)
    {
        if(position<n)
        {
            for(int i=1;i<position-1 && position!=0;i++)
            {
                p=p->prev;
            }
           cout<<"The element is deleted at position "<<position<<":";
        }
        else
        {
            cout<<"This position is not valid..Please try some other position ";
            cin>>position;
            checkValidPosition_before1(position,n);
        }
    }
void delete_atPositionBefore(int n)
{
    node *store;
    
    int position;
    cout<<"enter the position of element to be deleted:";
    cin>>position;
    // for(int i=1;i<position-1 && position!=0;i++)
    // {
    //     p=p->prev;
    // }
    checkValidPosition_before1(position,n);
    store=p->prev;
    p->prev=store->prev;
    store->prev->next=p;    
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
 void reverse(int n)
 {
    node *tail;
    tail=p;
    while(tail!=NULL)
    {
        cout<<tail->data<<" ";
        tail=tail->prev;
    }
    
    exit(0);
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
    cout<<"Double Linked List\n";
    cout<<"1)Normal Linked list\n 2)Insert_atHead\n 3)Insert_atEnd\n 4)Insert_atPosititonAfter\n 5)Insert_atPositionBefore\n 6)Delete_atHead\n 7)Delete_atEnd\n 8)Delete_atPositionAfter\n 9)Delete_atPositionBefore\n10)Rotate anticlockwise a node\n11)Rotate clockwise a node\n12)Reverse LinkedList\n";
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
            insert_atPositionAfter(n);
            break;
        case 5:
            insert_atPositionBefore(n);
            break;
        case 6:
            delete_atHead();
            break;
        case 7:
            delete_atEnd();
            break;
        case 8:
            delete_atPositionAfter(n);
            break;    
        case 9:
            delete_atPositionBefore(n);
            break;
        case 10:
            rotate_anticlokwise();
            break;   
        case 11:
            rotate_clockwise();
            break; 
        case 12:
            reverse(n);
            break;        
        default:
            cout<<"Ooops.. choose another one.";                    
    }
    cout<<"The Double Linked List is: ";
    show_data();
    return 0;
}