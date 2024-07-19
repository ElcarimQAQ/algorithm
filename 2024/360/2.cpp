#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[N], y[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>y[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int cnt = 1;
        queue<int> q;
        q.push(i);
        vector<int> vis(n + 1, 0);
        vis[i] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int j = 1; j <= n; j++){
                if(abs(x[u] - x[j]) + abs(y[u] - y[j]) <= k && !vis[j]){
                    cnt++;
                    q.push(j);
                    vis[j] = 1;
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1005;
// int x[N], y[N];

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin>>x[i];
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         cin>>y[i];
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++){
//         int cnt = 0;
//         for(int j = 1; j <= n; j++){
//             if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k){
//                 cnt++;
//                 ans = max(ans, cnt);
//             }
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }