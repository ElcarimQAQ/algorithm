#include <bits/stdc++.h>
using namespace std;
string str;
stack<char> st;

int checks(int x);
int checkb(int x);
int checkm(int x);

int checks(int x){
    for( int i = x+1; i< str.length();i++){
        if(str[i] == '{'){
            if(checkb(i) == 0)
                return 0;
        }
        if(str[i] == '}'){
            cout<<"?"<<endl;
            return 1;
        }
        else
            return 0;
    }
    return 1;
}

int checkb(int x){
    for( int i = x+1; i< str.length();i++){
        if(str[i] == '['){
            if(checkm(i) == 0)
                return 0;
        }
        if(str[i] == ']'){
             cout<<"?"<<endl;
            return 1;
            }
        else
            return 0;
    }
    return 1;
}

int checkm(int x){
    for( int i = x+1; i< str.length();i++){
        if(str[i] == '('){
            if(checks(i) == 0)
                return 0;
        }
        if(str[i] == ')')
            return 1;
        else
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        cin>>str;
        int ans = 0;
        if(str[0] == '(')
            ans = checks(0);
        if(str[0] == '[')
            ans = checkm(0);
        if(str[0] == '{')
            ans = checkb(0);
        // for(int i = 0;i< str.length();i++){
        //     st.push(str[i]);
        //     if(str[i] == '('){
                
        //     }
        // }
        cout<<ans<<endl;
    }


}