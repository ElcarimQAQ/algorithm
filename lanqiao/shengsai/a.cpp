#include <bits/stdc++.h>
using namespace std;

int check(int x){
    int cnt = 0;
    while(x > 0){
        int p =x %10;
        x/=10;
        if(p == 2)
            cnt++;
    }
    return cnt;
}
int main()
{
    int ans = 0;
    for(int i = 1; i <= 2020 ;++i){
        ans += check(i);
    }
    cout<<ans<<endl;
    return 0;
}