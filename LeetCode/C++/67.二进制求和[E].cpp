/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.24%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    59.5K
 * Total Submissions: 114.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int flag = 0;
        string result = "";
        if(a.length() == 0) return b;
        if(b.length() == 0) return a;
        int len_a = a.length(), len_b = b.length();
        int i = len_a - 1, j = len_b - 1;
        for(;i>=0 && j>=0; i--,j--){
            result.insert(0,1,(a[i]-'0'+b[j]-'0'+flag)%2+'0');
            flag = (a[i]-'0'+b[j]-'0'+flag)/2;
        }
        while(i>=0){
            if(flag){
                result.insert(0,1,(a[i]-'0'+flag)%2+'0');
                flag = (a[i]-'0'+flag)/2;
                i--;
            }
            else{
                result.insert(0,a.substr(0,i+1));
                break;
            }
        }
        while(j>=0){
            if(flag){
                result.insert(0,1,(b[j]-'0'+flag)%2+'0');
                flag = (b[j]-'0'+flag)/2;
                j--;
            }
            else{
                result.insert(0,b.substr(0,j+1));
                break;
            }
        }
        if(flag)    result.insert(0,1,'1');
        return result;
    }
};
// @lc code=end

/*
294/294 cases passed (4 ms)
Your runtime beats 87.06 % of cpp submissions
Your memory usage beats 25.16 % of cpp submissions (8.9 MB)
*/