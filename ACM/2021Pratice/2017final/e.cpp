#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
const int maxn=10005;
using namespace std;
typedef long long ll;
long double A[maxn];

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n;
    cin>>t;
    for(int cas = 1; cas <= t;cas++){
        cin>>n;
        long double x,y;
        char s;
        for(int i =1;i <= n;i++){
            cin>>x>>s>>y;
            A[i] = x / (x + y);
        }
        // sort(g+1,g+1+n,cmp);
        sort(A+1,A+1+n);
        long double sum1 = 0.0;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            sum1 += A[i];
            if(sum1 < 1.0)
                cnt++;
            else break;
        }
        cout<<"Case #"<<cas <<": "<< cnt << endl;
    }
    
	return 0;
}
