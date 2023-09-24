#include<iostream>
using namespace std;
int main(){
    int val,i=0,n=7,pos=-1;
    int arr[n]={2,4,6,7,9,10,5};
    cout<<"Enter Value you want to search:";
    cin>>val;
    while(i<=n){
        if(arr[i]==val){
            pos=i;
            cout<<"Element is found at index: "<<i;
            break;
        }
        i++;
    }
    if(pos==-1){
        cout<<"Element is not present in given array!";
    }
    return 0;
}