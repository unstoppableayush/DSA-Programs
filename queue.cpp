#include<iostream>
using namespace std;
#define max 6
int queue[max];
int rear=-1;
int front=-1;
void enqueue(int val){
    if(rear==max-1){
        cout<<"Queue Overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=val;
    }
    else{
        rear++;
        queue[rear]=val;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue Underflow"<<endl;
    }
    else if(front==rear){
        cout<<"The Dequeued element is :"<<queue[front]<<endl;
        rear=-1;
        front=-1;     
    }
    else{
        cout<<"The Dequeued element is :"<<queue[front++]<<endl;
    }
}
void display(){
    int i=0;
    if(rear==-1 && front==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Elements of Queue:"<<endl;
        for(i=front;i<rear+1;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int ch , value;
    cout<<"Enter 1 to display"<<endl
    <<"Enter 2 to Perform Enqueue"<<endl
    <<"Enter 3 to perform Dequeue"<<endl
    <<"Enter 4 to exit"<<endl;
    
    do{
        cout<<endl;
        cout<<"Enter Your Choice:"<<endl;
        cin>>ch;
        switch(ch){
        case 1:
            display();
            break;
        case 2: 
                cout<<"Enter Value to insert:";
                cin>>value;
                enqueue(value);
                break;
        case 3: 
                dequeue();
                break;
        case 4:
                exit(1);
        }
    }
    while(1);
}