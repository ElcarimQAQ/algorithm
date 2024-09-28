#include <bits/stdc++.h>
using namespace std;
const int N=10005;
set<int> s;
// vector< vector<int, int>> graph(N);
vector<pair<int, int>> tele,graph(N);
unorderd_map<int, int> pos;

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    s.insert(1);
    s.insert(n);
    for (int i= 0;i <= m;i++){
        cin>>u>>v;
        s.insert(u);
        s.insert(v);
        tele.push_back({u,v});
    }
    vector<int> point(s.begin(), s.end());
    for(int i = 0;i <= point.size(); i++)
        pos[point[i]] = i;

    for(int i = 1; i<=n;i++){
        u = i;
        v = i-1;
        graph[u].push_back({v, pos[u] - pos[v]});
        graph[v].push_back({u, pos[u] - pos[v]});
    }
    for (auto pa:tele){
        u = pa.first;
        v = pa.second;
        graph[u].push_back({v,0});
        graph[v].push_back({u,0});
    }

    vector<int> dist(point.size(), INT_MAX);
    start = pos[1];
    end = pos[n];
    dist[1] = 0;
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
    pq.push({0, start})
    while (!pq.empty()) {
        auto [current_dist, u_idx] = pq.top();
        pq.pop();
        if (current_dist > dist[u_idx])
            continue;
        for (auto [v_idx, cost] : graph[u_idx]) {
            if (dist[v_idx] > dist[u_idx] + cost) {
                dist[v_idx] = dist[u_idx] + cost;
                pq.push({dist[v_idx], v_idx});
            }
        }
    }

    cout << dist[end] << endl;
    return 0;
}