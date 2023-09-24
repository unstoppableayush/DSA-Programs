//program to coutn odd numbers, even numbers and multiple of 3
/*
#include<iostream>
using namespace std;
int main(){
    int N,             //input number
    counterofodds=0, //counter of odd numbers
    countermultiple=0; //counter of multiple of 3

    do{
        cout<<"Enter Number(-1 to finish): ";
        cin>>N;
        if(N!=-1) 
        {
            if(N%2==1) counterofodds++;
            if(N%3==0) countermultiple++;
        }
    }while(N!=-1);

    cout<<"Number of odd numbers: "<<counterofodds<<endl;
    cout<<"Number of multiple of 3 : "<<countermultiple;

    return 0;

}
*/
//Now same program using class

#include<iostream>
using namespace std;
class Counter{
    public:
        Counter(int N=0){
            data=N;     //Constructor defalult value will be zero
        }
        void increment(int d=1){
           
            data=data+d;
        }
        int getvalue(){
            return data;  //return the current count
        }
    private:
        int data;         //stores the count
};
int main(){
    int N;
    Counter counterofodds , countermultiple , counterofevens;
    do
    {
        cout<<"Enter Number (Enter -1 to finish): ";
        cin>>N;
        if(N!=-1)
        {
            if(N%2==1)
            {
                counterofodds.increment();
            }
            if(N%2==0){
                counterofevens.increment();
            }
            if(N%3==0){
                countermultiple.increment();
            }
        }

    }while(N!=-1);

    
        cout<<"Number of odd numbers : "<<counterofodds.getvalue()<<endl;
        cout<<"Number of even numbers : "<<counterofevens.getvalue()<<endl;
        cout<<"Number of multiple of 3 : "<<countermultiple.getvalue();

    return 0;
}