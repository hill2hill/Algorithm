/*
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）


输出描述:
示例1

输入 			输出
8 				18

*/
//贪心，能截3就截3
class Solution {
public:
    int cutRope(int number) {
        if(number == 2)	return 1;
        if(number == 3) return 2;
        int exp = number/3, r = number%3;
        if(r == 0)	return pow(3,exp);
        if(r == 1)	return 4*pow(3,exp-1);
        if(r == 2)	return 2*pow(3,exp);
    }
};