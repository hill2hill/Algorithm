/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (55.34%)
 * Likes:    246
 * Dislikes: 0
 * Total Accepted:    44.8K
 * Total Submissions: 77.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
private:
	vector<vector<int>> ans;
	vector<int> path;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<int> tmp = nums;
    	int len = nums.size();
    	if(nums.size() == 0)	return ans;
    	if(nums.size() == 1){
            ans.push_back(nums);
            return ans;
        }
    	DFS(nums);
    	return ans;
    }

    void DFS(vector<int> remain){
    	if(remain.size() == 0 && find(ans.begin(), ans.end(), path) == ans.end()){
    		ans.push_back(path);
    		return;
    	}
    	vector<int> tmp = remain;
    	for(int i = 0; i<remain.size(); i++){
    		swap(remain[i], remain[remain.size()-1]);
    		path.push_back(remain[remain.size()-1]);
    		remain.pop_back();
    		DFS(remain);
            path.pop_back();
    		remain = tmp;
    	}
    }
};
// @lc code=end

/*
30/30 cases passed (1692 ms)
Your runtime beats 5.04 % of cpp submissions
Your memory usage beats 5.25 % of cpp submissions (36.8 MB)
*/
