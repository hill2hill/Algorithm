/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (70.93%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    39.7K
 * Total Submissions: 54.2K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    int n;
public:
    void DFS(int start, int depth){
        if(depth == 0){
            ans.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++){
            path.push_back(i);
            DFS(i+1, depth-1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k < 0 || k > n)  return ans;
        this -> n = n;
        DFS(1, k);

        return ans;
    }
};
// @lc code=end

/*
回溯法一遍过
27/27 cases passed (28 ms)
Your runtime beats 82.78 % of cpp submissions
Your memory usage beats 85.19 % of cpp submissions (11.8 MB)
*/