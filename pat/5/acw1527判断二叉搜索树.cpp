#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
int qx[maxn],zx[maxn],hx[maxn];
vector<int> ans;

bool build(int ql, int qr, int zl, int zr,int type)
{
    if(zr < zl  && qr < ql)
        return true;
    
    int p;
    int root = qx[ql];
    if(type == 0) {
        for(p = zl; p <= zr; p++)
            if(zx[p] == root) 
                break;    
        if(p > zr) return false;  //bug2, 判断能不能找到的条件需要注意
    }else {
        for(p = zr;p >= zl; p--)
            if(zx[p] == root) 
                break;
        if(p < zl ) return false;
    }
    if(!build(ql + 1 , ql + p - zl, zl, p - 1, type)) //bug3，根节点不在区间里头，记得去掉
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
        ans.clear();  //bug1,ans忘记清空
        reverse(zx, zx + n);
        if(build(0, n-1, 0, n-1, 1)){
            cout<<"YES"<<endl;
            for(auto  v : ans)
                cout<<v<<" ";
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}