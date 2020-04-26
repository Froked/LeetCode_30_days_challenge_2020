/**

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

**/

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

class Solution {
public:
    int n,m;
    bool isValid(int x,int y)
    {
        return x >= 0 and y >= 0 and x < n and y < m;
    }
    
    void dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<char>>& grid)
    {
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(!isValid(X,Y)) continue;
            if(!vis[X][Y] && grid[X][Y] == '1') dfs(X,Y,vis,grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        vector< vector<bool> > vis(n,vector<bool>(m,0));
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++) 
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    dfs(i,j,vis,grid);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};