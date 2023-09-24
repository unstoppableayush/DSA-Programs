#include<iostream>
using namespace std;
#define max 6
int front=-1;
int rear=-1;
int queue[max];
void enqueue(int data){
    if(front==-1 && rear ==-1){
        front=0;
        rear=0;
        queue[rear]=data;
    }
    else if((rear+1)%max==front){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=data;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else if(front==rear){
        cout<<"Dequeued Element is :"<<queue[front];
        rear=front=-1;
    }
    else{
        cout<<"Dequeued Element is :"<<queue[front];
        front=(front+1)%max;
    }
}
void display(){
    int i=0;
    if(rear==-1 && front==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        int i=front;
        cout<<"Elements of Queue:"<<endl;
        while(i!=rear){
            cout<<queue[i]<<" ";
            i=(i+1)%max;
        }
        cout<<queue[rear];
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
    return 0;
}