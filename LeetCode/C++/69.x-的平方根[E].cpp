/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.20%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    92K
 * Total Submissions: 245.1K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int MAX = 46340;
    int mySqrt(int x) {
        if(x < 2)   return x;
        int left = 0, right = (x<MAX)?x:MAX, mid;
        while(1){
            mid = (left + right)/2;
            if(mid == MAX)  return mid;
            if(((mid*mid)<=x) && ((mid*mid+2*mid+1)>x)){
                return mid;
            }
            else if((mid*mid) >x){
                right = mid - 1;
            }
            else if((mid*mid) <x){
                left = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

/*
1017/1017 cases passed (4 ms)
Your runtime beats 83.74 % of cpp submissions
Your memory usage beats 58.27 % of cpp submissions (8.1 MB)
*/