#include<iostream>
using namespace std;
int partition(int arr[],int s, int e){
    
    
    int index =s; 
    for(int i=s+1;i<=e;i++){
        if(arr[s]>arr[i]){
            index++;
        }
    }

    swap(arr[s],arr[index]);
    int q =arr[index];

    while(index > s && index <e){
        while(arr[s]<q){
            s++;
        }
        while(arr[e]>q){
            e--;
        }
        if(s <index && e> index){
            swap(arr[s++],arr[e--]);
        }
        
    }

    return index;

}
void quickSort(int *arr,int s,int e){

    //Base case

    if(s>=e){
        return;
    }

    int index = partition(arr,s,e);
    quickSort(arr,s,index-1);
    quickSort(arr,index+1,e);
}
int main(){
    int arr[9]={13,34,8,10,45,67,78,90,65};
    int n=9;
    cout<<"Hello Abhishek"<<endl;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}