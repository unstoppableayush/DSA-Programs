#include<iostream>
using namespace std;
int main(){
    int i,j,temp,flag,n=6;
    int arr[n]={3,7,8,9,2,1};
    for(int i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    cout<<"Sorted array : ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}