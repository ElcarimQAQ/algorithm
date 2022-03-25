#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 10005;
int pre[maxn];
int p[maxn];
int vis[maxn];
set<int> mp;
void init(){
    for(int i = 1;i <= maxn;i++){
        pre[i] = i;
    }
}

int find(int x){
    if(pre[x] == x)
        return x;
    else
        return pre[x] = find(pre[x]);
}

void merge(int a,int b)
{
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        pre[max(pa,pb)] = min(pa,pb);
    }
}

int count()
{
	int cnt = 0;
	for (int i = 1; i <= maxn; i++){
		if (find(i) == i && vis[i])
			cnt++;
    }
	return cnt;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,q;
    cin>>t;
    init();
    while(t--){
        cin>>n;
        for(int i = 1;i <= n;i++)
            cin>>p[i];
        sort(p+1,p+1+n);
        for(int i = 1;i <= n;i++){
            vis[p[i]] = 1;
            if(i != 1)
                merge(p[i],p[i-1]);
        }
    }
    cin>>q;
    int x,y;
    int cnt =0;
    for(int i = 1;i <= maxn;i++){
        if(vis[i]){
            cnt++;
         //   mp.insert(pre[i]);
        }
    }
    int cnt2 = count(); 
    cout<<cnt<<" "<<cnt2<<endl;
    while(q--){
        cin>>x>>y;
        if(find(x) == find(y))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
