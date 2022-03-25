#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define F first
#define S second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
int a[MAX],d[MAX],n;
int main()
{
	//freopen("data.in","r",stdin);
    //freopen("2.out","w",stdout);
	int t,iCase=0;
	cin>>t;
	while(t--) {
		scanf("%d",&n);
		for(int i = 1; i<=n; i++) scanf("%d",a+i);
		a[n+1]=0;
		for(int i = 1; i<=n+1; i++) d[i] = a[i] - a[i-1];
		int cur = 4,flag = 1;
		for(int i = 1; i<=n-2; i++) {
			if(d[i] <= 0) continue; 
			cur = max(cur,i+3);
			while(d[cur] >= 0 && cur <= n+1) cur++;
			while(cur <= n+1 && d[i] > 0) {
				while(d[cur] >= 0 && cur <= n+1) cur++;
				if(cur > n+1) break;
				
				int dc = min(d[i],-d[cur]);//abs
				d[i] -= dc;
				d[cur] += dc;
			}
			if(d[i] > 0) {flag = 0;break;}//这句加不加都可以 想想为什么
		}
		for(int i = 1; i<=n+1; i++) {
			if(d[i] < 0) flag = 0;
		}
		if(flag == 1) printf("Case #%d: Yes\n",++iCase);
		else printf("Case #%d: No\n",++iCase);
	}
	return 0 ;
}