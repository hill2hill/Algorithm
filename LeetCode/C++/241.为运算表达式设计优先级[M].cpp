/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (69.42%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 11.6K
 * Testcase Example:  '"2-1-1"'
 *
 * 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及
 * * 。
 * 
 * 示例 1:
 * 
 * 输入: "2-1-1"
 * 输出: [0, 2]
 * 解释: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * 示例 2:
 * 
 * 输入: "2*3-4*5"
 * 输出: [-34, -14, -10, -10, 10]
 * 解释: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        int count_op = 0;
        for(auto c:input){
            if(c=='+' || c=='-' || c== '*') count_op++;
            if(count_op > 1)    break;
        }
        if(count_op == 1){
            ans.push_back(compute(input));
            return ans;
        }
        if(count_op == 0){
            ans.push_back(atoi(input.c_str()));
            return ans;
        }
        vector<int> ans_01, ans_02;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                ans_01 = diffWaysToCompute(input.substr(0,i));
                ans_02 = diffWaysToCompute(input.substr(i+1,input.length()-i-1));
            }
            for(auto val1:ans_01){
                for(auto val2:ans_02){
                    if(input[i] == '+') ans.push_back(val1+val2);
                    else if(input[i] == '-') ans.push_back(val1-val2);
                    else ans.push_back(val1*val2);
                }
            }
            ans_01.clear(); ans_02.clear();
        }

        return ans;
    }
    vector<string> split(string str, char delimiter = ' '){
        vector<string> ans;
        string tmp;
        for(char c:str){
            if(c != delimiter){
                tmp += c;
            }
            else{
                if(tmp != "")	ans.push_back(tmp);
                tmp = "";
            }
        }
        if(tmp != ""){
            ans.push_back(tmp);
        }
        return ans;
    }

    int compute(string str){
        vector<string> nums;
        int ans;
        if(str.find("+") != string::npos){
            nums = split(str,'+');
            ans = atoi(nums[0].c_str())+atoi(nums[1].c_str());
        }
        if(str.find("-") != string::npos){
            nums = split(str,'-');
            ans = atoi(nums[0].c_str())-atoi(nums[1].c_str());
        }
        if(str.find("*") != string::npos){
            nums = split(str,'*');
            ans = atoi(nums[0].c_str())*atoi(nums[1].c_str());
        }
        if(str.find("/") != string::npos){
            nums = split(str,'/');
            ans = atoi(nums[0].c_str())/atoi(nums[1].c_str());
        }
        return ans;
    }
};
// @lc code=end

/*
Accepted
25/25 cases passed (8 ms)
Your runtime beats 57.87 % of cpp submissions
Your memory usage beats 47.22 % of cpp submissions (13.6 MB)
*/