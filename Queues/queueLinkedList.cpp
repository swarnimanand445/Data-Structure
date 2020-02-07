#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int element)
{
    if(front==NULL)
    {
        node *new_node=new node();
        new_node->data=element;
        new_node->next=NULL;
        front=new_node;
        rear=new_node;
        cout<<"data intered successfully in front:"<<front->data<<"\n";
    }
    else
    {
        node *new_node=new node();
        new_node->data=element;
        rear->next=new_node;
        rear=new_node;
        cout<<"data intered successfully in rear:"<<rear->data<<"\n";
    }
    
}
void dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue Underflow occurs\n";
        return;
    }
    else
    {
        node *store;
        store=front;
        front=front->next;
        cout<<"Deleted element from queue is:"<<store->data<<"\n";
        free(store);
    }
    
}
void peek()
{
    if(front==NULL)
    {
        cout<<"Queue Underflow occurs\n";
        return;
    }
    else
    {
        cout<<"Front element of queue is:"<<front->data<<"\n";
        return;
    }
}
void isEmpty()
{
    if(front==NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        cout<<"Queue is not empty\n";
        return;
    }
}
void display()
{
    if(front==NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        node *temp;
        temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
int main()
{
    
    int choice,data;
    cout<<"Queue Operation:\n";
    cout<<"1)Enqueue\n2)Dequeue\n3)Front\n4)isEmpty\n5)Display\n6)Exit\n";
    while(1)
    {
        cout<<"enter the choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enqueue Operation:\n";
            cout<<"Enter the element in the queue";
            cin>>data;
            enqueue(data);
            break;
        case 2:
            cout<<"Dequeue Operation:\n";
            dequeue();
            break;
        case 3:
            cout<<"Front Element:\n";
            peek();
            break;  
        case 4:
            cout<<"IsEmpty:\n";
            isEmpty();
            break;      
        case 5:
            cout<<"Display Elements:\n";
            display();
            break;
        case 6:
            exit(0);        
        default:
            cout<<"Choose another option ......\n";
            break;
        }
    }
    return 0;
}