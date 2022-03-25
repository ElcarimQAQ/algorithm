#include <bits/stdc++.h>
using namespace std;
string str;

int check(char c,char x){
    if (c == '(' && x == ')')
        return 1;
    if (c == '[' && x == ']')
        return 1;
    if (c == '{' && x == '}')
        return 1;
    return 0;
        
}

int check2(char c,char x){
    if (c == '(' && x == '{')
        return 1;
    if (c == '[' && x == '(')
        return 1;
    if (c == '{' && x == '[')
        return 1;
    return 0;
        
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        stack<char> st;
        cin>>str;
        // cout<<str.length();
        int ans =1;
        for(int i = 0; i < str.length() - 1;i++ ){
            // cout<<i<<endl;
            if(str[i] == ')' || str[i] == ']'||str[i] == '}' ){
                char c = st.top();
                // cout<<st.size()<<" "<<str[i]<<endl;
                if(st.size() != 0)
                    st.pop();
                if(check(c,str[i]) == 0){
                    ans = 0;
                    break;
                }
                if(st.empty()){
                    // cout<<"empty"<<endl;
                    continue;
                }
                char la = st.top();
                //if(str[i] == '}') cout<<la<<" "<<c<<endl;
                if(check2(la,c) == 0){
                    ans = 0;
                    break;
                }
            }  
            else {
                st.push(str[i]);
                // cout<<str[i]<<endl;
            }
        }
        // cout<<"?"<<endl;
        if(ans == 0)    cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;


}