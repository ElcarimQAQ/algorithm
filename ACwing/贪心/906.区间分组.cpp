#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Range
{
    int l, r;
    bool operator < (const Range& W) const{
        return l < W.l;
    }
}range[N];

priority_queue<int, vector<int>, greater<int>> heap;  

int main()
{
    int n, l ,r;
    cin>>n;
    for(int i= 0; i < n; i++) {
        cin>>l>>r;
        range[i] = {l,r};
    }
    sort(range, range + n);
    for(int i = 0; i < n; i++){
        auto r = range[i];
        if(heap.empty() || r.l <= heap.top()) heap.push(r.r);
        else{
            heap.pop();
            heap.push(r.r);
        }
    }
    cout<<heap.size()<<'\n';
    return 0;
}