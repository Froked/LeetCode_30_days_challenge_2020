/**

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

**/

class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int f(int x, int y, vector<vector<int>>& grid)
    {
        if(x == n - 1 && y == m - 1) return grid[x][y];
        if(x >= n || y >= m) return INT_MAX / 2;
        int &ret = dp[x][y];
        if(ret != -1) return ret;
        ret = 0;
        int f1 = grid[x][y] + f(x + 1, y, grid);
        int f2 = grid[x][y] + f(x, y + 1, grid);
        return ret = min(f1, f2);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        n = grid.size();
        if(!n) return 0;
        m = grid[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return f(0, 0, grid);
    }
};