#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }

};
void preoder( struct Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}
void inorder( struct Node *node){
    if(node==NULL){
        return ;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void postorder( struct Node *node){
    if(node==NULL){
        return ;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
int main(){
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);

    cout<<"Preorder : ";
    preoder(root);
    // 1 2 5 3
    cout<<endl;

    cout<<"Inorder : ";
    inorder(root);
    //2 5 1 3
    cout<<endl;

    cout<<"Postorder : ";
    postorder(root);
    //5 2 3 1
    cout<<endl;
    return 0;
}
