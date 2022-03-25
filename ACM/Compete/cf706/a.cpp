#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int a[maxn];
int b[maxn];
vector<int> pos;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t,n,k;
    cin>>t;
    string s,s1;
    while(t--){
        cin>>n>>k;
        cin>>s;
        s1 = s;
        reverse(s.begin(),s.end());
        //cout<<s<<endl;
        int f = 0,cnt = 0;
        for(int i = 0;i < n ; i++ ){
            if(s[i] != s1[i] ){
                if(cnt >= k)
                    f = 1;
                break;
            }
            cnt++;
            if(cnt >= k){
                f = 1;
                break;
            }
        }
        if(k == 0 || ( f && (k*2+1 <= n)))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}