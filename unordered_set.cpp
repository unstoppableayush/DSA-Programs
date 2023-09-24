#include<iostream>
#include<unordered_set>
using namespace std;
/*
unordered_set<int> b : On an average , each operation like insert , find and delete takes O(1) time on average .
 Worst Case can take O(N) time for each operation but it rarely occurs.
 Elements are unordered and unique(not redundent)
*/
int main(){
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(5);
    if(s.find(5)==s.end()){    //find , finds the elmenents in unod_set
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }
    for(auto it=s.begin(); it!=s.end() ;it++){
        cout<<(*it)<<endl;
    }
    s.clear();               //removes all of the elements from an unordered_set and empties it. 
    cout<<s.size()<<endl;   //return size of unordered set

    s.insert(5);
    s.insert(10);
    s.insert(8);

    s.count(10);            //represnts how many times 10 is present
    if(s.count(9)==0){
        cout<<"Not present"<<endl;
    }
    else{
        cout<<"Present"<<endl;
    }
    s.erase(10);            //remove the element
    cout<<s.size();
    s.erase(s.begin(),s.end());
    return 0;
}