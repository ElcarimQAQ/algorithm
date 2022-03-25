#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1e6+5;
vector<int> vis;
vector<int> c;
vector<int> num[maxn];
int main()
{
    int n;
    cin>>n;
    int num;
    string x;
    string sign;
    int mi = INF;
    int ma = 0;
    int cnt = 0;
    for (int i = 0;i < n;i++){
        cin>>x>>sign>>num[i];
        c.push_back(num[i]-1);
        c.push_back(num[i]);
        c.push_back(num[i]+1);
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for(int i = 0;i < n;++i){
        auto it = lower_bound(c.begin(), c.end(), num[i]);
        num[i] = it - c.begin() + 1;
    }  
}