/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），

现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。

例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。


是不是很简单？OK，搞定它！
*/
//思路：两次翻转
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(!len)	return str;
        n = n%len;
        if(!n)	return str;
        string a, b, tmp;
        a = reverse(tmp.assign(str, 0,n)); //从下标0开始，长度为n的子串
        b = reverse(tmp.assign(str, n,len-n));//从下标n开始，长度为len-n的子串
        return reverse(a+b);
    }
    string reverse(string str){
    	string result = "";
        int len = str.length();
    	for(int i = 0; i < len; i++){
    		result.append(1, str[len-i-1]);
    	}
        return result;
    }
};