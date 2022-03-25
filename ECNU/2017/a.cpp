#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<int> vis;

int main()
{
    int n;
    cin>>n;
    int num;
    string x;
    string sign;
    int mi = INF;
    int ma = 0;
    int cnt = 0;
    while(n--)
    {
        cin>>x>>sign>>num;
        if(sign == "<="){
            if(num >= ma){
                ma = max(ma,num);
                cnt++;
            }
        }
        else if(sign == "<"){
            if(num - 1 >= ma){
                ma = max(ma,num - 1);
                cnt++;
            }
        }
        else if(sign == ">"){
            if(num + 1 <= mi ){
                mi = min(mi,num + 1);
                cnt++;
            }
        } 
        else if(sign == ">="){
            if(num <= mi ){
                mi = min(mi,num);
                cnt++;
            }
        }
        else vis.push_back(num);
    }
    if(ma == 0)
        ma = INF;
    if(mi == INF)
        mi = 0;
    for (auto v : vis){
        if(v >= mi && v <= ma){
            cnt++;
            break;
        }
    }
    cout<<cnt<<endl;
    
}