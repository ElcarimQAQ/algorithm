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
double a[maxn];
double avg,sum;

struct node
{
    double num,cnt;
    double val;

    bool operator < (const node& b) const {
        return val < b.val;
    }
};

double cal(node x)
{
    return  x.cnt * (x.num / x.cnt - avg) * (x.num / x.cnt - avg) - (x.cnt + 1) * (x.num / (x.cnt + 1) - avg) * (x.num / (x.cnt + 1) - avg);//增加一个后方差的减小量 
}

int main()
{
    int t,n,m;
    cin>>t;
    for (int c = 1; c <= t; c++)
    {
        double ans = 0.0;
        sum = 0.0;
        cin>>n>>m;
        for(int i = 1 ;i <= n; i++){
            scanf("%lf",&a[i]);
            sum += a[i];
        }
        avg = sum / m;
        priority_queue<node> q;
        for(int i = 1 ;i <= n; i++){
            node now;
            now.num = a[i];
            now.cnt = 1;
            now.val = cal(now);
            q.push(now);
        } 
        for(int i = 1 ;i <= m - n; i++){
            node now = q.top();
            q.pop();
            now.cnt++;
            now.val = cal(now);
            q.push(now);
        }
        while(!q.empty()){
            node now = q.top();
            q.pop();
            ans += now.cnt * (now.num / now.cnt - avg) * (now.num / now.cnt - avg);
        }
        //cout<<ans<<endl;
        printf("Case #%d: %.12lf\n",c,ans/m);
    }
    
    return 0;
}