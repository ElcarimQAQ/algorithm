#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 505;
int w[maxn], g[maxn][maxn];
int st[maxn],dis[maxn],cnt[maxn],num[maxn];
int n, m, c1, c2;

void dij() {
    memset(dis, INF, sizeof(dis));
    dis[c1] = 0,cnt[c1] = 1,num[c1] = w[c1];

    for(int i = 0;i < n; i++) {
        int t = -1;
        //������ӿ���һ���꣬���������������������ÿһ���ҵ����ڼ����о�����С�ĵ�t��ÿһ�ζ���������û�ù���t����һ�λ�ѳ��������
        for(int j = 0; j< n; j++) 
            if(st[j] == 0 && (t == -1 || dis[t]  > dis[j] )) 
                t = j;
        
        st[t] = 1;

        for(int j = 0; j < n; j++) {
            if(dis[j] > dis[t] + g[t][j]) {
                dis[j] = dis[t] + g[t][j];
                cnt[j] = cnt[t];
                num[j] = num[t] + w[j];
            }else if(dis[j] == dis[t] + g[t][j]) {
                cnt[j] += cnt[t] ;
                num[j] = max(num[j] , num[t] + w[j]);
            }
        }
    }
} 

int main() {
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>c1>>c2;
    for(int i = 0;i < n; i++) 
        cin >> w[i];
    int u,v,l;
    memset(g, INF, sizeof(g));
    while(m--) {
        cin>> u >> v >>l;
        g[u][v] = g[v][u] = min(l, g[u][v]);
    }

    dij();
    cout<<cnt[c2] <<' '<<num[c2]<<endl;

    return 0;
}