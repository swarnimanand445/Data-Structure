#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int top=-1;
void push(char *stack,char data)
{
    if(top>=MAX)
    {
        cout<<"Overflow occurs\n";
        return ;
    }
    else 
    {
        stack[++top]=data;
        cout<<"Data inserted successfully in stack:"<<stack[top]<<"\n";
    }
}
char pop(char *stack)
{
    char x;
    if(top==-1)
    {
        cout<<"Underflow occurs\n";
        return '\0';
    }
    else
    {
       x=stack[top--];
       return x;
    }
}
char peek(char *stack)
{
    if(top==-1)
    {
        cout<<"Stack is empty\n";
        return '\0';
    }
    else
    {
        return stack[top];
    }
    
}
bool isEmpty()
{
    if(top==-1)
    {
       //cout<<"stack is empty";
        return true;
    }
    else
    {
       // cout<<"stack is not empty";
        return false;
    }
}
void display(char *stack)
{
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }
}
bool isbalencedParenthesis(char *stack,char *str)
{
    char y;
    for(int i=0;i<strlen(str);i++)
    {
        //cout<<str[i]<<endl;
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(stack,str[i]);
            continue;
        }

        switch(str[i])
        {
            case ')':
            {
                y=pop(stack);
                if(y=='{' || y=='[')
                    return false;
                break;
            }
            case '}':
            {
                y=pop(stack);
                if(y=='(' || y=='[')
                    return false;
                break;
            }
            case ']':
            {
                y=pop(stack);
                if(y=='('|| y=='{')
                    return false;
                break;
            }
            default:
                break;
        }
        
        
    }
    if(!isEmpty())
        return false;
    else
     return true;
}
int main()
{
    char stack[MAX];
    char str[MAX];
    char x,data;
    int ch;
    bool emp,balanced;
     cout<<"Stack Operation\n";
    cout<<"1)push data\n2)pop data\n3)peek data\n4)isEmpty\n5)Display element of stack\n6)Balenced Parenthesis\n7)exit\n";
    while(1)
    {
        cout<<"enter the choice \n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"push in stack\n";
            cout<<"enter the data into the stack\n";
            cin>>data;
            push(stack,data);
            break;
        case 2:
            cout<<"pop from stack\n";
            cout<<pop(stack);
            break;
        case 3:
            cout<<"peek from stack\n";
            cout<<peek(stack);
            break;
        case 4:
            cout<<"isEmpty stack\n";
            emp=isEmpty();
            if(emp==true)
            {
                cout<<"Stack is  empty\n";
            }
            else
            {
                cout<<"Stack is not Empty\n";
            }
            break;
        case 5:
            display(stack);
            break;
        case 6:
            cout<<"Balenced Parenthesis\n";
            cout<<"enter the string:";
            cin>>str;
            balanced=isbalencedParenthesis(stack,str);
            if(balanced==true)
            {
                cout<<"Balanced\n";
            }
            else
            {
                cout<<"Not Balanced\n";
            }
            break;
        case 7:
            exit(0);                     
        default:
                cout<<"choose another one.....";  
        }
    }
    
}