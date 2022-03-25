#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e5+7;
typedef long long ll;
int a[1005];
vector<int> pre;

int main ()
{
    //  freopen("data.in", "r", stdin);
    // freopen("1.out", "w", stdout);	
	cin.tie(0),ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    pre[0] = s[0] -'0';
    for(int i =1;i < n;i++) {
        pre[i] = pre[i-1] + s[i] -'0';
    }
    int m= pre[n-1];
    for(int i = 1;i <= m; i++){
        if( m%i == 0){
            for(int j =1 ;j <= m/i ;j++ ){
                if(find(pre.begin(),pre.end(),i*j)){

                }
            }
        }
    }

	return 0;
}
