 #include <bits/stdc++.h>
 using namespace  std;
int p;
int v[4] = {25,10,5,1};
int n[4];

int dfs(int coin,int sum,int cnt){
    if(coin == 4)
        return -1;
    if(sum + v[coin] > p || n[coin] == 0)
        dfs(coin + 1,sum,cnt);
    if(sum + v[coin] == p)
        return cnt;
    n[coin]--;
    dfs(coin,sum + v[coin],cnt+1);
}

 int main()
 {
 
    cin>>p;
    int n1,n2,n3,n4;
    cin>>n[3]>>n[2]>>n[1]>>n[0];
    int ans = dfs(0,0,0);
    if(ans == -1)
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
    return 0;
 }