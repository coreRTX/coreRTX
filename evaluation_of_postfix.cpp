#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
int evaluate(string s)
{
    stack<float> st;
    string result;
    float r;
 
    for (int i = 0; i < s.length(); i++) {
        float a;
        float b;
        
        if(s[i]=='+'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            
            r=b+a;
            
            st.push(r);
        }
        else if(s[i]=='-'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            r=b-a;
            st.push(r);
        }
        else if(s[i]=='*'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            r=b*a;
            st.push(r);
        }
        else if(s[i]=='/'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            r=b/a;
            st.push(r);
        }
        else if(s[i]=='^'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            r=pow(b,a);
            st.push(r);
        }
        else{
            
            int b=s[i]-48;
        
            st.push(b);
            

        }
    }
    cout<<r;
    return r;
    
}
int main(){
    string s;
    cout<<"Enter postfix Expression  ";
    cin>>s;
    evaluate(s);
    

}