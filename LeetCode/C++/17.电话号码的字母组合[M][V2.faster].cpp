/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.39%)
 * Likes:    581
 * Dislikes: 0
 * Total Accepted:    78.5K
 * Total Submissions: 149.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    string map[8][4] ={
        {"a","b","c"},
        {"d","e","f"},
        {"g","h","i"},
        {"j","k","l"},
        {"m","n","o"},
        {"p","q","r","s"},
        {"t","u","v"},
        {"w","x","y","z"}
    };
    int length[8] ={3,3,3,3,3,4,3,4};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int len = digits.length();
        if(len == 1){
            for(int i = 0; i<length[digits[0]-'0'-2];i++){
                ans.push_back(map[digits[0]-'0'-2][i]);
            }
            return ans;
        }
        if(len == 0)    return ans;
        vector<string> sub_ans = letterCombinations(digits.substr(1,len-1));
        for(int i = 0;i < length[digits[0]-'0'-2];i++){
            for(int j = 0; j < sub_ans.size(); j++){
                ans.push_back(map[digits[0]-'0'-2][i]+sub_ans[j]);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
25/25 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 22.02 % of cpp submissions (8.8 MB)
*/