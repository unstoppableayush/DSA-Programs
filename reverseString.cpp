#include<iostream>
using namespace std;
int main(){
    string st="Ayush";
    string temp;
    for(int i=st.length() ; i>=0;i--){
        temp=temp+st[i];

    }
    cout<<temp;
    return 0;
}