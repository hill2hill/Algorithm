/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (59.20%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    57.4K
 * Total Submissions: 93.8K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        //存储下标key为排序后的字符串，value为该key对应于ans中第几个vector
        unordered_map<string, int> hashmap;
        int index = 0;

        for(auto str:strs){
        	string key = str;
            sort(key.begin(), key.end());
        	if(hashmap.count(key)){//已有的key，通过key找对应的ans下标
        		ans[hashmap[key]].push_back(str);
        	}
        	else{//没见过的key新建
        		vector<string> v(1,str);
        		ans.push_back(v);
        		hashmap[key] = index++;
        	}
        }
        return ans;
    }
};
// @lc code=end

/*
unordered_map速度比map快！
101/101 cases passed (36 ms)
Your runtime beats 92.97 % of cpp submissions
Your memory usage beats 93.19 % of cpp submissions (17.6 MB)
*/