#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int top=-1;
void push(int *stack,int data)
{
    if(top>=MAX)
    {
        cout<<"Overflow occurs\n";
        return;
    }
    else
    {
        stack[++top]=data;
        //cout<<"Data inserted successfully in stack:"<<stack[top]<<"\n";
    }
}
int pop(int *stack)
{
    int pop_data;
    if(top==-1)
    {
        cout<<"Underflow occurs\n";
        return 0;
    }
    else
    {
       pop_data=stack[top--];
       //cout<<"Data poped successfully from stack:"<<pop_data<<"\n";
       return pop_data;
    }
}
void isEmpty(int *stack)
{
    if(top==-1)
    {
        cout<<"stack is empty\n";
        return;
    }
    else
    {
        cout<<"Stack is not empty\n";
        return;
    }
}
int peek(int *stack)
{
    if(top==-1)
    {
        cout<<"Stack is empty\n";
        return 0;
    }
    else
    {
        //cout<<"The first data of Stack is:"<<stack[top];
        return stack[top];
    }
}
void display(int *stack)
{
    if(top==-1)
    {
        cout<<"stack is empty";
        return;
    }
    cout<<"Display Elements of Stack: ";
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<"\n";
}
int postfixEvaluation(char *input,int *stack)
{
    int a,b,c,x;
    int i=0;
    while(input[i]!='\0')
    {
        if(input[i]>='0' && input[i]<='9')
        {
            x=input[i]-48;
            push(stack,x);
        }
        else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/')
        {
            a=pop(stack);
            b=pop(stack);
            switch (input[i])
            {
                case '+':    
                    c=b+a;
                    push(stack,c);
                    break;
                case '-':
                    c=b-a;
                    push(stack,c);
                    break;
                case '*':
                    c=b*a;
                    push(stack,c);
                    break;
                case '/':
                    c=b/a;
                    push(stack,c);
                    break;            
            }
        }
        i++;
    }
    return pop(stack);
}
int prefixEvaluation(char *input,int *stack)
{
    int x,a,b,c;
    int i=strlen(input)-1;
    while(input[i]!='\0')
    {
        if(input[i]>='0' && input[i]<='9')
        {
            x=input[i]-48;
            push(stack,x);
        }
        else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')
        {
            a=pop(stack);
            b=pop(stack);
            switch(input[i])
            {
                case '+':
                    c=a+b;
                    push(stack,c);
                    break;
                case '-':
                    c=a-b;
                    push(stack,c);
                    break;
                case '*':
                    c=a*b;
                    push(stack,c);
                    break;
                case '/':
                    c=a/b;
                    push(stack,c);
                    break;            
            }
        }
        i--;
    }
    return pop(stack);
}
int findPresidence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;    
    }
}
void infixTopostfix(char *infix,char *postfix,int *stack)
{
    int i=0,j=0,ch;
    while(infix[i++]!='\0');
    infix[i+1]='\0';
    infix[i--]=')';
    while(i>0)
    {
        infix[i]=infix[i-1];
        i--;
    }
    infix[i]='(';
    i=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(stack,infix[i]);
        }    
        else if(infix[i]>='a' && infix[i]<='z')
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
        {
            
            while(peek(stack)=='+' || peek(stack)=='-' ||peek(stack)=='*' ||peek(stack)=='/')
            {
                if(findPresidence(peek(stack))>=findPresidence(infix[i]))
                {
                    postfix[j++]=pop(stack);
                }
                else
                {
                    break;
                }  
            }
            push(stack,infix[i]);
        }
        else if(infix[i]==')')
        {
            while((ch=pop(stack))!='(')
            {
                postfix[j++]=ch;
            }
        }
        i++;
    }
    postfix[j]='\0';
    for(int i=0;i<strlen(postfix);i++)
    {
        cout<<postfix[i];
    }
    cout<<endl;
}
void infixToprefix(char *infix,char *prefix,int *stack)
{
    char infix1[MAX];
    char postfix[MAX];
    int a,b,c;
    int i=0,j=0,ch;
    while(infix[i++]!='\0');
    infix[i+1]='\0';
    infix[i--]=')';
    while(i>0)
    {
        infix[i]=infix[i-1];
        i--;
    }
    infix[i]='(';

    cout<<infix<<endl;

    a=strlen(infix)-1;
    for(b=0;b<strlen(infix);b++)
    {
        infix1[b]=infix[a];
        a--;
    }
    infix1[b]='\0';

    cout<<infix1<<endl;
    
    for(int k=0;k<strlen(infix1);k++)
    {
        if(infix1[k]=='(')
        {
            infix1[k]=')';
        }
        else if(infix1[k]==')')
        {
            infix1[k]='(';
        }
    }

    cout<<infix1<<endl;
    
    i=0;
    while(infix1[i]!='\0')
    {
        if(infix1[i]=='(')
        {
            push(stack,infix1[i]);
        }    
        else if(infix1[i]>='a' && infix1[i]<='z')
        {
            postfix[j++]=infix1[i];
        }
        else if(infix1[i]=='+' || infix1[i]=='-' || infix1[i]=='*' || infix1[i]=='/')
        {
            while(peek(stack)=='+' || peek(stack)=='-' ||peek(stack)=='*' ||peek(stack)=='/')
            {
                if(findPresidence(peek(stack))>=findPresidence(infix1[i]))
                {
                    postfix[j++]=pop(stack);
                }
                else
                {
                    break;
                }  
            }
            push(stack,infix1[i]);
        }
        else if(infix1[i]==')')
        {
            while((ch=pop(stack))!='(')
            {
                postfix[j++]=ch;
            }
        }
        i++;
    }
    postfix[j]='\0';
    for(int i=0;i<strlen(postfix);i++)
    {
        cout<<postfix[i];
    }
    cout<<endl;
    int f,g;
    f=strlen(postfix)-1;
    for(g=0;g<strlen(postfix);g++)
    {
        prefix[g]=postfix[f];
        f--;
    }
    prefix[g]='\0';
    for(int i=0;i<strlen(prefix);i++)
    {
        cout<<prefix[i];
    }
    cout<<endl;
}
bool isbalencedParenthesis(char *str,int *stack)
{
    char x;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(' || str[i]=='{' ||str[i]=='[')
        {
            push(stack,str[i]);
            continue;
        }
        else
        {
            switch(str[i])
            {
                case '(':
                    {
                        x=peek(stack);
                    }
            }
        }
        
    }
}
int main()
{
    int data,choice,size,size1;
    int stack[MAX];
    char input[MAX];
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];
    char str2[MAX];
    cout<<"Stack Operation\n";
    cout<<"1)push data\n2)pop data\n3)peek data\n4)isEmpty\n5)Display element of stack\n6)Postfix Evaluation\n7)Prefix Evaluation\n8)Infix to Postfix\n9)Infix to Prefix\n10)Balanced Parenthesis\n11)Exit loop\n";
    while(1)
    {
        cout<<"enter the choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Push operation\n";
                cout<<"enter the data in the stack:";
                cin>>data;
                push(stack,data);
                break;
            case 2:
                cout<<"Pop Operation\n";
                cout<<"Data deleted successfully from stack:";
                cout<<pop(stack)<<endl;
                break;    
            case 3:
                cout<<"Peek Operation\n";
                cout<<"The first data of Stack is:";
                cout<<peek(stack)<<endl;
                break;
            case 4:
                cout<<"Isempty Operation:\n";
                isEmpty(stack) ;
                break;
            case 5:
                display(stack) ;
                break;  
            case 6:
                cout<<"Postfix Evaluation:";
                cout<<"enter the size of postfix expression:";
                cin>>size;
                for(int i=0;i<size;i++)
                {
                    cin>>input[i];
                }
                cout<<"After Postfix Evaluation:"<<postfixEvaluation(input,stack)<<endl;
                break;
            case 7:
                cout<<"Prefix Evaluation:";
                cout<<"enter the size of prefix expression:";
                cin>>size;
                for(int i=0;i<size;i++)
                {
                    cin>>input[i];
                }
                cout<<"After Prefix Evaluation:"<<prefixEvaluation(input,stack)<<endl;
                break;
            case 8:
                cout<<"Infix To Postfix Conversion:\n";
                cout<<"enter the size of infix notation";
                cin>>size1;
                cout<<"enter the infix notataion";
                for(int i=0;i<size1;i++)
                {
                    cin>>infix[i];
                }
                infixTopostfix(infix,postfix,stack);
                memset(infix,'\0',MAX);
                memset(stack,'\0',MAX);
                break;
            case 9:
                cout<<"Infix to Prefix Conversion:\n";
                cout<<"enter the size of infix notation";
                cin>>size1;
                cout<<"enter the infix notataion";
                for(int i=0;i<size1;i++)
                {
                    cin>>infix[i];
                }
                infixToprefix(infix,prefix,stack);
                memset(infix,'\0',MAX);
                memset(stack,'\0',MAX);
                break;  
            case 10:
                cout<<"Balanced Parenthesis\n";
                cout<<"enter the string :";
                cin>>str2;
                bool balenced=isbalencedParenthesis(str2,stack); 
                if(balenced)
                cout<<"Balenced";
                else
                {
                    cout<<"Not Balenced";
                }
                
                break;     
            case 11:
                exit(0);        
            default:
                cout<<"choose another one.....";     
        }
    
    }
    
    return 0;
}