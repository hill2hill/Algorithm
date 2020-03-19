/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (72.53%)
 * Likes:    565
 * Dislikes: 0
 * Total Accepted:    89.5K
 * Total Submissions: 120.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
private:
	vector<vector<int>> ans;
	vector<int> path;
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
    	if(remain.size() == 0){
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
回溯法 ~  深度优先搜索

几个重要的部分
1: 主函数DFS入口
2: 当前结果push后，将剩余部分进入DFS
3: DFS结束后，当前结果pop
4: 递归出口
25/25 cases passed (8 ms)
Your runtime beats 62.71 % of cpp submissions
Your memory usage beats 70.06 % of cpp submissions (9.2 MB)
*/

