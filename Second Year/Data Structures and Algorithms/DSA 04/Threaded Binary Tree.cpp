#include<iostream>
using namespace std;
typedef struct bst
{
    int data;
    int lth,rth;
    struct bst *left,*right;    
}node;

class thread
{
    public:
    node *dummy;
    node *New,*root, *temp,*right;
    
    thread()
    {
        root=NULL;
    }
    void create();
    void display();
    void find();
    void delet();
};

void thread::create()
{
    void insert(node*,node*);
    New=new node;
    New->left=NULL;
    New->right=NULL;
    New->lth=0;
    New->rth=0;
    cout<<"\nEnter the element:";
    cin>>New->data;
    if(root==NULL)
    {
        root=New;
        dummy=new node;
        dummy->data=-999;
        dummy->left=root;
        root->left=dummy;
        root->right=dummy;
    }
    else
    insert(root,New);
}

void thread::display()
{
    void inorder(node *,node *dummy);
    if(root==NULL)
    cout<<"Tree is not created";
    else
    {
        cout<<"\n Tree is:";
        inorder(root,dummy);
    }
}

void thread::find()
{
    node *search(node *,node *,int,node **);
    node *temp,*parent;
    int key;
    cout<<"\n Enter the elements which u want to search";
    cin>>key;
    temp=search(root,dummy,key,&parent);
    if(temp==NULL)
    cout<<"\n Element is not present";
    else
    cout<<"\nIts parent node is:"<<parent->data;
}

void thread::delet()
{
    void del(node *,node *, int);
    int key;
    cout<<"\n Enter the element";
    cin>>key;
    del(root,dummy,key);
    
}

void insert(node *root,node *New)
{
    if(New->data<root->data)
    {
        if(root->lth==0)
        {
            New->left=root->left;
            New->right=root;
            root->left=New;
            root->lth=1;
        }
        else
        insert(root->left,New);
    }
    if(New->data>root->data)
    {
        if(root->rth==0)
        {
            New->right=root->right;
            New->left=root;
            root->rth=1;
            root->right=New;
        }
        else
        insert(root->right,New);
    }
}

node *search(node *root,node *dummy,int key,node **parent)
{
    node *temp;
    int flag=0;
    temp=root;
    while((temp!=dummy))
    {
        if(temp->data==key)
        {
            cout<<"\n The"<<temp->data<<"element is present";
            flag=1;
            return temp;
        }
        *parent=temp;
        if(temp->data>key)
            temp=temp->left;
        else
            temp=temp->right;
    }
    return NULL;
}

void del(node *root,node *dummy,int key)
{
    node *temp,*parent,*temp_succ;
    node *search(node *,node *,int,node **);
    int flag=0;
    temp=search(root,dummy,key,&parent);
    if(root==temp)
    {
        cout<<"\n Its root node which can not be deleted";
        return;
    }
    //deleting a node with two children
    if(temp->lth==1 && temp->rth==1)
    {
        parent=temp;
        temp_succ=temp->right; //finding inorder successor
        while(temp_succ->lth==1)
        {
            flag=1;
            parent=temp_succ;
            temp_succ=temp_succ->left;
        }
        if(flag==0)
        {
            temp->data=temp_succ->data;
            parent->right=temp_succ->right;
            parent->rth=0;
        }
        else
        //inorder successor is on left  subbranch and it has to be traversed
        {
            temp->data=temp_succ->data;
            parent->rth=0;
            parent->lth=0;
            parent->left=temp_succ->left;
        }
        cout<<"Now deleted it";
        return;
    }
    //deleting a node having only achild
    //the node to be deleted has left child
    if(temp->lth==1 && temp->rth==0)
    {
        if(parent->left==temp)
        {
            (temp->left)->right=parent;
            parent->left=temp->left;
        }
        else
        {
            (temp->left)->right=temp->right;
            parent->right=temp->left;
        }
        temp=NULL;
        delete temp;
        cout<<"Now deleted";
        return;
    }
    //the node to be deleted has right child
    if(temp->lth==0 && temp->rth!=0)
    {
        if(parent->left==temp)
        {
            parent->left=temp->right;
            (temp->right)->left=temp->left;
            (temp->right)->right=parent;
                    }
        else
        {
            parent->right=temp->right;
            (temp->right)->left=parent;
        }
        temp=NULL;
        delete temp;
        cout<<"\n Now delted";
        return;
    }
    //deleting a node which is having no child
    if(temp->lth==0 && temp->rth==0)
    {
        if(parent->left==temp)
        {
            parent->left=temp->left;
            parent->lth=0;
        }
        else
        {
             parent->right=temp->right;
            parent->rth=0;
        }
        cout<<"\n Now delted";
        return;
    }
}

void inorder(node *temp,node *dummy)
{
    while(temp!=dummy)
    {
        while(temp->lth==1)
        temp=temp->left;
        cout<<"  "<<temp->data;
        while(temp->rth==0)
        {
            temp=temp->right;
            if(temp==dummy)
            return;
            cout<<" "<<temp->data;
        }
        temp=temp->right;
    }
}

int main()
{
    int ch;
    char ans='N';
    thread th;
    do
    {
        cout<<"\n .....Threaded binary tree....";
        cout<<"\n 1. Create ";
        cout<<"\n 2. Display ";
        cout<<"\n 3. Search ";
        cout<<"\n 4. Delete \n";
        cin>>ch;
        switch(ch)
        {
            case 1: do
                    {
                        th.create();
                        cout<<"\n More elements?(Y/N)";
                        cin>>ans;
                    }while(ans=='y');
                    break;

            case 2: th.display();
                    break;

            case 3: th.find();
                    break;

            case 4: th.delet();
                    break;
        }
        cout<<"\n Want to go back to main menu";
        cin>>ans;
    }while(ans=='y');
    return 1;
}