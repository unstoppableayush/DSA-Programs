#include<iostream>
using namespace std;
selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }        
        }
        if(min!=i){
            int temp;
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}
int main(){
    int i=0,n=8,j,min;
    int arr[n]={2,6,4,7,5,1,9,0};
    
    selectionsort(arr,n);
    cout<<"Sorted array : ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}




// for(i=0;i<n-1;i++){
    //     min=i;
    //     for(j=i+1;j<n;j++){
    //         if(arr[j]<arr[min]){
    //             min=j;
    //         }        
    //     }
    //     if(min!=i){
    //         int temp;
    //         temp=arr[i];
    //         arr[i]=arr[min];
    //         arr[min]=temp;

    //     }
    // }
    // cout<<"Sorted array : ";
    // for(i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }