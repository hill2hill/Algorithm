/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？*/

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        if(len < 2)	return str;
        string result="";
        int p = len - 1, left = len - 1;
        while(p > 0){
        	if(str[p] == ' '){
        		result += str.substr(p+1, left-p);//字符串的子串
        		result +=" ";
        		left = p-1;
        	}
        	p--;
        }
        result += str.substr(0,left+1);//字符串的子串

        return result;
    }
};