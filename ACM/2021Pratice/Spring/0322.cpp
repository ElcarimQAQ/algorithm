#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;

class Solution {
public:
    int add(int num1, int num2){
        while(num2){
            int ans = num1 ^ num2;
            int cal = (num1 & num2) << 1;
            num1 = ans,num2 = cal;
        }
        return num1;
    }
};

int main()
{
    int a,b;
    cin>>a>>b;
    Solution s;
    int ans = s.add(a,b);
    cout<<ans<<endl;
    return 0;
}