/*大家都知道斐波那契数列，现在要求

输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。

n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)    return 0;
    	if(n == 1 || n == 2)	return 1;
    	int Fib[39] = {0,1,1};
    	for(int i = 3; i < n; i++){
    		Fib[i] = Fib[i-1] + Fib[i-2];
    	}
    	return Fib[n];
    }
};//上面这个版本不好


class Solution {
public:
    int Fibonacci(int n) {
    	int Fib[39] = {0,1};
        int i = 2;
    	while(i <= n){
            Fib[i] = Fib[i-1] + Fib[i-2];
            i++;
        }
    	return Fib[n];
    }
};