/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 *
 * https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (43.27%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 20.7K
 * Testcase Example:  '5\n7'
 *
 * 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
 * 
 * 示例 1: 
 * 
 * 输入: [5,7]
 * 输出: 4
 * 
 * 示例 2:
 * 
 * 输入: [0,1]
 * 输出: 0
 * 
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int zeros = 0;
        while(n>m){
            zeros++;
            n >>= 1;
            m >>= 1;
        }

        return m << zeros;
    }
};
// @lc code=end

/*最长含1公共前缀
8266/8266 cases passed (8 ms)
Your runtime beats 88.91 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6 MB)
*/