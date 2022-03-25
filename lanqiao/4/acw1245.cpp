#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(int x)
{
    while(x > 0){
        int c = x%10;
        if(c == 0||c == 2 ||c ==1|| c== 9)
            return 1;
        x /= 10;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    ll ans = 0;
    for(int i =1 ;i<= n;i++){
        if(check(i))
            ans += 1ll *i;
    }
    cout<<ans<<endl;
    return 0;
}