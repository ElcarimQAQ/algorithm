#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        if (k <= n - 2) 
        {
            cout << (k - 2) * (k - 1) * m / 2 << endl;
        }
        else if (k <= n + m - 3)
        {
            int res = (n - 2) * (n - 1) * m / 2;
            k -= n - 2;
            res += (k - 1) * k / 2 + (k) * m * (n - 1);
            cout << res << endl;
        }
        else 
        {
            int res = (n - 2) * (n - 1) * m / 2;
            res += (m - 2) * (m - 1) / 2 + m * (m - 1);
            k -= n + m - 3;
            // cout << res << endl;

            int a1 = n * m - 2;
            int a2 = n * m - 1;

            res += (k / 2) * (a1 + a2);
            res += (k % 2) * a2;
            cout << res << endl;
        }
    }
    return 0; 
}