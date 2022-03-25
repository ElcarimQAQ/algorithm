#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  pair<int,int> PII; 
string s[6],str[6];
vector<PII> ans,ans2;
int mi = 18;
int vis[6][6];
void turn(int x,int y){
    if(0 < x || x >= 4 || y < 0 || y >= 4)
        return;
    if(s[x][y] == '+')
        s[x][y] = '-';
    else s[x][y] = '+';
}

void change(int x,int y){
    for(int i = 0;i < 3;++i){
        turn(x,i);
        turn(i,y);
    }
    turn(x,y);
}

void dfs(int x,int y,int cnt)
{
    if((x >= 4 && y == 3) || (x == 3 && y >= 4) && cnt <= mi){
        int f = 1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                if(s[i][j] == '+'){
                    f = 0;
                    break;
                }
            }
        if(f && cnt < mi) ans2 = ans;
        ans.clear();
        for(int i = 0;i < 4; ++i)
            s[i] = str[i];
        return;
    }
    if(0 < x || x >= 4 || y < 0 || y >= 4)
        return;
    dfs(x,y + 1,cnt);
    dfs(x + 1,y,cnt);
    change(x,y);
    ans.push_back({x,y});
    dfs(x,y + 1,cnt + 1);
    dfs(x + 1,y,cnt + 1);
}

int main()
{
    for(int i = 0;i < 4; ++i){
        cin>>str[i];
        s[i] = str[i];
    }
    dfs(0,0,0);
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}