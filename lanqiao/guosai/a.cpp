#include <bits/stdc++.h>
using namespace  std;

int check(int x)
{
    while(x > 0){
        int a = x%10;
        if(a == 2) return 1;
        x /= 10;
    }
    return 0;
}
int main()
{
    int ans = 0;
    for(int i = 1; i<= 2020;i++){
        if(check(i))
            ans++;
    }
    cout<<ans<<endl;
}