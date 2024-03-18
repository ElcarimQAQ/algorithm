#include <bits/stdc++.h>
using namespace std;
int ma[1005][1005];
int pre[1005][1005];

int main()
{
    int n, m, q,x1,x2,y1,y2;
    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++){            
            cin>>ma[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j-1] - pre[i-1][j-1] + ma[i][j];
        }

    while(q--){
        cin>>x1>>y1>>x2>>y2;
        cout<<pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1 - 1] + pre[x1-1][y1-1]<<endl;
    }     
    return 0;
}