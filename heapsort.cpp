// What is Heap?
// => Heap is a complete binary tree that comes with a heap order property
// What is CBT?
// => Every level is completely filled except the last level
// =>Nodes always added from the left .

//         0
//     /  \ 
//     1    2
//     / \
//     3   4

//     Heap Order property
//     ________|_________
//     |                 |
// Max Heap        Min Heap
//     (60)             (30)
//     /    \            /   \
// (50)     (40)     (40)   (50)
// /  \              /   
// (30) (20)        (60)

//     _______________________________
// | x  | 60 | 50 | 40 | 30 | 20 | 

// Node = i th index
// left child = 2*i index
// right child= 2*i + 1 index
// parent = (i/2)


//          Deletion
// ---------------------------
//      R         Step 1 : Swap(put) root node with last node
//     (55)       --------
//     /  \      Del R          (52)
//   (54)  (53)    =>           /   \
//   /  \                     (54)   (53)
// (50) (52)                  /  \
//                          (50) (52)

//         step 2 : Remove last node
//                      R
//                     (52)
//                     /  \
//                   (54)  (53)
//                   /  
//                (50)  

//         step 3 : Propagate root node to its correct position


//         Heapify algorithm
// -----------------------------------

//             Heap Sort
// ---------------------------------------
// Algo =>  while(heapsize>1)
//              1. swap a[1] (root) -> a[n] (last node)
//              2. root node -> coorect position

//              {70 , 60 , 55 , 45 , 50}
// max-heap

//       (70)                 (50)               (60)  
//       /   \                /   \             /    \
//     (60)   (55)  =>     (60)   (55)  =>    (50)    (55)
//     /   \               /  \                /
//    (45) (50)          (45)  (70)           (45)

//                 {60, 50 , 55 , 45 | 70}   size-- // 70 deleted
//                                           size=4
//                 {45 , 50 , 55 | 60 , 70}  size-- // 60 deleted
//                                           size=3
//                 {45 , 50 | 55 , 60 , 70}  size-- // 55 deleted
//                                           size=2
//                 {45 | 50 , 55 , 60 , 70}  size-- //50 deleted
//                                           size=1                        
//                  Element is now sorted


                    

#include<iostream>
#include<queue>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;
    
    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index]=val;
        
        while(index > 1){
            int parent = index / 2;

            if(arr[parent] < arr[index]){
                swap(arr[index] , arr[parent]);
            }
            else{
                return;
            }
        }

        //T.C = O(logn)
    }
    void print(){
        for(int i=1 ; i <= size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        } 

        arr[1]=arr[size];  //step 1 : puting the last value at first
        size--;            //step 2 : removing the last node

        int i = 1;
    while(2 * i <= size){  // Adjusting the heap starting from the root
        int leftindex = 2 * i;
        int rightindex = 2 * i + 1;
        int maxIndex = i;

        // Check if left child is greater than parent
        if(arr[leftindex] > arr[i]){
            maxIndex = leftindex;
        }

        // Check if right child is greater than parent or left child
        if(rightindex <= size && arr[rightindex] > arr[maxIndex]){
            maxIndex = rightindex;
        }

        if(maxIndex != i){  // If a child is greater, swap with the parent
            swap(arr[i], arr[maxIndex]);
            i = maxIndex;  // Update the current index to the swapped index
        } else {
            return;  // If no swap needed, break the loop
        }
    }
    }
};

void heapify(int arr[], int size , int i){
    int largest = i; // assume current index is largest
    int left = 2*i ;  //left child index
    int right = 2*i + 1; //right child index

    if( left <= size && arr[left] > arr[largest] ){
        largest = left;
    }
    if( right <= size && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);  //swap the root with largest
        heapify(arr , size , largest); //hepify the affected sub tree
    }
    //T.C -  O(logn)
}

void heapSort(int arr[] , int n){
    int size = n;
    while(size > 1){
        //step1 : swap
        swap(arr[size] , arr[1]);    
        size--;

        //step 2
        heapify(arr, size , 1);
        
    }
}
int main(){
    Heap hp;
    hp.insert(55);
    hp.insert(60);
    hp.insert(70);
    hp.insert(30);

    hp.print();
    hp.deletefromHeap();

    //Heapify
    int arr[6]={-1,54,53,55,52,50};
    int n=5;

    //heap creation
    for(int i=n/2 ; i>0 ; i--){
        heapify(arr, n , i);
    }
    cout<<"priting the array after heapify : "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    //heapsort

    heapSort(arr,n);
    cout<<"printing the array after heap sort: "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    //priority queue
    cout<<"heap using priority queue"<<endl;

    //maxheap
    cout<<"maxheap using priority queue"<<endl;

    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(5);
    pq.push(10);

    cout<<"Elemnet at Top :"<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top: "<<pq.top()<<endl;
    cout<<"Size of pq is :"<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }

    //min heap
    cout<<"minheap using priority queue"<<endl;

    priority_queue<int , vector<int> , greater<int> > minheap;

    minheap.push(1);
    minheap.push(2);
    minheap.push(5);
    minheap.push(10);

    cout<<"Element at Top :"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top: "<<minheap.top()<<endl;
    cout<<"Size of pq is :"<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }


    return 0;
}
