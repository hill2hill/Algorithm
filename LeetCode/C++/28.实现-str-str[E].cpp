/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.02%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    120.9K
 * Total Submissions: 306.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int son_len = needle.length(); 
        if(son_len == 0)    return 0;

        int fa_len = haystack.length();
        if(fa_len < son_len) return -1;
        int pos = 0, fa_p = 0, son_p = 0;
        while(pos <= fa_len - son_len){
            if(haystack[pos] == needle[son_p]){
                fa_p = pos;
                while(son_p<son_len){
                    if(haystack[fa_p] != needle[son_p]) break;
                    fa_p++,son_p++;
                }
                if(son_p == son_len){
                    return pos;
                }
                else{
                    son_p = 0;
                }
            }
            pos++;
            
        }
        return -1;
    }
};
// @lc code=end

/*
74/74 cases passed (4 ms)
Your runtime beats 93.63 % of cpp submissions
Your memory usage beats 13.88 % of cpp submissions (9.4 MB)
*/