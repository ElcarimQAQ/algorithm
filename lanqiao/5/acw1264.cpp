#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int s[maxn],tr[maxn];
int n,m,a,b,k;

int  lowbit(int x){
    return x & -x;
}

void add(int x,int v)
{
    for(int i = x; i <= n;i += lowbit(i))
        tr[i] +=v ;
}
int querry(int x){
    int  res = 0;
    for(int i = x;i ;i -= lowbit(i))
        res += tr[i];
    return res;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i= 1;i <= n; ++i) 
    {   
        cin>>s[i];
        add(i,s[i]);
    }
    while(m--){
        cin>>k>>a>>b;
        if(k == 1){
            add(a,b);
        }
        if(k == 0)
            cout<<querry(b)-querry(a - 1)<<endl;
    }
    return 0;
}