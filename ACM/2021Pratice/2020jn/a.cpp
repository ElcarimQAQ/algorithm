#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
const int mod = 998244353;
int equ, var;
int a[maxn][maxn];
int x[maxn][maxn];
int free_x[maxn];
int free_num;

int Guass() {
    int max_r, col, k;
    free_num = 0;
    for (k = 0, col = 0; k < equ && col < var; ++k, ++col) {
        max_r = k;
        for (int i = k + 1; i < equ; ++i) {
            if (abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if (a[max_r][col] == 0) {
            k--;
            free_x[free_num] = col;
            continue;
        }
        if (max_r != k) {
            for (int j = col; j < var + 1; ++j) {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; ++i) {
            if (a[i][col] != 0) {
                for (int j = col; j < var + 1; ++j)
                    a[i][j] ^= a[k][j];
            }
        }
    }
    for (int i = k; i < equ; ++i)
        if (a[i][col] != 0)
            return -1;
    if (k < var) return var - k;
    return 0;
}
long long fib[maxn];
int A[maxn][maxn], b[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    fib[0] = 1;
    for (int i = 1; i <= 200; ++i) fib[i] = fib[i - 1] * 2 % mod;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
            a[i][j] = A[i][j];
        }
            
    int x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            cin >> b[i][j];
    long long ans = 1;
    equ = var = n;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            a[i][i] = (A[i][i] - b[i][j] + 2) % 2;  
        }
        
        int tmp = Guass();
        ans = ans * fib[tmp] % mod;

        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < n; ++l) 
                a[k][l] = A[k][l];
        }
    }
    cout << ans << endl;
}