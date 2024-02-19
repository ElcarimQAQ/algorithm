#include<bits/stdc++.h>
using namespace std;

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]

vector<int> nums = {5,7,7,8,8,10};

int solve(int target){
    int l = 0, r = nums.size();
    while(l < r) {
        int mid = l + r >> 1;
        cout<<"idx"<<mid<<"mid"<<nums[mid]<<endl;
        if(nums[mid] == target){
            int s = -1, e =-1;
            for(int j = l; j< r; j++){
                if(nums[j] == target && s == -1)
                    s = j;
                if(nums[j] != target && s != -1 && e == -1)
                    e = j;
            }
            cout<<s<<" "<<e-1<<endl;
            return mid;
        }
        else if(nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return -1;
}

int main()
{
    cout<<solve(8)<<endl;
    return 0;
}