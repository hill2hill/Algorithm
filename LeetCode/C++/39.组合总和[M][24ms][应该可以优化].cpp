/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (67.29%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    67.1K
 * Total Submissions: 98K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        if(target < candidates[0])  return ans;
        
        vector<int> tmp;
        search(ans,target,tmp,candidates);

        return ans;
    }
    void search(vector<vector<int>> &ans, int target, vector<int> tmp, vector<int> &candidates){
        if(target == 0){
            ans.push_back(tmp);
        }
        else if(target >= candidates[0]){
            for(int i = 0; i < candidates.size() && candidates[i] <= target; i++){
                if(tmp.size()==0 || candidates[i] >= tmp[tmp.size()-1]){
                    vector<int> t = tmp;//感觉这句话多余了，影响速度了
                    t.push_back(candidates[i]);
                    search(ans,target-candidates[i],t,candidates);
                }
            }
        }
    }
};
// @lc code=end

/*
168/168 cases passed (24 ms)
Your runtime beats 36.65 % of cpp submissions
Your memory usage beats 18.52 % of cpp submissions (16.6 MB)
*/