#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
}*root=NULL;
typedef struct bstnode node;
vector<int> arr;
node *createnode(node *root,int key)
{
    if(root==NULL)
    {
        root=new node();
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        arr.push_back(root->data);
        for(int i=0;i<arr.size();i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    else if(key>root->data)
    {
        root->right=createnode(root->right,key);
    }
    else if(key<root->data)
    {
        root->left=createnode(root->left,key);
    }
    return root;
}
void inorder(node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}
void postorder(node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
     
}
int greatest(node *root)
{
    if(root==NULL)
    return 0;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int lowest(node *root)
{
    if(root==NULL)
    return 0;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
node *maximum(node *root)
{
    if(root==NULL)
    return root;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    cout<<"The greatest element in left subtree of root is:"<<root->data;
    return root;
}
node *delete1(node *root,int target)
{
    if(root==NULL)
    return root;
    else if(target<root->data)
    {
        root->left=delete1(root->left,target);
    }
    else if(target>root->data)
    {
        root->right=delete1(root->right,target);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            cout<<"deleted element from tree is"<<root->data;
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            node *temp;
            temp=root;
            root=root->right;
            cout<<"deleted element from tree is"<<temp->data;
            free(temp);
        }
        else if(root->right==NULL)
        {
            node *temp;
            temp=root;
            root=root->left;
            cout<<"deleted element from tree is"<<temp->data;
            free(temp);
        }
        else
        {
            node *temp=maximum(root->left);
            root->data=temp->data;
            root->left=delete1(root->left,temp->data);
        }
        
    }
    return root;
}
int height(node *root)
{
    int h;
    if(root==NULL)
    return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right)
    {
        h=1+left;
    }
    else
    {
        h=1+right;
    }
    return h;
}
node *search(node *root,int key)
{
    if(root==NULL)
    {
        cout<<"data not found in tree structure";
    }
    else if(root->data==key)
    {
        cout<<"Element found in tree";
    }
    else if(key<root->data)
    {
        root->left=search(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=search(root->right,key);
    }
    return root;
}
int leaf_nodes(node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        if((root->left==NULL) && (root->right==NULL))
        return 1;
        else
        {
            return(leaf_nodes(root->left)+leaf_nodes(root->right));
        }
        
    }
}
int  non_leaf(node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        if((root->left!=NULL) || (root->right!=NULL))
        {
            return(1+non_leaf(root->left)+non_leaf(root->right));
        }
    }
}
int sum(node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        return(root->data+sum(root->left)+sum(root->right));
    }
}
int no_of_nodes(node *root)
{
    int c=1;
    if(root==NULL)
    return 0;
    else
    {
        c+=no_of_nodes(root->left)+no_of_nodes(root->right);
    }
    return c;
}
int main()
{
    int choice,data,target,h,greater,smaller,key,leaf,nonleaf,sum1,nodes;
    cout<<"Tree Data Structure\n";
    cout<<"1)Createnode\n2)Inorder\n3)Preorder\n4)Postorder\n5)Delete\n6)Height of tree\n7)Greatest node\n 8)Smallest node\n9)Searching\n10)Leaf node\n11)Non_leaf node\n12)Sum of node\n13)No of nodes\n14)Exit\n ";
    while(1)
    {
        cout<<"enter the choice:";
        cin>>choice;   
        switch (choice)
        {
            case 1:
                cout<<"CreateNode\n";
                cout<<"enter the data in the tree";
                cin>>data;
                root=createnode(root,data);
                cout<<"\n";
                break;
            case 2:
                cout<<"Indorder Traversal\n";    
                inorder(root);
                cout<<"\n";
                break;
            case 3:
                cout<<"Preorder Traversal\n";
                preorder(root);
                cout<<"\n";
                break;
            case 4:
                cout<<"Postorder Traversal\n";
                postorder(root);
                cout<<"\n";
                break;
            case 5:
                cout<<"Greatest node:";
                greater=greatest(root);
                cout<<greater;
                cout<<"\n";
                break;
            case 6:
                cout<<"Lowest Node:";
                smaller=lowest(root);
                cout<<smaller;
                cout<<"\n";
                break;
            case 7:
                cout<<"Delete Operation\n";
                cout<<"enter the data want to delete:";
                cin>>target;
                delete1(root,target);
            
                cout<<"\n";
                break;
            case 8:
                cout<<"Height of tree:";
                h=height(root);
                cout<<h;
                cout<<"\n";
                break;        
            case 9:
                cout<<"Search operation";
                cout<<"enter the element want to search";
                cin>>key;
                search(root,key);
                cout<<"\n";
                break;    
            case 10:
                cout<<"No of leaf nodes";
                leaf=leaf_nodes(root); 
                cout<<leaf;
                cout<<"\n";
                break;   
            case 11:
                cout<<"No of non leaf nodes";
                nonleaf=non_leaf(root);
                cout<<nonleaf;
                cout<<"\n";
                break;    
            case 12:
                cout<<"Sum of all the nodes";
                sum1=sum(root);
                cout<<sum1;    
                cout<<"\n";
                break;
            case 13:
                cout<<"Total No of nodes in tree";
                nodes=no_of_nodes(root);
                cout<<nodes;
                cout<<"\n";
                break;
            case 14:
                exit(0);    
            default:
            cout<<"give another choice:\n";
        }
    }
}