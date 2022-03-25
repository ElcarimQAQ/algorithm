#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    int m = n;
    int p ,ans = 0;
    if(m == 0)
        return 1;
    while(m > 0){
        p = m % 10;
        if(p == 0||p == 4||p == 6 || p == 9)
            ans += 1;
        else if(p == 8)
            ans += 2; 
        m /= 10;
    }
    return ans;
}

int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int flag = -1;
        for(int i = 1;i <= k; i++){
            n = f(n);
            if(n == 0){
                flag = i;
                break;
            }
        }
        if(flag == -1)
            cout<<n<<endl;
        else{
            if((k - flag) % 2)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}
