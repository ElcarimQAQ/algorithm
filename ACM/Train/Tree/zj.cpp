#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010, M = N * 2;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], depth[N];
int f[N][20], seq[N], cnt;
int sum[N];
PII trans[N];
int blca[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int dep, int father)
{
    cnt ++ ;
    seq[cnt] = u;
    // cout<<"u"<<u<<endl;
    depth[u] = dep;

    for (int i = 1; i < 20; i ++ ) f[u][i] = f[f[u][i - 1]][i - 1];

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            dist[j] = dist[u] + w[i];
            f[j][0] = u;
            dfs(j, dep + 1, u);
        }
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y]) swap(x, y);
    int d = depth[x] - depth[y];
    for (int i = 0; i < 20; i ++ )
        if (d >> i & 1)
            x = f[x][i];
    if (x == y) return x;

    for (int i = 19; i >= 0; i -- )
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    return f[x][0];
}

bool check(int mid)
{
    memset(sum, 0, sizeof sum);
    int maxd = 0, s = 0;
    for (int i = 1; i <= m; i ++ )
    {
        int x = trans[i].first, y = trans[i].second;
        int p = blca[i];
        int d = dist[x] + dist[y] - dist[p] * 2;
        // cout<<"uv"<<x<<" "<<y<<endl;
        // cout<<"l"<<d<<endl;
        if (d > mid)
        {
            sum[x] += 1, sum[y] += 1;
            sum[p] -= 2;
            maxd = max(maxd, d - mid);
            s ++ ;
        }
    }
    // cout<<"s"<<s<<endl;
    if (!s) return true;

    for (int i = n; i; i -- )
    {
        int x = seq[i];
        sum[f[x][0]] += sum[x];
        // cout<<"ne"<<x<<endl;
    }
    for (int i = 1; i <= n; i ++ )
        if (sum[i] == s && dist[i] - dist[f[i][0]] >= maxd){
            // cout<<"s"<<s<<endl;
            return true;
        }
    return false;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    dfs(1, 0, -1);

    for (int i = 1; i <= m; i ++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        trans[i] = {x, y};
        blca[i] = lca(x, y);
        // cout<<blca[i]<<endl;
    }

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        cout<<mid<<endl;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", r);
    return 0;
}

