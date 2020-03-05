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
// bool isEmpty(int *queue)
// {
//     if(front==-1)
//     {
//         cout<<"Queue is empty\n";
//         return true;
//     }
//     else
//     {
//         cout<<"Queue is not empty\n";
//         return false;
//     }
// }
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
// void push(int *stack,int data)
// {
//     if(top==MAX-1)
//     {
//         cout<<"overflow";
//         return;
//     }
//     else
//     {
//         stack[++top]=data;
//         cout<<"data entered successfully in stack1:"<<stack[top];
//     }
// }
// int pop(int *stack)
// {
//     int data;
//     if(top==-1)
//     {
//         cout<<"underflow";
//         return 0;
//     }
//     else
//     {
//         data=stack[top--];
//         cout<<"data popped from stack is:"<<data<<"\n";
//         return data;
//     }
// }
// bool isEmpty1(int *stack)
// {
//     if(top==-1)
//     {
//         cout<<"stack is empty\n";
//         return true;
//     }
//     cout<<"stack is not empty\n";
//     return false;
// }

// int size(int *stack)
// {
//     int s=0;
//     if(top==-1)
//     {
//         return 0;
//     }
//     else
//     {
//         for(int i=top;i>=0;i--)
//         {
//             s++;
//         }
//         return s;
//     }
// }
int main()
{
    int data,ch;
    int queue[MAX];
    // int stack1[MAX];
    // int stack2[MAX];
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
                //push(stack1,data);
                my1.push(data);
                cout<<"data entered successfully in stack1:"<<my1.top();
                break;
            }
            case 2:
            {
                int data1,data2;
                cout<<"Dequeue operation\n";
                dequeue(queue);
                //if(isEmpty(stack2)==true)
                if(my2.empty()==true)
                {
                    //while(isEmpty(stack1)==false)
                    while(my1.empty()==false)
                    {
                        //data1=pop(stack1);
                        
                        data1=my1.top();
                        my1.pop();
                        cout<<"data popped succesfully from stack1: "<<data1<<"\n";
                        //push(stack2,data1);
                        my2.push(data1);
                        cout<<"data entered succesfully in stack2: "<<data1<<"\n";
                    }
                }
                //data2=pop(stack2);
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
                //if(isEmpty(stack1) && isEmpty(stack2))
                if(my1.empty() && my2.empty())
                {
                    cout<<"queue is empty";
                }
                else
                {
                    cout<<"queue is not empty";
                }
               // isEmpty(queue);
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
                //cout<<size(stack1)+size(stack2);
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