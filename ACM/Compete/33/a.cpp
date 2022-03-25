    #include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
typedef long long ll;
typedef pair<int ,int> PII;
const  int maxn = 5e5+5;


int main()
{
    int t;
    string str;
    scanf("%d ",&t);
   
    int cnt1,cnt2,cnt3;
    while(t--){
        cnt1 = 0,cnt2 = 0,cnt3 = 0;
        while(getline(cin,str)){
            int ans = 0;
            if(str == "====="){
                break;
            }
            cnt1++;
            if(str=="")continue;
            for(int i = 0;i<str.size();i++){
                cnt3++;
                if(str[i] == ' ' && i != 0)  ans++;
            }
            cnt2 += ans+1;
            // cout<<ans+1<<endl;
            // cout<<cnt2<<endl;
        }
        cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    }
    
    return 0;
}