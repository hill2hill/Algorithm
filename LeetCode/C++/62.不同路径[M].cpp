/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (57.01%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    82.5K
 * Total Submissions: 138.6K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row_elements(n,1);
        for(int row = m-2; row >= 0; row--){
            for(int i = n-2; i >= 0; i--){
                row_elements[i] += row_elements[i+1]; 
            }
        }
        
        return row_elements[0];
    }
};
// @lc code=end

/*
动态规划
62/62 cases passed (4 ms)
Your runtime beats 62.42 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (7.5 MB)
*/
/*递归超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)    return 0;
        if(m == 1 || n == 1)    return 1;

        return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};
*/