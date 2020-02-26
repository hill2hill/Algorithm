/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.38%)
 * Likes:    758
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 102.7K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n <= 0)  return ans;
        string current = "";
        search(n,n,ans,current);
        return ans;
    }

    void search(int left, int right, vector<string> &ans, string current){
        if(left == 0 && right == 0)
            ans.push_back(current);
        
        if(right > left){
            
            search(left, right-1,ans,current+")");

        }
        if(left > 0){
            
            search(left-1,right,ans,current+"(");
        }
        
    }

};
// @lc code=end

/*贪心？！
8/8 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 40.78 % of cpp submissions (17.2 MB)
*/