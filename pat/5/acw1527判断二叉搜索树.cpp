#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
int qx[maxn],zx[maxn],hx[maxn];
vector<int> ans;

bool build(int ql, int qr, int zl, int zr,int type)
{
    if(qr <= ql && zr <= zl)
        return true;
    int p;
    int root = qx[ql];
    if(type == 0) {
        for(int i = zl;i <= zr; i++)
            if(zx[i] == root) {
                p = i;
                break;
            }
        return false;
    }else {
        for(int i = zr;i >= zl; i--)
            if(zx[i] == root) {
                p = i;
                break;
            }
        return false;
    }
    if(!build(ql, ql + p -1 - zl, zl, p - 1, type)) 
        return false;
    if(!build(qr - (zr - p - 1) , qr, p + 1, zr, type)) 
        return false;
    ans.push_back(root);
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 0;i < n; i++) {
        cin >> qx[i];
        zx[i] = qx[i];
    }
    sort(zx,zx + n);
    if(build(0, n-1, 0, n-1, 0)) {
        cout<<"YES"<<endl;
        for(auto  v : ans)
            cout<<v<<" ";
    } else {
        reverse(zx, zx + n);
        if(build(0, n-1, 0, n-1, 1)){
            cout<<"YES"<<endl;
            for(auto  v : ans)
                cout<<v<<" ";
        }
        else cout<<"NO"<<endl;
    }
    for(auto  v : ans)
                cout<<v<<" ";
 

    return 0;
}