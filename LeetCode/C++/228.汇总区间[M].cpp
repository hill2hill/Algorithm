/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 *
 * https://leetcode-cn.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (48.95%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 15.1K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
 * 
 * 示例 1:
 * 
 * 输入: [0,1,2,4,5,7]
 * 输出: ["0->2","4->5","7"]
 * 解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
 * 
 * 示例 2:
 * 
 * 输入: [0,2,3,4,6,8,9]
 * 输出: ["0","2->4","6","8->9"]
 * 解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
 * 
 */

// @lc code=start








#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string R(int left, int right, vector<int>& nums){
        string str = "";
        if(left == right-1){
            str += to_string(nums[left]);
        }
        else{
            str += to_string(nums[left]);
            str += "->";
            str += to_string(nums[right - 1]);
        }
        return str;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0, right = 1;
        if(nums.size() == 0)    return ans;
        if(nums.size() == 1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        sort(nums.begin(), nums.end());
        while(right <= nums.size()){
            if(right < nums.size() && nums[right] == nums[right-1] + 1){
                right++;
            }
            else{
                string str = R(left, right, nums);
                ans.push_back(str);
                left = right;
                right++;
            }
        }
        return ans;
    }
    
};
// @lc code=end

/*
时间复杂度NlogN  即排序的时间
Accepted
28/28 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (7 MB)
*/