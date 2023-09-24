#include<iostream>
using namespace std;

//Making Template of Node
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    
};
struct Node *create(){
    int x;
    struct Node *newnode=new Node();
    cout<<"Enter Data(-1 for no node):"<<endl;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    (*newnode).data=x;
    cout<<"Enter left child of "<<x<<endl;
    newnode->left=create();
    cout<<"Enter right child of "<<x<<endl;
    newnode->right=create();
    return newnode;
}
void preorder(struct Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
     

}
void postorder(struct Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
     cout<<root->data<<" ";

}
int main(){
    struct Node *root;
    root=NULL;
    root=create();
    cout<<"Preoder Traversal:"<<endl;
    preorder(root);
    cout<<endl<<"inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl<<"Postorder Traversal:"<<endl;
    postorder(root);
    return 0;
}