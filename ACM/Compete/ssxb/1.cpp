#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
typedef long long ll;
using namespace std;
map<int, int> vis;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		int ans = 0; vis.clear();
		for (int i = -1 * n; i <= n; ++i) {
			for (int j = -1 * n; j <= n; ++j) {
				int now = i * (i + 1) + j * (j + 1);
				
				vis[now]++;
			}
		}
		for (int i = -1 * n; i <= n; ++i) {
			for (int j = -1 * n; j <= n; ++j) {
				int now = i * (i + 1) + j * (j + 1);
				if (vis.count(now * k))
					ans += vis[now * k];
				if (now % k == 0 && vis.count(now / k))
					ans += vis[now / k];
			}
		}
		
		cout << ans / 2 << endl;
	}
}
