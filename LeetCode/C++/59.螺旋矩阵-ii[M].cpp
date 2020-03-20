/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (75.35%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 37.2K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> ans(n, vector<int> (n,1));
        int left = 0, right = n-1, up = 0, down = n-1;
        int worker = 1;
        while(true){
        	for(int i = left; i <= right; i++)	ans[up][i] = worker++;
        	if(++up > down) break;

        	for(int i = up; i<= down; i++)	ans[i][right] = worker++;
        	if(--right < left)  break;

        	for(int i = right; i>= left; i--)	ans[down][i] = worker++;
        	if(--down < up) break;

        	for(int i = down; i >= up; i--)	ans[i][left] = worker++;
        	if(++left > right) break;
        }

        return ans;
    }
};
// @lc code=end


/*
换汤不换药
20/20 cases passed (4 ms)
Your runtime beats 71.62 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.2 MB)
*/