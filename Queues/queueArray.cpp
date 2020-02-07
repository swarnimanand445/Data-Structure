#include<bits/stdc++.h>
using namespace std;
#define MAX 4
int front=-1,rear=-1;
void enqueue(int *queue,int element)
{
    if(rear>=MAX-1)
    {
        cout<<"Queue Overflow\n";
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front++;
        queue[++rear]=element;
    }
    else
    {
        queue[++rear]=element;
    }
}
void dequeue(int *queue)
{
    if(front==-1)
    {
        cout<<"Queue Underflow \n";
        return;
    }
    else if(front==rear)
    {
        cout<<"Last element in the queue is deleted:"<<queue[front];
        front=-1;
        rear=-1;
        return;
    }
    else
    {
        int data;
        data=queue[front++];
        cout<<"Dequeued element is :"<<data<<"\n";
    }
    
}
void peek(int *queue)
{
    if(front==-1)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        cout<<"First element of queue is:"<<queue[front]<<"\n";
        return;
    }
    
}
void isEmpty(int *queue)
{
    if(front==-1)
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
void display(int *queue)
{
    if(front==-1)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
    }
    
}
int main()
{
    int queue[MAX];
    int choice,data;
    cout<<"Queue Operation:\n";
    cout<<"1)Enqueue\n2)Dequeue\n3)Front\n4)isEmpty\n5)Display\n6)Exit\n";
    while(1)
    {
        cout<<"enter the choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enqueue Operation:\n";
            cout<<"Enter the element in the queue";
            cin>>data;
            enqueue(queue,data);
            break;
        case 2:
            cout<<"Dequeue Operation:\n";
            dequeue(queue);
            break;
        case 3:
            cout<<"Front Element:\n";
            peek(queue);
            break;  
        case 4:
            cout<<"IsEmpty:\n";
            isEmpty(queue);
            break;      
        case 5:
            cout<<"Display Elements:\n";
            display(queue);
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