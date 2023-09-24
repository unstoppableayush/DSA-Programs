#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
        //This function used for return operator precedence
        int prec(char op){
            if(op=='^'){
                return 3;
            }
            else if(op=='*' || op=='/'){
                return 2;
            }
            else if(op=='+' || op=='-'){
                return 1;
            }
            else{
                return -1;
            }
            

        }
        void infixToPrefix(string s){
                    stack<char> st;
                    string result;
                    for(int i=s.length();i>=0;i--){
                            char c=s[i];  // caracter by character looping
                            //If the scanned character is operand then print to the output
                            if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
                                result += c;
                            }
                            else if(c==')')
                            st.push(')');
                            else if(c=='('){
                                while(st.top()!=')'){
                                    result = result + st.top();
                                    st.pop();
                                }
                                st.pop();
                            }
                            else{
                                while(!st.empty() && prec(s[i])<= prec(st.top())){
                                    result = result + st.top();
                                    st.pop();
                                }
                                st.push(c);
                            }
                    }
                    while(!st.empty()){
                        result=result+st.top();
                        st.pop();
                    }
                    string res;
                    for(int i=result.length() ; i>=0;i--){
                        res=res+result[i];

                    }
                    cout<<"Prefix : "<<res<<endl;
            }
};
int main(){
    Stack obj;
    string exp;
    char choice;
    do{
        cout<<"Enter Infix Expression : ";
        cin>>exp;
        //K+L-M*N+(O^P)*W/U/V*T+Q
        //output:+K-L+*MN+*^OP/W/U*VTQ
        obj.infixToPrefix(exp);
        cout<<endl;
        cout<<"Do you want to try another expression [Y/N] : "<<endl;
        cin>>choice;
    }
    while(choice=='Y' || choice=='y');
    
    return 0;
}