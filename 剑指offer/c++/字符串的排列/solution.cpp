/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如      输入字符串abc,
        则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

class Solution {
public:
    //递归的思路
    vector<string> Permutation(string str) {
        vector<int> visited(60);//标记某字符是否已经用过
        vector<string> res, sum_res;
        if(str.length() == 1){
            res.push_back(str);
            return res;
        };
        for(int index = 0; index < str.length(); index++){
            if(visited[str[index]-'A'] == 0){
                res.clear();
                res = Permutation(GetSubStr(str,index));
                for(int i = 0; i < res.size(); i++){
                    res[i].insert(0,1,str[index]);//在前面插入一个字符
                }
                sum_res.insert(sum_res.end(),res.begin(),res.end());
                visited[str[index]-'A'] = 1;
            }
            
        }
        return sum_res;
    }
    string GetSubStr(string str, int index){
        return str.substr(0,index)+str.substr(index+1,str.length());
    }
};



