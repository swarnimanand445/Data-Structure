#include<bits/stdc++.h>
using namespace std;
// struct node
// {
//     int data;
//     struct node *next;
// }*top=NULL;
// void push(int element)
// {
//    if(top==NULL)
//    {
//         node *new_node=new node();
//         new_node->data=element;
//         new_node->next=NULL;
//         top=new_node;
//         cout<<"Data inserted successfully in the top of stack:"<<new_node->data<<"\n";
//    }
//    else
//    {
//        node *new_node=new node();
//        new_node->data=element;
//        new_node->next=top;
//        top=new_node;
//        cout<<"Data inserted successfully in the top of stack:"<<new_node->data<<"\n";
//    }
   
// }
// void pop()
// {
//     if(top==NULL)
//     {
//         cout<<"Stack is empty\n";
//         return;
//     }
//    else
//    {
//        node *store;
//        store=top;
//        cout<<"Data deleted successfully from top of stack:"<<store->data<<"\n";
//        top=top->next;
//        free(store);
       
//    }
   
// }
// void isEmpty()
// {
//     if(top==NULL)
//     {
//         cout<<"Stack is empty\n";
//         return;
//     }
//    else
//    {
//        cout<<"Stack is not empty\n";
//        return;
//    }
// }
// void peek()
// {
//     if(top==NULL)
//     {
//         cout<<"Stack is empty\n";
//         return;
//     }   
//     else
//     {
//         cout<<"Top element of stack is: "<<top->data<<"\n";
//     }
    
// }
// void display()
// {
//     if(top==NULL)
//     {
//         cout<<"stack is empty\n";
//         return;
//     }
    
//     cout<<"Display Elements of Stack: ";
//     node *temp=top;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<"\n";
// }
struct node{
    char data;
    struct node* next; 
}*top=NULL;
void push(char element)
{
    if(top==NULL)
    {
        node *new_node=new node();
        new_node->data=element;
        new_node->next=NULL;
        top=new_node;
        cout<<"data intered "<<new_node->data<<endl;
    }
    else
    {
        node *new_node=new node();
        new_node->data=element;
        new_node->next=top;
        top=new_node;
        cout<<"data intered "<<new_node->data<<endl;
    }
    
}
void pop()
{
    if(top==NULL)
    {
        cout<<"Underflow occurs";
        return ;
    }
    else
    {
        node *store;
        store=top;
        top=top->next;
        //cout<<"Pooped element from stack is:"<<store->data<<endl;
        free(store);
    }
}
char peek()
{
    if(top==NULL)
    {
        cout<<"Underflow occurs\n";
        return '\0';
    }
    else
    {
        cout<<"Top element of stack is: "<<top->data<<endl;
        return top->data;
    }
}
bool isEmpty()
{
    if(top==NULL)
    {
        cout<<"Stack is Null \n";
        return true;
    }
    else
    {
        cout<<"Stack is not Null \n";
        return false;
    }
}
void display()
{
    if(top==NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    node *temp;
    temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
bool isbalencedParenthesis()
{
    node *head=NULL,*p=NULL;
    char element,x;
    int l=1,ch1,ch2,n;
    cout<<"enter the size of linked list";
    cin>>n;
    cout<<"enter the 1st element in the linked list";
    cin>>element;
    node *input=new node();
    input->data=element;
    input->next=NULL;
    p=input;
    head=p;
    for(int i=2;i<=n;i++)
    {
        cout<<"enter the element in the linked list";
        cin>>element;
        node *input=new node();
        input->data=element;
        input->next=NULL;
        p->next=input;
        p=p->next;  
    }
    
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        
        if(head->data=='(' || head->data=='{' || head->data=='[')
        {
            push(head->data);
            head=head->next;
            continue;
        }
        switch(head->data)
        {
            case ')':
            {
                x=peek();
                pop();
                if(x=='{' || x=='[')
                    return false;
                break;    
            }
            case '}':
            {
                x=peek();
                pop();
                if(x=='(' || x=='[')
                    return false;
                break;    
            }
            case ']':
            {
                x=peek();
                pop();
                if(x=='(' || x=='{')
                    return false;
                break;
            }           
        }
        head=head->next;
    }
    
    if(isEmpty()==false)
        return false;
    else
    {
        return true;
    }
    
}
int main()
{
    int choice;
    char data;
    bool empty,balanced;
    
    cout<<"Stack Operation\n";
     cout<<"1)push data\n2)pop data\n3)peek data\n4)isEmpty\n5)Display element of stack\n6)Balenced Parenthesis\n7)Exit loop\n";
    while(1)
    {
       
        cout<<"enter the choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Push operation\n";
                cout<<"\nenter the data in the stack:";
                cin>>data;
                push(data);
                break;
            case 2:
                cout<<"Pop Operation\n";
                pop();
                break;    
            case 3:
                cout<<"Peek Operation\n";
                cout<<peek();
                break;
            case 4:
                cout<<"Isempty Operation:\n";
                empty=isEmpty() ;
                if(empty==true)
                {
                    cout<<"Stack is empty";
                }
                else
                {
                    cout<<"Stack is not empty";
                }
                break;
            case 5:
                display() ;
                break;  
            case 6:
                cout<<"Balanced Parenthesis\n";
                balanced=isbalencedParenthesis();
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
    
    return 0;
}