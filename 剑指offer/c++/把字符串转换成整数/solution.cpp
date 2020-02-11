/*题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例:
输入

+2147483647
    1a33
输出

2147483647
    0
    */

class Solution {
public:
    int StrToInt(string str) {
        int label = 1, len = str.length(), result = 0, MAX = 2147483647;
        if(!len)    return 0;
        for(int i = 0; i < len; i++){
            if(str[i] == '+' || str[i] == '-'){
                if(i == 0 && str[i] == '-')    label = -1;
                if(i != 0)    return 0;
            }
            else if(str[i] - '0' >= 0 && str[i] -'9' <= 0){
                if(MAX/10 < result)    return 0;
                if(label == 1){
                    if(MAX/10 == result && str[i]-'0' > 7)    return 0;
                }
                else{
                    if(MAX/10 == result && str[i]-'0' > 8)    return 0;
                }
                result *= 10;
                result += str[i] - '0';
            }
            else return 0;
        }
        return result*label;
    }
};