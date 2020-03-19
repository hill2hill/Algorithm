/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (40.84%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 117.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        if(!len1 || !len2)  return "";
        if(num1 == "0" || num2 == "0")  return "0";
        vector<int> tmp_ans(len1+len2+1,0);
        for(int j = len2-1; j >= 0; j--){ //第二行
            for(int i = len1-1; i >= 0; i--){ //第一行
                tmp_ans[len1 -1-i + len2 -1-j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        /*for(int i = 0; i<len1+len2+1; i++){
            cout <<tmp_ans[i]<<' ';
        }*/
        string ans;
        int up = 0;
        for(int i = 0; i < len1+len2+1; i++){
            ans += (tmp_ans[i] + up)%10 + '0';
            up = (tmp_ans[i] + up)/10;
        }

        while(ans.back() == '0')    ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans;

    }
};
// @lc code=end

//"1213"\n"34"
/*一开始忘记了数字是从高位向低位顺序存储的，导致计算时把高位结果存到了低位

看了leetcode题解，整体思路没有问题，其实我可以把num1和num2一开始就翻转，这样就简单许多了
311/311 cases passed (12 ms)
Your runtime beats 47.27 % of cpp submissions
Your memory usage beats 42.27 % of cpp submissions (9 MB)
*/