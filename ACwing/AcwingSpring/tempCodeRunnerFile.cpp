#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isUgly(int n) {
    //     vector<int> ans;
    //     while(n){
    //         int f = 1;
    //        for(int i = 2;i <= sqrt(n);++i){
    //            if(n % i == 0){
    //                f = 0;
    //                cout<<i<<endl;
    //             //    ans.push_back(i);
    //                n = n / i;
    //                break;
    //            }
    //        }
    //        if(f)
    //         break;
    //    } 
    // //    cout<<n<<endl;
    //    if(n != 1)
    //         ans.push_back(n);
    //     for(int i = 0;i < ans.size(); ++i){
    //         cout<<ans[i]<<endl;
    //         if(ans[i] != 2 && ans[i] != 3 && ans[i] != 5)
    //             return false;
    //     }
    //     return true;
        set<int> num;
        priority_queue<int,vector<int>,greater<int> > q;
        num.insert(1);q.push(1);
        num.insert(2);q.push(2);
        num.insert(3);q.push(3);
        num.insert(5);q.push(5);
        while(num.size() <= n){
            int t = q.top();
            q.pop();
            // cout<<t<<endl;
            if(num.find(t * 2) == num.end())
                num.insert(t * 2);q.push(t * 2);
            if(num.find(t * 3) == num.end())
                num.insert(t * 3);q.push(t * 3);
            if(num.find(t * 5) == num.end())
                num.insert(t * 5);q.push(t * 5);
        }
        std::set<int>::iterator it = num.begin();
        int cnt =0;
        while(it != num.end()){
            // cout<<*it<<endl;
            cnt++;
            if(cnt == n)
                return *it;
                it++;
        }
        return 1;
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