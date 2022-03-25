#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        vector<int> ans;
        while(n){
            int f = 1;
           for(int i = 2;i <= sqrt(n);++i){
               if(n % i == 0){
                   f = 0;
                   cout<<i<<endl;
                //    ans.push_back(i);
                   n = n / i;
                   break;
               }
           }
           if(f)
            break;
       } 
    //    cout<<n<<endl;
       if(n != 1)
            ans.push_back(n);
        for(int i = 0;i < ans.size(); ++i){
            cout<<ans[i]<<endl;
            if(ans[i] != 2 && ans[i] != 3 && ans[i] != 5)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s = Solution();
    int n;
    cin>>n;
    cout<<s.isUgly(n);
    return 0;
}