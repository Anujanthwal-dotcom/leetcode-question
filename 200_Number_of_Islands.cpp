// 200. Number of Islands
// Difficulty: Medium
// URL: https://leetcode.com/problems/number-of-islands/
//
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//
//
// Example 1:
//
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
//
// Example 2:
//
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
//
//
//
// Constraints:
//
// 	  * m == grid.length
//
// 	  * n == grid[i].length
//
// 	  * 1 <= m, n <= 300
//
// 	  * grid[i][j] is '0' or '1'.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid,n,m,i,j);
                }
            }
        }
        return islands;
    }
private:
    void dfs(vector<vector<char>>& grid, int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';

        dfs(grid,n,m,i+1,j);
        dfs(grid,n,m,i-1,j);
        dfs(grid,n,m,i,j+1);
        dfs(grid,n,m,i,j-1);
    }
};