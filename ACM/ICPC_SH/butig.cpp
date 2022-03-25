#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll m = (n-1)*n/2;
    ll nn = n -n/3;
    ll mm = (nn-1)*nn/2;
    cout<<m-mm<<endl;
    system("pause");
    return 0;
}