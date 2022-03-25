#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 200005;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums .size() < 3)
            return false;
        int fr[maxn],la[maxn];
        fr[0] = nums[0];
        for(int i = 1; i< nums.size();i++){
            fr[i] = min(fr[i - 1],nums[i]);
        }
        la[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0;i--){
            la[i] = max(la[i + 1],nums[i]);
        }
        for(int i = 1;i < nums.size() - 1; i++){
            if(fr[i - 1] < la[i + 1] && fr[i - 1] < nums[i] && la[i + 1] < nums[i])
                return true;
            else if( fr[i - 1] < nums[i]){
                for(int j = i + 1 ;j < nums.size() ; j++){
                    if(nums[j] < nums[i] && nums[j] > fr[i - 1])
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1,3,2,4,5,6,7,8,9,10
    };
    Solution s;
    bool ans = s.find132pattern(nums);;
    cout<<ans<<endl;
}