/*
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。*/
class Solution {
public:
    bool isNumeric(char* string)
    {    
        bool flag = true;
        if(strlen(string) == 0)	return false;
        if(*string == '+' || *string == '-')	string++;
        while(isdigit(*string) && (*string != '\0'))	string++;
        if(*string == '.'){
            string++;//fuck,forgeted
        	while(isdigit(*string) && (*string != '\0'))	string++;
        }
        if(*string == 'e' || *string == 'E'){
            string++;//fuck,forgeted
            flag = false;
        	if(*string == '+' || *string == '-')	string++;
        	while(isdigit(*string) && (*string != '\0'))	string++,flag = true;
        }

        return (*string == '\0') && flag;
    }
    
};