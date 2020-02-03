/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if(n < 0)	return 0;
    	int exp = 1, f, c, b, result = 0;
    	do{
    		f = n/(10*exp);
    		c = n%(10*exp)/exp;
    		b = n%exp;
    		if(f){
    			if(c > 1){
    				result += (f+1)*exp;
    			}
    			else if(c == 1){
    				result += f*exp + (b+1);
    			}
    			else if(c == 0){
    				result += f*exp;
    			}
    		}
    		else if(f == 0){
    			if(c > 1){
    				result += (f+1)*exp;
    			}
    			else if(c == 1){
    				result += b+1;
    			}
    		}
    		exp *= 10;
    	}while(n/exp);

    	return result;
    }
};