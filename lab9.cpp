#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *n = new Node();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct Node *search(struct Node *root,int data)
{
    if(root==NULL)
    return NULL;
    if(data==root->data)
    return root;
    else if(data<root->data)
    {
        return search(root->left,data);
    }
    else 
    {
        return search(root->right,data);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" -> "<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void Inorder(struct Node* root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" -> "<<endl;
        Inorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" -> "<<endl;
    }
}
struct Node *Insert(struct Node *root,int data)
{
    struct Node *prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(data==root->data)
        {
        return root;
        }
        else if(data<root->data)
        {
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
    struct Node *ptr = createNode(data);
    if(data<prev->data)
    {
        prev->left=ptr;
    }
    else
    {
        prev->right=ptr;
    }
}
struct Node *inorderpresessor(struct Node *root)
{
    root = root->left;
    while(root->right!= NULL)
    {
        root=root->right;
    }
    return root;
}

struct Node *deletion(struct Node *root,int value)
{
    struct Node *ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(value < root->data)
    {
   root->left = deletion(root->left,value);
    }
    else if(value > root->data)
    {
        root->right=deletion(root->right,value);
    }
    else{
        ipre = inorderpresessor(root);
        root->data=ipre->data;
        root->left=deletion(root->left,ipre->data);

    }
return root;
}
int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
     
  
    // cout<<"PREORDER"<<endl;
    // preorder(p);
    // cout<<"\nINORDER"<<endl;
    // Inorder(p);
    // cout<<"\nPOSTORDER"<<endl;
    // postorder(p);
   
   //search function
//    struct Node *n = search(p,5);
//    if(n!=NULL)
//    {
//        cout<<"Found:"<<n->data;
//    }
//    else 
//    {
//        cout<<"Element Not Found";
//    }

//insert function
// Insert(p,7);

p:
int choice;
cout<<"------------------------------------------------------------------------"<<endl;
cout<<"|\t\t\t\t\t\t\t\t\t|"<<endl;
cout<<"|\t\t\t\t\t\t\t\t\t|"<<endl;
cout<<"|\t\t\t\t\t\t\t\t\t|"<<endl;
cout<<"\t\t\t|----------LAB 9-------------";
cout<<"|\t\t\t\t\t\t\t\t\t|"<<endl;
cout<<"|\t\t\t\t\t\t\t\t\t|"<<endl;
cout<<"|\t\t\t\t\t\t\t\t\t|"<<endl;
cout<<"-----------------------------------------------------------------------"<<endl;
cout<<"PRESS 1 TO INSERT NEW NODE"<<endl;
cout<<"PRESS 2 TO IN-OREDER TRAVERSAL"<<endl;
cout<<"PRESS 3 TO PRE-ORDER TRAVERSAL"<<endl;
cout<<"PRESS 4 TO POST-ORDER TRAVERSAL"<<endl;
cout<<"PRESS 5 FOR DELETION"<<endl;
cout<<"PRESS 6 TO SEARCH"<<endl;;
cin>>choice;
switch(choice)
{
    case 1:
    Insert(p,5);
    cout<<p->right->right->data<<": Inserted ";
    cout<<endl;
    break;

    case 2:
    cout<<"\nINORDER:"<<endl;
    Inorder(p);
    break;

    case 3:
    cout<<"PREORDER:"<<endl;
    preorder(p);
    break;

    case 4:
    cout<<"\nPOSTORDER:"<<endl;
    postorder(p);
    break;

    case 5:
    int y;
    cout<<"eneter element to be deleted:";
    cin>>y;
    deletion(p,y);
    break;

    case 6:
    int z;
    cout<<"eneter elemnt to be searched:";
    cin>>z;
    struct Node *n = search(p,z);
  { if(n!=NULL)
   {
       cout<<"Found:"<<n->data<<endl;
   }
   else 
   {
       cout<<"Element Not Found"<<endl;
  }
  }
}
goto p;
    return 0;
}