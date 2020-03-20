/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (33.37%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    59K
 * Total Submissions: 172.9K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)	return 0;
        if(x == 1)	return 1;
        if(n == 0)	return 1;
        long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }

        return fastPow(x, N);
    }

    double fastPow(double x, long N){
        if(N == 0)  return 1;
        if(N == 1)  return x;
        double half = fastPow(x, N/2);
        if(N%2 == 1){
            return x*half*half;
        }
        return half*half;
    }
};
// @lc code=end



/*

正确思路，使用快速幂法
使用long型代替 int ,防止越界
304/304 cases passed (4 ms)
Your runtime beats 67.89 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (7.6 MB)
*/
/*

不正确
整体思路1：循环乘法(X)
整体思路2：成倍乘法(X)
x有几种情况
0. x==1 return 1
1. x==0 return 0;
2. x>0
3. x<0

n有几种情况
1.n==0 return 1;
2.n>0
3.n<0
特殊情况：
1. n=INT_MAX
2. n=INT_MIN
*/