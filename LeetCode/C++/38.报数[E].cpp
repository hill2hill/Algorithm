/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (53.12%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    69.8K
 * Total Submissions: 128.6K
 * Testcase Example:  '1'
 *
 * 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * 
 * 注意：整数序列中的每一项将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 解释：这是一个基本样例。
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 =
 * 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。
 * 
 */

// @lc code=start

#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string former = "1", str = "1";
        for(int i = 1; i<n; i++){
            str = "";
            char p = former[0];
            int count = 1;
            for(int j = 1;j<former.length();j++){
                if(former[j] == p){    
                    count++;
                }
                else {//if(former[j] != p)
                    str += to_string(count);
                    str.append(1,p);
                    p = former[j];
                    count = 1;
                }                
            }
            str += to_string(count);
            str.append(1,p);
            former = str;
        }
        return str;
    }
};

// @lc code=end

/*
18/18 cases passed (4 ms)
Your runtime beats 87.57 % of cpp submissions
Your memory usage beats 79.7 % of cpp submissions (8.6 MB)
*/

//题意理解错误...
//  | | |
//  V V V
// #include <vector>
// #include <string>
// using namespace std;
// class Solution {
// public:
//     string countAndSay(int n) {
//         string start = "1";
//         vector<int> counting(10,0);//声明指定长度的vector
//         //counting[1] = 1;
//         for(int i = 1; i < n; i++){
//             count(start, counting);
//             start = reFresh(counting);
//         }
//         return start;
//     }
//     void count(string str, vector<int> &counting){
//         for(int i = 0; i < str.length(); i++){
//             counting[str[i] - '0']++;//字符转数字
//         }
//     }
//     string reFresh(vector<int> &counting){
//         string str;
//         for(int i = 9; i >= 0; i--){
//             if(counting[i]){
//                 str.append(to_string(counting[i]));
//                 str.append(to_string(i));
//             }
//         }
//         for(int tmp = 0; tmp < 10; tmp++){
//             counting[tmp] = 0;
//         }
//         return str;
//     }
// };