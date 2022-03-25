#include <bits/stdc++.h>
using namespace std;
#define PII pair<double,double> 
typedef long long ll;
const int maxn = 1e6+5;
int a[maxn],b[maxn];
PII po[maxn];
int n;
PII cal(int i,int j)
{
    double x1,y1;
    x1 = (b[j] - b[i]) * 1.0 / (a[i] - a[j]);
    y1 = a[i] * 1.0 * x1 + b[i];
    return {x1,y1};
}
int main()
{
    int ans,f = 0;
    cin>>n;
    for(int i = 1;i <= n; ++i)
        cin>>a[i]>>b[i];
    for(int i = 1;i <= n; ++i)
        if(a[i] != a[1] || b[i] != b[1]){
            f = 1;break; 
         }
    if(n == 1|| f == 0) ans = 2;
    f = 0;
    for(int i = 1;i <= n; ++i)
        if(a[i] != a[1]){
            f = 1;break; 
        }
    if(f == 0)
        ans = n + 1;
    else{
        if(n == 2){
            if(a[1] != a[2]) ans = 4;
            else
                if(b[1] != b[2]) ans = 3;
        }
        if(n == 3){
            int cnt = 0;
            f =1;
            for(int i = 1;i <= n; i++){
                for(int j = i + 1;j <= n;++j ){
                    po[++cnt] = cal(i,j);
                    if(po[cnt] != po[1])
                        f = 0;
                }
            }
            if(f)
                ans =6;
            else
            ans =7;
        }
    }
    cout<<ans<<endl;
    return 0;
}