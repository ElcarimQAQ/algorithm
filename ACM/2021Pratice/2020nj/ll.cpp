#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PI;
const double eps = 1e-6;
const LL N = 200010;
const LL INF = 0x3f3f3f3f;
const LL mod = 1000000007; //998244353
LL powmod(LL a, LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; }return res; }

LL a[N], b[N];

void init() {
    for (LL i = 0; i < N; i++) {
        a[i] = b[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL T; cin >> T;
    while (T--) {
        init();
        LL n, m; cin >> n >> m;
        LL ans = 0;
        for (LL i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (LL i = 1; i <= m; i++) {
            cin >> b[i];
        }
        b[0] = -INF;
        b[m + 1] = INF;
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        for (LL i = 1; i <= m + 1; i++) {
            LL lf = upper_bound(a + 1, a + 1 + n, b[i - 1]) - a; //两个blue石头之间
            LL rt = lower_bound(a + 1, a + 1 + n, b[i]) - a - 1;
            ans = max(ans, rt - lf + 1);
        }
        if (ans <= 0) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}