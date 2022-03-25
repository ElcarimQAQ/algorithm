#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<int,int> PII;
const int maxn =  500005;
PII vis[maxn];

bool cmp(PII a,PII b)
{
    return a.second<b.second;
}
int main() {
	int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int j = 0,cnt = 0;
    for(int i = 0;i < n;i++){
        if(str[i] == 'a'){
            vis[++cnt].first = i;
            vis[cnt].second = i - j -1;
             j = i;
        }
    }
    sort(vis + 1,vis + cnt + 1, cmp);
    for(int i = 1;i <= cnt;i++){
        if(vis[i].second <= k)
        {   
            int s= 0; 
            for(int j = vis[i].first;j < str.size(); j++){
                str[j] = 'a';
                s++;
                if(s >= k )
                    break;
            }
            k -= vis[i].second;
            cout<<k<<endl;
        }
        cout<<str<<endl;
    }
    cout<<str<<endl;
    return 0;
}
