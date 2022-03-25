#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll a[maxn];

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll mx = 0;
        int f = 0;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
            if(a[i] != a[1])
                f = 1;
                mx = max(mx,a[i]);
        }

        if(n == 1 || f == 0){
            cout<<0<<endl;
            continue;
        }
        int f1 = 1,f2 = 1;
        f = 1;
        for(int i = 1;i < n;i++){
            if(a[i ] > a[i + 1])
                f1 = 0;
            if(a[i] < a[i + 1])
                f2 = 0;
            if(a[i + 1] - a[i] != a[2] - a[1])
                f = 0;
        }
        if(f1 || f2){
            if(f)
                cout<<0<<endl;
            else
                cout<<-1<<endl;
            continue;
        }
        ll c = 0,m = 0;
        for(int i = 1;i < n ;i++){
            if(a[i + 1] > a[i]){
                if(c != 0 && c != a[i + 1] - a[i]){
                    f = -1;
                    break;
                }
                c = a[i + 1] - a[i];
            }
        }
        for(int i = 1;i < n;i++){
            if(a[i + 1]< a[i]){
                if(m != 0 && m != a[i] + c  - a[i + 1]){
                    f = -1;
                    break;
                }
                m = a[i] + c - a[i + 1];
                if(m <= mx || m <= c){
                    f = -1;
                    break;
                }
            }
        }
        if(f == -1)
            cout<<-1<<endl;
        else
            cout<<m<<" "<<c<<endl;
        
    }
    return 0;
}