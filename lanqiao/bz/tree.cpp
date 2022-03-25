#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int tr[maxn];

int lowbit(int x){
    return x & -x;
}

void update(int u,int v)
{
    for(int i = u;u < maxn; i += lowbit(i)){
        tr[u] += v;
    }
}

int querry(int u){
    int res = 0;
    for(int  i = u;i >= 1;i-= lowbit(i))
        res += tr[i];
    return res;
}