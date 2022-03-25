#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
const  int maxn = 100005;
int a[maxn];
int le[maxn];

int main()
{
    int n,m,l,r;
    cin>>n>>m;
    for(int i = 1; i <= n;++i){
        cin>>a[i];
        le[i] = le[i -1] + a[i];
    }
    while(m--){
        cin>>l>>r;
        cout<<le[r] - le[l - 1]<<endl;
    }
    return 0;
}