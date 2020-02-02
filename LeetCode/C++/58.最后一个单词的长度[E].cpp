/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (31.48%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    64.2K
 * Total Submissions: 199.4K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
 * 
 * 如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0) return 0;
        int result = 0, flag = 0;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] != ' '){
                if(flag == 0){
                    flag = 1;
                }
                result++;
            }
            if(s[i] == ' '){
                if(flag == 1)   break;
            }
        }
        return result;
    }
}; 
// @lc code=end

/*59/59 cases passed (0 ms)?
Your runtime beats 100 % of cpp submissions
Your memory usage beats 6.89 % of cpp submissions (8.9 MB)*/
/*59/59 cases passed (4 ms)
Your runtime beats 78.42 % of cpp submissions
Your memory usage beats 6.77 % of cpp submissions (8.9 MB)*/