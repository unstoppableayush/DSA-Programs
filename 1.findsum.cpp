//find sum of 1d array 
#include<iostream>
using namespace std;
int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int array[5]={4,5,6,2,3};
    cout<<"Sum:"<<sum(array,5);
    return 0;
}