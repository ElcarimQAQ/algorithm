#include <bits/stdc++.h>
using namespace std;
int H[2] = {129,130};
int W[2] = {25,27};

int main()
{
    std::ios::sync_with_stdio(false);
    int n,s,h,w;
    cin>>n;
    while(n--) {
        cin>>s>>h>>w;
        if(h > H[s]) cout<<"ni li hai!"<<" ";
        else if(h == H[s]) cout<<"wan mei!"<<" ";
        else cout<<"duo chi yu!"<<" ";
        if(w > W[s]) cout<<"shao chi rou!"<<endl;
        else if(w == W[s]) cout<<"wan mei!"<<endl;
        else cout<<"duo chi rou!"<<endl;
    }
    return 0;
}