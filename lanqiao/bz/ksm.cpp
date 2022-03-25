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
bool vis[maxn];
int prime[maxn];
int num = 0;

ll ksm(ll a,ll b,ll m){
    ll res = 1;
    while(b){
        if(b & 1)
            res = res * a % m;
        a = a * a % mod;
        b >>= 1;
    }
    return res;

}