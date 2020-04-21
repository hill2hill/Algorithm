/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (42.45%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    13.6K
 * Total Submissions: 30.9K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int len = s.length();
        if(len <= 10)   return ans;
        set<string> seen;
        string window = s.substr(0,10);
        seen.insert(window);
        for(int i = 1; i < len-9; i++){
            string tmp = window.substr(1,9);
            //cout << tmp <<endl;
            window = tmp + s[i+9];
            //cout << window <<endl;
            if(seen.find(window) != seen.end())    ans.push_back(window);
            seen.insert(window);
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
// @lc code=end

/*使用暂存set好慢！！！
32/32 cases passed (584 ms)
Your runtime beats 5.04 % of cpp submissions
Your memory usage beats 60 % of cpp submissions (20.4 MB)
*/