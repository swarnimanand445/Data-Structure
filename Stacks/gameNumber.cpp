#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int top=-1;
void push(int *stack,int data)
{
    if(top==MAX-1)
    {
        //cout<<"Overflow occurs\n";
        return ;
    }
    else 
    {
        stack[++top]=data;
        //cout<<"Data inserted successfully in stack"<<n<<":"<<stack[top]<<"\n";
    }
}
void display(int stack2[])
{
    for(int i=0;i<=top;i++)
    {
        if(stack2[i] != 0)
        cout<<stack2[i]<<" ";
    }
}
int greatest(int *arr,int data,int n)
{
    int max=arr[data];
    for(int i=data+1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
void gameNumber(int *stack1,int *stack2,int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                push(stack1,arr[j]);
                for(int k=j;k<n;k++)
                {
                    for(int u=k+1;u<n;u++)
                    {
                        if(arr[k]>arr[u])
                        {
                            push(stack2,arr[u]);
                            break;
                        }
                        
                    }
                    break;
                }
             break;
            }
            
        }
        if(arr[i]>=greatest(arr,i,n))
        {
            push(stack1,-1);
            push(stack2,-1);
        }
    }
}

int main()
{
    int stack1[MAX];
    int stack2[MAX];
    int arr[MAX];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    gameNumber(stack1,stack2,arr,n);
    display(stack2);
    return 0;
}
    
