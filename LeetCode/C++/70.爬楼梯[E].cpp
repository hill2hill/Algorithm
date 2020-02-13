/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (47.13%)
 * Likes:    830
 * Dislikes: 0
 * Total Accepted:    132.1K
 * Total Submissions: 276.3K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
//递归深度太多，重复计算导致超时，所以选择动态规划方法
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int n_1 = 1, n_2 = 2, plans = 0;
        for(int i = 3; i <= n; i++){
            plans = n_1 + n_2;
            n_1 = n_2;
            n_2 = plans;
        }  
        return plans;
    }
};
// @lc code=end

/*
45/45 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 80.76 % of cpp submissions (8.1 MB)
*/