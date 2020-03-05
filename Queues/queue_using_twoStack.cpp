//Queue implementation using two Stacks
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
stack<int>my1;
stack<int>my2;
int front=-1;
int rear=-1;
int top=-1;
void enqueue(int *queue,int data)
{
    if(rear==MAX-1)
    {
        cout<<"Overflow\n";
        return;
    }
    else if(front==-1 && rear==-1)
    {
        queue[++front]=data;
        queue[++rear]=data;
        cout<<"data inserted successfully:"<<queue[rear]<<"\n";
    }
    else
    {
        queue[++rear]=data;
        cout<<"data inserted successfully:"<<queue[rear]<<"\n";
    }
    
}
void dequeue(int *queue)
{
    int data;
    if(front==-1)
    {
        cout<<"Underflow\n";
        return;
    }
    else if(front==rear)
    {
        data=queue[front];
        front=-1;
        rear=-1;
        cout<<"data deleted from queue is:"<<data<<"\n";
        return;
    }
    else
    {
        data=queue[front++];
        cout<<"data deleted from queue is:"<<data<<"\n";
    }
    
}
int peek(int *queue)
{
    if(front==-1)
    {
        cout<<"underflow\n";
        return 0;
    }
    else
    {
        cout<<"Front element of queue:";
        cout<<queue[front];
        return queue[front];
    }
    
}

void display(int *queue)
{
    if(front==-1)
    {
        cout<<"underflow\n";
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
    int data,ch;
    int queue[MAX];
    
    cout<<"Queue Opearion\n";
    cout<<"1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty\n5.Display\n6.Size of queue\n7.exit\n";
    while(1)
    {
        cout<<"enter your choice";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enqueue operation\n";
                cout<<"enter the data want to input";
                cin>>data;
                enqueue(queue,data);
            
                my1.push(data);
                cout<<"data entered successfully in stack1:"<<my1.top();
                break;
            }
            case 2:
            {
                int data1,data2;
                cout<<"Dequeue operation\n";
                dequeue(queue);
          
                if(my2.empty()==true)
                {
               
                    while(my1.empty()==false)
                    {   
                        data1=my1.top();
                        my1.pop();
                        cout<<"data popped succesfully from stack1: "<<data1<<"\n";
                    
                        my2.push(data1);
                        cout<<"data entered succesfully in stack2: "<<data1<<"\n";
                    }
                }
            
                data2=my2.top();
                my2.pop();
                cout<<"data popped succesfully from stack2: "<<data2<<"\n";
                
                break;
            }
            case 3:
            {
                cout<<"Peek operation\n";
                peek(queue);
                break;
            }
            case 4:
            {
                cout<<"Checking queue isEmpty\n";
              
                if(my1.empty() && my2.empty())
                {
                    cout<<"queue is empty";
                }
                else
                {
                    cout<<"queue is not empty";
                }
          
                break;
            }
            case 5:
            {
                cout<<"Display Queue\n";
                display(queue);
                break;
            }
            case 6:
            {
                cout<<"Size of the queue:\n";
             
                cout<<my1.size()+my2.size();
                break;
            }
            case 7:
            {
                exit(0);
            }
        }
    }
    
}
