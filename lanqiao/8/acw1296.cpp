#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500005;
#define INF 0x3f3f3f3f
typedef long long ll;
int s[maxn];
bool st[maxn];
int prime[maxn],cnt;

void get_prime(int n){
    for(int i = 2;i <= n;i++){
        if(!st[i]) prime[cnt++] = i;
        for(int j = 1;j <= n; ++j){
            st[i * j] = true;
            if(prime[j] % i == 0)   break;
        }
    }
}

void dfs(int last,int prod ,int s)
{
    if(s == 1)
        
    for(int i = 1;i <= )

}

int main()
{
    int k;
    get_prime(maxn - 1);
    cin>>k;
    for(int i = 1;i <= k; i++){
        cin>>s[i];
        dfs()
    }
    
    return 0;
}