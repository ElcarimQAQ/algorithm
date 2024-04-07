#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N], q[N];
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0;i < n; i ++){
        cin >> a[i];
    }

    int hh=0, tt = -1;
    for(int i = 0;i < n; i ++){
        if(hh <= tt && q[hh] < i - k + 1) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;

        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
    cout<<endl;

    hh = 0, tt = -1;
    for(int i = 0;i < n; i ++){
        if(hh <= tt && q[hh] < i - k + 1) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;

       if(i >= k - 1) cout << a[q[hh]] <<' ';
    }
    return 0;
}