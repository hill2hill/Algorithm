/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (47.33%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    26.6K
 * Total Submissions: 54.7K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
	int factorial(int n){
		int ans = 1;
		while(n>1){
			ans *= n;
			n--;
		}
		return ans;
	}
    string getPermutation(int n, int k) {
        vector<char> numState;
        if(n == 1)	return "1";
        string ans;
        for(int i=0; i<=n;i++)	numState.push_back(i+'0');
        int group = factorial(n-1);
    	while(n>1){
    		int index = 1+(k-1)/group;
    		ans += numState[index];
    		n--;
    		if(k%group==0)  k = group;//这里是唯一一个要特殊处理的地方，如果恰好是组内最后一个，余数为零，其实就是下一轮中最后一个
            else k = k%group;
    		group = factorial(n-1);
    		numState.erase(numState.begin()+index);
    	}
    	ans += numState[1];
        return ans;
    }
};
// @lc code=end

/*
膨胀了！
200/200 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6 MB)
*/