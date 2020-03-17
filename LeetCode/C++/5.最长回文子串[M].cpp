/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.57%)
 * Likes:    1758
 * Dislikes: 0
 * Total Accepted:    182.9K
 * Total Submissions: 641.3K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int left, right;
        int sublen = 0, tmplen = 0;
        if(len <= 1)    return s;
        for(int i = 0; i < len; i++){
            tmplen = longest_substr(s, i, i);
            if(tmplen > sublen){
                sublen = tmplen;
                left = i - tmplen/2;
                right = i + tmplen/2;
            }
            if(i == len -1) continue;
            tmplen = longest_substr(s, i, i+1);
            if(tmplen > sublen){
                sublen = tmplen;
                left = i - tmplen/2 + 1;
                right = i + tmplen/2 ;
            }
        }

        return s.substr(left, right - left + 1);
    }
    int longest_substr(string &s, int mid_l, int mid_r){
        int len = s.length();
        while(mid_l>=0 && mid_r<len && s[mid_l] == s[mid_r]){
            mid_l--, mid_r++;
        }
        return mid_r - mid_l - 1;
    }
};
// @lc code=end

/*
对于每个i位置的字符s[i]，分别检查
a：以s[i]为中心的           最长    奇数长度子串长度
b：以s[i]和s[i+1]为中心的   最长    偶数长度子串长度
103/103 cases passed (32 ms)
Your runtime beats 78.97 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.2 MB)
*/