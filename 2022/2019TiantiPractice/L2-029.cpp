#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10005;
int p[maxn] = {0};
int xf[maxn];
int a,b;

void InitPrime(int x) {
    for(int i = 2 ;i <= sqrt(x) + 5; i++) {
        for(int j = 2; j * i <= x; j++) {
            p[i * j] = 1;
        }
    }
}

int judge(int x){
    int vis[maxn] = {0};
    int next = x;
    vector<int> save;
    bool flag = false;
    while(next != 1 && vis[next] != 1) {
        x = next;
        next = 0;
        vis[x] = 1;
        while(x > 0) {
            next += (x%10) *(x%10);
            x /= 10;
        }
        save.push_back(next);
    }
    if(next != 1)  return 0;
    for(auto v : save) {
        if(v >= a && v <= b)
            xf[v] = 0;
    }
    return save.size();
}

int main() 
{
    std::ios::sync_with_stdio(false);
    cin>>a>>b;
    InitPrime(b);
    p[1] = 1;
    memset(xf ,1 ,sizeof xf);
    for(int i = a;i <= b; i++) {
        if(!xf[i]) continue;
        xf[i] = judge(i);
        if(!p[i]) 
            xf[i] *= 2;
    }
    bool flag = false;
    for(int i = a;i <= b; i++) {
        if(xf[i] != 0) {
            cout<<i<<" "<<xf[i]<<endl;
            flag = true;
        }
    }
    if(!flag) puts("SAD");
    return 0;
}