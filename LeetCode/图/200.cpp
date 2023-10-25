//
// Created by lbyang on 23-10-25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        if (x < 0 || y < 0 || x >= n || y >=m )
            return ;
        if (grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        dfs(x + 1, y, n,m, grid);
        dfs(x - 1, y, n, m, grid);
        dfs(x, y+1, n ,m, grid);
        dfs(x, y-1, n ,m, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(),ans = 0;
        for(int i = 0;i <n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == '1'){
                    dfs(i ,j, n ,m, grid);
                    ans++;
                }

            }
        }
        return ans;
    }
};