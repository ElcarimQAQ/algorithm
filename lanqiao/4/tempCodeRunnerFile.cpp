#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w,m,n;
    cin>>w>>m>>n;
    int x1 =  (m + w -1) / w,x2 = (n + w -1) / w;
    int y1,y2;
    if(x1 % 2){
        y1 = m - (x1-1) * w;
    }
    else{
        y1 =  w - (m - (x1-1) * w) + 1;
    }
    if(x2 % 2)
        y2 = n - (x2-1) * w;
    else{
        y2 =  w - (n - (x2-1) * w) + 1;
    }
    // cout<<x1<<" "<<x2<<" "<<y1<<"  "<<y2<<endl;
    cout<<abs(x1 -x2)+ abs(y1-y2)<<endl;
    return 0;
}