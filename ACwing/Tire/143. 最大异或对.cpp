#include <bits/stdc++.h>
using namespace std;

int son[3000005][2], idx = 0;
int a[3000005], n;
void insert(int x){
    int p = 0;
    // 数据范围2^31
    for(int i = 30; ~i; i--){
        int u = x >> i & 1;
        // 如果没有这个节点，就创建一个，新的下标
        if(!son[p][u]) son[p][u] = ++idx; 
        p = son[p][u];
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 30; ~i; i--){
        int u = x >> i & 1;
        if(son[p][!u]){
            res += 1 << i;
            p = son[p][!u];
        }else p = son[p][u];
    }
    return res;

}

int main(){
    cin >> n;
    for (int i =0; i < n; i++){
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n ; i++) {
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    return 0;
}