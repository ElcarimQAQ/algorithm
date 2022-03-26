#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll d,k;
    cin>>d>>k;
    double sum = 0;
    ll an,sn;
    int cnt = 0;
    for(ll i = min(k,ll(1e7)) ;i >= 1;i--){
        an = 1 + d * (i - 1);
        // cout<<an<<endl;
        if(sum == 0) 
            sum = an;
        else
            sum = an + 1.0/sum;
        cnt++;
    }
    sum =1.0/sum;
    printf("%.16lf\n",sum);
    return 0;
}