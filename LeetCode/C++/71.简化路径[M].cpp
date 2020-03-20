/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 *
 * https://leetcode-cn.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (37.79%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 79.4K
 * Testcase Example:  '"/home/"'
 *
 * 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
 * 
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..）
 * 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
 * 
 * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 /
 * 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："/home/"
 * 输出："/home"
 * 解释：注意，最后一个目录名后面没有斜杠。
 * 
 * 
 * 示例 2：
 * 
 * 输入："/../"
 * 输出："/"
 * 解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
 * 
 * 
 * 示例 3：
 * 
 * 输入："/home//foo/"
 * 输出："/home/foo"
 * 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
 * 
 * 
 * 示例 4：
 * 
 * 输入："/a/./b/../../c/"
 * 输出："/c"
 * 
 * 
 * 示例 5：
 * 
 * 输入："/a/../../b/../c//.//"
 * 输出："/c"
 * 
 * 
 * 示例 6：
 * 
 * 输入："/a//b////c/d//././/.."
 * 输出："/a/b/c"
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string q;
        //q += '/';
        vector<string> str;

        //删除多余的 '/'
        int len = path.length();
        for(int i = 1; i < len; i++){
        	if(path[i] == path[i-1] && path[i] == '/')	continue;
        	q += path[i];
        }
        if(q[q.length()-1] == '/')	q.pop_back();
        //cout << q;
        //拆分文件夹名称
        str.push_back("/");
        
        
        for(int i = 0; i < q.length(); i++){
        	string tmp;
            //cout <<'~';
        	while(q[i] != '/' && i < q.length()){
        		tmp += q[i++];
                
        	}
        	if(tmp == ".")	continue;
        	else if(tmp == ".."){
        		if(str.size() == 1)	continue;
        		else	str.pop_back();
        	}
        	else str.push_back(tmp);
        }
        
        if(str.size() == 1) return "/";

        string ans;
        for(int i = 1; i<str.size(); i++){
            ans += '/';
        	ans += str[i];            
        }
        //ans.pop_back();
        //cout << ans;
        return ans;
    }
};
// @lc code=end

/*
先去除多余的'/'
再按顺序检查每个文件夹名称
如果"./" 什么都不做
如果"../" 保证根目录的条件下，出栈
普通文件夹名则入栈
254/254 cases passed (8 ms)
Your runtime beats 82.93 % of cpp submissions
Your memory usage beats 91.62 % of cpp submissions (9.7 MB)
测试用例
"/../"
"/a/../../b/../c//.//"
"/a//b////c/d//././/.."
*/