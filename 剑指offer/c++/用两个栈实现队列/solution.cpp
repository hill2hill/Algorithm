/*用两个栈来实现一个队列，完成队列的Push和Pop操作。 
队列中的元素为int类型。*/
class Solution
{
public:
    void push(int node) {
        if(stack1.empty() && stack2.empty())
        {
        	stack1.push(node);
        }
        else
        {
        	while(!stack2.empty())
        	{
        		stack1.push(stack2.top());
        		stack2.pop();
        	}
        	stack1.push(node);
        }
    }

    int pop() {
    	if(stack1.empty() && stack2.empty()) return 0;
        while(!stack1.empty()){
        	stack2.push(stack1.top());
        	stack1.pop();
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};