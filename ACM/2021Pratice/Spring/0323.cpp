#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int a[maxn],b[maxn];
unordered_map<int,int > l,r,pos;
vector<int> ans;
queue<int> q;
int build(int il, int ir, int pl, int pr)
{
    int root = a[pr];
    int k = pos[root];
    if (il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if (ir > k) r[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1);
    return root;
}

void bfs(int root){
    q.push(root);
    while(!q.empty()){
        int t = q.front();
        ans.push_back(t);
        q.pop();
        int ll = l[t];
        if(ll)
            q.push(ll);
        int rr = r[t];
        if(rr)
            q.push(rr);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i <  n; i++)
        cin>>a[i];
    for(int i = 0;i < n; i++){
        cin>>b[i];
        pos[b[i]] = i;
    }
    int r = build(0,n - 1,0,n - 1);
    bfs(a[n - 1]);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}