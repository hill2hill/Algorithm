/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (57.80%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    41.7K
 * Total Submissions: 69K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> can;
public:
    void DFS(int start, int target){
        
        /*cout <<"private can elements: ";
        for(int j = 0; j < can.size();j++){
            cout << can[j] <<' ';
        }*/
        if(target == 0 && find(ans.begin(), ans.end(), path) == ans.end()){
            ans.push_back(path);
            //cout << endl;
            return;
        }
        if(start >= can.size()) return;
        for(int i = start; i < can.size(); i++){
            if(can[i] <= target ){
                //cout << "try: can_"<<i<<":\t"<<can[i]<<'\t';
                path.push_back(can[i]);
                //cout<<"path size: "<< path.size() << "\telements: ";
                /*for(int j = 0; j < path.size();j++){
                    cout << path[j] <<' ';
                }
                
                cout << endl;*/

                //cout << "DFS("<<i+1<<","<<target - can[i]<<"):";
                DFS(i+1, target - can[i]);
                path.pop_back();
            }
            if(can[i] > target)  break;
        }
        //cout <<"break"<<endl;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        if(candidates.size() < 1)   return ans;
        sort(candidates.begin(), candidates.end());
        if(target < candidates[0])  return ans;
        can = candidates;
        DFS(0, target);

        return ans;
    }
};
// @lc code=end

/*
DFS的思路，同时限制不要重复使用以前测试过的节点了，防止重复
使用private全局变量，减少传入参数？失败了？
172/172 cases passed (4 ms)
Your runtime beats 97.71 % of cpp submissions
Your memory usage beats 85.14 % of cpp submissions (8.9 MB)
*/