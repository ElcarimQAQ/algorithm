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

void get_prime(int n){
    for(int i = 2 ; i <= n ;++i){
        if(!vis[i]) prime[num++] = i;
        for(int j = 0 ;prime[j] * i <= n ; ++j){
            vis[prime[j] * i] = 1;
            if( i % prime[j] == 0)
                break;
        }
    }
}