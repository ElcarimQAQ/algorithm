#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, st[N], tt;

int main()
  {
    cin >> n;
    
    for(int i = 0;i < n; i++)
    {
        int x;
        cin >> x;

        while(st[tt] >= x && tt) tt--;
        if(tt) cout<<st[tt]<<' ';
        else cout<<-1<<' ';
        st[++tt] = x;
    }
    return 0;
  }