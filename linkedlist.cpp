#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void insert(int newdata){
        struct Node* newnode=new Node;
        Node *temp;
        newnode->data=newdata;
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
            // At last
            // newnode->next = head;
            // head = newnode;
        } 
}
void traverse(){
    Node* temp=head;
    
    if(temp==NULL){
        cout<<"Linked list doesn't exist!"<<endl;
    }
    else{
        cout<<"Elements are:"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
   
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    traverse();

   return 0;
}