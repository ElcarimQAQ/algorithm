#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  pair<int,int> PII; 
string s[6],str[6];
vector<PII> ans ;
int mi = 17;
void turn(int x,int y){
    if(0 > x || x >= 4 || y < 0 || y >= 4)
        return;
    // cout<<x<<" "<<y<<endl;
    if(s[x][y] == '+')
        s[x][y] = '-';
    else s[x][y] = '+';
}

void change(int x,int y){
    for(int i = 0;i < 4;++i){
        turn(x,i);
        turn(i,y);
    }
    turn(x,y);
}

int main()
{
    for(int i = 0;i < 4; ++i){
        cin>>str[i];
        s[i] =str[i];
    }
    // for(int i = 0;i < 4; ++i)
    //     cout<<s[i]<<endl;
    // cout<<endl;
    // change(2,2);
    // for(int i = 0;i < 4; ++i)
    //     cout<<s[i]<<endl;
    for(int  t = 0;t < (1 << 17); t++){
        ans.clear();
        for(int i = 0;i < 4; ++i)
            s[i] = str[i];
        int m = t,cnt = 0;
        for(int i = 0;i < 16;++i){
            if(m  >> i & 1){
                int x = i / 4 ;
                int y = i % 4;
                // cout<<x<<" "<<y<<endl;
                change(x,y);
                cnt++;
                ans.push_back({x,y});
            }
        }
        int f = 1;
        // for (int i = 0; i < 4; i++)
        //     cout<<s[i]<<endl;
        
        for(int i = 0;i < 4;i++ )
            for(int j = 0;j< 4;j++){
                if(s[i][j] == '+'){
                    f = 0;
                    break;
                }
            }
        if(f ){
            cout<<ans.size()<<endl;
            for(int i = 0; i < ans.size();++i)
                cout<<ans[i].first + 1<<" "<<ans[i].second + 1<<endl;
            break;
        }
    }
    return 0;
}