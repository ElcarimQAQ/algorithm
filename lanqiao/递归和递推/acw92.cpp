#include <bits/stdc++.h>
using namespace std;
int a[20];
 int n;
void dfs(int l,int cnt){
    if(l > cnt){
        for(int i =1;i <= cnt;++i)
            cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = 0;i <= n; ++i){
        if(i <= a[l - 1])
            continue;
        a[l] = i;
        dfs(l + 1,cnt);
    }
}
int main()
{
    cin>>n;
    cout<<endl;
    for(int i =1;i <= n; ++i)
        dfs(1,i);

}