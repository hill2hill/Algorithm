/*定义栈的数据结构，
请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
public:
	stack<int> value_stack, min_stack;
    void push(int value) {
    	if(value_stack.empty()){//栈为空判断，不能随便删
    		value_stack.push(value);
        	min_stack.push(value);
    	}
        if(value > min_stack.top()){
        	value_stack.push(value);
        	min_stack.push(min_stack.top());
        }
        else{
        	value_stack.push(value);
        	min_stack.push(value);
        }
    }
    void pop() {
    	if(!value_stack.empty()){
    		value_stack.pop();
        	min_stack.pop();
    	}        
    }
    int top() {
        return value_stack.top();
    }
    int min() {
        return min_stack.top();
    }

};