#include<iostream>
#include<vector>
using namespace std;    
void merge(int arr[], int l, int m, int r)
    {
         vector<int> temp;
         int mid=m;
         int left=l;
         int right=m+1;
         int high=r;
         while(left<=mid && right<=high){
             if(arr[left]<=arr[right]){
                 temp.push_back(arr[left]);
                 left++;
             }else{
                 temp.push_back(arr[right]);
                 right++;
             }
         }
         if(left<=mid){
             while(left<=mid){
                 temp.push_back(arr[left]);
                 left++;
             }
         }
         else{
             while(right<=high){
                 temp.push_back(arr[high]);
                 right++;
             }
         }
         for(int i=l;i<=r;i++){
             arr[i]=temp[i-l];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
    int main(){
        int arr[6]={4,3,2,1,6,4};
        mergeSort(arr,0,6-1);
        for(int i=0;i<6;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
    }