/*
给定一个double类型的浮点数base和int类型的整数exponent。

求base的exponent次方。

保证base和exponent不同时为0*/

class Solution {
public:
    double Power(double base, int exponent) {
    	if(base == 0.0 && exponent == 0)	return 0;//好像不用？
    	if(base == 0.0)	return 0;//base == 0.0能行，但是书上好像不让
    	if(exponent == 0)	return 1;

    	if(exponent < 0){
    		base = 1/base;
    		exponent = -exponent;
    	}
    	double result = 1;
    	for(int i = 0; i < exponent; i++){
    		result *= base;
    	}
    	return result;
    }
};