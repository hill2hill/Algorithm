/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (34.42%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    24.5K
 * Total Submissions: 68.7K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

// @lc code=start
bool cmp(int a, int b){
        return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans;
        for(auto i:nums)    ans += to_string(i);
        if(ans[0] == '0')  return "0";
        return ans;
    }
    
};
// @lc code=end

/*Accepted
222/222 cases passed (28 ms)
Your runtime beats 17.39 % of cpp submissions
Your memory usage beats 5.43 % of cpp submissions (11.2 MB)
*/