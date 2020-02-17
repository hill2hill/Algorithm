/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (45.52%)
 * Likes:    566
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 205.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(numRows <= 0 || len == 0)    return"";
        if(numRows == 1)    return s;
        vector<string> result(numRows,"");
        int row = 0, mod = 2*numRows-2, i = 0, check = 0;
        while(i<len){
            check = 0;
            while(check <= mod/2){
                if(i%mod == check || i%mod == mod-check){
                    result[check].append(1,s[i]);
                    break;
                }
                else check++;
            }
            i++;           
        }
        string ans = "";
        for(int x = 0; x < numRows; x++){
            ans += result[x];
        }
        return ans;
    }
};
// @lc code=end

/*
1158/1158 cases passed (64 ms)
Your runtime beats 12.57 % of cpp submissions
Your memory usage beats 64.15 % of cpp submissions (10.5 MB)*/