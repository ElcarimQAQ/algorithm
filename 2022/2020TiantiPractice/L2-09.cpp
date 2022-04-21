#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10005;
stack<int> s1;
stack<char> s2;

int main() 
{
    std::ios::sync_with_stdio(false);
    int n, a,b;
    char op;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;
        s1.push(a);
    }
    for(int i = 0;i < n - 1; i++){
        cin>>op;
        s2.push(op);
    }
    while(!s1.empty() || !s2.empty()) {
        a = s1.top();
        s1.pop();
        if(!s1.empty()){ 
            b = s1.top();
            s1.pop();
        } else {
            cout<<a<<endl;
            break;
        }
        op = s2.top();
        s2.pop();
        int c;
        if(op == '/' ){
            if( a == 0) {
                printf("ERROR: %d/0", b);
                break;
            }
            c = b/a;
        }else if(op == '*') c = b * a;
        else if (op == '-') c = b - a;
        else c = b + a;
        s1.push(c);
    }

    
    return 0;
}