#include<iostream>
using namespace std;
int main(){
    int arr[8]={2,4,5,6,7,8,9,10};
    int beg=0,end=7,pos=-1,val,mid;
    cout<<"Enter value to search:";
    cin>>val;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==val){
            pos=mid;
            cout<<"Element is found at index :"<<pos;
            break;
        }
        else if(arr[mid]>val){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    if(pos==-1){
        cout<<"Element is not present in given array!";
    }
    return 0;
}