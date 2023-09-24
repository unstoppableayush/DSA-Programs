#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=0;
    int temp[ub-lb+1];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int i=lb;i<=ub;i++){
        arr[i]=temp[i-lb];
    }
}
void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(){
    int ub=6;
    int arr[ub]={3,5,2,1,0,9};
    mergesort(arr,0,ub-1);
    for(int i=0;i<ub;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}