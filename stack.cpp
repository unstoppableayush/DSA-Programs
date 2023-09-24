#include<iostream>
using namespace std;
#define max 6
int stack[max] , top=0;
void push(int val){
    if(top==max){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top=top+1;
        stack[top]=val;
        cout<<"Element "<<val<<" is pushed into stack "<<endl;
    }
}
void pop(){
    if(top==0){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<"Popped element is "<<stack[top--]<<endl;
    }
}
void display(){
    int i;
    if(top<=0){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Elements are :"<<endl;
        for(i=1;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int data,ch;
    
        cout<<"Enter 1 to Display"<<endl
        <<"Enter 2 to Push"<<endl
        <<"Enter 3 to Pop"<<endl
        <<"Enter 4 to Exit "<<endl<<endl;
    do{
        
        cout<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        
        
        switch(ch){
            case 1: 
                display();
                break;
            case 2:
                cout<<"Enter data to push: ";
                cin>>data;
                push(data);
                break;
            case 3:
                pop();
                break;
            case 4:
                exit(1);
            default:
                cout<<"Enter Valid Choice !!";
        }
    }
    while(1);

    return 0;
}