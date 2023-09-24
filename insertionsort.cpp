#include<iostream>
using namespace std;
int main(){
    int i,n=8,j,temp;
    int arr[n]={2,6,4,7,5,1,9,0};
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"Sorted array : ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}