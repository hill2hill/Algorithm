/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (45.69%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    66.5K
 * Total Submissions: 140K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    int rows, cols;
public:
    void traceBack(int x, int y, vector<vector<char>>& grid){
        grid[x][y] = '0';
        if(x+1 < rows && grid[x+1][y] == '1'){
            traceBack(x+1, y, grid);
        }
        if(y+1 < cols && grid[x][y+1] == '1'){
            traceBack(x, y+1, grid);
        }
        if(x-1 >=0 && grid[x-1][y] == '1'){
            traceBack(x-1, y, grid);
        }
        if(y-1 >=0 && grid[x][y-1] == '1'){
            traceBack(x, y-1, grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        rows = grid.size();
        if(!rows)   return 0;
        cols = grid[0].size();
        if(!cols)   return 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    traceBack(i, j, grid);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*回溯法
47/47 cases passed (8 ms)
Your runtime beats 97.9 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.5 MB)
*/