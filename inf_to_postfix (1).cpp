#include <iostream>
#include <stack>

using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
 
        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    //cout << result << endl;
    return result;

}
void infixToPrefix(string s){
    string a;
    for (int i = 0; i < s.length(); i++) {
        if(s[s.length()-i-1]=='('){
            a=a+')';
        }
        else if(s[s.length()-i-1]==')'){
            a=a+'(';
        }
        else{
            a=a+s[s.length()-i-1];
        }
    
        
    }
    //cout<<a<<endl;
    string b;
    b=infixToPostfix(a);
    //cout<<b<<endl;
    string c;
    for (int j = 0; j < b.length(); j++) {
        c=c+b[b.length()-j-1];
    }
    cout<<"Prefix Expression:  "<<c<<endl;


}
int main(){
    string s;
    cout<<"Enter infix Expression  ";
    cin>>s;
    cout<<"Potfix Expression:  "<<infixToPostfix(s)<<endl;
    infixToPrefix(s);
   
    return 0;
}