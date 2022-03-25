#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <bitset>

using namespace std;
#define lowbit(i) (i & (-i))
#define eps 1e-7
#define GETMID int mid = (l + r) >> 1
#define lson u << 1
#define rson u << 1 | 1
#define Lson u << 1, l, mid
#define Rson u << 1 | 1, mid + 1, r
#define Maxn (100000 + 10)
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a);
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int MAXN = 100010;

int n, m, fa[MAXN], ans = 0;
struct edge {
int u, v, w;
bool operator < (const edge &b) const { return w < b.w; }
}e[MAXN];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
scanf("%d%d", &n, &m);
for(int i = 1; i <= m; ++i)
scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

for(int i = 1; i <= n; ++i)
fa[i] = i;

sort(e + 1, e + m + 1);

for(int i = 1, fu, fv; i <= m; ++i) {
fu = find(e[i].u);
fv = find(e[i].v);

if(fu == fv) continue;

ans += e[i].w;
fa[fu] = fv;
}

printf("%d\n", ans);

return 0;
}
