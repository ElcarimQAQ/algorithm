#include<bits/stdc++.h>
using namespace std;
const  int maxn = 100005;
int a[maxn];

int main()
{
    int n,q,k;
    cin>>n>>q;
    for(int i = 1;i <= n; ++i)
        cin>>a[i];
    while(q--){
        cin>>k;
        int p = lower_bound(a + 1,a + n + 1,k) - a;
        int q = upper_bound(a + 1,a + n + 1,k) - a;
        if(a[p] != k) cout<<-1<<" "<<-1<<endl;
        else{
            cout<<p - 1<<" "<<q - 2<<endl;
        }
    }
    return 0;

}