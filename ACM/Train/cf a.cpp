#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
typedef long long ll;
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,L,v,l,r,cnt;
    cin>>t;
    while(t--){
        cnt=0;
        scanf("%d%d%d%d",&L,&v,&l,&r);
        int i=0;
        while(i<=L){
            if(i>l&&i<=r){
                i=r/v*v+v;
            }
            if(i<l){
                cnt+=(l-1)/v;
                i=l/v*v+v;
            }
            if(i>r&&i<=L){
                cnt+=L/v-r/v;
                break;
            }
        }
        printf("%d\n",cnt);
    }
	return 0;
}

