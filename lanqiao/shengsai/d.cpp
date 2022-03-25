#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int  day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct  da
{
    int y,m,d;
    da() {}
    da(int a,int b,int c): y(a),m(b),d(c){}
};

int check(int y)//判断闰年
{
    if((y % 100 == 0) && (y % 400 == 0))
        return 1;
    if((y % 100 != 0) && (y % 4 == 0))
        return 1;
    return 0;
}

int cal(da s,da e)//两个日期的天数
{
    int d = 0;
    //首年
    if(s.y != e.y){
        for(int i = s.m ;i <= 12; ++i){
            if(check(s.y))
            {
                if(i == 2){
                    if(i == s.m )
                        d +=  29 - s.d + 1;
                    else d += 29;
                }
                else{
                    if(i == s.m )
                        d +=  day[i - 1] - s.d + 1;
                    else d += day[i - 1];
                }
            }
            else{
                if(i == s.m )
                    d +=  day[i - 1] - s.d + 1;
                else d += day[i - 1];
            }
        }
    }
    // cout<<d<<endl;
    for(int i = s.y + 1 ;i < e.y; ++i){
        if(check(i))
            d += 366;
        else d += 365;
    }
    // cout<<d<<endl;
    for(int i = 1; i <= e.m ; ++i){
        if(check(e.y) )
        {
            if(i == 2){
                if(i == e.m )
                    d +=  e.d;
                else d += 29;
            }
            else{
                if(i == e.m )
                    d +=  e.d;
                else d += day[i - 1];
            }
        }
        else{
            if(i == e.m )
                    d +=  e.d;
            else d += day[i - 1];
        }
    }
    return d;
}
int main()
{
    da s(2000,1,1),e(2020,10,1);
    int ans =cal(s,e);
    // cout<<ans<<endl;
    int cnt = ans;
    for(int i = 1;i <= cnt; ++i){
        if( (i-1) % 7 == 2)
            ans++;
    }
    // cout<<ans<<endl;
    for(int i = s.y; i <= e.y; i++){
        for(int j = 1;j <= 12; j++){
            if(i == e.y && j > e.m)
                break;
            da u(i,j,1);
            cnt = cal(s,u);
            if((cnt - 1) % 7 != 2){
                // cout<<u.y<<" "<<u.m<<" "<<u.d<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}