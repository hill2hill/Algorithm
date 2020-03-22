/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (75.13%)
 * Likes:    497
 * Dislikes: 0
 * Total Accepted:    70.6K
 * Total Submissions: 91.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
private:
	vector<vector<int>> ans;
	vector<int> path;
	vector<int> nums;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        this -> nums = nums;
        DFS(0,n);

        return ans;
    }
    void DFS(int start, int remain){
    	if(remain == 0){
    		ans.push_back(path);
    		return;
    	}
    	path.push_back(nums[start]);
    	DFS(start+1, remain-1);
    	path.pop_back();
    	DFS(start+1, remain-1);
    }
};
// @lc code=end

/*
回溯法+全局变量
10/10 cases passed (4 ms)
Your runtime beats 80.09 % of cpp submissions
Your memory usage beats 23.01 % of cpp submissions (12.2 MB)
*/