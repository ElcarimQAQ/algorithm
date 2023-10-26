#include <bits/stdc++.h>
using namespace std;

int leavf_node = 0;
int num[100];
vector<int> tree[105];
int height =0;
void dfs(int u, int h){
    num[h]++;
    if (tree[u].size() == 0){
        leavf_node++;
        height = max(height, h);
        return;
    }
    for(auto v: tree[u]){
        if (v != u) {
            dfs(v, h+1);
        }
    }
}

int main(){
    int u,v;
    tree[1].push_back(2);
    tree[1].push_back(3);
    tree[2].push_back(4);
    tree[2].push_back(5);
    tree[3].push_back(6);
    tree[3].push_back(7);
    tree[3].push_back(8);
    dfs(1, 0);
    cout<<"h :"<<height+1<<endl;
    for(int i = 0;i< height+1;i++){
        cout<<num[i]<<endl;
    }
    cout<<"road_node:"<<leavf_node<<endl;
    cout<<"leavf_node:"<<leavf_node<<endl;
    return 0;
}