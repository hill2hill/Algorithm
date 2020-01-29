/*
输入一个整数数组，
判断该数组是不是某二叉搜索树的后序遍历的结果。

如果是则输出Yes,否则输出No。

假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if(sequence.size() == 0)	return false;

    	return check(0, sequence.size()-1, sequence);
    }

    bool check(int left_index, int root_index, std::vector<int> sequence){
    	if(root_index - left_index < 2)	return true;
        int i;//游标
    	//如果序列中只有右子树
    	if(sequence[left_index] > sequence[root_index]){
    		for(i = left_index; i<root_index; i++){
    			if(sequence[i] < sequence[root_index])	return false;
    		}
    		return check(left_index,root_index-1,sequence);
    	}
    		

    	//如果序列中只有左子树
    	if(sequence[root_index-1] < sequence[root_index-1]){
    		for(i = left_index; i<root_index; i++){
    			if(sequence[i] > sequence[root_index])	return false;
    		}
    		return check(left_index, root_index-1, sequence);
    	}
        int p;
    	for(p = left_index; p<root_index; p++){
    		if(sequence[p] > sequence[root_index])
    			break;
    	}
    	for(i = p; i < root_index; i++){
    		if(sequence[i] < sequence[root_index])	return false;
    	}
    	return check(left_index, p-1, sequence) && check(p, root_index-1, sequence); 
    			/*
    				&& (sequence[root_index-1] > sequence[root_index]);
    				这样只测试一个不够的，必须子树全部值都大于或小于根节点
    			*/
    }
};

/*我使用的是递归的思路，但是提示中说明考察栈的使用*/