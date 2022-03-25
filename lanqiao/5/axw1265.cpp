#include<bits/stdc++.h>
using namespace std;
const int maxn = 32005;
typedef pair<int ,int> PII;
int tr[maxn];
int n;
int ans[maxn];

int lowbit(int x){
    return x & -x;
}

void add(int x,int v)
{
    for(int i = x; i < maxn ; i += lowbit(i)){
        tr[i] +=v ;
    }
}

int querry(int x){
    int res = 0;
    for(int i = x;i; i-= lowbit(i)){
        res += tr[i];
    }
    return res; 
}

int main()
{
    int x,y,ny,nx;
    cin>>n;
    for(int  i = 1; i<= n;i++){
        cin>>x>>y;
        x++;
        int t = querry(x);
        ans[t]++;
        add(x,1);
    }
    for(int i = 0 ;i < n;i++)
        cout<<ans[i]<<endl;
    return 0;
}