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
    temp->next=temp;
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
            temp->next=head;
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
    cout<<"enter no of rotattion in CircularsingleLList";
    cin>>k;
    if(k==0)
    {
        return;
    }
    node *current=head;
    while(count<k && current->next!=head)
    {
        current=current->next;
        count++;
    }
    // if(current==NULL)
    // return;
    node *kthNode=current;
    while(current->next!=head)
    {
        current=current->next;
    }
    current->next=head;
    head=kthNode->next;
    kthNode->next=head;
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
    p->next=new_node;
    head=new_node; 
}
 //-------------------------------------------------------------------------------------------------- 
void insert_atEnd()
{
    int element;
    cout<<"enter the new element in the list:";
    cin>>element;
    node *new_node=new node();
    new_node->next=head;
    p->next=new_node;
    new_node->data=element;
}
 //-------------------------------------------------------------------------------------------------- 
 void checkValidPosition(int position,int n)
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
            checkValidPosition(position,n);
        }
    }
void insert_atPosition(int n)
{
    int position,element;
    p=head;
    cout<<"enter the position of new element:";
    cin>>position;
    checkValidPosition(position,n);
    cin>>element;
    node *new_node=new node();
    new_node->data=element;
    
    // for(int i=1;i<position-1 && position!=0;i++)
    // {
    //     p=p->next;
    // }
    new_node->next=p->next;
    p->next=new_node;
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atHead()
{
    node *store;
    store=head;
    p->next=head->next;
    head=head->next;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
void delete_atEnd()
{
    node *store;
    p=head;
    while(p->next->next!=head)
    {
        p=p->next;
    }
    store=p->next;
    p->next=head;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
 void checkValidPosition1(int position,int n)
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
            checkValidPosition1(position,n);
        }
    }
void delete_atPosition(int n)
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
    checkValidPosition1(position,n);
    store=p->next;
    p->next=store->next;
    free(store);
}
 //-------------------------------------------------------------------------------------------------- 
 void reverse()
 {
    node *current,*prev,*next1;
    current=head;
    prev=p;
    next1=NULL;
    while(current!=p)
    {
        next1=current->next;
        current->next=prev;
        prev=current;
        current=next1;
    }
    current->next=prev;
    head=current;
    
 }
void show_data()
{
    node *temp1;
    temp1=head;
    while(temp1->next!=head)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<temp1->data;
}
 //-------------------------------------------------------------------------------------------------- 
int main()
{
    int n,choice;
    cout<<"enter the no of elements in a linked list:";
    cin>>n;
    get_data(n);
    cout<<"Single Circular Linked List\n";
    cout<<"1)Normal Linked list\n 2)Insert_atHead\n 3)Insert_atEnd\n 4)Insert_atPosititon\n 5)Delete_atHead\n 6)Delete_atEnd\n 7)Delete_atPosition\n8)Rotate around a node\n9)Reverse Linked List\n";
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
            insert_atPosition(n);
            break;
        case 5:
            delete_atHead();
            break;
        case 6:
            delete_atEnd();
            break;
        case 7:
            delete_atPosition(n);
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
    cout<<"The Single Circular Linked List is";
    show_data();
    return 0;
}