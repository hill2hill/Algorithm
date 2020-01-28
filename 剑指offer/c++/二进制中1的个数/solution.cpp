/*输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。*/

class Solution {
public:
     int  NumberOf1(int n) {
     	int sum=0,abs=n;
        if(n < 0){
        	sum = 1;
        	abs = -n;
         }
        while(abs != 0){
        	sum += abs & 1;
        	abs = abs >> 1;
        }
        return sum;
     }
};//有问题!!!!!!!!!!!!!!!!!!!!下面的正确!!!!!!!!!!!!!!!!!!!!

class Solution {
public:
     int  NumberOf1(int n) {
     	int sum=0,abs=n;
        if(n < 0){
        	sum = 1;
        	abs = n & 0x7FFFFFFF;
         }
        while(abs > 0){
        	sum += abs & 1;
        	abs = abs >> 1;
        }
        return sum;
     }
};