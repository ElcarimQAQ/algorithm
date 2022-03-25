#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1005;
struct node
{
    int sh,sm,ed,em;
}book[maxn];
int vis[maxn];

int cal(int sh,int sm,int eh,int em){
    if(em > sm)
        return 60 * (eh - sh) + em - sm;
    else{
        return 60 * (eh - sh - 1) + em + 60 - sm;
    }

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,hh,mm;
    char a,b;
    cin>>t;
    int cnt = 0,time = 0;
    while(cin>>n>>a>>hh>>b>>mm){
        if(n == 0){
            memset(vis,0,sizeof(vis));
            if(cnt != 0){
                if(time%cnt ==0)
                    cout<<cnt<<" "<<time/cnt<<endl;
                else{
                    double ans = time * 1.0 / cnt;
                    if(ans - time / cnt >= 0.5) 
                        cout<<cnt<<" "<<time / cnt + 1<<endl;
                    else
                        cout<<cnt<<" "<<time / cnt <<endl;
                }
            }
            else
                cout<<cnt<<" "<<cnt<<endl;
            cnt = 0;
            time = 0;
            continue;
        }
        if(a == 'S' && vis[n] == 0&&n != 0){
            vis[n] = 1;
            book[n].sh = hh;
            book[n].sm = mm;
        }
        else{
            if(vis[n]){
                vis[n] = 0;
                time += cal(book[n].sh,book[n].sm,hh,mm);
                cnt++;
            }
        }
    }
    return 0;
}
