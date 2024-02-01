/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// copilot不用补全

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = l + (r - l ) / 2;
            cout<<mid<<endl;
            pair<int,int> idx = findMatrixIdx(mid, n);
            cout<<idx.first<<" "<<idx.second<<endl;
            // cout<<"matrix[idx.first][idx.second]"<<matrix[idx.first][idx.second]<<endl;
            if (matrix[idx.first][idx.second] == target) return true;
            else if (matrix[idx.first][idx.second] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
    
    pair<int,int> findMatrixIdx(int x, int n) {
        int row = x / n;
        int col = x % n;
        return {row, col};
    }
};


// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}