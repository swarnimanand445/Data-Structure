#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head,*p;
void get_data(int n)
{
    node *temp=new node();
    int element;
    cout<<"enter the element in 1st node:";
    cin>>element;
    temp->data=element;
    temp->next=NULL;
   
    if(temp!=NULL)
    {
        head=temp;
        p=temp;
        for(int i=2;i<=n;i++)
        {
            node *temp=new node();
            int element;
            cout<<"enter the element in "<<i<<" node:";
            cin>>element;
            temp->data=element;
            temp->next=NULL;
            p->next=temp;
            p=p->next;
        }
    }
    else
    {
        exit(0);
    }
 
}
void swap(node *ptr1,node *ptr2)
{
    int temp=ptr1->data;
    ptr1->data=ptr2->data;
    ptr2->data=temp;
}
void bubbleSort()
{
    node *ptr;
    node *lptr=NULL;
    int swapped,i;
    if(head==NULL)
     return;

    do{
        swapped=0;
        ptr=head;
        while(ptr->next!=lptr)
        {
            if(ptr->data > ptr->next->data)
            {
                swap(ptr,ptr->next);
                swapped=1;
            }
            ptr=ptr->next;
        }
        lptr=ptr;
    }
    while(swapped);//if swapped=1 then loop will continue and if swapped=0 the loop will stop
}    

   
void show_data()
{
    node *temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}
int main()
{
    int n;
    cout<<"enter the total no node";
    cin>>n;
    get_data(n);
    bubbleSort();
    cout<<"The Single Linked List is:";
    show_data();
    return 0;
}