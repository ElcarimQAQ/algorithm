#include <bits/stdc++.h>
using namespace std;
const int N = 200000005;
int vis[N];

int check(int n){
    int N = n;
    int cnt= 0;
    bool flag1 = false, flag2 = false; 
    while (n > 0)
    {
        if(vis[n]){
            vis[N] = cnt + vis[n];
            return vis[N];
        }
        if (n % 10 == 6 || n % 10 == 8)
        {
            if (n % 10 == 6) {
                cnt++;
                flag1 = true;
            }
            if (n % 10 == 8) {
                flag2 = true;
            }
        }
        n /= 10;
    }
    if (flag1 && flag2) {
        vis[N] = cnt;
        return cnt;
    }
    else
        return 0;
}


int main()
{
    int t, a ,b;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        int cnt = 0;
        for(int i = b; i >= a; i--){
            int x = check(i);
            if(x != 0){
                cnt += x;
            }
        }
        cout<<cnt<<'\n';
    }
    
    return 0;
}