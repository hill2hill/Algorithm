/*
第一个只出现一次的字符

题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中

找到第一个只出现一次的字符,并返回它的位置, 
如果没有则返回 -1（需要区分大小写）.
*/

//直觉哈希
/*
先将所有字符hash方式映射到一个计数数组
每次出现值加一

查看计数数组
	如果有值为一的，都保存到一个候选vector中
	如果没有，直接返回-1

再遍历字符串，如果只计数出现一次，就返回该字符位置；
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
    	if(str.length() == 0)	return -1;
    	if(str.length() == 1)	return 0;
        vector<int> count(100,0);
        for(int i  = 0; i < str.length(); i++){
        	count[str[i] - 'A']++;
        }
        for(int i = 0; i < str.length(); i++){
        	if(count[str[i] - 'A'] == 1){
        		return i;
        	}
        }
        return -1;
    }
};