/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (18.76%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    35.9K
 * Total Submissions: 186K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 
 * 说明:
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == 0)   return 0;
        if(divisor == INT_MIN) return 0;
        if(divisor == 1)   return dividend;
        if(dividend == INT_MIN && divisor == -1)    return INT_MAX;
        if(divisor == -1)   return -dividend;
        
        if(dividend < 0 && divisor <0 && dividend > divisor)    return 0;
        if(dividend > 0 && divisor > 0 && dividend < divisor)   return 0;
        int ans = 0, delta = 1;
        int flag = 0;
        if(dividend == INT_MIN){
            if(divisor < 0) dividend -= divisor, ans++;
            else dividend += divisor, ans++;
        }
        
        if(dividend < 0)    flag--, dividend = - dividend;
        else flag++;
        if(divisor < 0) flag--,divisor = -divisor;
        else flag++;
        //cout <<"begin:"<<dividend<<"/"<<divisor<<endl;
        while(dividend > 0){
            while(dividend > divisor &&divisor < 1073741824){
                divisor = divisor << 1;
                //cout << "divisor amply to: "<<divisor<<";\t";
                delta =delta << 1;
                //cout << "level: "<< delta <<endl;
            }
            while(dividend < divisor){
                divisor = divisor >> 1;
                delta = delta >> 1;
                //cout << "divisor modified to: "<<divisor<<";\t";
                //cout << "level: "<< delta <<endl;
                if(delta == 1)  break;
            }
            dividend -= divisor;
            //cout <<"new:"<<dividend<<"/"<<divisor<<endl;
            
            if(dividend < 0)   break;
            ans += delta;
            //cout << "current ans:"<<ans<<endl;
        }

        if(flag == 0)   return -ans;
        return ans;
    }
};
// @lc code=end

/* 大量的if
主要是防止溢出
对最大最小的判断

因为INT_MIN 的绝对值要比INT_MAX的绝对值大1
所以先考虑掉所有的INT_MIN情况，然后将所有的计算划到正数域内就可以
（全划分到负数域其实也可以，不过leetcode不支持负数的算术左移）

用位运算代替*2和/2运算，能减少时间复杂度到logN
989/989 cases passed (4 ms)
Your runtime beats 82.5 % of cpp submissions
Your memory usage beats 18.55 % of cpp submissions (8.3 MB)
*/