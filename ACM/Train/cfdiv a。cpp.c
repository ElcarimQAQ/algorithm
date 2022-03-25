#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
typedef long long ll;
int ak[1005];

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n,s,k;
    cin>>t;
    while(t--){
        memset(ak,0,sizeof(ak));
        cin>>n>>s>>k;
        int a;
        for(int i=1;i<=k;i++){
            scanf("%d",&a);
            ak[a]=1;
        }

    }
	return 0;
}

