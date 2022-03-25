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
    int t,n,m;
    cin>>t;
    for(int c = 1 ; c <= t;c++ )
    {
        pos.clear();
        cin>>n;
        for(int i = 1 ; i <= n;i++){
            scanf("%d",&a[i]);
            b[i] = a[i] - a[i-1];
            if(b[i] < 0)
                pos.push_back(i);
        }
        b[n+1] = 0 - a[n];
        int j = 0;
        int f = 1;
        for(int i = 1;i <= n+1;){
            if(b[i] > 0){
                if((pos[j] - i) >= 3 && (pos[j] - i) <= 5){
                    if(b[i] + b[pos[j]] > 0){
                        b[i] = b[i] + b[pos[j]];
                        b[pos[j]] = 0;
                        j++;
                        continue;
                    }
                    else if(b[i] + b[pos[j]] == 0){
                        b[i] = b[i] + b[pos[j]];
                        b[pos[j]] = 0;
                        j++;
                    }
                    else{
                        b[pos[j]] = b[i] + b[pos[j]];
                        b[i] = 0;
                    }
                }
                else{
                    f = 0;
                    break;
                }
            }
            i++;
            if(j >= pos.size() && b[i] > 0){
                f = 0;
                break;
            }
        }
        if(f)
            printf("Case #%d: Yes\n",c);
        else
            printf("Case #%d: No\n",c);
    }
    return 0;
}